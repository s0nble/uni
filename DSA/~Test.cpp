#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef int ElementType;

struct SNode {
    ElementType element;
    SNode* next;

    SNode(ElementType value = 0, SNode* next_node = NULL) {
        element = value;
        next = next_node;
    }
};

typedef SNode* SPosition;

class SinglyLinkedList {
private:
    SNode* head;
    SNode* tail;
    int counter;

public:
    SinglyLinkedList() {
        head = new SNode();
        tail = head;
        counter = 0;
    }

    ~SinglyLinkedList() {
        clear();
        delete head;
    }

    void clear() {
        SNode* current = head->next;
        while (current != NULL) {
            SNode* temp = current;
            current = current->next;
            delete temp;
        }
        head->next = NULL;
        tail = head;
        counter = 0;
    }

    SPosition first() { return head; }
    SPosition end() { return tail; }
    int size() const { return counter; }
    bool is_empty() const { return counter == 0; }

    void insert(ElementType x, SPosition p = NULL) {
        if (p == NULL) p = tail;

        SNode* new_node = new SNode(x, p->next);
        p->next = new_node;

        if (new_node->next == NULL) tail = new_node;
        counter++;
    }

    void insert_sorted(ElementType x) {
        SPosition current = head;
        while (current->next != NULL && current->next->element < x) {
            current = current->next;
        }
        insert(x, current);
    }

    void delete_at(SPosition p) {
        if (p == NULL || p->next == NULL) return;

        SNode* temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
        counter--;
    }

    ElementType retrieve(SPosition p) {
        if (p == NULL || p->next == NULL) {
            cout << "Invalid position" << endl;
            return 0;
        }
        return p->next->element;
    }

    SPosition next(SPosition p) {
        if (p == NULL) return NULL;
        return p->next;
    }

    SPosition locate(ElementType x) {
        SPosition current = head;
        while (current->next != NULL) {
            if (current->next->element == x) return current;
            current = current->next;
        }
        return tail;
    }

    int locate_in_range(ElementType x, int start_pos, int end_pos) {
        if (start_pos < 1) start_pos = 1;
        if (end_pos > counter) end_pos = counter;
        if (start_pos > end_pos) return -1;

        SNode* current = head->next;
        int index = 1;

        while (current != NULL && index <= end_pos) {
            if (index >= start_pos && current->element == x) return index;
            current = current->next;
            index++;
        }

        return -1;
    }

    void purge() {
        SPosition p = head;
        while (p->next != NULL) {
            SPosition q = p->next;
            while (q->next != NULL) {
                if (q->next->element == p->next->element)
                    delete_at(q);
                else
                    q = q->next;
            }
            p = p->next;
        }
    }

    bool swap_adjacent_at(int first_index) {
        if (first_index < 1 || first_index >= counter) return false;

        SPosition prev = head;
        for (int i = 1; i < first_index; i++) {
            prev = prev->next;
        }

        SNode* first_node = prev->next;
        SNode* second_node = first_node->next;

        prev->next = second_node;
        first_node->next = second_node->next;
        second_node->next = first_node;

        if (first_node->next == NULL) tail = first_node;
        return true;
    }

    static SinglyLinkedList merge_lists(SinglyLinkedList& l1, SinglyLinkedList& l2) {
        SinglyLinkedList merged;

        SNode* current = l1.head->next;
        while (current != NULL) {
            merged.insert(current->element);
            current = current->next;
        }

        current = l2.head->next;
        while (current != NULL) {
            merged.insert(current->element);
            current = current->next;
        }

        return merged;
    }

    void print(const string& label) {
        cout << label;
        SNode* current = head->next;
        while (current != NULL) {
            cout << current->element << " ";
            current = current->next;
        }
        cout << endl;
    }
};

struct DNode {
    ElementType element;
    DNode* next;
    DNode* prev;

    DNode(ElementType value = 0) {
        element = value;
        next = NULL;
        prev = NULL;
    }
};

typedef DNode* DPosition;

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    int counter;

public:
    DoublyLinkedList() {
        head = new DNode();
        tail = head;
        counter = 0;
    }

    ~DoublyLinkedList() {
        clear();
        delete head;
    }

    void clear() {
        DNode* current = head->next;
        while (current != NULL) {
            DNode* temp = current;
            current = current->next;
            delete temp;
        }
        head->next = NULL;
        tail = head;
        counter = 0;
    }

    void insert(ElementType x, DPosition p = NULL) {
        if (p == NULL) p = tail;

        DNode* new_node = new DNode(x);
        new_node->next = p->next;
        new_node->prev = p;

        if (p->next != NULL) p->next->prev = new_node;
        p->next = new_node;

        if (new_node->next == NULL) tail = new_node;
        counter++;
    }

    void insert_sorted(ElementType x) {
        DPosition current = head;
        while (current->next != NULL && current->next->element < x) {
            current = current->next;
        }
        insert(x, current);
    }

    bool swap_adjacent_at(int first_index) {
        if (first_index < 1 || first_index >= counter) return false;

        DPosition first_node = head->next;
        for (int i = 1; i < first_index; i++) {
            first_node = first_node->next;
        }

        DPosition second_node = first_node->next;
        DPosition before_first = first_node->prev;
        DPosition after_second = second_node->next;

        before_first->next = second_node;
        second_node->prev = before_first;

        second_node->next = first_node;
        first_node->prev = second_node;

        first_node->next = after_second;
        if (after_second != NULL)
            after_second->prev = first_node;
        else
            tail = first_node;

        return true;
    }

    void print(const string& label) {
        cout << label;
        DNode* current = head->next;
        while (current != NULL) {
            cout << current->element << " ";
            current = current->next;
        }
        cout << endl;
    }
};

bool is_balanced(const string& expression) {
    stack<char> s;

    for (int i = 0; i < static_cast<int>(expression.length()); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top_char = s.top();
            s.pop();

            bool matches =
                (top_char == '(' && ch == ')') ||
                (top_char == '{' && ch == '}') ||
                (top_char == '[' && ch == ']');

            if (!matches) return false;
        }
    }

    return s.empty();
}

void reverse_queue(queue<int>& q) {
    if (q.empty()) return;

    int front_value = q.front();
    q.pop();
    reverse_queue(q);
    q.push(front_value);
}

bool is_palindrome(const string& text) {
    queue<char> q;
    stack<char> s;

    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        q.push(text[i]);
        s.push(text[i]);
    }

    while (!q.empty()) {
        if (q.front() != s.top()) return false;
        q.pop();
        s.pop();
    }

    return true;
}

void print_queue(queue<int> q, const string& label) {
    cout << label;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}