#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class Node {
 public:
  T data;
  Node<T>* next;
};

template <class T>
class Iterator {
 public:
  // Check if the iterator reached the end of the list
  bool end();
  // Return the data at |node|
  T operator->();
  // Advance the iterator
  void operator++(int a);

  Node<T>* prev;
  Node<T>* node;
};

template <class T>
class LinkedList {
 public:
  // Get an iterator to the first node.
  Iterator<T> begin();

  Iterator<T> last();
  // Insert a new node before |it|.
  void insert(Iterator<T> it, T data);
  // Erase the node at |it|.
  void erase(Iterator<T> it);

  void push_back(Iterator<T> it, T data);

  Node<T>* head;
};

#endif  // LINKED_LIST