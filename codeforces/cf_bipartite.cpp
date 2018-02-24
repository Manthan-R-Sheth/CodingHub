#include<bits/stdc++.h>
#include<climits>
using namespace std;

const int MAX = 100005;

vector<int> visited;
list<int> adj[MAX];
set<int> arya;
set<int> pari;
vector<int> colorArr;


bool isBipartite(int src,int n)
{
    colorArr[src] = 1;
    visited[src]=true;
    queue <int> q;
    q.push(src);
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        list<int>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (colorArr[(*it)] == -1 && !visited[(*it)])
            {
                colorArr[(*it)] = 1 - colorArr[u];
                visited[(*it)]=true;
                q.push(*it);
            }
 
            else 
                if (colorArr[(*it)] == colorArr[u])
                    return false;
        }
    }
    return true;
}


int main()
{
    int n,m,u,v;
    cin>>n>>m;
    visited.resize(n+1,false);
    colorArr.resize(n+1,-1);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool flag=true;
    for (int i = 1; i <=n; ++i)
    {
        if(!visited[i])
        {
            bool tmp= isBipartite(i,n);
            flag =(flag & tmp);
        }
    }
    set<int>::iterator it;
    if(flag)
    {

        for (int i = 1; i <=n; ++i)
        {
            if(colorArr[i]==1 && visited[i])
                arya.insert(i);
            else
                if(colorArr[i]==0 && visited[i])
                    pari.insert(i);
        }
        
        cout<<arya.size()<<endl;
        for(it=arya.begin();it!=arya.end();it++)
        {
            cout<<(*it)<<" ";
        }
        cout<<endl;
        cout<<pari.size()<<endl;
        for(it=pari.begin();it!=pari.end();it++)
        {
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;
}