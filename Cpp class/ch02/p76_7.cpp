#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first_name, last_name;
    getline(cin, first_name);
    cin >> last_name;
    cout << first_name + " " + last_name << endl;
    return 0;
}