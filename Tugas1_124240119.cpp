#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float IPK;
};

void tampilkanData(Mahasiswa* mhs, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << mhs[i].Nama << ", NIM: " << mhs[i].NIM << ", IPK: " << mhs[i].IPK << endl;
    }
}

int sequentialSearch(Mahasiswa* mhs, int n, string nim) {
    for (int i = 0; i < n; i++) {
        if (mhs[i].NIM == nim) {
            return i;
        }
    }
    return -1;
}

void quickSortNama(Mahasiswa* mhs, int low, int high) {
    if (low < high) {
        string pivot = mhs[high].Nama;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (mhs[j].Nama < pivot) {
                i++;
                swap(mhs[i], mhs[j]);
            }
        }
        swap(mhs[i + 1], mhs[high]);

        int pi = i + 1;
        quickSortNama(mhs, low, pi - 1);
        quickSortNama(mhs, pi + 1, high);
    }
}

void quickSortIPK(Mahasiswa* mhs, int low, int high) {
    if (low < high) {
        float pivot = mhs[high].IPK;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (mhs[j].IPK < pivot) {
                i++;
                swap(mhs[i], mhs[j]);
            }
        }
        swap(mhs[i + 1], mhs[high]);

        int pi = i + 1;
        quickSortIPK(mhs, low, pi - 1);
        quickSortIPK(mhs, pi + 1, high);
    }
}

void bubbleSort(Mahasiswa* mhs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mhs[j].IPK < mhs[j + 1].IPK) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }
}

int binarySearch(Mahasiswa* mhs, int l, int r, string nama) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mhs[mid].Nama == nama) {
            return mid;
        }
        if (mhs[mid].Nama < nama) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    Mahasiswa mhs[] = {
        {"Najmah", "124240001", 3.5},
        {"Melanie", "124240002", 3.6},
        {"Gracia", "124240003", 3.7},
        {"Winda", "124240004", 3.8},
        {"Danielle", "124240005", 3.9},
        {"Kanzler", "124240006", 3.4},
        {"Justin", "124240007", 3.3},
        {"Ziko", "124240008", 3.2},
        {"Meldie", "124240009", 3.1},
        {"Atlas", "124240010", 3}
    };
    int n = sizeof(mhs) / sizeof(mhs[0]);
    int pilihan;
    string cariNIM, cariNama;

    do {
        cout << "\n1. Tampilkan Mahasiswa\n";
        cout << "2. Cari Berdasarkan NIM\n";
        cout << "3. Cari Berdasarkan Nama\n";
        cout << "4. Sort IPK Mahasiswa (asc)\n";
        cout << "5. Sort IPK Mahasiswa (desc)\n";
        cout << "6. Exit\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            system("cls");
            cout << "Daftar Mahasiswa :\n";
            tampilkanData(mhs, n);
            break;
        case 2:
            system("cls");
            cout << "Masukkan NIM: ";
            cin >> cariNIM;
            if (sequentialSearch(mhs, n, cariNIM) != -1) {
                cout << "Name: " << mhs[sequentialSearch(mhs, n, cariNIM)].Nama << ", NIM: " << mhs[sequentialSearch(mhs, n, cariNIM)].NIM << ", IPK: " << mhs[sequentialSearch(mhs, n, cariNIM)].IPK << endl;
            } else {
                cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan." << endl;
            }
            break;
        case 3:
            system("cls");
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, cariNama);
            quickSortNama(mhs, 0, n - 1); // Binary Search membutuhkan data terurut
            if (binarySearch(mhs, 0, n - 1, cariNama) != -1) {
                cout << "Name: " << mhs[binarySearch(mhs, 0, n - 1, cariNama)].Nama << ", NIM: " << mhs[binarySearch(mhs, 0, n - 1, cariNama)].NIM << ", IPK: " << mhs[binarySearch(mhs, 0, n - 1, cariNama)].IPK << endl;
            } else {
                cout << "Mahasiswa dengan Nama " << cariNama << " tidak ditemukan." << endl;
            }
            break;
        case 4:
            system("cls");
            quickSortIPK(mhs, 0, n - 1);
            tampilkanData(mhs, n);
            cout << "Mahasiswa telah diurutkan berdasarkan IPK (ascending)\n";
            break;
        case 5:
            system("cls");
            bubbleSort(mhs, n);
            tampilkanData(mhs, n);
            cout << "Mahasiswa telah diurutkan berdasarkan IPK (descending)\n";
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
