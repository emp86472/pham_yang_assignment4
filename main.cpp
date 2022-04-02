#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    BinaryTree<int> bt;

    int num[10] = {25, 50, 35, 15, 22, 10, 12, 4, 18, 24};

    for (int i = 0; i < 10; i++) {
        bt.insert(num[i]);
    } //for
    //bt.preOrder();
    cout << "original list: ";
    bt.inOrder();
    cout << endl;
    //bt.postOrder();
    int x = 25;
    cout << "remove root: ";
    bt.deleteItem(x);
    bt.inOrder();
    cout << endl;
    /**
    x = 10;
    cout << "remove same: ";
    bt.deleteItem(x);
    bt.inOrder();
    cout << endl;

    x = 22;
    cout << "remove same: ";
    bt.deleteItem(x);
    bt.inOrder();
    cout << endl;
    */
    return 0;
} //main
