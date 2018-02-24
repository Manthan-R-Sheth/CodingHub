#include<bits/stdc++.h>
#define maxn 100005
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define plld(t) printf("%lld\n",t)
#define fo(i,n) for(long long i=0;i<n;i++)
 
using namespace std;

char c[1000000]; 
long long ml[1000000];
long long cod[1000000];
long long MAX=100003;
long long pr[1000000];
bool v[100003];
int len, sp[100003];

long long maxim(long long a,long long b)
{
    return(a>b)?a:b;
}
 
long long mini(long long a,long long b )
{
    return (a>b)?b:a;
 
}
 
void check()
{
    for(int i=1;i<=3;i++)
    {
        ml[i]=1;
        cod[i]=i;
    }
    for(int i=4;i<=100000;i++)
    {
           if(sp[i]!=i)
           {
            int t1=sp[i];
            int t2=i/sp[i];
            ml[i]=ml[t1]+ ml[t2];
            cod[i]=cod[t1]+cod[t2];
           }
           else 
           {
                int te=10000;
                int jm=-1;
            	for(int j=1;j<i && j<11;j++)
            	{
	                int k=i-j;
	                int t2=cod[j] + cod[k];
	                if(t2<te)
	                {
	                    te=t2;
	                    jm=j;
                	}
            	}
	            pr[i]=jm;
	            ml[i]=maxim(ml[jm],ml[i-jm]);
	            cod[i]=cod[jm]+cod[i-jm] + (2*ml[i])- ml[jm] - ml[i-jm];
           }
    }
}

void sieve()
{
    for (int i = 2; i < MAX; i += 2)  
    { 
    	 sp[i] = 2;
    }
    for (long long i = 3; i < MAX; i += 2)
    {
        if (!v[i])
        {
            sp[i] = i;
            for (long long j = i; (j*i) < MAX; j += 2)
            {
                if (!v[j*i])    
                	v[j*i] = true, sp[j*i] = i;
            }
        }
    }
}

int ans[110];
int curr = 0;
int last = 0;
void solved(int k)
{
    if(k<=3)
    {
        for(int i=0;i<k;i++)
        {
            ans[curr] = last+k-i;
            curr++;
        }
        last = last+k;
    }
    else
    {
        if(sp[k]!=k)
        {
            solved(sp[k]);
            solved(k/sp[k]);
        }
        else
        {
            int maxmum = ml[pr[k]];
            if(maxmum>ml[k-pr[k]])
            {
                int digis = cod[pr[k]];
                int prevlast = last;
                last = last+digis;
                solved(k-pr[k]);
                int diff = maxmum-ml[k-pr[k]];
                for(int i=0;i<diff;i++)
                {
                    ans[curr] = last+i+1;
                    curr++;
                }
                last = last + diff;
                int currlast = last;
                last = prevlast;
                solved(pr[k]);
                last = currlast;
            }
            else
            { 
                int digis = cod[k-pr[k]];
                int prevlast = last;
                last = last+digis;
                solved(pr[k]);
                int diff = ml[k-pr[k]]-ml[pr[k]];
 
                for(int i=0;i<diff;i++)
                {
                    ans[curr] = last+i+1;
                    curr++;
                }
                last = last+diff;
                int currlast = last;
                last = prevlast;
                solved(k-pr[k]);
                last = currlast;
            }
        }
    }
}
 
int main()
{
 
    sieve();
    check();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        curr = 0;
        last = 0;
        int k;
        scanf("%d",&k);
        solved(k);
        cout<<curr<<endl;
        for(int i=0;i<curr;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}