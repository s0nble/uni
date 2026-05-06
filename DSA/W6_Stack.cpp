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
    void push(ElementType el) {
        if(isFull()){
            cout<<"Stack is full!"<<endl;
            return;
        }        
        arr[counter] = el;
        counter++;
    }

    // Task 2: remove and return the top element
    ElementType pop() {
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return -99999;
        }
        int current = arr[counter-1];
        counter--;
        return current;
    }

    // Task 3: return the top element without removing it
    ElementType peek() {
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return -999999;
        }
        return arr[counter-1];
    }
};

// Task 4: reverse a stack using a second stack
ArrayStack reverse(ArrayStack s1, int size) {
    ArrayStack s2(size);
    while(!s1.isEmpty()){
        s2.push(s1.pop());
    }
    return s2;
}

void printStack(ArrayStack s) { // pass by value (copy!)
    cout << "Top to ";
    while(!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
}

// Task 5: merge two stacks preserving order
ArrayStack merge(ArrayStack &s1, int size1, ArrayStack &s2, int size2) {
    ArrayStack s3(size1 + size2);
    while(!s2.isEmpty()){
        s3.push(s2.pop());
    }
    while(!s1.isEmpty()){
        s3.push(s1.pop());
    }
    ArrayStack s4(size1 + size2);
    while(!s3.isEmpty()){
        s4.push(s3.pop());
    }
    return s4;
}

ArrayStack copyStack(ArrayStack s, int size) {
        ArrayStack temp(size);
        ArrayStack copy(size);

        // Step 1: reverse original into temp
        while (!s.isEmpty()) {
            temp.push(s.pop());
        }

        // Step 2: restore original AND build copy
        while (!temp.isEmpty()) {
            int x = temp.pop();
            s.push(x);      // restore original
            copy.push(x);   // build copy
        }

        return copy;
    }


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
    void push(ElementType el) { 
        node* newNode = new node; 
        newNode->element = el;
        newNode->next = top;
        top = newNode;
        counter++;
    }


    // Task 7: remove and return the top element
    ElementType pop() {
        if(isEmpty()){
            cout << "Stack is empty!"<<endl;
            return -999999999; 
        }
        
        node* current = top;
        top = current->next;
        ElementType temp;
        temp=current->element;
        delete current;
        counter--;
        return temp;

        
    }

    //Task 8: peek
ElementType peek(){
    if(isEmpty()){
        cout << "Stack is empty!" <<endl;
        return -9999999;
    }
    return top->element;
}
};

// Task 9: reverse a linked stack using a second stack
LinkedStack reverse(LinkedStack &s1) {
    LinkedStack s2;
    while(!s1.isEmpty()){
        s2.push(s1.pop());
    }

return s2;
}

// Task 10: merge two linked stacks preserving order
LinkedStack merge(LinkedStack &s1, LinkedStack &s2) {
    LinkedStack s4;
    while(!s2.isEmpty()){
        s4.push(s2.pop());
    }
    while(!s1.isEmpty()){
        s4.push(s1.pop());
    }
    LinkedStack s5;
    while(!s4.isEmpty()){
        s5.push(s4.pop());
    }
    return s5;
}

LinkedStack copyStack(LinkedStack s) { // pass by value (copy)
        LinkedStack temp;
        LinkedStack copy;

        // Step 1: reverse into temp
        while (!s.isEmpty()) {
            temp.push(s.pop());
        }

        // Step 2: restore original + build copy
        while (!temp.isEmpty()) {
            int x = temp.pop();
            s.push(x);       // restore original
            copy.push(x);    // build copy
        }

        return copy;
    }

void printStack(LinkedStack s) { // copy
    cout << "Top → ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
}


int main() {
    // ── Test Part A ──────────────────────────────────
    // cout << "=== Array Stack ===" << endl;
    // ArrayStack s1(3);
    // s1.push(5);
    // s1.push(15);
    // s1.push(25);
    // cout<< "Top: " << s1.peek() << endl;        // 25
    // cout << "Popped: " << s1.pop() << endl;      // 25
    // cout << "Popped: " << s1.pop() << endl;      // 25
    // cout<< "Size: " << s1.size() << endl;        // 2

    // ArrayStack s(3);
    // s.push(1); s.push(2); s.push(3);
    // // stack top→bottom: 3, 2, 1

    // ArrayStack r = reverse(s, 3);
    // cout << r.pop() << endl;  // 1
    // cout << r.pop() << endl;  // 2
    // cout << r.pop() << endl;  // 3


    // ArrayStack a(3), b(3);
    // a.push(5); a.push(15); a.push(25);
    // b.push(65); b.push(75); b.push(85);
    // ArrayStack m = merge(a, 3, b, 3);
    // // pop all to see order: 85 75 65 25 15 5
    // while (!m.isEmpty()) cout << m.pop() << " ";
    // cout << endl;

    // ── Test Part B ──────────────────────────────────
    // cout << "=== Linked Stack ===" << endl;
    // LinkedStack s6;
    // s2.push(10);
    // s2.push(20);
    // s2.push(30);
    // cout << "Top: " << s2.peek() << endl;        // 30
    // cout << "Popped: " << s2.pop() << endl;      // 30
    // cout << "Size: " << s2.size() << endl;        // 2

    // s6.push(1); s6.push(2); s6.push(3);
    // LinkedStack r = reverse(s6);
    // cout << r.pop() << endl;  // 1
    // cout << r.pop() << endl;  // 2
    // cout << r.pop() << endl;  // 3
    // return 0;
    
    // LinkedStack a, b;
    // a.push(5); a.push(15); a.push(25);
    // b.push(65); b.push(75); b.push(85);
    // LinkedStack m = merge(a, b);
    // while (!m.isEmpty()) cout << m.pop() << " ";
    // cout << endl;
}