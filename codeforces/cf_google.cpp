#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int inf = 1001001001;

int n,k,ans;
string S,s;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> S >> s;
    int k=0;
    for (int i=0; i<S.size(); i++){
        k=0;
        for (int j=0; j<s.size(); j++){
            if (S[i+j]==s[j]) k++;
        }
        if (k==s.size()){
            S[i+s.size()-1]='#';
            ans++;
        }
    }
    cout << ans<<endl;
    return 0;
}