/*
Given a square matrix mat of size N x N. The task is to find the determinant of this matrix.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix. The next line contains the elements of the matrix in row-wise form.

Output:
Print the determinant of the matrix.

Your Task:
This is a function problem. You only need to complete the function determinantOfMatrix() that takes matrix and n as parameters and returns determinant.

Constraints:
1 <= T <= 40
1 <= N <= 7
-10 <= mat[i][j] <= 10

Example:
Input:
2
4
1 0 2 -1 3 0 0 5 2 1 4 -3 1 0 5 0
3
1 2 3 4 5 6 7 10 9
Output:
30
12

#############################################################Solution###################################################################
*/

class Determinant
{
    static int determinantOfMatrix(int mat[][], int n)
    {
        int det=0;
        int sign=1;
	   if(n==1)
	    return mat[0][0];
	    
	   
	   for(int i=0;i<n;i++){
	       int temp[][]=new int[n-1][n-1];
	       getCofactor(mat,temp,0,i,n);
	  
	       det+=sign*mat[0][i]*determinantOfMatrix(temp,n-1);
	       
	       sign =-sign;
	   }
	   
	   return det;
    }
    
    static void getCofactor(int [][] mat,int [][]temp,int p,int q,int n){
        int i=0,j=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if((row !=p) && (col != q) )
                    temp[i][j++]=mat[row][col];
                    
                    }
                    if(j==(n-1)){
                        i++;
                        j=0;
                    }  
        }
    }
}
