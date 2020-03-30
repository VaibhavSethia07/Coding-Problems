/*
Given a boolean matrix mat[r][c] of size r X c, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is r and c, r is the number of rows and c is the number of columns.The next r lines contain c elements having either 0 or 1 and separated by spaces.

Output:
Print the modified array.

Your Task:
This is a function problem. You only need to complete the function booleanMatrix that takes r, c, and matrix as parameters and prints the modified array. You need to append a newline to separate ouput of individual testcases.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0
Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0

##############################################################Solution###################################################################
*/

class ModifyMat
{
    static void booleanMatrix(int r, int c, int mat[][])
    {
        int []rTrack=new int[r];
        int []cTrack=new int [c];
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    rTrack[i]=1;
                    cTrack[j]=1;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(rTrack[row]==1|| cTrack[col]==1){
                        mat[row][col]=1;
                }
                sb.append(mat[row][col]+" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
