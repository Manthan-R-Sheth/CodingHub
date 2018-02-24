#include<map>
#include<set>
#include<list>
#include<cmath>
#include<iomanip>
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
long long ans;
void computeLPSArray(string pat, unsigned long long M, unsigned long long lps[])
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}

void KMPSearch(string pat, string txt,unsigned long long M,unsigned long long N)
{
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M+1];
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        ans++;
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    cout<<ans<<endl;
}

int main()
{
	ans=0;
	int n,m;
	cin>>n>>m;
	string pat="",txt="";
	for(int i=0;i<n;i++)
	{	
		int len;
		char ch,let;
		cin>>len>>ch>>let;
		string letter(len,let);
		txt.append(letter);
	}
	for(int i=0;i<m;i++)
	{
		int len;
		char ch,let;
		cin>>len>>ch>>let;
		string letter(len,let);
		pat.append(letter);
	}
	unsigned long long N=txt.length();
	unsigned long long M=pat.length();
	KMPSearch(pat,txt,M,N);
}