#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("song.txt");
    if(!fout){
        cout << "fail to open the file!" << endl;
    }
    int year = 2023;
    char singer[] = "ketty";
    char song[] = "firework";

    fout << year << '\n';
    fout << singer << endl;
    fout << song << endl;

    fout.close();
    return 0;
}