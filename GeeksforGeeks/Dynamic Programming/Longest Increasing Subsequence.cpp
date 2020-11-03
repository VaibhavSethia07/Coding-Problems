/*
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
For each testcase, in a new line, print the Max length of the subsequence in a separate line.

Constraints:
1 ≤ T ≤ 100
0 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

Explanation:
Testcase 2: Longest increasing subsequence is of size 3 with elements (there are many subsequence, but listing one of them): 5 7 9.

###################################################################################Solution########################################################################################
*/

// Naive Method
using namespace std;

int LIS(int* arr,int N){
    int lis[N];
    int res = 1;
    lis[0] = 1;
    
    for(int i=1;i<N;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i])
                lis[i] =  max(lis[j]+1,lis[i]);
            
        res = max(res,lis[i]);
    }
    return res;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++) cin>>arr[i];
	    cout<<LIS(arr,N)<<"\n";
	}
	return 0;
}

// Using array and binary search
using namespace std;

int Ceil(int start,int end,int X,int* arr){
    int res=0;
    
    while(start<=end){
        int mid = start+(end-start)/2;
        
        if(arr[mid]>=X){
            res = mid;
            end = mid-1;
        }else
            start = mid+1;
    }
    
    return res;
}

int main() {
    int T;
    cin>>T;
    
    while(T-->0){
        int N;
        cin>>N;
        
        int arr[N]={0};
        int lis[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        lis[0] = arr[0];
        int len=1;
        
        for(int i=1;i<N;i++){
            if(lis[len-1]<arr[i])
                lis[len++] = arr[i];
            else{
                int c = Ceil(0, len-1, arr[i],lis);
                lis[c] = arr[i];
            }
        }
        
        cout<<len<<"\n";
    }	
	return 0;
}

// Using vector and in-built binary search function

int main() {
    int T;
    cin>>T;
    
    while(T-->0){
        int N;
        cin>>N;
        
        int arr[N]={0};
        vector<int> lis;
        for(int i=0;i<N;i++)
            cin>>arr[i];
            
        lis.push_back(arr[0]);
        
        for(int i=1;i<N;i++){
            if(arr[i]>lis.back())
                lis.push_back(arr[i]);
            else{
                int c = lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
                lis[c] = arr[i];
            }
        }
        cout<<lis.size()<<"\n";
    }	
	return 0;
}

