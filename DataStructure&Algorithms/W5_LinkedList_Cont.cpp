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

void insert_x_after_y(elmenetType x, elmenetType y){
    insert(x, next(locate(y)));
}

elmenetType size(){ return counter; }

};


elmenetType sum(List l){
List newList;
} 

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


int main(){
    List l;
    l.insert(10, l.first());
    l.insert(20, l.end());
    l.insert(30, l.end());
    l.insert(40, l.end());
    l.insert(50, l.end());
    cout << "Size: " << l.size()<<endl;
    l.print_list();
    
    position pos = l.locate(10);
    pos = l.next(pos);  
    l.insert(30, pos);

    l.print_list();

    
    List l2;
    l2.insert(-10, l2.end());
    l2.insert(-20, l2.end());
    l2.insert(-30, l2.end());
    l2.insert(-40, l2.end());
    
    List l3 = concatinate(l, l2);
    
    l3.print_list();
    
    
    
    
    
    
    
    return 0;
}