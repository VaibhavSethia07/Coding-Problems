/*
Given a Square matrix mat[] of size NxN. Your task is to find minimum number of operation(s) that are required to make the matrix Beautiful.
A Beautiful matrix is a matrix in which sum of elements in each row and column is equal. In one operation you can only increment any value of cell of matrix by 1.

Input:
First line of the input contains an integer T denoting the number of test cases. Then T test case follows. First line of each test case contains an integer N denoting the size of the matrix. Next line contains NxN space separated integers denoting the elements of the matrix.

Output:
For each test case print a single integer in a new line denoting the minimum number of operations required that needed to be performed.

Your Task:
This is a function problem. You need to complete the function findMinOpeartion() that takes matrix and n as parameters and returns count of minimum number of operations.

Constraints:
1 <= T <= 150
1 <= N <= 100
1 <= mat[i][j] <= 150

Example:
Input:
2
2
1 2 3 4
3
1 2 3 4 2 3 3 2 1
Output:
4
6

Explanation:
TestCase 1:
4 3
3 4
1. Increment value of cell(0, 0) by 3
2. Increment value of cell(0, 1) by 1
Hence total 4 operation are required.
Testcase 2:Original matrix is as follows:
1 2 3
4 2 3
3 2 1
We need to make increment in such a way that each row and column has one time 2 , one time 3 , one time 4. For that we need 6 operations.

#############################################################Solution###################################################################
*/

class Operation
{
    static int findMinOperation(int n, int mat[][])
    {
        int rowSum=0;
        int colSum=0;
        int maxSum=0;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rowSum+=mat[i][j];
                colSum+=mat[j][i];
                sum+=mat[i][j];
            }
            maxSum=Math.max(rowSum,maxSum);
            maxSum=Math.max(colSum,maxSum);
            rowSum=0;
            colSum=0;
            
        }
        return maxSum*n-sum;
    }
}

