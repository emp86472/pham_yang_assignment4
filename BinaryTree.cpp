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
    root->deleteChildren();
    root = NULL;
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
        length++;
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
                cout << "Item already in tree." << endl;
                break;
            } else if (temp->data < key) {
                pretemp = temp;
                temp = temp->right;
                placeRight = true;
            } else if (temp->data > key) {
                pretemp = temp;
                temp = temp->left;
                placeRight = false;
            } //if
        } //while
    } //if
} //insert

/**
 * Note: pretemp == NULL checks for first iteration
 * The deleteRight bool allows us to decide which way
 * pretemp should point to
 */
template<class T>
void BinaryTree<T>::deleteItem(T &key) {
    NodeType<T> *temp = root;
    NodeType<T> *pretemp;
    if (root == NULL) {
        cout  << "Item not in tree." << endl;
    } //if
    bool deleteRight = false;
    while (temp != NULL) {
        if (temp->data == key) {
            //node we want to remove
            if (temp->left == NULL && temp->right == NULL) {//leaf node
                if (pretemp == NULL) {
                    root = NULL;
                } else if (deleteRight) {
                    pretemp->right = NULL;
                } else {
                    pretemp->left = NULL;
                } //if
                delete temp;
                length--;
            } else if (temp->left == NULL) {//1 child
                if (pretemp == NULL) {
                    root = temp->right;
                } else {
                    if (deleteRight) {
                        pretemp->right = temp->right;
                    } else {
                        pretemp->left = temp->right;
                    } //if
                } //if
                delete temp;
                length--;
            } else if (temp->right == NULL) {//1 child
                if (pretemp == NULL) {
                    root = temp->left;
                } else {
                    if (deleteRight) {
                        pretemp->right = temp->left;
                    } else {
                        pretemp->left = temp->left;
                    } //if
                } //if
                delete temp;
                length--;
            } else { //if neither is null (2 children)
                //find logical predecessor
                pretemp = temp;
                temp = temp->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                } //while
                //recursive call to deleteItem
                T value = temp->data;
                this->deleteItem(value);
                pretemp->data = value;
            } //if
            return;
        } else if (temp->data < key) {
            pretemp = temp;
            temp = temp->right;
            deleteRight = true;
        } else if (temp->data > key) {
            pretemp = temp;
            temp = temp->left;
            deleteRight = false;
        } //if
    } //while
    cout << "Item not in tree." << endl;
} //deleteItem

template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {
    NodeType<T> *temp = root;
    while (temp != NULL) {
        if (temp->data == item) {
            found = true;
            return;
        } else if (temp->data < item) {
            temp = temp->right;
        } else if (temp->data > item) {
            temp = temp->left;
        } //if
    } //while
    found = false;
} //retrieve

template<class T>
void BinaryTree<T>::preOrder() const {
    root->preOrder();
    cout << endl;
} //preOrder

template<class T>
void BinaryTree<T>::inOrder() const {
    root->inOrder();
    cout << endl;
} //inOrder

template<class T>
void BinaryTree<T>::postOrder() const {
    root->postOrder();
    cout << endl;
} //postOrder

template<class T>
int BinaryTree<T>::getLength() const {
    return length;
} //getLength

template<class T>
int BinaryTree<T>::getNumSingleParent() const {
    return root->getNumSingleParent();
} //getNumSingleParent

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {
    return root->getNumLeafNodes();
} //getNumLeafNodes

template<class T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T> node) const {
    if (node.left == NULL && node.right == NULL) {
        throw 1;
    } else if (node.left == NULL) {
        return node.right->data;
    } else if (node.right == NULL) {
        return node.left->data;
    } //if
    return node.left->data + node.right->data;
} //getSumOfSubtrees

template<class T>
T BinaryTree<T>::getSumOfSubtrees(T value) const {
    NodeType<T> *temp = root;
    while (temp != NULL) {
        if (temp->data == value) {
            return getSumOfSubtrees(*temp);
        } else if (temp->data < value) {
            temp = temp->right;
        } else if (temp->data > value) {
            temp = temp->left;
        } //if
    } //while
    throw 0;
} //getSumOfSubtrees

template<class T>
void NodeType<T>::inOrder() const {
    if (left != NULL) {
        left->inOrder();
    } //if
    cout << data;
    cout << " ";
    if (right != NULL) {
        right->inOrder();
    } //if
} //inOrder

template<class T>
void NodeType<T>::preOrder() const {
    cout << data;
    cout << " ";
    if (left != NULL) {
        left->preOrder();
    } //if
    if (right != NULL) {
        right->preOrder();
    } //if
} //preOrder

template<class T>
void NodeType<T>::postOrder() const {
    if (left != NULL) {
        left->postOrder();
    } //if
    if (right != NULL) {
        right->postOrder();
    } //if
    cout << data;
    cout << " ";
} //postOrder

template<class T>
int NodeType<T>::getNumSingleParent() const {
    int b = 0;
    int i = 0;
    if (left != NULL) {
        i += left->getNumSingleParent();
        b++;
    } //if
    if (right != NULL) {
        i += right->getNumSingleParent();
        b++;
    } //if
    if (b == 1) {
        i++;
    } //if
    return i;
} //getNumSingleParent

template<class T>
int NodeType<T>::getNumLeafNodes() const {
    int b = 0;
    int i = 0;
    if (left != NULL) {
        i += left->getNumLeafNodes();
        b++;
    } //if
    if (right != NULL) {
        i += right->getNumLeafNodes();
        b++;
    } //if
    if (b == 0) {
        i++;
    } //if
    return i;
} //getNumLeafNodes

template<class T>
void NodeType<T>::deleteChildren() const {
    if (left != NULL) {
        left->deleteChildren();
    } //if
    if (right != NULL) {
        right->deleteChildren();
    } //if
    delete this;
} //deleteChildren

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
template class NodeType<int>;
template class NodeType<float>;
template class NodeType<string>;
