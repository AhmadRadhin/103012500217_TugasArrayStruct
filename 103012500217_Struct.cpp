#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 40;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
};

int main() {
    Mahasiswa mahasiswa[N];
    string cari;
    ifstream file("list_absensi.txt");

    if (!file) {
        cout << "File tidak ditemukan.\n";
        return 1;
    }

    string line;
    getline(file, line);

    for (int i = 0; i < N; i++) {
        getline(file, mahasiswa[i].nim, ',');
        getline(file, mahasiswa[i].nama, ',');
        getline(file, line);
        mahasiswa[i].persentaseKehadiran = stof(line);
    }
    file.close();

    cout << "=== DAFTAR MAHASISWA ===\n";
    for (int i = 0; i < N; i++)
        cout << i + 1 << " | " << mahasiswa[i].nim << " | "
             << mahasiswa[i].nama << " | "
             << mahasiswa[i].persentaseKehadiran << "%\n";
    cout << "Total Mahasiswa: " << N << "\n";

    cout << "\nCari NIM: ";
    cin >> cari;

    for (int i = 0; i < N; i++) {
        if (mahasiswa[i].nim == cari) {
            cout << "Data ditemukan: " << mahasiswa[i].nama << " | "
                 << mahasiswa[i].persentaseKehadiran << "%\n";

            cout << "Kehadiran baru: ";
            cin >> mahasiswa[i].persentaseKehadiran;

            cout << "Setelah update: " << mahasiswa[i].nama << " | "
                 << mahasiswa[i].persentaseKehadiran << "%\n";
            return 0;
        }
    }

    cout << "Data tidak ditemukan.\n";
    return 0;
}