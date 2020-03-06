/*
You are given a number n. You need to find the count of digits in n.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing n.

Output:
For each testcase, in a newline, print the count of digits in n.

Your Task:
This is a function problem. You only need to complete the function countDigits that takes n as parameter and returns the count of digits in n.

Constraints:
1 <= T <= 100
1 <= n <= 107

Examples:
Input:
2
1
99999
Output:
1
5
*/

##########################################################Solution#########################################################################
class Digitcount
{
    // complete the below function
    public static int countDigits(int n)
    {
        // add your code here
        if(n==0)
            return 0;
        return 1 + countDigits(n/10);
    }
}
