/*
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Your Task:
This is a function problem. You only need to complete the function spirallyTraverse that takes m, n, and matrix as parameters and prints the spiral traversal. The driver code automatically appends a new line.

Constraints:
1 <= T <= 100
2 <= M, N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7

Explanation:
Testcase 1:


Testcase 2: Applying same technique as shown above , output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.

#########################################################Solution#######################################################################
*/

class Traverse
{
    static void spirallyTraverse(int m, int n, int mat[][])
    {
       int startRow=0,startCol=0;
       int endRow=m-1,endCol=n-1;
       
       while(startRow<=endRow && startCol<=endCol){
           int row=startRow;
           int col=startCol;
           
           for(;row<=endRow && col<=endCol;col++)
                System.out.print(mat[row][col]+" ");
                
           col--;
           row++;
            
           for(;row<=endRow && col>=startCol;row++)
                System.out.print(mat[row][col]+" ");
            
           row--;
           col--;
           
           for(;row>startRow && col>=startCol;col--)
                System.out.print(mat[row][col]+" ");
            
           col++;
           row--;
           
           for(;row>startRow && col<endCol;row--)
                System.out.print(mat[row][col]+" ");
                
           startRow++;
           startCol++;
           
           endRow--;
           endCol--;
       }
      
    }
}
