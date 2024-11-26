// TernaryTree.h 

#pragma once
#include <stdexcept>
#include <algorithm>
template<typename T>
class TernaryTreePrefixIterator;
template<typename T>
class TernaryTree
{
public:

	using TTree = TernaryTree<T>;
	using TSubTree = TTree*;
private:

	T fKey;
	TSubTree fSubTrees[3];
	// private default constructor used for declaration of NIL
	TernaryTree() :
		fKey(T())
	{
		for (size_t i = 0; i < 3; i++)
		{
			fSubTrees[i] = &NIL;
		}
	}
public:
	using Iterator = TernaryTreePrefixIterator<T>;

	static TTree NIL; // sentinel
	// getters for subtrees
	const TTree& getLeft() const { return *fSubTrees[0]; }
	const TTree& getMiddle() const { return *fSubTrees[1]; }
	const TTree& getRight() const { return *fSubTrees[2]; }
	// add a subtree
	void addLeft(const TTree& aTTree) { addSubTree(0, aTTree); }
	void addMiddle(const TTree& aTTree) { addSubTree(1, aTTree); }
	void addRight(const TTree& aTTree) { addSubTree(2, aTTree); }

	// remove a subtree, may through a domain error
	const TTree& removeLeft() { return removeSubTree(0); }
	const TTree& removeMiddle() { return removeSubTree(1); }
	const TTree& removeRight() { return removeSubTree(2); }


    //------------------------------------------------------------------- CHANGE FROM HERE
// Problem 1: TernaryTree Basic Infrastructure
private:
    // remove a subtree, may throw a domain error [22]
    const TTree& removeSubTree(size_t aSubtreeIndex)
    {

        if (fSubTrees[aSubtreeIndex] == &NIL)
        {
            throw std::domain_error("Subtree is NIL");
        }
        const TTree& subtree = *fSubTrees[aSubtreeIndex];
        fSubTrees[aSubtreeIndex] = &NIL; 
        return subtree;
    }

    // add a subtree; must avoid memory leaks; may throw domain error [18]
    void addSubTree(size_t aSubtreeIndex, const TTree& aTTree)
    {
        if (fSubTrees[aSubtreeIndex] != &NIL)
        {
            throw std::domain_error("Subtree is not NIL");
        }
        fSubTrees[aSubtreeIndex] = new TTree(aTTree);
    }

public:
    // TernaryTree l-value constructor [10]
    TernaryTree(const T& aKey) 
    {
        fKey = aKey;
        fSubTrees[0] = &NIL;
        fSubTrees[1] = &NIL;
        fSubTrees[2] = &NIL;
    }

    // destructor (free sub-trees, must not free empty trees) [14]
    ~TernaryTree()
    {
        if (fSubTrees[0] != &NIL)
        {
            delete fSubTrees[0];
            fSubTrees[0] = &NIL;
        }
        if (fSubTrees[1] != &NIL)
        {
            delete fSubTrees[1];
            fSubTrees[1] = &NIL;
        }
        if (fSubTrees[2] != &NIL)
        {
            delete fSubTrees[2];
            fSubTrees[2] = &NIL;
        }
    }


    // return key value, may throw domain_error if empty [6]
    const T& operator*() const
    {
        if (empty())
        {
            throw std::domain_error("Operation not supported");
        }
        return fKey;
    }

    // returns true if this ternary tree is empty [4]
    bool empty() const
    {
        return this == &NIL;
    }

    // returns true if this ternary tree is a leaf [10]
    bool leaf() const
    {
        return fSubTrees[0] == &NIL && fSubTrees[1] == &NIL && fSubTrees[2] == &NIL;
    }

    // return height of ternary tree, may throw domain_error if empty [48]
    size_t height() const
    {
        if (empty())
        {
            throw domain_error("Operation not supported");
        }
        if (leaf())
        {
            return 0;
        }
        size_t height[3] = {};

        if (!fSubTrees[0]->empty())
        {
            height[0] = fSubTrees[0]->height();
        }
        else
        {
            height[0] = 0;
        }

        if (!fSubTrees[1]->empty())
        {
            height[1] = fSubTrees[1]->height();
        }
        else
        {
            height[1] = 0;
        }

        if (!fSubTrees[2]->empty())
        {
            height[2] = fSubTrees[2]->height();
        }
        else
        {
            height[2] = 0;
        }


        return std::max(std::max(height[0], height[1]), height[2]) + 1;
    }





	//------------------------------------------------------------------- CHANGE FROM HERE

