#include <iostream>
using namespace std;

typedef int ElmenetType;

struct node {
    ElmenetType element;
    node* next;
    node* prev; // 🔥 NEW
};

typedef node* Position;

class List {
private:
    node* head;   // dummy node
    node* tail;
    int counter;

public:
    List() { make_null(); }

    void make_null() {
        head = new node;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        counter = 0;
    }

    Position end() { return tail; }

    Position first() { return head; }

    Position next(Position pos) {
        if (pos == tail) return NULL;
        return pos->next;
    }

    // 🔥 O(1) now
    Position previous(Position pos) {
        if (pos == head) return NULL;
        return pos->prev;
    }

    void insert(ElmenetType x, Position p = NULL) {
        if (p == NULL) p = end();

        Position new_node = new node;
        new_node->element = x;

        new_node->next = p->next;
        new_node->prev = p;

        if (p->next != NULL)
            p->next->prev = new_node;

        p->next = new_node;

        if (new_node->next == NULL)
            tail = new_node;

        counter++;
    }

    void delete_at(Position p) {
        if (p == end() || p == NULL) {
            cout << "No element to be deleted\n";
            return;
        }

        Position temp = p->next;

        p->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = p;
        else
            tail = p;

        delete temp;
        counter--;
    }

    Position locate(ElmenetType x) {
        Position p = head;
        while (p->next != NULL) {
            if (p->next->element == x) return p;
            p = p->next;
        }
        return p;
    }

    Position locate_in_range(ElmenetType x, Position pos, Position end_pos) {
        Position p = pos;
        while (p->next != end_pos && p->next != NULL) {
            if (p->next->element == x) return p;
            p = p->next;
        }
        return p;
    }

    ElmenetType retrieve(Position pos) {
        if (pos == tail || pos == NULL) {
            cout << "No element to retrieve\n";
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

    // 🔥 NEW: print reverse
    void print_reverse() {
        cout << "Reverse: ";
        Position p = tail;
        while (p != head) {
            cout << p->element << " ";
            p = p->prev;
        }
        cout << endl;
    }

    int size() { return counter; }
};

// ── Utility Functions ──────────────────────────────────────────

// 🔥 optimized using prev (no need to scan!)
List reverse(List l1) {
    List l2;
    Position pos = l1.previous(l1.end());

    while (pos != l1.first()) {
        l2.insert(l1.retrieve(pos), l2.end());
        pos = l1.previous(pos);
    }
    return l2;
}

List reverse_modified(List l1) {
    List l2;
    Position pos = l1.first();

    while (pos != l1.end()) {
        l2.insert(l1.retrieve(pos), l2.first());
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
    while (true) {
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
        if (m < L.retrieve(curr))
            m = L.retrieve(curr);
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
    // test if needed
    return 0;
}