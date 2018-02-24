	#include<iostream>
	#include<cstdio>
	#include<cstdlib>
	#include<vector>
	using namespace std;

	vector<vector<int> > seqlist;

	void update(int n,long x,long y, long lastans){
		seqlist[(x^lastans)%n].push_back(y);
	}

	int getlastans(int n,long x,long y,long lastans){
		vector<int> v=seqlist[(x^lastans)%n];
		int lastansupdate= v[y%v.size()];
		return lastansupdate;
	}

	void initialise(){
		for (int x = 0; x < 100000; x++)
		{
	    	seqlist.push_back(vector <int> ());
		}
	}

	int main(){
		int n,q,qt;
		long x,y,lastans=0;
		cin>>n>>q;
		initialise();
		for (int i = 0; i < q; ++i)
		{
			cin>>qt>>x>>y;
			if(qt==1){
					update(n,x,y,lastans);
				}
			else 
				if(qt==2){
						lastans=getlastans(n,x,y,lastans);
						cout<<lastans<<endl;
				}
				else
					continue;
		}
	}