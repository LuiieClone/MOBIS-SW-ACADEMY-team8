#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the address: ";

    char address[100];
    cin.getline(address, 100, '\n');
    cout << "address: " << address << endl;
    return 0;
}