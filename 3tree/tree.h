#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <iostream>

using std::string;

template <typename T>
std::string my_to_string(const T& t) {
  return std::to_string(t);
}

template <>
std::string my_to_string(const std::string& t) {
  return "\"" + t + "\"";
}

template <typename T1, typename T2>
int compare(const T1 a, const T2 b) {
    if (b > a) {
      return 1;
    }
    if (b == a) {
      return 0;
    }
    return -1;
}

template <>
int compare<std::string, std::string> (std::string a, std::string b) {
  return b.compare(a);
}

template <typename T> struct Node {
  T element;
  int height;
  Node<T> *left;
  Node<T> *right;

  Node(T element)
      : element{element}, height{0}, left{nullptr}, right{nullptr} {}
  Node(T element, int height)
      : element{element}, height{height}, left{nullptr}, right{nullptr} {}
};

template <typename T> class Tree {
private:
  size_t m_size;
  Node<T> *m_root;

public:
  // Constructor
  Tree();

  // Rule of three:
  // If a class requires a user-defined destructor, a user-defined copy
  // constructor, or a user-defined copy assignment operator, it almost
  // certainly requires all three.

  // Destructor
  ~Tree();

  // Returns a pointer to the root
  Node<T> *root();

  // Checks whether the tree is empty
  bool empty() const;

  // Returns the number of elements
  size_t size() const;

  // Returns the height of the tree
  int height() const;

  // Inserts the specified element
  void insert(T element);

  // Checks whether the container contains the specified element
  bool contains(T element) const;

  // Returns the maximum element
  T max() const;

  // Returns the minimum element
  T min() const;

  // Returns the successor of the specified element
  T successor(T element);

  // Convert each element in the tree to string in pre-order.
  string pre_order();

  // Convert each element in the tree to string in order.
  string in_order();

  // Convert each element in the tree to string in post-order.
  string post_order();

  // Returns a string equivalent of the tree
  string to_string(bool with_height = true) const {
    return m_to_string(with_height, m_root, 0);
  }

private:
  string m_to_string(bool with_height, Node<T> *node, int ident) const {
    string res;
    if (node == nullptr) {
      return res;
    }
    if (node->right != nullptr) {
      res += m_to_string(with_height, node->right, ident + 2);
    }
    for (int i = 0; i < ident; i++) {
      res += " ";
    }
    res += my_to_string(node->element);
    if (with_height) {
      res += "(h=" + my_to_string(node->height) + ")";
    }
    res += "\n";
    if (node->left != nullptr) {
      res += m_to_string(with_height, node->left, ident + 2);
    }
    return res;
  }

  // Feel free to declare helper functions here, if necessary
  };

// Constructor
template <typename T> Tree<T>::Tree() : m_root(nullptr) {
  m_size = 0;
}

template <typename T>
void deleteNode(Node<T> *node) {
      if (node != nullptr) {
          deleteNode(node->left); // Delete left subtree
          deleteNode(node->right); // Delete right subtree
          delete node; // Delete current node
      }
  }

// Destructor
template <typename T> Tree<T>::~Tree() {
  deleteNode(m_root);
}

// Returns a pointer to the root
template <typename T> Node<T> *Tree<T>::root() {
  return m_root;
}

// Checks whether the tree is empty
template <typename T> bool Tree<T>::empty() const {
  return m_root == nullptr;
}

// Returns the number of elements
template <typename T> size_t Tree<T>::size() const {
  return m_size;
}

// Returns the height of the tree
template <typename T> int Tree<T>::height() const {
  return empty() ? -1 : m_root->height;
}

template <typename T>
int node_height(Node<T>* node) {
  return node == nullptr ? -1 : node->height;
}

template <typename T>
Node<T>* right_rotate(Node<T> *y)  
{  
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = std::max(node_height(y->left), node_height(y->right)) + 1;  
    x->height = std::max(node_height(x->left), node_height(x->right)) + 1;  
  
    // Return new root  
    return x;  
} 
template <typename T>
Node<T>* left_rotate(Node<T> *x)  
{  
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;  
  
    // Perform rotation  
    y->left = x;
    x->right = T2; 
  
    // Update heights  
    x->height = std::max(node_height(x->left), node_height(x->right)) + 1;
    y->height = std::max(node_height(y->left), node_height(y->right)) + 1;
  
    // Return new root  
    return y;  
} 

