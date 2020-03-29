/*
You are given a matrix A of dimensions n1 x m1. You have to interchange the rows(first row becomes last row and so on).

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase two lines of input. The first line contains dimensions of the array A, n1 and m1. The second line contains n1 * m1 elements separated by spaces.

Output:
For each testcase, in a new line, print the resultant matrix.

Your Task:
This is a function problem. You only need to complete the function interchangeRows() that takes n1,m1, and matrix as parameter and modifies the array. The driver code automatically appends a new line.

Constraints:
1 <= T <= 100
1 <= n1, m1 <= 30
1 <= arri <= 100

Examples:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
5 3
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Output:
13 14 15 16 9 10 11 12 5 6 7 8 1 2 3 4
13 14 15 10 11 12 7 8 9 4 5 6 1 2 3

Explanation:
Testcase 1: Original matrix is as follows:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Matrix after exchanging rows:
13 14 15 16
9 10 11 12
5 6 7 8
1 2 3 4
Testcase 2: Original matrix is as follows:
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
After interchanging rows:
13 14 15
10 11 12
7 8 9
4 5 6
1 2 3

##########################################################Solution######################################################################
*/
class ModifyMat
{
    static void interchangeRows(int n1, int m1, int arr1[][])
    {
        int start=0;
        int end=n1-1;
        
        while(start<end){
            int []temp=arr1[start];
            arr1[start]=arr1[end];
            arr1[end]=temp;
            start++;
            end--;
        }
    }
}
