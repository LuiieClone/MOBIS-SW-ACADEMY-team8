#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int m = 9;
    int n = 2;
    swap(m, n);
    cout << m << '\t' << n << '\t' << endl;
}