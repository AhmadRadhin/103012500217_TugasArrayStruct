#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 40;

int main() {
    string nim[N], nama[N], cari;
    float persentaseKehadiran[N];
    ifstream file("list_absensi.txt");

    if (!file) {
        cout << "File tidak ditemukan.\n";
        return 1;
    }

    string line;
    getline(file, line);

    for (int i = 0; i < N; i++) {
        getline(file, nim[i], ',');
        getline(file, nama[i], ',');
        getline(file, line);
        persentaseKehadiran[i] = stof(line);
    }
    file.close();

    cout << "=== DAFTAR MAHASISWA ===\n";
    for (int i = 0; i < N; i++)
        cout << i + 1 << " | " << nim[i] << " | " << nama[i]
             << " | " << persentaseKehadiran[i] << "%\n";
    cout << "Total Mahasiswa: " << N << "\n";

    cout << "\nCari NIM: ";
    cin >> cari;

    for (int i = 0; i < N; i++) {
        if (nim[i] == cari) {
            cout << "Data ditemukan: " << nama[i] << " | "
                 << persentaseKehadiran[i] << "%\n";

            cout << "Kehadiran baru: ";
            cin >> persentaseKehadiran[i];

            cout << "Setelah update: " << nama[i] << " | "
                 << persentaseKehadiran[i] << "%\n";
            return 0;
        }
    }

    cout << "Data tidak ditemukan.\n";
    return 0;
}