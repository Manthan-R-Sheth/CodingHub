#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	int n,qtype,x;
	stack <int> numbers;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>qtype;
		if(qtype==1){
			cin>>x;
			numbers.push(x);
			v.push_back(x);
		}
		else
			if(qtype==2){
				numbers.pop();
				v.pop_back();
			}
			else{
				int max= *(max_element(v.begin(), v.end()));
				cout<<max<<endl;
			}
	}
}