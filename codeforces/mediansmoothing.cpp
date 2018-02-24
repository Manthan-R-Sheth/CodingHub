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
#include<functional>
#include<cstring>
#include<climits>
using namespace std;

const int MAXN = 505050;

int N;
int arr[MAXN];

int modify(int l, int r)
{
  if(l == r) return 0;
  if(arr[l] == arr[r])
  {
    for(int i=l+1; i<r; i++)
      arr[i] = arr[l];
    return (r-l)/2;
  }
  else
  {
    int m = (l+r+1)/2;
    for(int i=l+1; i<m; i++)
      arr[i] = arr[l];
    for(int i=m; i<r; i++)
      arr[i] = arr[r];
    return (r-l-1)/2;
  }
}

int main()
{
  cin>>N;
  for(int i=0; i<N; i++)
    cin>>arr[i];

  int ans = 0;
  int lb = 0;
  for(int i=0; i<N; i++)
  {
    if(i == N-1 || arr[i] == arr[i+1])
    {
      ans = max(ans, modify(lb, i));
      lb = i+1;
    }
  }

  cout<<ans<<"\n";
  for(int i=0; i<N; i++)
    cout<<arr[i]<<(i==N-1 ? "\n" : " ");

  return 0;
}