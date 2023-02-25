#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("song.txt");
    if(!fin){
        cout << "fail to open the file!" << endl;
        return 0;
    }
    
    char name[20], song[20];
    int year;

    fin >> year;
    fin >> name;
    fin >> song;

    cout << "year: " << year << endl;
    cout << "name: " << name << endl;
    cout << "song: " << song << endl;

    fin.close();
    return 0;
}