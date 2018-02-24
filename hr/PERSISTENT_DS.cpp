#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>
using namespace std;

#define MX  100007
#define GOL(x) (x?x->l:NULL)
#define GOR(x) (x?x->r:NULL)
#define Size(x) (x?x->cnt:0)
#define mid ((l+r)>>1)

struct Node
{
    int cnt;
    Node *l,*r;
    
    Node()
    {
        cnt = 0;
        l = r = NULL;
    }
};

vector< int > adj[MX];
vector< int > ppl[MX];
Node Tree[18*MX];
int avail;
Node* Roots[MX];
int L[MX],T[MX];
int PP[MX][20];

Node* update(Node* idx,int l,int r,int pos)
{
    Node *u = &Tree[++avail];
    
    if (idx != NULL)    
    {
        *u = *idx;
    }
    
    if (l == r) 
    {
        u->cnt++;
        return u;
    }
      
    u->cnt++;
    
    if (pos <= mid)     
        u->l = update(u->l,l,mid,pos);
    else                
        u->r = update(u->r,mid+1,r,pos);
    
    return u;
}

int query(Node* u,Node* v,Node *p,Node *fp,int l,int r,int k)
{
    if (l == r)     
        return l;
    
    int sum = Size(GOL(u)) + Size(GOL(v)) - Size(GOL(p)) - Size( GOL(fp) );  
    
    if (sum >= k)
    {
        return query( GOL(u),GOL(v),GOL(p),GOL(fp),l,mid,k );
    }
    else 
    {
        return query( GOR(u),GOR(v),GOR(p),GOR(fp),mid+1,r,k-sum );
    }
}

void bfs(int n,int m)
{
    queue<int>q;
    
    q.push(1);
    q.push(0);
    q.push(0);
    
    Roots[0] = NULL;
    
    while(!q.empty())
    {
        int u = q.front();q.pop();
        int p = q.front();q.pop();
        int l = q.front();q.pop();
        
        L[u] = l;
        T[u] = p;
        
        Roots[u] = Roots[p];
        
        for (int i=0;i<(int)ppl[u].size();i++)
        {
            int x = ppl[u][i];
            
            Roots[u] = update(Roots[u],1,m,x);
        }
        
        for (int i=0;i<(int)adj[u].size();i++)
        {
            int v = adj[u][i];
            
            if (v != p)
            {
                q.push(v);
                q.push(u);
                q.push(l+1);
            }
        }
    }
}

void sparse(int n)
{
    for (int i=1;i<=n;i++)  
        PP[i][0] = T[i];
    
    for (int j=1;(1<<j) < n;j++)
    {
        for (int i=1;i<=n;i++)
        {
            if (PP[i][j-1])
                PP[i][j] = PP[ PP[i][j-1] ][j-1];
        }
    }
}

int LCA(int p,int q)
{
    if(L[p] < L[q])     
        swap(p,q);
    
    int b;
    
    for (b=1;(1<<b) <= L[p];b++);   
        b--;
    
    for (int i=b;i>=0;i--)
    {
        if ( L[p] - (1<<i) >= L[q] )
            p = PP[p][i];
    }
    if (p == q)     
        return p;
    
    for (int i=b;i>=0;i--)
    {
        if (PP[p][i] && PP[p][i] != PP[q][i])
        {
            p = PP[p][i];
            q = PP[q][i];
        }
    }
    
    return T[p];
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        
        ppl[x].push_back(i);
    }
    
    Roots[0] = NULL;
    
    bfs(n,m);
    sparse(n);
    
    while(q--)
    {
        int u,v,a;
        cin>>u,v,a;
        
        int lca = LCA(u,v);
        int cnt = Size( Roots[u] ) + Size( Roots[v] ) - Size( Roots[lca] ) - Size( Roots[T[lca]] );
        int k = min( cnt,a );
        
        vector< int > vec;
        
        for (int i=1;i<=k;i++)
        {
            int x = query(Roots[u],Roots[v],Roots[lca],Roots[T[lca]],1,m,i);
            
            vec.push_back(x);
        }
        
        cout<<vec.size()<<endl;
        
        for (int i=0;i<(int)vec.size();i++)
        {
            cout<<vec[i];
            cout<<endl;
        }
    }
    return 0;
}