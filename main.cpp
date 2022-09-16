#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include "linked_list.h"

// Step 1. create a Grocery class that holds an isle and a name
class Grocery {
 public:
  int isleNumber;
  std::string groceryName;
};

template <class T>
void LinkedList<T>::insert(Iterator<T> it, T data) {
    Node<T>* temp = new Node<T>;
    temp->data = data;
    if (this->head->next == NULL) {
        this->head->next = temp;
    }
    else {
        it.prev->next = temp;
        temp->next = it.node;
        it.node = temp;
    }
}

template <class T>
void LinkedList<T>::push_back(Iterator<T> it, T data) {
    Node<T>* temp = new Node<T>;
    temp->data = data;
    it.node->next = temp;
}

template <class T>
Iterator<T> LinkedList<T>::begin() {
    Iterator<T> obj;
    obj.prev = this->head;
    obj.node = this->head->next;
    return obj;
}

template <class T>
Iterator<T> LinkedList<T>::last() {
    Iterator<T> obj;
    obj = this->begin();
    while (!obj.end()) {
        obj.operator++(1);
    }
    return obj;
}

template <class T>
bool Iterator<T>::end() {
    return (this->node->next == NULL);
}

template <class T>
void Iterator<T>::operator++(int a) {
    for (int i = 0; i < a; i++) {
        this->prev = this->node;
        this->node = this->node->next;
    }
}

template <class T>
T Iterator<T>::operator->() {
    return this->node->data;
}

template <class T>
void LinkedList<T>::erase(Iterator<T> it) {
    Node<T>* newNext = it.node->next;
    it.prev->next = newNext;
    it.node = newNext;
}

void printList(LinkedList<Grocery> groceryList) {
  for (auto it = groceryList.begin(); !it.end(); it.operator++(1)) {
    std::cout << it.operator->().groceryName << std::endl;
  }
  std::cout << groceryList.last().operator->().groceryName << std::endl;
}

int main() {
  // Step 2. Construct a LinkedList<Grocery>
  LinkedList<Grocery> groceryList;
  groceryList.head = new Node<Grocery>;

  // Step 3: Read N groceries and insert them one-at-a-time
  // into the list, making sure you insert them in sorted order.
  // I recommend using iterators and `insert()`.
  int groceries;
  std::cin >> groceries;
  for (int i = 0; i < groceries; i++) {
    Grocery grocery;
    std::cin >> grocery.isleNumber >> grocery.groceryName;
    if (groceryList.head->next == NULL) {
      groceryList.insert(groceryList.begin(), grocery);
    } else if (groceryList.begin().end()) {
      groceryList.push_back(groceryList.begin(), grocery);
    } else {
      bool inserted = false;
      for (auto it = groceryList.begin(); !it.end(); it.operator++(1)) {
        if (it.operator->().isleNumber >= grocery.isleNumber) {
          // insert before it
          groceryList.insert(it, grocery);
          inserted = true;
          break;
        }
      }
      if (!inserted) {
        auto it = groceryList.last();
        if (it.operator->().isleNumber >= grocery.isleNumber) {
          // insert before it
          groceryList.insert(it, grocery);

          inserted = true;
        } else {
          groceryList.push_back(it, grocery);
        }
      }
    }
  }

  // Step 4: Read M groceries and remove them one-at-a-time
  // from the list. I recommend using iterators, and `erase()`.
  int kitchenNum;
  std::cin >> kitchenNum;
  for (int i = 0; i < kitchenNum; i++) {
    std::string kitchenGroceries;
    std::cin >> kitchenGroceries;
    for (auto it = groceryList.begin(); !it.end(); it.operator++(1)) {
      if (kitchenGroceries == it.operator->().groceryName) {
        groceryList.erase(it);
        break;
      }
    }
    auto lastGrocery = groceryList.last();
    if (lastGrocery.operator->().groceryName == kitchenGroceries) {
      groceryList.erase(lastGrocery);
    }
  }

  // Step 5: Print out all groceries in the list.
  printList(groceryList);
  return 0;
}