#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<stack>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
stack<struct TrieNode*> dfstack;

struct TrieNode
{
	struct TrieNode* children[26];
	bool isLeaf;
};

struct TrieNode* getNode()
{
	struct TrieNode* pNode=NULL;
	pNode = (struct TrieNode* )malloc(sizeof(struct TrieNode));
	if (pNode)
    {
        pNode->isLeaf = false;
 
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}

bool lastleaf(struct TrieNode* current)
{
	for (int i = 0; i < 26; i++)
	{
		if(current->children[i]!=NULL)
		{
			return false;
		}
	}
	return true;
}

void dfs(struct TrieNode* start)
{
	while(!lastleaf(start))
	{
		for (int i = 0; i < 26; i++)
		{
			if(start->children[i]!=NULL)
			{
				dfstack.push(start);
				dfs(start->children[i]);
			}
		}
        
	}
}

void addcon(struct TrieNode* root, string value)
{
	int length=value.length();
	struct TrieNode* pCrawl=root;
	for(int level=0;level<length;level++)
	{
		int i=CHAR_TO_INDEX(value[level]);
		if(!pCrawl->children[i])
		{
			pCrawl->children[i]=getNode();
		}
		pCrawl=pCrawl->children[i];
	}
	pCrawl->isLeaf = true;
}

int getCount()
{
	int count=0;
	while(!dfstack.empty())
	{
		struct TrieNode* curr= dfstack.top();
		dfstack.pop();
		if(curr->isLeaf==true)
		{
			count++;
		}
	}
	return count;
}

int findcon(struct TrieNode* root,string value)
{
	int level,index;
    int length = value.length();
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(value[level]);
 
        if (!pCrawl->children[index])
            return 0;
 
        pCrawl = pCrawl->children[index];
    }
    dfs(pCrawl);
	return getCount();
}

int main()
{
	int n;
	string q,value;
	cin>>n;
	struct TrieNode* root= getNode();
	while(n--)
	{
		cin>>q;
		if(q.compare("add")==0)
		{
			cin>>value;
			addcon(root,value);
		}
		if(q.compare("find")==0)
		{
			cin>>value;
			int con=findcon(root,value);
			cout<<con<<endl;
		}
	}
}