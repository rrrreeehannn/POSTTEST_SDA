#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* head = head_ref;
    Node* tail = head->prev; // tail adalah node sebelum head (karena circular)

    // Kasus 2: Sisipkan sebelum head (data lebih kecil atau sama dengan head->data)
    if (data < head->data) {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head_ref = newNode; // update head
        return;
    }

    // Kasus 3: Cari posisi yang tepat di tengah atau akhir
    Node* current = head;
    while (current->next != head && current->next->data < data) {
        current = current->next;
    }

    // Sisipkan setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}
