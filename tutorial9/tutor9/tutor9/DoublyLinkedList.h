#pragma once
#include <utility>  // For std::move

template<typename T>
class DoublyLinkedList
{
private:
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;

public:
    // l-value constructor
    explicit DoublyLinkedList(const T& aPayload)
        : fPayload(aPayload), fNext(this), fPrevious(this) {}

    // r-value constructor
    explicit DoublyLinkedList(T&& aPayload)
        : fPayload(std::move(aPayload)), fNext(this), fPrevious(this) {}

    // aNode becomes previous of this
    DoublyLinkedList& push_front(DoublyLinkedList& aNode) {
        aNode.fNext = this;
        aNode.fPrevious = fPrevious;
        fPrevious->fNext = &aNode;
        fPrevious = &aNode;
        return *this;
    }

    // aNode becomes next of this
    DoublyLinkedList& push_back(DoublyLinkedList& aNode) {
        aNode.fPrevious = this;
        aNode.fNext = fNext;
        fNext->fPrevious = &aNode;
        fNext = &aNode;
        return *this;
    }

    // Removes this node by connecting its neighbors to each other
    void isolate() {
        fPrevious->fNext = fNext;
        fNext->fPrevious = fPrevious;
        fNext = this;
        fPrevious = this;
    }

    // Exchange payloads of this node and aNode
    void swap(DoublyLinkedList& aNode) {
        std::swap(fPayload, aNode.fPayload);
    }

    // Dereference operator, returns payload
    const T& operator*() const {
        return fPayload;
    }

    // Returns constant reference to payload
    const T& getPayload() const {
        return fPayload;
    }

    // Returns constant reference to next node
    const DoublyLinkedList& getNext() const {
        return *fNext;
    }

    // Returns constant reference to previous node
    const DoublyLinkedList& getPrevious() const {
        return *fPrevious;
    }
};
