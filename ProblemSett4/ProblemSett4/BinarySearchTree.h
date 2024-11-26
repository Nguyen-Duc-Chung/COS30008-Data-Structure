// BinarySearchTree.h

// COS30008, Problem Set 4, Problem 2, 2022
#pragma once
#include "BinaryTreeNode.h"
#include <stdexcept>
// Problem 3 requirement
template<typename T>
class BinarySearchTreeIterator;
template<typename T>
class BinarySearchTree
{
private:
	using BNode = BinaryTreeNode<T>;
	using BTreeNode = BNode*;
	BTreeNode fRoot;
public:
	BinarySearchTree() : fRoot(&BNode::NIL) {}
	~BinarySearchTree() {
		if (!fRoot->empty())
		{
			delete fRoot;
		}
	}

	bool empty() const {
		return fRoot->empty();
	}

	size_t height() const {
		if (empty())
		{
			throw std::domain_error("Empty tree has no height.");
		}
		return fRoot->height();
	}

	bool insert(const T& aKey) {
		if (fRoot == &BNode::NIL)
		{
			fRoot = new BNode(aKey);
			return true;
		}
		return fRoot->insert(aKey);
	}

	bool remove(const T& aKey) {
		if (fRoot != &BNode::NIL)
		{
			if (fRoot->key == aKey)
			{
				// Handle removal of root
				if (fRoot->left->empty() && fRoot->right->empty())
				{
					delete fRoot;
					fRoot = &BNode::NIL;
				}
				else if (!fRoot->left->empty())
				{
					const T& lMax = fRoot->left->findMax();
					fRoot->key = lMax;
					fRoot->left->remove(lMax, fRoot);
				}
				else
				{
					const T& lMin = fRoot->right->findMin();
					fRoot->key = lMin;
					fRoot->right->remove(lMin, fRoot);
				}
				return true;
			}
			else
			{
				return fRoot->remove(aKey, nullptr);
			}
		}
		return false;
	}
	// Problem 3 methods
	using Iterator = BinarySearchTreeIterator<T>;

	// Allow iterator to access private member variables
	friend class BinarySearchTreeIterator<T>;
	Iterator begin() const {

		Iterator iter(*this);
		return iter;
	}
	Iterator end() const {

		Iterator iter(*this);
		iter.clearStack(); 
		return iter;
	}
};
