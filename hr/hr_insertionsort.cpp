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
#include<vector>
#include<cstdlib>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
void insertionSort(vector <int>  ar) 
{
    int ans=ar[ar.size()-1];
    int j=ar.size()-2;
    while(j>=0 && ar[j]>=ans)
    {
        ar[j+1]=a[j];
        j--;
        for(int i=0;i<ar.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    a[j+1]=ans;
    for(int i=0;i<ar.size();i++)
            cout<<ar[i]<<" ";
        cout<<endl;

}
int main(void)
{
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    insertionSort(_ar);
    return 0;
}
