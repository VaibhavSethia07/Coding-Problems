/*Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string S that represents a number.

Output:
For each test case, in a new line, print the required result.

Constraints:
1 <= T <= 100
1 <= S <= 1012

Example:
Input:
2
1234
421

Output:
1670
491

Explanation:
Testcase1:
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234
        = 1670

Testcase2:
Sum = 4 + 2 + 1 + 42 + 21 + 421
        = 491

#############################################################################Solution###############################################################################
*/

// Naive Method
using namespace std;

long long int subSum(string str,int i,int N){
    if(N==i)
        return 0;
        
    long long int res=0;
    long int prev=0;
    long int curr;
    for(int j=i;j<N;j++){
        curr=prev*10+(str[j]-'0');
        res+=curr;
        prev=curr;
    }
    
    return res+subSum(str,i+1,N);
    
}

int main() {
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int N=str.length();
        cout<<subSum(str,0,N)<<"\n";
    }
	return 0;
}

// DP (Tabulation) Method
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--){
	    string str;
	    cin>>str;
        int N = str.length();
	    long long int dp[N+1];
	    dp[0] = 0;
        long long int res=0;
	    for(int i=0;i<N;i++){
	        dp[i+1] = dp[i]*10+(str[i]-'0')*(i+1);
	        res+=dp[i+1];
	    }
	   cout<<res<<"\n";
	    
	}
	return 0;
}
