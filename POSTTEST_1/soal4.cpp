#include <iostream>
using namespace std;

// Fungsi untuk menukar dua variabel integer menggunakan double pointer
void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;

    // Input dua nilai
    cout << "Masukkan nilai pertama (x): ";
    cin >> x;
    cout << "Masukkan nilai kedua (y): ";
    cin >> y;

    // Pointer ke variabel
    int *px = &x;
    int *py = &y;

    cout << "\nSebelum pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Panggil fungsi tukar dengan double pointer
    tukar(&px, &py);

    cout << "\nSesudah pertukaran:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
