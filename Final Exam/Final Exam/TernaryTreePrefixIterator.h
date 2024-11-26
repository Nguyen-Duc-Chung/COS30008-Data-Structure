// TernaryTreePrefixIterator.h
// COS30008, Final Exam, 2022

#pragma once

#include "TernaryTree.h"

#include <stack>

template<typename T>
class TernaryTreePrefixIterator
{
private:
    using TTree = TernaryTree<T>;
    using TTreeNode = TTree*;
    using TTreeStack = std::stack<const TTree*>;

    const TTree* fTTree;                // ternary tree
    TTreeStack fStack;                  // traversal stack

public:

    using Iterator = TernaryTreePrefixIterator<T>;

    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);

        return old;
    }

    bool operator!=(const Iterator& aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    /////////////////////////////////////////////////////////////////////////
    // Problem 4: TernaryTree Prefix Iterator

private:

    // push subtree of aNode [30]
    void push_subtrees(const TTree* aNode)
    {
        if (!(aNode->getRight().empty()))
        {
            const TTree* rightSubtree = &aNode->getRight();
            fStack.push(const_cast<TTreeNode>(rightSubtree));
        }

        if (!(aNode->getMiddle().empty()))
        {
            const TTree* middleSubtree = &aNode->getMiddle();
            fStack.push(const_cast<TTreeNode>(middleSubtree));
        }


    }

public:

    // iterator constructor [12]
    TernaryTreePrefixIterator(const TTree* aTTree)
    {
        fTTree = aTTree; 

        if (!(fTTree->empty()))
        {
            const TTree* tempTree = fTTree; 
            fStack.push(const_cast<TTreeNode>(tempTree)); 
        }
    }


    // iterator dereference [8]
    const T& operator*() const
    {
        const TTree* currentNode = fStack.top();
        return **currentNode;
    }

    // prefix increment [12]
    Iterator& operator++()
    {
        TTreeNode poppedNode = const_cast<TTreeNode>(fStack.top());
        fStack.pop();
        if (poppedNode != nullptr)
        {
            push_subtrees(poppedNode); 
        }
        else
        {
            throw std::logic_error("Null node encountered while incrementing.");
        }

        return *this;
    }

    // iterator equivalence [12]
    bool operator==(const Iterator& aOtherIter) const
    {
        if (fTTree != aOtherIter.fTTree)
        {
            return false;
        }
        else
        {
            if (fStack.size() != aOtherIter.fStack.size())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    // Auxiliaries [4,10]
    Iterator begin() const
    {
        Iterator iteratorCopy = *this;

        if (!(iteratorCopy.fTTree->empty()))
        {
            iteratorCopy.fStack = TTreeStack();
            const TTree* root = iteratorCopy.fTTree;
            iteratorCopy.fStack.push(const_cast<TTreeNode>(root));
        }

        return iteratorCopy;
    }

    Iterator end() const
    {
        Iterator iteratorCopy = *this;

        if (!iteratorCopy.fStack.empty())
        {
            iteratorCopy.fStack = TTreeStack();
        }

        return iteratorCopy;
    }

};