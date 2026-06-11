#include <iostream>
#include <stdexcept>
using namespace std;

typedef int ElementType;

// Part A: array-based stack
class ArrayStack {
private:
    ElementType* elements;
    int capacity;
    int counter;

public:
    ArrayStack(int max_size) {
        elements = new ElementType[max_size];
        capacity = max_size;
        counter = 0;
    }

    bool isEmpty() { return counter == 0; }
    bool isFull() { return counter == capacity; }
    int size() { return counter; }

    // Task 1: push an element onto the top
    void push(ElementType value) {
        throw logic_error("Task 1 not implemented");
    }

    // Task 2: remove and return the top element
    ElementType pop() {
        throw logic_error("Task 2 not implemented");
    }

    // Task 3: return the top element without removing it
    ElementType peek() {
        throw logic_error("Task 3 not implemented");
    }
};

// Task 4: return a reversed copy of an array stack
ArrayStack reverse(ArrayStack source, int capacity) {
    throw logic_error("Task 4 not implemented");
}

// Task 5: print from top to bottom without changing the caller's stack
void printStack(ArrayStack stack) {
    throw logic_error("Task 5 not implemented");
}

// Task 6: merge two stacks in the requested order
ArrayStack merge(ArrayStack& first, int first_size,
                 ArrayStack& second, int second_size) {
    throw logic_error("Task 6 not implemented");
}

// Task 7: return an independent copy with the same pop order
ArrayStack copyStack(ArrayStack source, int capacity) {
    throw logic_error("Task 7 not implemented");
}

// Part B: linked-list stack
struct node {
    ElementType element;
    node* next;
};

class LinkedStack {
private:
    node* top;
    int counter;

public:
    LinkedStack() {
        top = NULL;
        counter = 0;
    }

    bool isEmpty() { return top == NULL; }
    int size() { return counter; }

    // Task 8: push an element onto the top
    void push(ElementType value) {
        throw logic_error("Task 8 not implemented");
    }

    // Task 9: remove and return the top element
    ElementType pop() {
        throw logic_error("Task 9 not implemented");
    }

    // Task 10: return the top element without removing it
    ElementType peek() {
        throw logic_error("Task 10 not implemented");
    }
};

// Task 11: reverse a linked stack
LinkedStack reverse(LinkedStack& source) {
    throw logic_error("Task 11 not implemented");
}

// Task 12: print from top to bottom without changing the caller's stack
void printStack(LinkedStack stack) {
    throw logic_error("Task 12 not implemented");
}

// Task 13: merge two linked stacks in the requested order
LinkedStack merge(LinkedStack& first, LinkedStack& second) {
    throw logic_error("Task 13 not implemented");
}

// Task 14: return an independent copy with the same pop order
LinkedStack copyStack(LinkedStack source) {
    throw logic_error("Task 14 not implemented");
}

int main() {
    // ArrayStack array_stack(5);
    // array_stack.push(10);
    // array_stack.push(20);
    // array_stack.push(30);
    // cout << "Top: " << array_stack.peek() << endl;
    // cout << "Popped: " << array_stack.pop() << endl;
    // printStack(array_stack);

    // LinkedStack linked_stack;
    // linked_stack.push(5);
    // linked_stack.push(15);
    // linked_stack.push(25);
    // cout << "Top: " << linked_stack.peek() << endl;
    // cout << "Popped: " << linked_stack.pop() << endl;
    // printStack(linked_stack);

    return 0;
}
