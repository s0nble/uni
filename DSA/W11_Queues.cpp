#include <iostream>
#include <cassert>
using namespace std;

typedef int ElementType;

// ══════════════════════════════════════════════════════════════
// PART A – Array-Based Queue
// ══════════════════════════════════════════════════════════════

class ArrayQueue {
private:
    int front;
    int rear;
    int counter;
    int max_size;
    ElementType * arr;

public:
    ArrayQueue(int size) {
        max_size = size;
        counter = 0;
        front = 0;
        rear = -1;
        arr = new ElementType[max_size];
    }

    // Task 1: insert at the rear
    void enqueue(ElementType el) {
        if(isFull()){
            cout << "Queue Already Full" << endl;
        }
        else{
           rear = (rear + 1) % max_size;
            arr[rear] = el;
            counter++;
        }

    }

    // Task 2: remove and return the front element
    ElementType dequeue() {
        if(isEmpty()){
            cout << "Queue Already Empty" << endl;
            return -999999;
        }
        int temp = arr[front];
        front = (front + 1) % max_size;
        counter--;
        return temp;
    }

    // Task 3: return the number of elements
    int size() {
        return counter;
    }

    // Task 4: check whether the queue is empty
    bool isEmpty() {
        return counter == 0; 
    }

    // Task 5: check whether the queue is full
    bool isFull() {
        return counter == max_size;
    }

    ElementType frontView(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -999999;
        }
        else{
        return arr[front];
        }
    }

    ElementType rearView(){
       if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -999999;
        }
        return arr[rear];
    }

    void printQueue(){
        if(isEmpty()){
            cout<< "Queue is empty, Nothing to print" << endl;
            return;
        }
        for(int i=front; i != rear; i = (i + 1)%max_size){
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    int queueSearch(ElementType el){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else{
            for(int i = front; i != rear; i = (i + 1)%max_size){
                if (arr[i] == el){
                    return i;
                }   

            }
            if (arr[rear] == el){
                return rear;
            }
            }
        return -1;
    }


    void reverseQueue(){
        if(isEmpty()){
            return;
        }

        int temp = dequeue();
        reverseQueue();
        enqueue(temp);
    }

};


// ══════════════════════════════════════════════════════════════
// PART B – Linked-List Queue
// ══════════════════════════════════════════════════════════════

struct node {
    ElementType element;
    node * next;
};

class LinkedQueue {
private:
    node * front;
    node * rear;
    int counter;

public:
    LinkedQueue() {
        counter = 0;
        front = NULL;
        rear = NULL;
    }

    // Task 6: insert at the rear
    void enqueue(ElementType el) {
        
        node *newNode = new node;
        newNode->element = el;
        newNode->next = NULL;
        
        if(isEmpty()){
            front =  newNode;
        }
        else{
            rear->next = newNode;
        }
        rear = newNode;
        counter++;
    }

    void printQueue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        node *curr = front;
        while(curr!=NULL){
            cout << curr->element << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Task 7: remove and return the front element
    ElementType dequeue() {
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -999999;
        }

        node *temp = front;
        front = front->next;
        int value = temp->element;
        delete temp;
        counter--;
        
        if(isEmpty()){
            rear = NULL;
        }
        
        return value;
    }

    // Task 8: return the number of nodes
    int size() {
        return counter;
    }

    // Task 9: check whether the queue is empty
    bool isEmpty() {
        return counter == 0;
    }

    void reverseQueue(){
        if(isEmpty()){
            return;
        }
        int temp = dequeue();
        reverseQueue();
        enqueue(temp);
    }
};


int main() {
    // ── Test Part A ──────────────────────────────────
    // cout << "=== Array Queue ===" << endl;

    // ArrayQueue q(5);

    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);

    // cout << "Before reverse: ";
    // q.printQueue();

    // q.reverseQueue();

    // cout << "After reverse: ";
    // q.printQueue();

    // cout << "Dequeued: " << q.dequeue() << endl;
    // cout << "Dequeued: " << q.dequeue() << endl;

    // cout << "After two dequeues: ";
    // q.printQueue();

    // ── Test Part B ──────────────────────────────────
    // cout << "=== Linked Queue ===" << endl;
    LinkedQueue q2;

    q2.enqueue(5);
    q2.enqueue(9);
    q2.enqueue(10);
    q2.enqueue(11);

    cout << "Before reverse: ";
    q2.printQueue();

    q2.reverseQueue();

    cout << "After reverse: ";
    q2.printQueue();

    cout << "Dequeued: " << q2.dequeue() << endl;
    cout << "Dequeued: " << q2.dequeue() << endl;

    cout << "After two dequeues: ";
    q2.printQueue();

    return 0;
}