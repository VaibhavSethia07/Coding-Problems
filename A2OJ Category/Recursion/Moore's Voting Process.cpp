#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> v(N);
	
	for(int i=0;i<N;i++)
		cin>>v[i];
		
	int ind=0,cnt=1;
	
	for(int i=1;i<N;i++){
		if(v[i]==v[ind])
			cnt++;
		else
			cnt--;
		
		if(cnt==0){
			ind=i;
			cnt=1;
		}
	}
	
	cnt=0;
	for(int i=0;i<N;i++){
		if(v[i]==v[ind])
			cnt++;
	}
	
	if(cnt>(N>>1))
		printf("The number %d appears more than half of the time",v[ind]);
	else
		printf("No number has a majority");
	
	return 0;	
}
