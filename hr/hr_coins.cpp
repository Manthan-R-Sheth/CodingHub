#include<iostream>
#include<cstdio>
using namespace std;
int dp[250];
// int numberofways(int n,int m[],int coinslength){
// 	cout<<n<<endl;
// 	if(n==0)return 1;
// 	else

// 		if(coinslength<=0 || m==NULL)
// 			return 0;
// 		if(dp[n]!=0)
// 			return dp[n];
// 		else
// 		for(int i=0;i<coinslength;i++){
// 			if(n-m[i]>=0)
// 				dp[n]=numberofways(n-m[i],m,coinslength)+1;
// 			else 
// 				continue;
// 		}
// 		return dp[n];
// }
int numberofways( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
    int table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
int main(){
	int n,coinslength;
	int m[50];
	for(int i=0;i<250;i++)
		dp[i]=0;

	cin>>n>>coinslength;
	for(int i=0;i<coinslength;i++){
		cin>>m[i];
	}
	cout<<numberofways(m,coinslength,n)<<endl;
}