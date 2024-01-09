#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    class LinkedListNode {
    public:
        T data;
        LinkedListNode* next;

        LinkedListNode(T data) : data(data), next(nullptr) {}

        ~LinkedListNode() {
            delete next;
        }
    };

    LinkedListNode* head;

    Node() : head(nullptr) {}

    void add(T data) {
        LinkedListNode* node = new LinkedListNode(data);

        if (head == nullptr) {
            head = node;
        }
        else {
            LinkedListNode* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void print() {
        LinkedListNode* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void deleteNode(T data) {
        LinkedListNode* current = head;
        LinkedListNode* previous = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }

                current->next = nullptr;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    void exchange(T data1, T data2) {
        LinkedListNode* current1 = findNode(data1);
        LinkedListNode* current2 = findNode(data2);

        if (current1 != nullptr && current2 != nullptr) {
            T temp = current1->data;
            current1->data = current2->data;
            current2->data = temp;
        }
    }

    void clear() {
        delete head;
        head = nullptr;
    }

    void addBetween(T data, T data1, T data2) {
        LinkedListNode* current = head;
        LinkedListNode* previous = nullptr;

        while (current != nullptr) {
            if (current->data == data1 && current->next != nullptr && current->next->data == data2) {
                LinkedListNode* node = new LinkedListNode(data);
                node->next = current->next;
                current->next = node;
                return;
            }

            current = current->next;
        }
    }

    void addBefore(T data, T data1) {
        LinkedListNode* current = head;
        LinkedListNode* previous = nullptr;

        while (current != nullptr) {
            if (current->data == data1) {
                LinkedListNode* node = new LinkedListNode(data);
                node->next = current;
                if (previous != nullptr) {
                    previous->next = node;
                }
                else {
                    head = node;
                }
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    void removeBetween(T data, T data1, T data2) {
        LinkedListNode* current = head;
        LinkedListNode* previous = nullptr;

        while (current != nullptr) {
            if (current->data == data1 && current->next != nullptr && current->next->data == data2) {
                LinkedListNode* temp = current->next;
                current->next = current->next->next;
                temp->next = nullptr;
                delete temp;
                return;
            }

            current = current->next;
        }
    }

    LinkedListNode* findNode(T data) {
        LinkedListNode* current = head;

        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    ~Node() {
        delete head;
    }

    Node<T>& operator+=(T data) {
        add(data);
        return *this;
    }

    Node<T>& operator-=(T data) {
        deleteNode(data);
        return *this;
    }

    void operator()(T data1, T data2) {
        exchange(data1, data2);
    }

    void operator()(T data, T data1, T data2) {
        addBetween(data, data1, data2);
    }

    void operator--(int) {
        clear();
    }

    void operator[](T data1) {
        addBefore(data1, data1);
    }

    void operator()(T data, T data1, T data2, T data3) {
        removeBetween(data, data1, data2);
    }
};

int main() {
    Node<int> node;
    node += 1;
    node += 2;
    node += 3;
    node += 4;

    node.print();

    node += 5;
    node += 6;

    cout << endl;

    node.print();

    node -= 3;
    node -= 1;

    cout << endl;

    node.print();

    cout << endl;

    node(2, 5);

    node.print();

    cout << endl;

    node(7, 5, 4);

    node.print();

    cout << endl;

    node(5, 7, 4);

    node.print();

    cout << endl;

    node[8];

    node.print();

    cout << endl;

    node--;

    node += 1;

    node.print();

    return 0;
}