#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

template<typename T>
void run(int argc, char *argv[]) {

    ifstream file;
    file.open(argv[1]); // file with list
    setbuf(stdout, NULL);

    if (!file.is_open()) { // checks if file is open
        cout << "Error: cannot parse information from ";
        cout << argv[1] << endl;
        exit(0);
    } // if

    T nums;
    BinaryTree<T> tree;
    while (file >> nums) {
        tree.insert(nums);
    } // while

    file.close();

    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;

    T insert;
    T deleteItem;
    T retrieve;
    T sumTrees;

    while (true) {
        cout << "Enter a command: ";
        char command;
        cin >> command;
        cout << endl;

        if (command == 'i') { // insert
            cout << "Item to insert: ";
            cin >> insert;
            cout << endl;
            tree.insert(insert);
            cout << "In-Order: ";
            tree.inOrder();
            continue;
        } // if

        if (command == 'd') { // delete
            cout << "Item to delete: ";
            cin >> deleteItem;
            cout << endl;
            tree.deleteItem(deleteItem);
            cout << "In-Order: ";
            tree.inOrder();
            continue;
        } // if

        if (command == 'l') { // length
            cout << "Tree length: " << tree.getLength() << endl;
            continue;
        } // if

        if (command == 'n') { //in-order
            cout << "In-Order: ";
            tree.inOrder();
            continue;
        } // if

        if (command == 'p') { // pre-order
            cout << "Pre-order: ";
            tree.preOrder();
            continue;
        } // if

        if (command == 'r') { // retrieve
            cout << "Item to be retrieved: ";
            cin >> retrieve;
            cout << endl;
            bool b = true;
            tree.retrieve(retrieve, b);
            if (b == true) {
                cout << "Item found in tree." << endl;
            } else {
                cout << "Item not in tree." << endl;
            } // else
            continue;
        } // if

        if (command == 's') { // getNumSingleParents
            cout << "Number of Single Parents: " << tree.getNumSingleParent() << endl;
            continue;
        } // if

        if (command == 'f') { // getnumLeafNodes
            cout << "Number of leaf nodes: " << tree.getNumLeafNodes() << endl;
            continue;
        } // if

        if (command == 't') { // getSumOfSubtrees
            try {
                cout << "Item to get sum of subtrees: ";
                cin >> sumTrees;
                cout << "Sum of Subtrees: " << tree.getSumOfSubtrees(sumTrees) << endl;
            } catch (int num) {
                cout << "Item not found. " << endl;
            } // catch
            continue;
        } // if

        if (command == 'o') { // post-order
            cout << "Post-Order: ";
            tree.postOrder();
            continue;
        } // if

        if (command == 'q') { // quit
            cout << "Quiting program..." << endl;
            break;
        } // if

        else {
            cout << "Command not recognized. Try again" << endl;
            continue;
        } // else
    } // while
} // run



int main (int argc, char *argv[]) {

    cout << "Enter tree type (i - int, f - float, s - std::string): ";
    char type;
    cin >> type;
    cout << endl;

    if (type == 'i') {
        run<int>(argc, argv);
    } // if

    else if (type == 'f') {
        run<float>(argc, argv);
    } // if

    else if (type == 's') {
        run<string>(argc, argv);
    } // if

    else {
        cout << "Invalid command" << endl;
        exit(0);
    } // else

} // main

// specify types of data that we plan to support
//template typename run<int>;
//template typename run<float>;
//template typename run<string>;
