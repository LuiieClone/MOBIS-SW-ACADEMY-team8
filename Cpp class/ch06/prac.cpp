#include <iostream>
#include <string>
using namespace std;

int GetMin(int n, int m)
{
    int min;
    if(n > m)
        min = m;
    else
        min = n;
    return n;
}
double GetMin(double n, double m)
{
    double min;
    if(n > m)
        min = m;
    else
        min = n;
    return n;
}

string GetMin(char *n, char *m)
{
    string s1 = n;
    string s2 = m;
    string result = s1 < s2 ? s1 : s2;
    
    return result;
    
}

int GetMin(int a[], int size)
{
    int m = a[0];
    for(int i=1 ; i<=size ; i++)
    {
        if(m > a[i])
            m = a[i];
    }
    return m;
}


int main()
{
    int a, b;
    cout << "두개의 정수를 입력하세요 : ";
    cin >> a >> b;
    cout << "최소값은 " << GetMin(a, b) << "입니다.\n";

    double c, d;
    cout << "두개의 실수를 입력하세요 : ";
    cin >> c >> d;
    cout << "최소값은 " << GetMin(c, d) << "입니다.\n";

    char s1[20], s2[20];
    cout << "두개의 문자열을 입력하세요 : ";
    cin >> s1 >> s2;
    cout << "최소값은 " << GetMin(s1, s2) << "입니다.\n";

    int arr[] = {2, 19, 34, 387, 1, 45, 78, 45, 11, 29};
    cout << "배열의 원소 : ";
    for(int i = 0 ; i < 10 ; i++)
        cout << arr[i] << " ";
    cout << "\n최소값은 " << GetMin(arr, 10) << "입니다.\n";

    return 0;
}