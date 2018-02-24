#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<limits>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
int q = l ^ r, a = 1;
    while(q){
        q /= 2;
        a <<= 1;
    }
    return --a;
}

int main() {
    int res;
    int l;
    cin >> l;
    
    int r;
    cin >> r;
    
    res = maxXor(l, r);
    cout << res;
    
    return 0;
}
