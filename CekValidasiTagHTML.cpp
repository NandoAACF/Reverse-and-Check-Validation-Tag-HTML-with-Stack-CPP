// Program cek validasi tag HTML
// Nama: Agustinus Angelo Christian Fernando
// NIM: 21/473804/TK/52235
// Laporan dan Petunjuk sudah saya lampirkan di file PDF
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> inputHTML() { 
    
    vector<string> tags;

    // Mengambil input dari file html
    // Masukkan nama file di dalam tanda petik tersebut
    fstream input("input.html"); 

    while (input) { 
        string line;
        // Mengambil setiap code html dari file external dan dimasukkan ke string lines
        getline(input, line);

        int position = 0; 
        // Mencari '<'
        int awal = line.find("<", position); 
        
        // Looping untuk mengolah string sebelum di cek valid atau tidaknya
        while (awal!=string::npos) { 
            int akhir = line.find(">", awal+1); 
            tags.push_back(line.substr(awal, akhir-awal+1)); 
            position = akhir + 1; 
            awal = line.find("<", position);
        }
    }

    // Menutup file
    input.close();

    return tags; 
}

// Mengecek kecocokan tag pembuka dan penutup HTML
bool cekValid(const vector<string>& tags) { 
    
    // Inisialisasi variabel stack
    stack<string> Stack; 

    // Membuat alias dengan nama Iterator
    typedef vector<string>::const_iterator Iterator; 

    // Looping untuk pengecekan valid atau tidaknya tag
    for (Iterator i = tags.begin(); i != tags.end(); ++i) {
        // Jika pada karakter ke-1 tidak ada tanda '/', maka push ke stack
        if (i->at(1) != '/') {
            Stack.push(*i); 
        }
        else{
            // Jika stack kosong, maka return false
            if (Stack.empty()) {
                return false;
            }

            // Menyiapkan string open dan close untuk dibandingkan jumlahnya
            string open = Stack.top().substr(1); 
            string close = i->substr(2); 
            
            // Jika jumlah karakter string open dan close TIDAK sama, maka return false
            if (open.compare(close) != 0){ 
                return false;
            } 
            // Jika sama, maka lakukan operasi pop pada stack
            else{
                Stack.pop();
            } 
        }
    }

    // Jika stack kosong, maka tag HTML nya sudah betul
    if (Stack.empty()) {
        return true; 
    }
    // Jika stack ada isinya, maka tag HTML nya masih salah
    else{
        return false; 
    }
}

int main() {

    // Memberikan informasi kepada user, apakah tag pembuka dan penutup HTML nya sudah sesuai atau belum
    // Jika ADA tanda '/' pada tag penutup dan tag penutup sudah BALANCE dengan tag pembuka, maka sistem akan memberitahu user bahwa tag HTML VALID
    if(cekValid(inputHTML())){
        cout<<"============================================="<<endl;
        cout<<"Semua tag pada file HTML tersebut sudah VALID"<<endl;
        cout<<"============================================="<<endl;
    }
    // Jika TIDAK ada tanda '/' pada tag penutup atau tag penutupnya bahkan TIDAK ada, maka sistem akan memberitahu user bahwa tag HTML TIDAK VALID
    else{
        cout<<"======================================="<<endl;
        cout<<"Tag pada file HTML tersebut TIDAK VALID"<<endl;
        cout<<"======================================="<<endl;
    }

    return 0;
}