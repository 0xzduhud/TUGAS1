#include <iostream>
#include <string>
using namespace std;

struct roti {
    string nama;
    int code;
    int harga;
};

roti daftarRoti[] = {
    {"Roti Bakar", 187, 6000},
    {"Roti Kukus", 223, 7000},
    {"Roti Tawar", 156, 4000},
    {"Roti Panggang", 895, 5000},
    {"Roti Keju", 378, 9000}
};

int jmlData = sizeof(daftarRoti) / sizeof(daftarRoti[0]);

void tampilanData() {
    system("cls");
    roti *ptr_daftarRoti = daftarRoti;
    cout << "Tampilkan Data Roti" << endl;
    cout << "===============================" << endl;
    cout << "No\tNama\t\tKode\tHarga" << endl;
    cout << "===============================" << endl;
    for (int i = 0; i < jmlData; i++) {
        cout << i + 1 << "\t" << (ptr_daftarRoti + i)->nama << "\t" 
             << (ptr_daftarRoti + i)->code << "\t" << (ptr_daftarRoti + i)->harga << endl;
    }
    cout << "===============================" << endl;
}

void sequentialSearch() {
    int cariRoti;
    cout << "Masukkan kode yang dicari: ";
    cin >> cariRoti;
    
    bool ditemukan = false;
    for (int i = 0; i < jmlData; i++) {
        if (cariRoti == daftarRoti[i].code) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama: " << daftarRoti[i].nama << endl;
            cout << "Kode: " << daftarRoti[i].code << endl;
            cout << "Harga: " << daftarRoti[i].harga << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void binarySearch() {
    string cariRoti;
    cout << "Masukkan Nama yang dicari: ";
    cin >> ws;
    getline(cin, cariRoti);
    
    int low = 0, high = jmlData - 1;
    bool ditemukan = false;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (daftarRoti[mid].nama == cariRoti) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama: " << daftarRoti[mid].nama << endl;
            cout << "Kode: " << daftarRoti[mid].code << endl;
            cout << "Harga: " << daftarRoti[mid].harga << endl;
            ditemukan = true;
            break;
        } else if (cariRoti < daftarRoti[mid].nama) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = daftarRoti[high].harga;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (daftarRoti[j].harga < pivot) {
                i++;
                swap(daftarRoti[i], daftarRoti[j]);
            }
        }
        swap(daftarRoti[i + 1], daftarRoti[high]);
        int pi = i + 1;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void bubbleSort() {
    for (int i = 0; i < jmlData - 1; i++) {
        for (int j = 0; j < jmlData - i - 1; j++) {
            if (daftarRoti[j].harga < daftarRoti[j + 1].harga) {
                swap(daftarRoti[j], daftarRoti[j + 1]);
            }
        }
    }
}

int main() {
    int pilihan;
    char menuKembali;
    
    do {
        cout << "MENU PILIHAN : " << endl;
        cout << "1. Tampilkan Data Roti" << endl;
        cout << "2. Cari Data Roti Berdasarkan Kode" << endl;
        cout << "3. Cari Data Roti Berdasarkan Nama" << endl;
        cout << "4. Mengurutkan Data Roti secara Ascending Berdasarkan Harga" << endl;
        cout << "5. Mengurutkan Data Roti secara Descending Berdasarkan Harga" << endl;
        cout << "6. Keluar" << endl;
        cout << "===============================" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        cin.ignore();
        cout << "===============================" << endl;

        switch (pilihan) {
            case 1:
                tampilanData();
                break;
            case 2:
                sequentialSearch();
                break;
            case 3:
                
                binarySearch();
                break;
            case 4:
                quickSort(0, jmlData - 1);
                tampilanData();
                break;
            case 5:
                bubbleSort();
                tampilanData();
                break;
            case 6:
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        cout << "Kembali ke menu? (y/n) : ";
        cin >> menuKembali;
        cin.ignore();
    } while (menuKembali == 'y' || menuKembali == 'Y');

    return 0;
}
