/*
Given a binary matrix your task is to complete the function printMat which prints all unique rows of the given matrix. The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix.

Input:
The first line of input is an integer T denoting the no of test cases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test contains two integers row and col denoting the number of rows and columns of matrix. Then in the next line are row*col space separated values of the matrix M.

Output:
The output will be the unique rows of the matrix separated by space.

Note: The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Note : Dont print new line after each row instead print "$" without quotes .

Constraints:
1<=T<=20
1<=row,col<=40
0<=M[][]<=1

Example:
Input
1
3 4
1 1 0 1 1 0 0 1 1 1 0 1

Output
1 1 0 1 $1 0 0 1 $

Explanation
Above the matrix of size 3x4 looks like
1 1 0 1
1 0 0 1
1 1 0 1

############################################################Solution####################################################################
*/

class GfG
{
    public static void printMat(int a[][],int r, int c)
        {
            Set<String> binary=new HashSet<String>();
                
            for(int i=0;i<r;i++){
                String s ="";
                for(int j=0;j<c;j++){
                    s=s+String.valueOf(a[i][j])+" ";
                }
                    
                if(!binary.contains(s)){
                        binary.add(s);
                        System.out.print(s+"$");
                }
                    
            }
        }
}
