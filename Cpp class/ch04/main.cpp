#include <iostream>
using namespace std;

int main()
{
    int n = 3;

    int *p = new int[n];
    if(!p)
        cout << "Wrong!" << endl;
    
    for(int i=0 ; i<n ; i++)
    {
        cout << "Enter the integer: ";
        cin >> p[i];
    }

    int sum = 0;
    for(int i=0 ; i<n ; i++)
    {
        sum += p[i];
    }
    cout << "sum: "<< sum << endl;  
    cout << "avg " << sum/n << endl;  

    delete [] p;

    return 0;
}