#include "BinaryTree.h"
#include <string>

using namespace std; //use NULL, cout, cin

template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
} //constructor

template<class T>
BinaryTree<T>::~BinaryTree() {

} //destructor

template<class T>
void BinaryTree<T>::insert(T &key) {

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

} //inOrder

template<class T>
void BinaryTree<T>::postOrder() const {

} //postOrder

template<class T>
int BinaryTree<T>::getLength() const {
    return 0;
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

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
