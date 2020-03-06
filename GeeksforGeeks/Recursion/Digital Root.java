/*
You are given a number n. You need to find the digital root of n.
DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.
Eg.DigitalRoot(191)=1+9+1=>11=>1+1=>2

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing n.

Output:
For each testcase, in a newline, print the digital root of n.

Your Task:
This is a function problem. You only need to complete the function digitalRoot that takes n as parameter and returns the digital root of n.

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
9
*/

##########################################################Solution######################################################################
int digitalRoot(int n)
{
    //Your code here
    if(n<10)
        return n;
        
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    
    return digitalRoot(sum);
}
