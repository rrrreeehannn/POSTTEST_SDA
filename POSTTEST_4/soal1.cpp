#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi Push untuk menambahkan elemen ke stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi Pop untuk mengambil elemen dari stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi untuk membalik string dengan stack
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. Push setiap karakter ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Pop semua karakter dari stack, tambahkan ke string reversed
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    // Output: ataD rutkartS
    return 0;
}
