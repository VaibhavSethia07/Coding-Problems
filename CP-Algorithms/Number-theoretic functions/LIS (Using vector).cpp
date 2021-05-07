#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


void input(vector<long>& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vector<long>& v,int N){
	/* Finding LIS of an array */
	vector<long> lis;
	for(int i=0;i<N;i++){
		if(lis.empty() || lis.back()<v[i])
			lis.push_back(v[i]);
		else
			*upper_bound(lis.begin(),lis.end(),v[i])=v[i];
	}
	
	cout<<(int)lis.size()<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<long> v(N);
		input(v,N);
		solve(v,N);
	}
	
	return 0;	
}
