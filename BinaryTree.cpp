#include "BinaryTree.h"
#include <string>
#include <iostream>

using namespace std; //use NULL, cout, cin

template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
    length = 0;
} //constructor

template<class T>
BinaryTree<T>::~BinaryTree() {

} //destructor

template<class T>
void BinaryTree<T>::insert(T &key) {
    //create node to insert
    NodeType<T> *node = new NodeType<T>;
    node->data = key;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL) {
        root = node;
    } else {
        NodeType<T> *temp = root;
        NodeType<T> *pretemp;
        bool placeRight;
        while (true) {
            if (temp == NULL) {
                if (placeRight) {
                    pretemp->right = node;
                } else {
                    pretemp->left = node;
                } //if
                length++;
                break;
            } //if
            if (temp->data == key) {
                cout << "Duplicate item!" << endl;
                break;
            } else if (temp->data < key) {
                pretemp = temp;
                temp = temp->left;
                placeRight = false;
            } else if (temp->data > key) {
                pretemp = temp;
                temp = temp->right;
                placeRight = true;
            } //if
        } //while
    } //if
} //insert

template<class T>
void BinaryTree<T>::deleteItem(T &key) {

} //deleteItem

template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {

} //retrieve

template<class T>
void BinaryTree<T>::preOrder() const {

} //preOrder

template<class T>
void BinaryTree<T>::inOrder() const {
    root->inOrder();
} //inOrder

template<class T>
void BinaryTree<T>::postOrder() const {

} //postOrder

template<class T>
int BinaryTree<T>::getLength() const {
    return length;
} //getLength

template<class T>
int BinaryTree<T>::getNumSingleParent() const {
    return 0;
} //getNumSingleParent

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {
    return 0;
} //getNumLeafNodes

template<class T>
int BinaryTree<T>::getSumOfSubtrees(NodeType<T> node) const {
    return 0;
} //getSumOfSubtrees

template<class T>
int BinaryTree<T>::getSumOfSubtrees(T value) const {
    return 0;
} //getSumOfSubtrees

template<class T>
void NodeType<T>::inOrder() const {
    if (right != NULL) {
        right->inOrder();
    } //if
    cout << data << endl;
    if (left != NULL) {
        left->inOrder();
    } //if

} //inOrder

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
template class NodeType<int>;
template class NodeType<float>;
template class NodeType<string>;
