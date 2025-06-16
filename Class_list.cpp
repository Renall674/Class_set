#include <iostream>

using namespace std;

template <typename T>
class list {
private:
    struct Node {
        T value;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node(const T& v) : value(v) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t size_ = 0;

public:
    list(initializer_list<T> init) {
        for (const T& val : init) {
            push_back(val);
        }
    }

    ~list() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size_++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size_++;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size_--;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size_--;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    class iterator {
        Node* current;
    public:
        iterator(Node* node) : current(node) {}
        T& operator*() { return current->value; }
        iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const iterator& other) { return current != other.current; }
    };

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
};

int main() {
    list<int> l = { 10, 20, 30 };
    l.push_front(5);
    l.push_back(40);

    for (int val : l) {
        cout << val << endl;
    }

    l.pop_back();
    l.pop_front();
    cout << "Size: " << l.size();
}