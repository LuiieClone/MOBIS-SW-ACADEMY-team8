#include <iostream>
using namespace std;

int sum(int n)
{
    int sum = 0;
    for(int i=1 ; i<=n ; i++)
        sum += i;
    return sum;
}
int sum(int n, int m)
{
    int sum = 0;
    for(int i=n ; i<=m ; i++)
        sum += i;
    return sum;
    
}
int sum(int a[], int size)
{
    int sum = 0;
    for(int i=0 ; i<size ; i++)
        sum += a[i];
    return sum;
    
}

int main() {
    cout << sum(5) << endl;
    cout << sum(10, 20) << endl;
    int a[3] = {1, 3, 6};
    cout << sum(a, 3) << endl;
}