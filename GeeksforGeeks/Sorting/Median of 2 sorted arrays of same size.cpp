#include <bits/stdc++.h>
using namespace std;

int median(vector<int>& v,int start,int end){
	int N=end-start+1;
	
	if(N&1)
		return v[start+N/2];
	return (v[start+N/2]+v[start+N/2+1])/2;
}

int getMedian(vector<int>& A,vector<int>& B,int startA,int endA,int startB,int endB){
			
	if(startA+1==endA)
		return (max(A[startA],B[startB])+min(A[endA],B[endB]))/2;
	
	int m1=median(A,startA,endA);
	int m2=median(B,startB,endB);
	
	int mid1=(endA+startA+1)/2;
	int mid2=(endB+startB+1)/2;
	if(m1==m2)
		return m1;
	else if(m1<m2)
		return getMedian(A,B,mid1,endA,startB,mid2);
	else
		return getMedian(A,B,startA,mid1,mid2,endB);
}

int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<int> sub(N);
	vector<int> lab(M);
	
	for(int i=0;i<N;i++)
		cin>>sub[i];
	
	for(int i=0;i<M;i++)
		cin>>lab[i];
		
	cout<<"Median is "<<getMedian(sub,lab,0,N-1,0,M-1);
	return 0;	
}
