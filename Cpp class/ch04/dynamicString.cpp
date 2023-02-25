#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string address("Goyang-si");
    string copyAddress(address);

    char text[] = {'C', 'a', 't'};
    string title(text);
    bool ans = (address == copyAddress);
    cout << str << ": empty string" << endl;
    cout << ans << ": address == copyAddress string" << endl;
    cout << title << ": char array to string" << endl;
    return 0;
}