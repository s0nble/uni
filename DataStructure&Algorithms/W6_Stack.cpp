#include <iostream>
using namespace std;

typedef int ElementType;

// ══════════════════════════════════════════════════════════════
// PART A – Array-Based Stack
// ══════════════════════════════════════════════════════════════

class ArrayStack {
private:
    ElementType * arr;
    int max_size;
    int counter;

public:
    ArrayStack(int max) {
        arr = new ElementType[max];
        max_size = max;
        counter = 0;
    }

    bool isEmpty() { return counter == 0; }

    bool isFull() { return counter == max_size; }

    int size() { return counter; }

    // Task 1: push an element onto the stack
    // void push(ElementType el) { ... }

    // Task 2: remove and return the top element
    // ElementType pop() { ... }

    // Task 3: return the top element without removing it
    // ElementType peek() { ... }
};

// Task 4: reverse a stack using a second stack
// ArrayStack reverse(ArrayStack s1, int size) { ... }

// Task 5: merge two stacks preserving order
// ArrayStack merge(ArrayStack &s1, int size1, ArrayStack &s2, int size2) { ... }


// ══════════════════════════════════════════════════════════════
// PART B – Linked-List Stack
// ══════════════════════════════════════════════════════════════

struct node {
    ElementType element;
    node * next;
};

class LinkedStack {
private:
    node * top;
    int counter;

public:
    LinkedStack() {
        top = NULL;
        counter = 0;
    }

    bool isEmpty() { return top == NULL; }

    int size() { return counter; }

    // Task 6: push an element onto the stack
    // void push(ElementType el) { ... }

    // Task 7: remove and return the top element
    // ElementType pop() { ... }

    // Task 8: return the top element without removing it
    // ElementType peek() { ... }
};

// Task 9: reverse a linked stack using a second stack
// LinkedStack reverse(LinkedStack s1) { ... }

// Task 10: merge two linked stacks preserving order
// LinkedStack merge(LinkedStack &s1, LinkedStack &s2) { ... }


int main() {
    // ── Test Part A ──────────────────────────────────
    cout << "=== Array Stack ===" << endl;
    ArrayStack s1(6);
    // s1.push(5);
    // s1.push(15);
    // s1.push(25);
    // cout << "Top: " << s1.peek() << endl;        // 25
    // cout << "Popped: " << s1.pop() << endl;      // 25
    // cout << "Size: " << s1.size() << endl;        // 2

    // ── Test Part B ──────────────────────────────────
    cout << "=== Linked Stack ===" << endl;
    LinkedStack s2;
    // s2.push(10);
    // s2.push(20);
    // s2.push(30);
    // cout << "Top: " << s2.peek() << endl;        // 30
    // cout << "Popped: " << s2.pop() << endl;      // 30
    // cout << "Size: " << s2.size() << endl;        // 2

    return 0;
}