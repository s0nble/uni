#include <iostream>
using namespace std;

typedef int ElmenetType;

struct node {
    ElmenetType element;
    node* next;
};

typedef node* Position;

// Position p always points to the node BEFORE the current node to be processed.
class List {
private:
    node* head;    // points to the dummy node
    node* tail;    // points to the last real node
    int counter;

public:
    List() { make_null(); }

    void make_null() {
        head = new node;
        head->next = NULL;
        tail = head;
        counter = 0;
    }

    // returns a pointer to the last node (END sentinel)
    Position end() { return tail; }

    // returns the dummy head node
    Position first() { return head; }

    // ─── TODO: implement these ──────────────────────────

    //Task 1: insert x after position p
     void insert(ElmenetType x, Position p) { 
        if (p== NULL) p = end();
        node* new_node = new node; 
        new_node->element = x;
        new_node->next = p->next;
        p->next = new_node;
        
        if (new_node->next == NULL) tail = new_node;
        
        counter++;
     }

    // Task 2: return the element stored in the node AFTER p
    // ElmenetType retrieve(Position pos) { ... }

    // Task 3: print all elements
    // void print_list() { ... }

    // Task 4: return the position after pos
    // Position next(Position pos) { ... }

    // Task 5: find the position of x in the list
    // Position locate(ElmenetType x) { ... }

    // Task 6: insert x after the first occurrence of y
    // void insert_x_after_y(ElmenetType x, ElmenetType y) { ... }

    int size() { return counter; }
};

// Task 7: (free function) concatenate two lists into a new list
// List concatinate(List l1, List l2) { ... }

int main() {
    List l;

    // After you implement the functions, uncomment to test:

    // l.insert(10, l.end());
    // l.insert(20, l.end());
    // l.insert(30, l.end());
    // l.insert(5, l.first());
    // l.print_list();
    // cout << "Size: " << l.size() << endl;
    // cout << "First element: " << l.retrieve(l.first()) << endl;
    // cout << "Next after first: " << l.retrieve(l.next(l.first())) << endl;

    // Position pos = l.locate(20);
    // cout << "Located 20, element after it: " << l.retrieve(l.next(pos)) << endl;

    // l.insert_x_after_y(25, 20);
    // l.print_list();

    // List l2;
    // l2.insert(100, l2.end());
    // l2.insert(200, l2.end());
    // List l3 = concatinate(l, l2);
    // l3.print_list();

    return 0;
}