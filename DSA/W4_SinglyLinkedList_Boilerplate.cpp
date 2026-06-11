#include <iostream>
#include <stdexcept>
using namespace std;

typedef int ElementType;

struct node {
    ElementType element;
    node* next;
};

typedef node* Position;

// Position p points to the node BEFORE the element being processed.
class List {
private:
    node* head;
    node* tail;
    int counter;

public:
    List() {
        head = new node;
        head->next = NULL;
        tail = head;
        counter = 0;
    }

    Position first() { return head; }
    Position end() { return tail; }
    int size() { return counter; }

    // Task 1: return the next position
    Position next(Position pos) {
        throw logic_error("Task 1 not implemented");
    }

    // Task 2: find and return the position before pos
    Position previous(Position pos) {
        throw logic_error("Task 2 not implemented");
    }

    // Task 3: insert x after position p; append when p is NULL
    void insert(ElementType x, Position p = NULL) {
        throw logic_error("Task 3 not implemented");
    }

    // Task 4: delete the node after position p
    void delete_at(Position p) {
        throw logic_error("Task 4 not implemented");
    }

    // Task 5: return the position before the first x, or end when absent
    Position locate(ElementType x) {
        throw logic_error("Task 5 not implemented");
    }

    // Task 6: locate x between two positions
    Position locate_in_range(ElementType x, Position pos, Position end_pos) {
        throw logic_error("Task 6 not implemented");
    }

    // Task 7: return the element stored after pos
    ElementType retrieve(Position pos) {
        throw logic_error("Task 7 not implemented");
    }

    // Task 8: print all real nodes
    void print_list() {
        throw logic_error("Task 8 not implemented");
    }
};

// Utility-function exercises

// Task 9: return a new reversed list
List reverse(List source) {
    throw logic_error("Task 9 not implemented");
}

// Task 10: reverse by repeatedly inserting at the front
List reverse_modified(List source) {
    throw logic_error("Task 10 not implemented");
}

// Task 11: insert x immediately after the first y
void insert_x_after_y(ElementType x, ElementType y, List& list) {
    throw logic_error("Task 11 not implemented");
}

// Task 12: remove duplicate values
void purge(List& list) {
    throw logic_error("Task 12 not implemented");
}

// Task 13: remove all occurrences of x
void remove_occurrences(List& list, ElementType x) {
    throw logic_error("Task 13 not implemented");
}

// Task 14: split values into odd and even lists
void split(List source, List& odd, List& even) {
    throw logic_error("Task 14 not implemented");
}

// Task 15: concatenate two lists
List concatenate(List first, List second) {
    throw logic_error("Task 15 not implemented");
}

// Task 16: return the sum of all values
ElementType sum(List list) {
    throw logic_error("Task 16 not implemented");
}

// Task 17: return the maximum value
ElementType max_value(List list) {
    throw logic_error("Task 17 not implemented");
}

// Task 18: return a sorted copy of the list
List sort_list(List list) {
    throw logic_error("Task 18 not implemented");
}

int main() {
    // List list;

    // list.insert(10);
    // list.insert(20);
    // list.insert(10);
    // list.insert(30);
    // list.print_list();

    // Position before20 = list.locate(20);
    // cout << "Found: " << list.retrieve(before20) << endl;

    // purge(list);
    // list.print_list();

    // list.delete_at(list.first());
    // list.print_list();

    return 0;
}
