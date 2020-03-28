/*
Given a matrix mat[][] of size N x N. The task is to print the elements of the matrix in the snake pattern.


Input:
First line consists of an integer T denoting the number of test cases. First line of each test case consists of N, denoting number of elements(N x N) in Matrix. Second line of every test case consists of N x N spaced integers denoting elements of Matrix elements.

Output:
For each testcase, in a new line, print the matrix in snake pattern.

Your Task:
This is a function problem. You only need to complete the function print that takes a matrix and n as parameters and prints the matrix. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= mat[i][j] <= 100

Example:
Input:
2
3
45 48 54 21 89 87 70 78 15
2
1 2 3 4
Output:
45 48 54 87 89 21 70 78 15 
1 2 4 3

##########################################################Solution######################################################################
*/

class Snake_Pattern
{
    static void print(int a[][], int n)
    {
        for(int i=0;i<n;i++){
            if((i & 1)==0)
                for(int j=0;j<n;j++)
                    System.out.print(a[i][j]+" ");
            else
                for(int j=n-1;j>=0;j--)
                    System.out.print(a[i][j]+" ");
        }
    }
}
