#include <iostream>
#include <stdexcept>
using namespace std;

typedef int ElementType;

// Part A: circular array queue
class ArrayQueue {
private:
    int front;
    int rear;
    int counter;
    int capacity;
    ElementType* elements;

public:
    ArrayQueue(int max_size) {
        front = 0;
        rear = -1;
        counter = 0;
        capacity = max_size;
        elements = new ElementType[max_size];
    }

    // Task 1: insert at the rear using circular wraparound
    void enqueue(ElementType value) {
        throw logic_error("Task 1 not implemented");
    }

    // Task 2: remove and return the front value
    ElementType dequeue() {
        throw logic_error("Task 2 not implemented");
    }

    // Task 3: return the number of stored values
    int size() {
        throw logic_error("Task 3 not implemented");
    }

    // Task 4: return true when no values are stored
    bool isEmpty() {
        throw logic_error("Task 4 not implemented");
    }

    // Task 5: return true when the array is full
    bool isFull() {
        throw logic_error("Task 5 not implemented");
    }

    // Task 6: view the front without removing it
    ElementType frontView() {
        throw logic_error("Task 6 not implemented");
    }

    // Task 7: view the rear without removing it
    ElementType rearView() {
        throw logic_error("Task 7 not implemented");
    }

    // Task 8: print values in logical FIFO order
    void printQueue() {
        throw logic_error("Task 8 not implemented");
    }

    // Task 9: return the physical index of value, or -1
    int queueSearch(ElementType value) {
        throw logic_error("Task 9 not implemented");
    }

    // Task 10: reverse the queue, for example using recursion
    void reverseQueue() {
        throw logic_error("Task 10 not implemented");
    }
};

// Part B: linked-list queue
struct node {
    ElementType element;
    node* next;
};

class LinkedQueue {
private:
    node* front;
    node* rear;
    int counter;

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
        counter = 0;
    }

    // Task 11: insert at the rear
    void enqueue(ElementType value) {
        throw logic_error("Task 11 not implemented");
    }

    // Task 12: remove and return the front value
    ElementType dequeue() {
        throw logic_error("Task 12 not implemented");
    }

    // Task 13: return the number of stored nodes
    int size() {
        throw logic_error("Task 13 not implemented");
    }

    // Task 14: return true when the queue is empty
    bool isEmpty() {
        throw logic_error("Task 14 not implemented");
    }

    // Task 15: print values from front to rear
    void printQueue() {
        throw logic_error("Task 15 not implemented");
    }

    // Task 16: reverse the queue, for example using recursion
    void reverseQueue() {
        throw logic_error("Task 16 not implemented");
    }
};

int main() {
    // ArrayQueue array_queue(5);
    // array_queue.enqueue(10);
    // array_queue.enqueue(20);
    // array_queue.enqueue(30);
    // array_queue.printQueue();
    // cout << "Front: " << array_queue.frontView() << endl;
    // cout << "Dequeued: " << array_queue.dequeue() << endl;
    // array_queue.reverseQueue();
    // array_queue.printQueue();

    // LinkedQueue linked_queue;
    // linked_queue.enqueue(5);
    // linked_queue.enqueue(15);
    // linked_queue.enqueue(25);
    // linked_queue.printQueue();
    // cout << "Dequeued: " << linked_queue.dequeue() << endl;
    // linked_queue.reverseQueue();
    // linked_queue.printQueue();

    return 0;
}
