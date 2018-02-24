#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x7fffffff
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define pr pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define fr first
#define sc second
#define mset(arr,val) memset(arr,val,sizeof(arr));

const int MAX = 10000005;
const int MOD = 1e9+7;
int facts[MAX];
void factco(int num){
	for (int i = 0; i < MAX; ++i)
	{
		facts[i] = 0;
	}
	for(int i = 1;i<=num;i++){
		for(int j=0;j<=num/i;j++){
			int v = i + i*j;
			if(v<=num)
				facts[v]++;
			else
				break;
		}
	}
}

int main(){
	factco(MAX);
	int t;
	SCD(t);
	while(t--){
		int n;
		SCD(n);
		printf("%d\n",facts[n] );
	}
}