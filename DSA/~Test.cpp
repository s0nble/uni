#include <iostream>
using namespace std;

typedef double elmenetType;


struct node{
    elmenetType elem;
    node* next;
};

typedef node* position;

class List{
private:
    node* head;
    node* tail;
    int counter;

public:
List() {make_null();}

void make_null() {
    head = new node;
    head->next = NULL;
    tail = head;
    counter = 0;
}

position end() {return tail;}
position first() {return head;}

void insert(elmenetType x, position p){
    if(p == NULL) p = end();
    node* newNode = new node;
    newNode->elem = x;
    newNode->next = p->next;
    p->next = newNode;

    if(newNode->next == NULL) tail=newNode;
    
    counter++;
}

elmenetType retrieve(position pos){
    if(pos == end()){ 
        cout << "Inavlid Position"<<endl;
        return -1;
    }
    return pos->next->elem;
}

position next(position pos){
    if(pos == end() || pos == NULL){
        cout << "Invalid Position"<<endl;
    }
    return pos->next;
}

void print_list(){
    cout << "List is: ";
    position curr = first();
    
    while(curr != end()){
        cout << retrieve(curr) << " ";
        curr = next(curr);
    }

    cout << endl;
}

position locate(elmenetType x){
    position curr = first();
    while(curr != end()){
        if(x == retrieve(curr))
            return curr;
        curr = next(curr);
    }
    cout << "Cant locate this element"<<endl;
    return NULL;
}

position locate_in_range(elmenetType x, position start, position end){
    position curr = start;
    while(curr != end && curr != NULL){
        if(x == retrieve(curr))
            return curr;
        curr = next(curr);
    }
    cout << "Element not found in range"<<endl;
    return NULL;
}

elmenetType size(){ return counter; }

void purge(){
    node* curr = head->next;
    while(curr != NULL){
        node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head->next = NULL;
    tail = head;
    counter = 0;
}

};


List concatinate(List l1, List l2){
    List newList;
    
    position curr = l1.first();
    while(curr != l1.end()){
        newList.insert(l1.retrieve(curr), newList.end());
        curr = l1.next(curr);
    }

    curr = l2.first();
    while(curr != l2.end()){
        newList.insert(l2.retrieve(curr), newList.end());
        curr = l2.next(curr);
    }
    return newList;
}

List merge_two_lists(List l1, List l2){
    List mergedList;
    
    position curr = l1.first();
    while(curr != l1.end()){
        mergedList.insert(l1.retrieve(curr), mergedList.end());
        curr = l1.next(curr);
    }
    
    curr = l2.first();
    while(curr != l2.end()){
        mergedList.insert(l2.retrieve(curr), mergedList.end());
        curr = l2.next(curr);
    }
    
    return mergedList;
}


int main(){
    // Test basic list operations
    List l;
    l.insert(10, l.first());
    l.insert(20, l.end());
    l.insert(30, l.end());
    l.insert(40, l.end());
    l.insert(50, l.end());
    
    // Test locate_in_range
    position startPos = l.first();
    position endPos = l.locate(40);
    position foundPos = l.locate_in_range(30, startPos, endPos);
    if(foundPos != NULL) cout << "Found 30 in range" << endl;
    
    // Create second list
    List l2;
    l2.insert(-10, l2.end());
    l2.insert(-20, l2.end());
    l2.insert(-30, l2.end());
    l2.insert(-40, l2.end());
    
    // Test merge_two_lists (create third list from two lists)
    List l3 = merge_two_lists(l, l2);
    cout << "Merged List (l1 + l2): ";
    l3.print_list();
    cout << "Merged List Size: " << l3.size() << endl;
    
    // Test purge
    cout << "\nPurging List 3..." << endl;
    l3.purge();
    cout << "List 3 after purge - Size: " << l3.size() << endl;
    cout << "List 3 after purge: ";
    l3.print_list();
    
    return 0;
}