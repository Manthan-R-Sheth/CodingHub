#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int T;
	scanf("%d",&T);
 
    long long int r, c, m, k, j, leftover;
 
	while(T--) {
		scanf("%lld %lld %lld %lld %lld",&r,&c,&m,&k,&j);
		bool possible = false;
 
        if(r*c != m + k + j) {
            printf("No\n");
            continue;
        }
 
        if((m / c + k / c + j / c == r && m % c == 0 && k % c == 0 && j % c== 0) ||
           (m / r + k / r + j / r == c && m % r == 0 && k % r == 0 && j % r == 0)) {
            possible = true;
        }
 
        if(m % c == 0) {
            leftover = r - m / c;
            if(j % leftover == 0 && k % leftover == 0 && (k / leftover) +  (j / leftover) == c)
                possible = true;
        }
 
        if(k % c == 0) {
            leftover = r - k / c;
            if(m % leftover == 0 && j % leftover == 0 && (m / leftover) + (j / leftover)==c)
                possible = true;
        }
 
        if(j % c == 0) {
            leftover = r- j / c;
            if(m % leftover == 0 && k % leftover == 0 && ((m / leftover) + (k / leftover)==c))
                possible = true;
        }
 
        if(m % r == 0) {
            leftover = c - m / r;
            if(j % leftover == 0 && k % leftover == 0 && (j / leftover) + (k / leftover)==r)
                possible = true;
        }
 
        if(j % r == 0) {
            leftover = c - j / r;
            if(m % leftover == 0 && k % leftover == 0 && ((m / leftover) + (k / leftover)==r))
                possible = true;
        }
 
        if(k % r == 0) {
            leftover = c-(k / r);
            if(j % leftover == 0 && m % leftover == 0 && (m / leftover) + (j / leftover)==r)
                possible = true;
        }
        if(possible == true)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}