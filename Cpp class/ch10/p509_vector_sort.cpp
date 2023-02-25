#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> sv; // 문자열 벡터 생성

    cout << "5개 정수 입력" << endl;
    for(int n=0 ; n<5 ; n++) { // 한 줄에 한 개씩 5 개의 이름을 입력받는다.
        int m;
        cout << ">>";
        cin >> m;
        sv.push_back(m);
    }
    
    sort(sv.begin(), sv.end());

    vector<int>::iterator it;
    for(it=sv.begin() ; it!=sv.end() ; it++){
        cout << *it << " " << endl;
    }
    
}