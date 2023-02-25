#include <iostream>
#include <fstream>
using namespace std;


int main() {
    const char* firstFile = "song.txt";
    const char* secondFile = "/home/mobis/.bashrc";

    fstream fout(firstFile, ios::out | ios::app); // 쓰기 모드로 파일 열기
    if(!fout) { // 열기 실패 검사
        cout << firstFile << " 열기 오류";
        return 0;
    }

    fstream fin(secondFile, ios::in); // 읽기 모드로 파일 열기
    if(!fin) { // 열기 실패 검사
        cout << secondFile << " 열기 오류";
        return 0;
    }
    
    string line;
    ifstream fin2("/home/mobis/.bashrc");
    while (getline(fin2, line)){
        cout << line <<endl;
    }
/*
    int c;
    char buf[81];
    while(fin.getline(buf, 81)) { // 파일 끝까지 문자 읽기
        cout << buf <<endl;
    };
*/
    fin.close(); // 입력 파일 닫기
    fout.close(); // 출력 파일 닫기
}