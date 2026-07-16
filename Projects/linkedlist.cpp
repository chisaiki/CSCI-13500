// linkedlist.cpp
//
// where all the codes belongs

#include "linkedlist.hpp"

#include <iostream>
#include <stdexcept>

// Starts empty no nodes yet, so size is 0 and head points nowhere.
LinkedList::LinkedList() : size_(0), head_(nullptr) {}

// Walks through the whole list and deletes every node so nothing if left in memory once program is done
LinkedList::~LinkedList() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  size_ = 0;
}

// @param: the value we want to add.
// @return: nothing.
void LinkedList::InsertNode(const int value) {
  Node* new_node = new Node(value);

  if (head_ == nullptr) {
    // The list is empty, so this new node just becomes the head.
    head_ = new_node;
  } else {
    // Walk all the way to the last node, then hook the new one on.
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  ++size_;
}

// @param: the value we want to add.
// @return: nothing.
void LinkedList::InsertNodeFront(const int value) {
  Node* new_node = new Node(value);
  new_node->next = head_;
  head_ = new_node;
  ++size_;
}

// @param: the value we're looking for.
// @return: true if it's in the list, false if not.
bool LinkedList::Contains(const int value) const {
  Node* current = head_;
  while (current != nullptr) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

// @param: the 1-based position we want to remove.
// @return: true if it got removed, false if the position was bad.
bool LinkedList::Remove(const int position) {
  // Make sure the position actually exists in the list.
  if (position < 1 || position > size_) {
    return false;
  }

  Node* to_delete = nullptr;

  if (position == 1) {
    to_delete = head_;
    head_ = head_->next;
  } else {
    // Get to the node right before the one we're removing.
    Node* prev = head_;
    for (int i = 1; i < position - 1; ++i) {
      prev = prev->next;
    }
    to_delete = prev->next;
    prev->next = to_delete->next;
  }

  delete to_delete;
  --size_;
  return true;
}

// Prints all the values like: 10 -> 20 -> 30 -> nullptr
void LinkedList::PrintValues() const {
  Node* current = head_;
  while (current != nullptr) {
    std::cout << current->value << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

// Prints each node's position and where it lives in memory.
void LinkedList::PrintAddresses() const {
  Node* current = head_;
  int position = 1;
  while (current != nullptr) {
    std::cout << position << " " << current << std::endl;
    ++position;
    current = current->next;
  }
}

// @param: the 1-based position we want the value from.
// @return: the value stored there.
// @throws: std::out_of_range if the position doesn't exist.
int LinkedList::GetValueAtPosition(const int position) const {
  if (position < 1 || position > size_) {
    throw std::out_of_range("GetValueAtPosition: position out of range");
  }

  Node* current = head_;
  for (int i = 1; i < position; ++i) {
    current = current->next;
  }
  return current->value;
}

// @return: a pointer to a brand new list holding the reversed nodes.
LinkedList* LinkedList::ReverseList() {
  // Flip each node's next pointer so it points backward instead of
  // forward. Nothing new gets created here, I'm just re-using the
  // same nodes that already exist.
  Node* prev = nullptr;
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    current->next = prev;
    prev = current;
    current = next_node;
  }

  // Give the flipped chain to a brand new list.
  LinkedList* reversed_list = new LinkedList();
  reversed_list->head_ = prev;
  reversed_list->size_ = size_;

  // The original list doesn't own any nodes anymore.
  head_ = nullptr;
  size_ = 0;

  return reversed_list;
}

// @param: the value to insert, and the 1-based position to put it at.
// @return: nothing.
// @throws: std::out_of_range if the position doesn't make sense.
void LinkedList::InsertNodeAt(const int value, const int position) {
  // position one past the end means the value is appended to the list.
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("InsertNodeAt: position out of range");
  }

  if (position == 1) {
    InsertNodeFront(value);
    return;
  }

  // Get to the node before insertingss.
  Node* prev = head_;
  for (int i = 1; i < position - 1; ++i) {
    prev = prev->next;
  }

  Node* new_node = new Node(value);
  new_node->next = prev->next;
  prev->next = new_node;
  ++size_;
}

int LinkedList::GetSize() const {
  return size_;
}

// @param: another list to merge with this one.
// @return: a brand new list that alternates values from both lists.
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
  LinkedList* merged = new LinkedList();

  Node* current_first = head_;
  Node* current_second = second_list.head_;
  Node* tail = nullptr;  // Keeps track of the last node I added to merged.

  // makes a new node with this value and sticks it
  // onto the end of merged's chain. Because I keep a tail pointer, this
  // is instant every time instead of having to walk the list to find
  // the end, which is what keeps MergeIntertwine at O(n + m).
  auto AppendValue = [&](int value) {
    Node* new_node = new Node(value);
    if (merged->head_ == nullptr) {
      merged->head_ = new_node;
    } else {
      tail->next = new_node;
    }
    tail = new_node;
    ++merged->size_;
  };

  while (current_first != nullptr || current_second != nullptr) {
    if (current_first != nullptr) {
      AppendValue(current_first->value);
      current_first = current_first->next;
    }
    if (current_second != nullptr) {
      AppendValue(current_second->value);
      current_second = current_second->next;
    }
  }

  return merged;
}
