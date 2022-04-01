#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct NodeType {

public:
    T data;
    NodeType<T> *left;
    NodeType<T> *right;
};

template<class T>
class BinaryTree {

private:
    NodeType<T> *root;

public:
    BinaryTree();
    ~BinaryTree();
    void insert(T &key);
    void deleteItem(T &key);
    void retrieve(T &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength() const;
    //the weird functions
    int getNumSingleParent() const; //num of nodes that have 1 child
    int getNumLeafNodes() const; //num of leaf nodes
    int getSumOfSubtrees(NodeType<T> node) const;
    int getSumOfSubtrees(T value) const;
};

#endif
