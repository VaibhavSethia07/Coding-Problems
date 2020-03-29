/*
You are given a matrix A of dimensions n1 x m1. The task is to reverse the columns(first column exchanged with last column and so on).

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase two lines of input. The first line contains dimensions of the matrix A, n1 and m1. The second line contains n1*m1 elements
separated by spaces.

Output:
For each testcase, in a new line, print the resultant matrix.

Your Task:
This is a function problem. You only need to complete the function reverseCol() that takes n1, m1, and matrix as parameter and modifies the matrix. The driver code automatically appends a new line.

Constraints:
1 <= T <= 100
1 <= n1, m1 <= 30
0 <= arri <= 100

Examples:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
2 3
4 3 2 1 5 6
Output:
3 2 1 7 6 5 11 10 9 15 14 13
2 3 4 6 5 1

Explanation:
Testcase 1: Original array is as follows:
1 2 3
5 6 7
9 10 11
13 14 15

Array after exchanging columns:
3 2 1
7 6 5
11 10 9
15 14 13
Testcase 2: Original matrix is as follows:
4 3 2
1 5 6
After reversing the column of matrix
2 3 4
6 5 1

#################################################################Solution###############################################################
*/

class ModifyMat{
  {
    static void reverseCol(int n1, int m1, int arr1[][])
    {
        for(int i=0;i<n1;i++){
            int start=0,end=m1-1;
            while(start<end){
                arr1[i][start]=arr1[i][start]^arr1[i][end];
                arr1[i][end]=arr1[i][start]^arr1[i][end];
                arr1[i][start]=arr1[i][start]^arr1[i][end];
                start++;
                end--;
            }
        }
    }
}
