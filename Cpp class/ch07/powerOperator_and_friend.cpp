#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;  
public:
    Power(int kick=0, int punch=0)
    {
    this->kick = kick; this->punch = punch;    
    }
    //프렌드 선언
    friend Power operator+(int op1, Power op2);
    void show();
    Power operator+ (int op2);
    Power& operator+= (Power op2);
};

void Power::show() {
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(int op2) {
    Power tmp; // 임시 객체 생성
    tmp.kick = kick + op2; // kick 더하기
    tmp.punch = punch + op2; // punch 더하기
    return tmp; // 더한 결과 리턴
}

Power& Power::operator+=(Power op2) {
    kick = kick + op2.kick; // kick 더하기
    punch = punch + op2.punch; // punch 더하기
    return *this; // 더한 결과 리턴
}

//연산자 오버로딩과 프렌드
Power operator+(int op1, Power op2) {
    Power tmp; // 임시 객체 생성
    tmp.kick = op1 + op2.kick; // kick 더하기
    tmp.punch = op1 + op2.punch; // punch 더하기
    return tmp; // 임시 객체 리턴
}

int main()
{
    Power p1(10, 100);
    Power p2(1000, 10000);
    Power tmp;

    tmp = p1 + 2;
    tmp.show(); //kick=12,punch=102

    return 0;
}