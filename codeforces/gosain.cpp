#include<bits/stdc++.h>
using namespace std;

#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long

vector<pair<ll,int> > s,t;
char str[100];
vector<ll> pat,txt;
int M,N,lps[200010];
vector<int> pos;
void computeLPSArray();

void KMPSearch()
{
    
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray();

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
        pos.PB(i-j);
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
}

void computeLPSArray()
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
pair<ll,int> parse()
{
	int l=strlen(str),i;
	ll num=0;
	for(i=0;i<l-2;i++)
		num=num*10+str[i]-'0';
	return MP(num,str[l-1]-'a');
}
ll Hash(ll num,int ch)
{
	return num*26+ch; 
}
int main()
{
	int n,m,i;
	sd(n);sd(m);
	int ch;
	ll num=0;
	pair<ll,int> p;
	
	ss(str);
	p=parse();
	num=p.F;
	ch=p.S;
	for(i=1;i<n;++i)
	{
		ss(str);
		p=parse();
		if(p.S!=ch)
		{
			t.PB(MP(num,ch));
			num=p.F;
			ch=p.S;
		}
		else
			num+=p.F;
	}
	t.PB(MP(num,ch));
	
	ss(str);
	p=parse();
	num=p.F;
	ch=p.S;
	for(i=1;i<m;++i)
	{
		ss(str);
		p=parse();
		if(p.S!=ch)
		{
			s.PB(MP(num,ch));
			num=p.F;
			ch=p.S;
		}
		else
			num+=p.F;
	}
	s.PB(MP(num,ch));
	m=s.size();
	n=t.size();
	if(s.size()==1)
	{
		ll ans=0;
		for(i=0;i<n;++i)
			if(t[i].F>=s[0].F&&t[i].S==s[0].S)
				ans=ans+t[i].F-s[0].F+1;
		printf("%lld\n",ans);
		return 0;
	}
	if(s.size()==2)
	{
		ll ans=0;
		for(i=0;i<n-1;i++)
			if(t[i].S==s[0].S&&t[i+1].S==s[1].S)
				if(t[i].F>=s[0].F&&t[i+1].F>=s[1].F)
					ans++;
		printf("%lld\n",ans);
		return 0;
	}
	
	for(i=1;i<m-1;i++)
		pat.PB(Hash(s[i].F,s[i].S));
	for(i=0;i<n;i++)
		txt.PB(Hash(t[i].F,t[i].S));
	M=pat.size();
	N=txt.size();
	KMPSearch();
	ll ans=0;
	for(i=0;i<pos.size();++i)
		if(pos[i]&&pos[i]+M<N)
			if(t[pos[i]-1].S==s[0].S&&t[pos[i]+M].S==s[m-1].S)
				if(t[pos[i]-1].F>=s[0].F&&t[pos[i]+M].F>=s[m-1].F)
					ans++;
	printf("%lld\n",ans);
}