#include <iostream>
using namespace std;

// Fungsi untuk membalik array menggunakan pointer
void balikArray(int* arr, int n) {
    int* kiri = arr;            // pointer ke elemen pertama
    int* kanan = arr + n - 1;   // pointer ke elemen terakhir

    while (kiri < kanan) {
        int temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;

        kiri++;
        kanan--;
    }
}

int main() {
    const int n = 7;
    int data[n];

    // Isi array dengan kelipatan 3
    for (int i = 0; i < n; i++) {
        data[i] = (i + 1) * 3;
    }

    // Tampilkan array sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Panggil fungsi untuk membalik array
    balikArray(data, n);

    // Tampilkan array setelah dibalik
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
