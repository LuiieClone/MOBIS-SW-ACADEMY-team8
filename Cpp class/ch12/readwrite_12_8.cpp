#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* file = "sawon.txt";
    ifstream fin;
    fin.open(file, ios::in | ios::binary);

    if(!fin) {
        cout << 'ERROR!' << endl;
    }
    int count = 0;
    char s[32];
    while(true) {
        fin.read(s, 32);
        int n = fin.gcount();
        cout.write(s, n);

        count += n;
    }
    cout << "바이트 수: " << count << endl;
}