template <typename T>
Node<T>* _insert(Node<T>* node, T element) {
  if (node == nullptr){
    return new Node<T>(element);
  }
  if (compare(element, node->element) < 0){
    node->right = _insert(node->right, element);
  } else {
    node->left = _insert(node->left, element);
  }
  node->height = std::max(node_height(node->left), node_height(node->right)) + 1;
  
  int balance = node_height(node->left) - node_height(node->right);

  // Left Left Case
  if (balance > 1 && compare(element, node->left->element) > 0)
      return right_rotate(node);

  // Right Right Case
  if (balance < -1 && compare(element, node->right->element) < 0)
      return left_rotate(node);

  // Left Right Case
  if (balance > 1 && compare(element, node->left->element) < 0) {
      node->left = left_rotate(node->left);
      return right_rotate(node);
  }

  // Right Left Case
  if (balance < -1 && compare(element, node->right->element) > 0) {
      node->right = right_rotate(node->right);
      return left_rotate(node);
  }

  return node;
}
// Inserts an element
template <typename T> void Tree<T>::insert(T element) {
  m_size++;
  m_root = _insert(m_root, element);
}


// Checks whether the container contains the specified element
template <typename T> bool Tree<T>::contains(T element) const {
  Node<T>* current = m_root;

  while (current != nullptr){
    if (current->element == element){
      return true;
    }
    if (compare(element, current->element) < 0){
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return false;
}

// Returns the maximum element
template <typename T> T Tree<T>::max() const {
  Node<T>* current = m_root;
  if (current == nullptr){
    throw std::range_error("tree is empty");
  }
  while (current->right != nullptr){
    current = current->right;
  }
  return current->element;
}

// Returns the minimum element
template <typename T> T Tree<T>::min() const {
  Node<T>* current = m_root;
  if (current == nullptr){
    throw std::range_error("tree is empty");
  }
  while (current->left != nullptr){
    current = current->left;
  }
  return current->element;
}

// Returns the successor of the specified element
template <typename T> T Tree<T>::successor(T element) {
  Node<T>* current = m_root;
  Node<T>* first_left_parent = nullptr;
  while (current != nullptr){
    if (current->element == element){
      break;
    }
    if (compare(element, current->element) < 0){
      current = current->right;
    } else {
      first_left_parent = current;
      current = current->left;
    }
  }
  if (current != nullptr){
    if (current->right != nullptr){
      current = current->right;
      while(current->left != nullptr){
        current = current->left;
      }
      return current->element;
    }
  }
  
  if (first_left_parent == nullptr){
    throw std::out_of_range("max does not have successor");
  }
  return first_left_parent->element;
}

template <typename T>
string _pre_order(Node<T> *node) {
  return my_to_string(node->element)
    + (node->left == nullptr ? "" : " " + _pre_order(node->left))
    + (node->right == nullptr ? "" : " " + _pre_order(node->right));
}

template <typename T>
string Tree<T>::pre_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _pre_order(m_root);
}

template <typename T>
string _in_order(Node<T> *node) {
  return (node->left == nullptr ? "" : _in_order(node->left) + " ")
    + my_to_string(node->element)
    + (node->right == nullptr ? "" : " " + _in_order(node->right));
}

template <typename T>
string Tree<T>::in_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _in_order(m_root);
}

template <typename T>
string _post_order(Node<T> *node) {
  return (node->left == nullptr ? "" : _post_order(node->left) + " ")
    + (node->right == nullptr ? "" : _post_order(node->right) + " ")
    + my_to_string(node->element);
}

template <typename T>
string Tree<T>::post_order() {
  if (m_root == nullptr) {
    return "";
  }
  return _post_order(m_root);
}

#endif
