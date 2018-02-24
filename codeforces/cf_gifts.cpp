#include<iostream>
#include<vector>
#include<memory.h> 
using namespace std;
 
const int MAX_N = (int) 1e5;
 
vector<int> g[MAX_N];
int a[MAX_N];
bool inA[MAX_N];
 
vector<int> ts;
bool used[MAX_N];
 
void dfs1(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        dfs1(g[v][i]);
    }
    ts.push_back(v);
}
 
int r[MAX_N];
void dfs2(int v, int x) {
    if (r[v] != -1) {
        return;
    }
    r[v] = x;
    for (int i = 0; i < g[v].size(); i++) {
        dfs2(g[v][i], x);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        --a[i];
        inA[a[i]] = true;
    }
    for (int i = 0; i < n; i++) 
    {
        if (!used[i]) 
        {
            dfs1(i);
        }
    }
    
    memset(r, -1, sizeof(r));
    vector<int> ans;
    for (int i = 0; i < n; i++) 
    {
        if (inA[ts[i]]) 
        {
            dfs2(ts[i], ts[i]);
            ans.push_back(ts[i]);
        }
    }
 
    for (int i = 0; i < n; i++) 
    {
        cout<<ans[i]<<endl;
    }

    for (int i = 0; i < n; i++) 
    {
        if (r[i] != a[i]) 
        {
            cout << -1;
            return 0;
        }
    }
 
    cout<<"ANS"<<endl;
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) 
    {
        cout << ans[i] + 1 << "\n";
    }
 
 
    return 0;
}