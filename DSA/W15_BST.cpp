#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int element;
    node * left;
    node * right;
};

class BinarySearchTree {
private:
    node * root;
    int counter;

public:
    BinarySearchTree() {
        root = NULL;
        counter = 0;
    }

    // Task 1: insert a value into the correct position
    // void insert(int el) { ... }

    // Task 2: return true if a value exists in the tree
    // bool search(int el) { ... }

    // Task 3: print values in ascending order using inorder traversal
    // void inorder() { ... }

    // Task 4: return the number of stored nodes
    // int size() { ... }

    // Task 5: return true when the tree is empty
    // bool isEmpty() { ... }
};

int main() {
    // BinarySearchTree tree;

    // tree.insert(8);
    // tree.insert(3);
    // tree.insert(10);
    // tree.insert(1);
    // tree.insert(6);
    // tree.insert(14);
    // tree.insert(4);
    // tree.insert(7);
    // tree.insert(13);

    // cout << "Inorder traversal:" << endl;
    // tree.inorder();

    // cout << "Size: " << tree.size() << endl;

    // if (tree.search(7))
    // {
    //     cout << "7 found" << endl;
    // }
    // else {
    //     cout << "7 not found" << endl;
    // }

    // if (tree.search(2))
    // {
    //     cout << "2 found" << endl;
    // }
    // else {
    //     cout << "2 not found" << endl;
    // }

    return 0;
}