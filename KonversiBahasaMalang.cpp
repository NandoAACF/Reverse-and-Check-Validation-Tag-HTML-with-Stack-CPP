// Program untuk menerjemahkan bahasa slang dari Kota Malang
// Nama: Agustinus Angelo Christian Fernando
// NIM: 21/473804/TK/52235
// Laporan dan Petunjuk sudah saya lampirkan di file PDF
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <sstream>

using namespace std;

// Fungsi untuk membentuk kata/kalimat dalam kondisi reverse dengan memanfaatkan Stack
void reverse(string &str)
{
    // Mendeklarasikan Stack
    stack<int> Stack;
 
    // Memasukkan setiap huruf ke dalam Stack
    for (char huruf: str) {
        Stack.push(huruf);
    }
 
    // Looping untuk memindahkan huruf dari belakang ke depan
    for (int i = 0; i < str.length(); i++) {
        // Memasukkan huruf teratas dari stack ke variabel str urutan ke i sehingga tertata dalam kondisi reverse
        str[i] = Stack.top();
        // Menghapus huruf dari stack yang sudah dipindahkan ke variabel str
        Stack.pop();

        // Selection agar "ng" TIDAK dikonversi menjadi "gn"
        // Jika hasil reversenya adalah "gn", maka akan dikembalikan menjadi "ng" dengan metode swap
        if(str[i-1]=='g' && str[i]=='n'){
            char temp;
            // Melakukan swap untuk mengembalikan urutan semula 'n' dan 'g' sehingga tidak dibalik
            temp = str[i-1];
            str[i-1] = str[i];
            str[i] = temp;
            // Maka, hasil konversi dari "malang" adalah "ngalam"
        }
    }
    // Melakukan display hasil
    cout<<str;
}

// Untuk memproses kata per kata sehingga "arek malang" diubah menjadi "kera ngalam"
void split(string str) 
{
    // Memanfaatkan library string stream untuk memisah kedua kata
    istringstream ss(str);
    string kata; 
    
    // Memproses reverse untuk setiap kata, satu per satu
    while (ss >> kata) {
        reverse(kata);
        cout << " ";
    }
    // Maka, hasil konversi dari "arek malang" adalah "kera ngalam"
}
 
int main() 
{
    // Deklarasi variabel yang dibutuhkan
    string str;
    int choice;
    
    // Menu yang sudah sesuai dengan ketentuan di soal
    cout<<"=========================="<<endl;
    cout<<"Menu: "<<endl;
    cout<<"1. Konversi bahasa Malang"<<endl;
    cout<<"2. Selesai"<<endl;
    cout<<"=========================="<<endl;
    cout<<"Masukkan kode menu: ";
    cin >> choice;
    
    // Selection untuk menu nomor 1 dan 2
    switch (choice)
    {
    // Case jika pengguna memilih menu nomor 1
    case 1:
        // Tempat bagi pengguna untuk menginputkan kata / kalimat yang ingin direverse sesuai bahasa slang Malang
        cout<<"===================================="<<endl;
        cout<<"Masukkan kata / kalimat: ";
        getline(cin>>ws, str);
        cout<<"===================================="<<endl;
        cout<<"Hasilnya = ";
        // Menampilkan hasil kata/kalimat yang sudah diproses di fungsi reverse dan fungsi split
        split(str);
        cout<<"\n";
        cout<<"Tunggu 3 detik untuk kembali ke menu utama..."<<endl;
        // Program akan menunggu selama 3 detik sebelum kembali ke bagian menu utama
        sleep(3);
        // Mengarahkan program untuk kembali ke bagian awal fungsi main
        main();
        break;
    
    // Case jika pengguna memilih menu nomor 2 (untuk mengakhiri program)
    case 2:
        // Display ucapan terima kasih karena telah menggunakan program ini
        cout<<"=========================================="<<endl;
        cout<<"Terima kasih telah menggunakan program ini"<<endl;
        cout<<"=========================================="<<endl;
        break;

    // Case jika pengguna menginput angka yang salah
    default:
        // Memberitahu pengguna bahwa kode angka yang dimasukkan salah
        cout<<"Kode angka yang Anda masukkan salah!"<<endl;
        // Mengarahkan program untuk kembali ke bagian awal fungsi main
        // Tujuannya agar pengguna bisa menginputkan kembali kode angka yang benar
        main();
        break;
    }
 
    return 0;
}