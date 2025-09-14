#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n];

    // Input matriks 3x3
    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
        }
    }

    // Tampilkan matriks
    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    // Hitung jumlah diagonal utama (↘)
    int jumlahDiagonalUtama = 0;
    for (int i = 0; i < n; i++) {
        jumlahDiagonalUtama += matriks[i][i];
    }

    // Hitung jumlah diagonal sekunder (↙)
    int jumlahDiagonalSekunder = 0;
    for (int i = 0; i < n; i++) {
        jumlahDiagonalSekunder += matriks[i][n - i - 1];
    }

    // Total kedua diagonal
    int total = jumlahDiagonalUtama + jumlahDiagonalSekunder;

    cout << "\nJumlah diagonal utama    = " << jumlahDiagonalUtama << endl;
    cout << "Jumlah diagonal sekunder = " << jumlahDiagonalSekunder << endl;
    cout << "Total keduanya           = " << total << endl;

    return 0;
}
