2[U#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int rem,A=0,ANS=0,q,t,w,b,count=0,lcm;
	cin>>t>>w>>b;
	lcm=b/__gcd(b,w) *w;
	if( lcm<=0 || lcm%w!=0 || lcm%b!=0 ) lcm=t+1;
	rem=t%lcm;
	q=t/lcm;
	
	A=q *min(w,b) + min(rem,min(w,b)-1);
	long long int gcd;
	gcd=__gcd(A,t); cout<<A/gcd<<'/'<<t/gcd<<endl;
	return 0;
}