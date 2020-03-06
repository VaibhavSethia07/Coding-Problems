/*
Print numbers from 1 to N without the help of loops.

Input: 
The first line of the input contains T, denoting the number of testcases. First line of test case contains an integer N.

Output: 
For each test case, print numbers from 1 to N in newline.

Your Task:
This is a function problem. You only need to complete the function printNos that takes N as parameter and prints number from 1 to N recursively. The driver code adds the newline automatically after the function call.

Constraints:
1 <= T <= 100
1 <= N <= 990

Example:
Input:
2
10
5
Output:
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5
*/

########################################################Solution########################################################################
class Print
{
    
  public void printNos(int N)
    {
        //Your code here
        if(N==0)
            return;
        printNos(N-1);
        System.out.print(N+" ");
    }
}
