/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Sample Sudoku for you to get the logic for its solution:



Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.

Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).

Constraints:
0 ≤ grid[i][j] ≤ 9

##############################################################################Solution###########################################################################################
*/

class Sudoku
{
    static boolean SolveSudoku(int grid[][])
    {
        int N=grid.length;
        int x=N;
        int y=N;
        boolean flag = false;    
        
        for(int i=0;i<N;i++){   
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    x=i;
                    y=j;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        if(x==N && y==N)
            return true;
            
        for(int missing=1;missing<=N;missing++){
            if(isSafe(grid,x,y,N,missing)){
                grid[x][y] = missing;
                if(SolveSudoku(grid))
                    return true;
                grid[x][y] = 0;
            }
        }
        
        return false;
    }
    
    static void printGrid (int grid[][])
    {
        for(int i=0;i<grid.length;i++)  
            for(int j=0;j<grid[i].length;j++)
                System.out.print(grid[i][j]+" ");
    }
    
    static boolean isSafe(int[][] grid,int row,int col,int N,int missing){
        for(int k=0;k<N;k++){
            if(grid[row][k] == missing || grid[k][col] == missing)
                return false;
        }    
        int s = (int)Math.sqrt(N);
        int rs = row-(row%s);
        int cs = col-(col%s);
        
        for(int i=0;i<s;i++){  
            for(int j=0;j<s;j++)
                if(grid[rs+i][cs+j] == missing)
                    return false;
        }
        return true;
    }
}
