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

    // insert x after position p
    void insert(ElmenetType x, Position p = NULL) {
        if (p == NULL) p = end();
        Position new_node = new node;
        new_node->element = x;
        new_node->next = p->next;
        p->next = new_node;
        if (new_node->next == NULL) tail = new_node;
        counter++;
    }

    // delete the node after position p
    void delete_at(Position p) {
        if (p == end() || p == NULL) {
            cout << "No element to be deleted";
            return;
        }
        Position temp = p->next;
        p->next = p->next->next;
        if (p->next == NULL) tail = p;
        temp->next = NULL;
        delete temp;
        counter--;
    }

    // locate x — returns position of the node BEFORE x
    Position locate(ElmenetType x) {
        Position p = head;
        while (p->next != NULL) {
            if (p->next->element == x) return p;
            p = p->next;
        }
        return p;  // END() if not found
    }

    // locate x in range [pos, end_pos)
    Position locate_in_range(ElmenetType x, Position pos, Position end_pos) {
        Position p = pos;
        while (p->next != end_pos && p->next != NULL) {
            if (p->next->element == x) return p;
            p = p->next;
        }
        return p;  // END() if not found
    }

    // return the element stored in the node AFTER p
    ElmenetType retrieve(Position pos) {
        if (pos == tail || pos == NULL) {
            cout << "No element to retrieve";
            return 0;
        }
        return pos->next->element;
    }

    void print_list() {
        cout << "List is: ";
        Position p = head->next;
        while (p != NULL) {
            cout << p->element << " ";
            p = p->next;
        }
        cout << endl;
    }

    Position first()  { return head; }

    Position next(Position pos) {
        if (pos == tail) return NULL;
        return pos->next;
    }

    Position previous(Position pos) {
        if (pos == head) return NULL;
        Position q = head;
        while (q != NULL && q->next != pos) q = q->next;
        return q;
    }

    int size() { return counter; }
};

// ── Utility Functions ──────────────────────────────────────────

List reverse(List l1) {
    List l2;
    Position pos = l1.previous(l1.end());
    while (pos >= l1.first()) {
        int x = l1.retrieve(pos);
        l2.insert(x, l2.end());
        pos = l1.previous(pos);
    }
    return l2;
}

List reverse_modified(List l1) {
    List l2;
    Position pos = l1.first();
    while (pos != l1.end()) {
        int x = l1.retrieve(pos);
        l2.insert(x, l2.first());
        pos = l1.next(pos);
    }
    return l2;
}

void insert_x_after_y(ElmenetType x, ElmenetType y, List &l) {
    l.insert(x, l.next(l.locate(y)));
}

void purge(List &L) {
    Position p = L.first();
    while (p != L.end()) {
        Position q = L.next(p);
        while (q != L.end()) {
            if (L.retrieve(p) == L.retrieve(q))
                L.delete_at(q);
            else
                q = L.next(q);
        }
        p = L.next(p);
    }
}

void remove_occurrences(List &L, int x) {
    Position pos = L.first();
    while (1) {
        pos = L.locate_in_range(x, pos, L.previous(L.end()));
        if (pos == L.end()) break;
        else L.delete_at(pos);
    }
}

void split(List L, List &l_odd, List &l_even) {
    Position curr = L.first();
    while (curr != L.end()) {
        int x = L.retrieve(curr);
        if (x % 2 == 0)
            l_even.insert(x, l_even.end());
        else
            l_odd.insert(x, l_odd.end());
        curr = L.next(curr);
    }
}

List concatenate(List l1, List l2) {
    List l;
    Position curr = l1.first();
    while (curr != l1.end()) {
        l.insert(l1.retrieve(curr), l.end());
        curr = l1.next(curr);
    }
    curr = l2.first();
    while (curr != l2.end()) {
        l.insert(l2.retrieve(curr), l.end());
        curr = l2.next(curr);
    }
    return l;
}

ElmenetType sum(List L) {
    Position curr = L.first();
    ElmenetType s = 0;
    while (curr != L.end()) {
        s += L.retrieve(curr);
        curr = L.next(curr);
    }
    return s;
}

ElmenetType max_val(List L) {
    Position curr = L.first();
    ElmenetType m = L.retrieve(L.first());
    while (curr != L.end()) {
        if (m < L.retrieve(curr)) m = L.retrieve(curr);
        curr = L.next(curr);
    }
    return m;
}

List sort_list(List L) {
    List new_list;
    while (L.size() != 0) {
        ElmenetType m = max_val(L);
        new_list.insert(m, new_list.first());
        L.delete_at(L.locate(m));
    }
    return new_list;
}

// ──────────────────────────────────────────────────────────────

int main() {
    // your code here

    return 0;
}