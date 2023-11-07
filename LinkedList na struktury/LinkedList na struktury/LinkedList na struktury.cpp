
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

    ~Node() {
        delete head;
    }
};

int main() {
    Node<int> node;
    node.add(1);
    node.add(2);
    node.add(3);
    node.add(4);

    node.print();

    node.add(5);
    node.add(6);

    node.print();

    node.deleteNode(3);
    node.deleteNode(1);

    node.print();

    return 0;
}