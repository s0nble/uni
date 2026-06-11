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
    void insert(int el) {
        node * newNode = new node;
        newNode->element = el;
        newNode->left = NULL;
        newNode->right = NULL;
        
        if(isEmpty()){
            root = newNode;
            counter++;
            return;
        }
        node* current = root;
        node* parent = NULL;
        
        while(current != NULL){
            parent = current;

            if(el == current->element){
                delete newNode;
                return;
            }
            else if(el < current->element){
                current = current->left;
            }
            else{
                current = current->right;
            }
    }
    if(el < parent->element)
        parent->left = newNode;
    else
        parent->right = newNode;

    counter++;
    }

    // Task 2: return true if a value exists in the tree
    bool search(int el) {
        node* current = root;

        while (current != NULL) {
            if (el == current->element)
                return true;
            else if (el < current->element)
                current = current->left;
            else
                current = current->right;
        }

        return false;
    }

    // Task 3: print values in ascending order using inorder traversal
    void inorder() {
        stack<node*> nodes;
        node* current = root;

        while (current != NULL || !nodes.empty()) {
            while (current != NULL) {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();
            cout << current->element << " ";
            current = current->right;
        }

        cout << endl;
    }

    // Task 4: return the number of stored nodes
    int size() {
        return counter;
    }

    // Task 5: return true when the tree is empty
    bool isEmpty() {
        return counter == 0;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);

    cout << "Inorder traversal:" << endl;
    tree.inorder();

    cout << "Size: " << tree.size() << endl;

    if (tree.search(7))
    {
        cout << "7 found" << endl;
    }
    else {
        cout << "7 not found" << endl;
    }

    if (tree.search(2))
    {
        cout << "2 found" << endl;
    }
    else {
        cout << "2 not found" << endl;
    }

    return 0;
}
