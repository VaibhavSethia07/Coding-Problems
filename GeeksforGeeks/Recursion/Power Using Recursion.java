/*
You are given two numbers n and p. You need to find np.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing n and p.

Output:
For each testcase, in a newline, print np.

Your Task:
This is a function problem. You only need to complete the function RecursivePower that takes n and p as parameters and returns np.

Constraints:
1 <= T <= 80
1 <= n, p <= 9

Examples:
Input:
2
9 9
2 9
Output:
387420489‬
512
*/

#############################################################Solution###################################################################
int RecursivePower(int n,int p)
{
    //Your code here
    if(p==0)
        return 1;
        
    if(p==1)
        return n;
        
    if((p & 1)==1)
        return n*RecursivePower(n*n,p/2);
    
    return RecursivePower(n*n,p/2);
}
