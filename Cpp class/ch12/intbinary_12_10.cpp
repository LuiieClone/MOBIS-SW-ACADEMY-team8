#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char* file = "song.txt";
    ofstream fout;
    
    fout.open(file, ios::in | ios::binary);
    if(!fout) {
        cout << 'ERROR!' << endl;
    }

    int n[] = {0, 1, 2, 3, 4};
    double d = 3.14;
    fout.write((char*)n, sizeof(n));
    fout.write((char*)&d, sizeof(d));
    fout.close();
    
    ifstream fin(file, ios::in | ios::binary);
    if(!fin) {
        cout << 'ERROR!' << endl;
    }
    
    fin.read((char*)n, sizeof(n));
    fin.read((char*)&d, sizeof(d));
    for(int i=0 ; i<10 ; i++)
        cout << n[i] << ' ';
    cout << endl;
    fin.close();
}