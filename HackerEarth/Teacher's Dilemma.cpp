#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> sz;

void make_parent(int N){
	parent.clear();
	sz.clear();
	parent.resize(N);
	sz.resize(N);

	for(int i=0;i<N;i++){
		parent[i]=i;
		sz[i]=1;
	}
}

int find(int a){
	if(parent[a]==a)
		return a;
	return parent[a]=find(parent[a]);
}

void unite(int a,int b){
	a=find(a);
	b=find(b);

	if(a==b)
		return;
	if(sz[a]<sz[b])
		swap(a,b);
	parent[b]=a;
	sz[a]+=sz[b];
}

int main() {
	int N,M,a,b;
	cin>>N>>M;

	make_parent(N);

	for(int i=0;i<M;i++){
		cin>>a>>b;
		a--;
		b--;
		unite(a,b);
	}

	set<int> rep;
	for(int i=0;i<N;i++){
		rep.insert(find(i));
	}
	long long ans=1;
	long long mod=1000000007;
	for(auto& p:rep){
		ans=(ans*sz[p])%mod;
	}
		
	cout<<ans%mod<<"\n";
}

