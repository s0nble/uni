#include <iostream>
#include <stdexcept>
using namespace std;

typedef int ElementType;
typedef int Position;

class List {
private:
    ElementType* elements;
    int capacity;
    Position last;

public:
    List(int n) {
        elements = new ElementType[n];
        capacity = n;
        last = -1;
    }

    // Task 1: empty the list without changing its capacity
    void make_null() {
        throw logic_error("Task 1 not implemented");
    }

    // Task 2: return the position immediately after the final element
    Position end() {
        throw logic_error("Task 2 not implemented");
    }

    // Task 3: insert x at pos and shift later values to the right
    void insert(ElementType x, Position pos) {
        throw logic_error("Task 3 not implemented");
    }

    // Task 4: delete the value at pos and shift later values to the left
    void delete_at(Position pos) {
        throw logic_error("Task 4 not implemented");
    }

    // Task 5: return the position of x, or -1 when it is absent
    Position locate(ElementType x) {
        throw logic_error("Task 5 not implemented");
    }

    // Task 6: return the position of x inside [pos, end_pos], or -1
    Position locate_in_range(ElementType x, Position pos, Position end_pos) {
        throw logic_error("Task 6 not implemented");
    }

    // Task 7: return the value stored at pos
    ElementType retrieve(Position pos) {
        throw logic_error("Task 7 not implemented");
    }

    // Task 8: print all values from first to end
    void print_list() {
        throw logic_error("Task 8 not implemented");
    }

    Position first() { return 0; }
    Position next(Position pos) { return pos + 1; }
    Position previous(Position pos) { return pos - 1; }
    int size() { return last + 1; }
};

// Utility-function exercises

// Task 9: return a new list containing the values in reverse order
List reverse(List source) {
    throw logic_error("Task 9 not implemented");
}

// Task 10: reverse by repeatedly inserting at the front
List reverse_modified(List source) {
    throw logic_error("Task 10 not implemented");
}

// Task 11: insert x immediately after the first occurrence of y
void insert_x_after_y(ElementType x, ElementType y, List& list) {
    throw logic_error("Task 11 not implemented");
}

// Task 12: remove duplicate values while keeping the first occurrence
void purge(List& list) {
    throw logic_error("Task 12 not implemented");
}

// Task 13: remove every occurrence of x
void remove_occurrences(List& list, ElementType x) {
    throw logic_error("Task 13 not implemented");
}

// Task 14: place odd and even values into separate lists
void split(List source, List& odd, List& even) {
    throw logic_error("Task 14 not implemented");
}

// Task 15: return a list containing first followed by second
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

int main() {
    // List list(10);

    // list.insert(8, list.end());
    // list.insert(3, list.end());
    // list.insert(8, list.end());
    // list.insert(6, list.end());
    // list.print_list();

    // cout << "Position of 3: " << list.locate(3) << endl;
    // cout << "Value at position 1: " << list.retrieve(1) << endl;

    // purge(list);
    // list.print_list();

    // List odd(10), even(10);
    // split(list, odd, even);
    // odd.print_list();
    // even.print_list();

    return 0;
}
