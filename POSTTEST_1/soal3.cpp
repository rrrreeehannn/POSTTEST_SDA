#include <iostream>
using namespace std;

// Definisi struct Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    // Input data mahasiswa
    cout << "Input data " << n << " mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin.ignore(i == 0 ? 0 : 1, '\n'); // clear buffer (hanya sekali cukup)
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    // Cari mahasiswa dengan IPK tertinggi
    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[indexMax].ipk) {
            indexMax = i;
        }
    }

    // Tampilkan mahasiswa dengan IPK tertinggi
    cout << "\n=== Mahasiswa dengan IPK tertinggi ===" << endl;
    cout << "Nama : " << mhs[indexMax].nama << endl;
    cout << "NIM  : " << mhs[indexMax].nim << endl;
    cout << "IPK  : " << mhs[indexMax].ipk << endl;

    return 0;
}
