#include <iostream>
#include <string>
using namespace std;

// Struktur Node Linked List
struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

// Pointer awal linked list
Node* head = nullptr;

// NIM dan Personalisasi
const int NIM_AKHIR = 83;  // dua digit terakhir NIM
const int POS_SISIP = 4;   // digit terakhir (3) + 1 = 4

// Fungsi Tambah Item Baru (ke akhir)
void tambahItem(string nama, string tipe) {
    Node* baru = new Node{nama, NIM_AKHIR, tipe, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << NIM_AKHIR << "!\n";
}

// Fungsi Sisipkan Item di posisi tertentu (POS_SISIP)
void sisipItem(string nama, string tipe) {
    Node* baru = new Node{nama, NIM_AKHIR, tipe, nullptr};

    if (head == nullptr || POS_SISIP == 1) {
        baru->next = head;
        head = baru;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < POS_SISIP - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Posisi melebihi panjang list, item ditambahkan di akhir.\n";
            tambahItem(nama, tipe);
            delete baru; // karena tambahItem sudah buat baru
            return;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << POS_SISIP << "!\n";
}

// Fungsi Hapus Item Terakhir
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

// Fungsi Gunakan Item
void gunakanItem(string nama) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Item \"" << nama << "\" digunakan! Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "Jumlah item habis, \"" << nama << "\" dihapus dari inventory.\n";
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

// Fungsi Tampilkan Inventory
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=========== INVENTORY ===========\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "=================================\n";
}

// MAIN PROGRAM
int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "\n+----------------------------------------------------------------------+\n";
        cout << "|                    GAME INVENTORY MANAGEMENT                         |\n";
        cout << "|          Muhammad Rayhan Setiawan - 2409106083                       |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                                  |\n";
        cout << "| 2. Sisipkan Item                                                     |\n";
        cout << "| 3. Hapus Item Terakhir                                               |\n";
        cout << "| 4. Gunakan Item                                                      |\n";
        cout << "| 5. Tampilkan Inventory                                               |\n";
        cout << "| 0. Keluar                                                            |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                cin >> nama;
                cout << "Masukkan tipe item: ";
                cin >> tipe;
                sisipItem(nama, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                cin >> nama;
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
