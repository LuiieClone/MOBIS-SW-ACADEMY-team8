#include <iostream>
using namespace std;

int mult(int x, int y) {
    if( x<0 || y<0 ){
        throw "NO NEGATIVE";}
    else
        return x*y;
}

// int max(int x, int y) throw(int) {
//     if(x < 0) throw x;
//     else if(y < 0) throw y;
//     else if(x > y) return x;
//     else return y;
// }

int main() {
    int n = mult(8, -7);
    int m = max(50, 60);
    try {
        cout << n << endl;
    }
    catch(const char* neg) {
        cout << "Error " << neg;
    }
}