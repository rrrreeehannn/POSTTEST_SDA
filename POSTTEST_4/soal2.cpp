#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi push
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi pop
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi cek apakah pasangan kurung cocok
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Fungsi utama: cek apakah kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        // Jika kurung buka -> push
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika kurung tutup -> cek pasangan
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) {
                return false; // tidak ada pasangan
            }
            char topChar = pop(stackTop);
            if (!isMatchingPair(topChar, c)) {
                return false; // pasangan tidak cocok
            }
        }
    }

    // Kalau setelah loop stack kosong -> seimbang
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " 
         << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") 
         << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " 
         << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") 
         << endl;

    string expr3 = "((()))";
    cout << expr3 << " -> " 
         << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") 
         << endl;

    string expr4 = "({[]})";
    cout << expr4 << " -> " 
         << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") 
         << endl;

    string expr5 = "({[})";
    cout << expr5 << " -> " 
         << (areBracketsBalanced(expr5) ? "Seimbang" : "Tidak Seimbang") 
         << endl;

    return 0;
}
