#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {7, 2, 9, 6, 1};
    
    sort(v.begin(), v.end(), [](int x, int y)->bool{ return x > y; });
    for_each(v.begin(), v.end(), [](int n){cout << n <<' ';});
    cout << endl;
}