/*
You are given a matrix A of dimensions n1 x m1. You have to exchange A's first column with last column.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains dimensions of the matrix A, n1 and m1. The second line contains n1*m1 elements of matrix separated by spaces.

Output:
For each testcase, in a new line, print the resultant matrix.

User Task:
The task is to complete the function exchangeColumns() which is used to do required operation on matrix. The addition of newline is automatically done by the driver code.

Constraints:
1 <= T <= 100
1 <= n1, m1<= 30
0 <= arr[i] <= 100

Examples:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
2 3
4 3 2 1 5 6
Output:
4 2 3 1 8 6 7 5 12 10 11 9 16 14 15 13
2 3 4 6 5 1

Explanation:
Testcases 1: Matrix is as follow:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

After exchanging first  column with last column, we have matrix as follows:
4 2 3 1
8 6 7 5
12 10 11 9
16 14 15 13
Testcase 2: Matrix is as follows:
4 3 2
1 5 6
After exchanging columns matrix will be:
2 3 4
6 5 1.

########################################################Solution########################################################################
*/

class ModifyMat
{
    static void exchangeColumns(int n1, int m1, int arr1[][])
    {
       for(int i=0;i<n1;i++){
        int temp=arr1[i][0];
        arr1[i][0]=arr1[i][m1-1];
        arr1[i][m1-1]=temp;
       }
       for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            System.out.print(arr1[i][j]+" ");
    }
}
