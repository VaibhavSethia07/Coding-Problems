/*
You are given a number n. You need to find nth Fibonacci number.
F(n)=F(n-1)+F(n-2); where F(1)=1 and F(2)=1

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing n.

Output:
For each testcase, in a newline, print F(n).

Your Task:
This is a function problem. You only need to complete the function fibonacci that takes n as parameters and returns F(n).

Constraints:
1 <= T <= 20
1 <= n <= 20

Examples:
Input:
2
1
20
Output:
1
6765
*/

############################################################Solution####################################################################
class PrintFib
{
    static long fibonacci(int n)
    {
        // your code here
        if(n==0)
            return 0;
        if(n==1)
            return 1;
            
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
