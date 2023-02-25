#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int me, computer = rand()%3;
    cout << "가위(0), 바위(1), 보(2): ";
    cin >> me;

    if (me - computer == 0)
        cout << "비겼습니다!" << endl;
    else if ((me > computer) or (abs(me - computer) > 1))
    {
        cout << "이겼습니다!" << endl;
        cout << "me: " << me << " computer: " << computer << endl;
    }
    else
    {
        cout << "졌습니다..." << endl;
        cout << "me: " << me << " computer: " << computer << endl;
    }
    return 0;
}