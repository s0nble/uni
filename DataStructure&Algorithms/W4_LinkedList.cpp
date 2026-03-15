#include <iostream>
using namespace std;

typedef int ElmenetType;
typedef int Position;

class List {
private:
    ElmenetType *elements;
    int capacity;
    Position last;

public:
    List(int n)
    {
        elements = new ElmenetType[n];
        capacity = n;
        last = -1;
    }

    void make_null()
    {
        last = -1;
    }

    Position end()
    {
        return last + 1;
    }

    void insert(ElmenetType x, Position pos)
    {
        if (last == capacity - 1)
            cout << "list is full";
        else if (pos > last + 1 || pos < 0)
            cout << pos << ":pos is out of range" << last;
        else {
            for (Position i = last; i >= pos; i--)
                elements[i + 1] = elements[i];
            last++;
            elements[pos] = x;
        }
    }

    void delete_at(Position pos)
    {
        if (pos > last || pos < 0)
            cout << "pos is out of range";
        for (Position i = pos + 1; i <= last; i++)
            elements[i - 1] = elements[i];
        last--;
    }

    Position locate(ElmenetType x)
    {
        for (Position i = 0; i <= last; i++)
            if (x == elements[i]) return i;
        return -1;
    }

    Position locate_in_range(ElmenetType x, Position pos, Position end_pos)
    {
        for (Position i = pos; i <= end_pos; i++)
            if (x == elements[i]) return i;
        return -1;
    }

    ElmenetType retrieve(Position pos)
    {
        if (pos > last || pos < 0) {
            cout << "pos is out of range";
            return -1;
        }
        return elements[pos];
    }

    void print_list()
    {
        for (Position i = 0; i <= last; i++)
            cout << elements[i] << "-";
        cout << endl;
    }

    Position first()                { return 0; }
    Position next(Position pos)     { return pos + 1; }
    Position previous(Position pos) { return pos - 1; }
    int size()                      { return last + 1; }
};

// ── Utility Functions ──────────────────────────────────────────────

List reverse(List l1)
{
    List l2(l1.end());
    Position pos = l1.previous(l1.end());
    while (pos != l1.previous(l1.first())) {
        l2.insert(l1.retrieve(pos), l2.end());
        pos = l1.previous(pos);
    }
    return l2;
}

List reverse_modified(List l1)
{
    List l2(l1.end());
    Position pos = l1.first();
    while (pos != l1.end()) {
        l2.insert(l1.retrieve(pos), l2.first());
        pos = l1.next(pos);
    }
    return l2;
}

void insert_x_after_y(ElmenetType x, ElmenetType y, List &l)
{
    Position pos = l.locate(y);
    if (pos != l.end())
        l.insert(x, l.next(pos));
    else
        cout << "Y not found\n";
}

void purge(List &L)
{
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

void remove_occurrences(List &L, ElmenetType x)
{
    Position pos = L.first();
    while (true) {
        pos = L.locate_in_range(x, pos, L.previous(L.end()));
        if (pos == -1) break;
        else L.delete_at(pos);
    }
}

void split(List L, List &odd, List &even)
{
    Position curr = L.first();
    while (curr != L.end()) {
        ElmenetType x = L.retrieve(curr);
        if (x % 2 == 0) even.insert(x, even.end());
        else              odd.insert(x, odd.end());
        curr = L.next(curr);
    }
}

List concatenate(List l1, List l2)
{
    List l(l1.end() + l2.end());
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

ElmenetType sum(List L)
{
    Position curr = L.first();
    ElmenetType s = 0;
    while (curr != L.end()) {
        s += L.retrieve(curr);
        curr = L.next(curr);
    }
    return s;
}

ElmenetType max(List L)
{
    Position curr = L.first();
    ElmenetType m = L.retrieve(L.first());
    while (curr != L.end()) {
        if (m < L.retrieve(curr)) m = L.retrieve(curr);
        curr = L.next(curr);
    }
    return m;
}

// ──────────────────────────────────────────────────────────────────

int main()
{
    // your code here

    return 0;
}