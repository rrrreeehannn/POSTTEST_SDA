#include <iostream>
#include <string>
using namespace std;

// Struktur Node Double Linked List
struct Node {
    int id;              // ID unik item
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
    Node* prev;
};

// Pointer awal dan akhir
Node* head = nullptr;
Node* tail = nullptr;

// Personalisasi
const int NIM_AKHIR = 83;   // dua digit terakhir NIM
const int POS_SISIP = 4;    // digit terakhir (3) + 1 = 4
int autoID = 1;             // auto increment ID

// Fungsi Tambah Item Baru (ke akhir)
void tambahItem(string nama, string tipe) {
    Node* baru = new Node{autoID++, nama, NIM_AKHIR, tipe, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << NIM_AKHIR << "!\n";
}

// Fungsi Sisipkan Item di posisi tertentu
void sisipItem(string nama, string tipe) {
    Node* baru = new Node{autoID++, nama, NIM_AKHIR, tipe, nullptr, nullptr};

    if (head == nullptr || POS_SISIP == 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
    } else {
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < POS_SISIP - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr || temp->next == nullptr) {
            // Tambahkan di akhir
            tambahItem(nama, tipe);
            delete baru; // karena tambahItem sudah membuat node baru
            return;
        }
        baru->next = temp->next;
        baru->prev = temp;
        temp->next->prev = baru;
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << POS_SISIP << "!\n";
}

// Fungsi Hapus Item Terakhir
void hapusItemTerakhir() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Node* hapus = tail;
    tail = tail->prev;
    if (tail != nullptr) tail->next = nullptr;
    else head = nullptr;
    delete hapus;
}

// Fungsi Gunakan Item
void gunakanItem(string nama) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->namaItem == nama) {
            temp->jumlah--;
            cout << "Item \"" << nama << "\" digunakan! Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "Jumlah item habis, \"" << nama << "\" dihapus dari inventory.\n";
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan!\n";
}

// Fungsi Tampilkan Inventory dari depan
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=========== INVENTORY (Depan -> Belakang) ===========\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". ID: " << temp->id 
             << " | Nama: " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->next;
    }
    cout << "=====================================================\n";
}

// Fungsi Tampilkan Inventory dari belakang
void tampilkanDariBelakang() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=========== INVENTORY (Belakang -> Depan) ===========\n";
    Node* temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". ID: " << temp->id 
             << " | Nama: " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << "\n";
        temp = temp->prev;
    }
    cout << "=====================================================\n";
}

// Fungsi Cari Item berdasarkan ID atau Nama
void cariDetailItem() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "Cari berdasarkan (1 = ID, 2 = Nama): ";
    int pilihan;
    cin >> pilihan;

    if (pilihan == 1) {
        int idCari;
        cout << "Masukkan ID: ";
        cin >> idCari;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == idCari) {
                cout << "Detail Item -> ID: " << temp->id
                     << ", Nama: " << temp->namaItem
                     << ", Jumlah: " << temp->jumlah
                     << ", Tipe: " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item dengan ID " << idCari << " tidak ditemukan!\n";
    } else if (pilihan == 2) {
        string namaCari;
        cout << "Masukkan Nama Item: ";
        cin >> namaCari;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->namaItem == namaCari) {
                cout << "Detail Item -> ID: " << temp->id
                     << ", Nama: " << temp->namaItem
                     << ", Jumlah: " << temp->jumlah
                     << ", Tipe: " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item \"" << namaCari << "\" tidak ditemukan!\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    }
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
        cout << "| 5. Tampilkan Inventory (Depan -> Belakang)                           |\n";
        cout << "| 6. Tampilkan Inventory (Belakang -> Depan)                           |\n";
        cout << "| 7. Cari Detail Item (berdasarkan ID/Nama)                            |\n";
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
            case 6:
                tampilkanDariBelakang();
                break;
            case 7:
                cariDetailItem();
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
