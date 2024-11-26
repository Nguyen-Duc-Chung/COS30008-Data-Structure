// BinarySearchTreeIterator.h

// COS30008, Problem Set 4, Problem 3, 2022
#pragma once
#include "BinarySearchTree.h"
#include <stack>
template<typename T>
class BinarySearchTreeIterator
{
private:
using BSTree = BinarySearchTree<T>;
using BNode = BinaryTreeNode<T>;
using BTreeNode = BNode*;
using BTNStack = std::stack<BTreeNode>;

const BSTree& fBSTree; // binary search tree
BTNStack fStack; // DFS traversal stack

void pushLeft( BTreeNode aNode ) {
    while (!aNode->empty())
    {
        fStack.push(aNode);
        aNode = aNode->left;
    }
}

public:

using Iterator = BinarySearchTreeIterator<T>;

BinarySearchTreeIterator(const BSTree& aBSTree) : fBSTree(aBSTree) {

    pushLeft(fBSTree.fRoot);
}

const T& operator*() const {

    return fStack.top()->key;
}

Iterator& operator++() {

    BTreeNode currentNode = fStack.top();
    fStack.pop();

    if (!currentNode->right->empty())
    {
        pushLeft(currentNode->right);
    }

    return *this;
}

Iterator operator++(int) {

    Iterator temp = *this;
    ++(*this);
    return temp;
}

void clearStack()
{
    fStack = BTNStack(); // Assign an empty stack to clear it
}

bool operator==( const Iterator& aOtherIter ) const {

    return fStack == aOtherIter.fStack;
}
bool operator!=( const Iterator& aOtherIter ) const {

    return !(*this == aOtherIter);
}
Iterator begin() const {

    return Iterator(fBSTree);
}
Iterator end() const {

    Iterator temp(fBSTree);
    temp.fStack = BTNStack(); // Assign an empty stack to indicate the end
    return temp;
}
};
