/*
Given a number N. The task is to find the nth Catalan number.
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Input:
The first line of input contains a single integer T which denotes the number of test cases. The first line of each test case contains a single integer N.

Output:
For each test case, in a new line print the Catalan number at position N.
Note: Positions start from 0 as shown above.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
3
5
4
10

Output:
42
14
16796
Explanation:
From the given first few Catalan's number we can easily the answer for first two test cases.

##################################################################################Solution#########################################################################################
*/

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision;

// Memoization
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision;

int256_t catalan(int N,int K,int256_t** dp){
    if(K==0 || K==N)
        return 1;
    if(dp[N][K]!=-1)
        return dp[N][K];
    return dp[N][K]=catalan(N-1,K,dp)+catalan(N-1,K-1,dp);
}


int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        int256_t** dp = new int256_t*[2*N+1];
        for(int i=0;i<=2*N;i++){
            dp[i] = new int256_t[2*N+1];
            for(int j=0;j<=2*N;j++)
                dp[i][j] = -1;
        }
    	cout<<catalan(2*N,N,dp)/(N+1)<<"\n";
    }
	return 0;
}

// Tabulation
int256_t Ncatalan(int N){
    int256_t dp[N+1]={0};
    dp[0]=1;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++)
            dp[i]+=dp[i-1-j]*dp[j];
    }
    
    return dp[N];
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        cout<<Ncatalan(N)<<"\n";
    }
	return 0;
}
