/*
Two matrices A[][] and B[][] can only be multiplied if A's column size is equal to B's row size. The resultant matrix will have dimensions equal to A's row size and B's column size.
You are given two matrices A and B. A is of dimension n1 x m1; and B is of dimension n2 x m2. You have to multiply A with B and print the resultant matrix. If multiplication is not possible then print -1.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains four lines of input. The first line contains dimensions of the first array n1 and m1. The second line contains n1 * m1 elements separated by spaces. The third line contains dimensions of the second array n2 and m2. The fourth line contains n2 * m2 elements separated by spaces.

Output:
For each testcase, in a new line, print the resultant matrix if possible; else print -1.

Your Task:
This is a function problem. You only need to complete the function multiplyMatrix that takes n1,m2,n2,m2,matrix1,matrix2 as parameters and prints the multiplied matrix. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= n1, m1, n2, m2 <= 30
0 <= arri <= 100

Examples:
Input:
2
3 2
4 8 0 2 1 6
2 2
5 2 9 4
1 1
2
1 1
3
Output:
92 40 18 8 59 26
6

###########################################################Solution#####################################################################
*/

class Multiplication
{
    static void multiplyMatrix(int n1, int m1, int n2, int m2, int arr1[][], int arr2[][])
    {
        if(m1 != n2){
            System.out.print(-1);
            return ;
        }
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                int mul=0;
                for(int k=0;k<m1;k++)
                    mul+=arr1[i][k]*arr2[k][j];
                System.out.print(mul+" ");
            }
        }
    }
}