	// Problem 2: TernaryTree Copy Semantics
	// copy constructor, must not copy empty ternary tree [10]
    TernaryTree(const TTree& aOtherTTree) : fKey(aOtherTTree.fKey)
    {
        size_t i = 0;
        while (i < 3)
        {
            if (aOtherTTree.fSubTrees[i] != &NIL)
            {
                fSubTrees[i] = new TTree(*aOtherTTree.fSubTrees[i]);
            }
            else
            {
                fSubTrees[i] = &NIL;
            }
            ++i;
        }

    }
	// copy assignment operator, must not copy empty ternary tree
	// may throw a domain error on attempts to copy NIL [36]
    TTree& operator=(const TTree& aOtherTTree)
    {
        if (this == &aOtherTTree)
        {
            return *this;
        }

        size_t i = 0;
        while (i < 3)
        {
            fSubTrees[i] != &NIL 
                               ? delete fSubTrees[i] 
                               : void();

            fSubTrees[i+=1] = &NIL;
        }

        fKey = aOtherTTree.fKey;
        i = 0;

        while (i < 3)
        {
            fSubTrees[i] = (aOtherTTree.fSubTrees[i] != &NIL) 
                                ? new TTree(*aOtherTTree.fSubTrees[i]) 
                                : &NIL;
            ++i;
        }
        return *this;

    }

	// clone ternary tree, must not copy empty trees [10]
	TSubTree clone() const
    {
        TSubTree newTree = new TTree(fKey);

         // WAY 1
      for (size_t i = 0; i < 3; i++)
      {
          if (fSubTrees[i] != &NIL)
          {
              newTree->fSubTrees[i] = fSubTrees[i]->clone();
          }
          else
          {
              newTree->fSubTrees[i] = &NIL;
          }
      } 

        return newTree;
    }
    /* WAY 2
      if (fSubTrees[0] != &NIL)
       {
           newTree->fSubTrees[0] = fSubTrees[0]->clone();
       }
       else
       {
           newTree->fSubTrees[0] = &NIL;
       }

       if (fSubTrees[1] != &NIL)
       {
           newTree->fSubTrees[1] = fSubTrees[1]->clone();
       }
       else
       {
           newTree->fSubTrees[1] = &NIL;
       }

       if (fSubTrees[2] != &NIL)
       {
           newTree->fSubTrees[2] = fSubTrees[2]->clone();
       }
       else
       {
           newTree->fSubTrees[2] = &NIL;
       }*/

    
	//------------------------------------------------------------------- CHANGE FROM HERE
	
	// Problem 3: TernaryTree Move Semantics
	 // TTree r-value constructor [12]
	TernaryTree(T&& aKey) : fKey(std::move(aKey))
    {
        fSubTrees[0] = &NIL;
        fSubTrees[1] = &NIL;
        fSubTrees[2] = &NIL;
    }

	// move constructor, must not copy empty ternary tree [12]
    TernaryTree(TTree&& aOtherTTree) : fKey(std::move(aOtherTTree.fKey))
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (aOtherTTree.fSubTrees[i] != &NIL)
            {
                fSubTrees[i] = aOtherTTree.fSubTrees[i]; 
                aOtherTTree.fSubTrees[i] = &NIL;        
            }
            else
            {
                fSubTrees[i] = &NIL; 
            }
        }
        aOtherTTree.fKey = T();

    }
	// move assignment operator, must not copy empty ternary tree [36]
    TTree& operator=(TTree&& aOtherTTree)
    {
        if (this == &aOtherTTree)
        {
            return *this;
        }

        if (this != &aOtherTTree)
        {
            int i = 0;
            while (i < 3)
            {
                if (fSubTrees[i] != &NIL)
                {
                    delete fSubTrees[i];
                }
                fSubTrees[i] = &NIL; 
                i++;
            }

            fKey = std::move(aOtherTTree.fKey);

            i = 0;
            while (i < 3)
            {
                fSubTrees[i] = aOtherTTree.fSubTrees[i];
                aOtherTTree.fSubTrees[i] = &NIL; 
                i++;
            }
        }

        aOtherTTree.fKey = T();

        return *this;
    }


	//------------------------------------------------------------------- CHANGE FROM HERE

	// Problem 4: TernaryTree Prefix Iterator
	 // return ternary tree prefix iterator positioned at start [4]
    Iterator begin() const
    {
        Iterator iterator(this);
        return iterator.begin();
    }

	// return ternary prefix iterator positioned at end [6]
    Iterator end() const
    {
        Iterator iterator(this);
        return iterator.end();
    }
	
};

template<typename T>
TernaryTree<T> TernaryTree<T>::NIL;
 