/*
A Maze is given as N*N matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. Find the minimum number of Hops required for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].

Note:
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].

Example 1:

Input:
N = 4
maze[][] = {{2,1,0,0},{3,0,0,1},
{0,1,0,1},{0,0,0,1}}
Output:
1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1
Explanation: Rat started with m[0][0] and
can jump up to 2 steps right/down. First
check m[0][1] as it is 1, next check
m[0][2], this won't lead to the solution.
Then check m[1][0], as this is 3(non-zero)
so we can make 3 jumps to reach m[1][3].
From m[1][3] we can move downwards taking
1 jump each time to reach destination at
m[3][3]. 
Example 2:

Input:
N = 4
maze[][] = {{2,1,0,0}{2,0,0,1},
{0,1,0,1},{0,0,0,1}}
Output: -1
Explanation: As no path exists, so -1.
Your task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes the Maze and its dimensions N as inputs and prints the valid path if it exists. If it does not exist, print -1. 

Expected Time Complexity: O(NN).
Expected Auxiliary Space: O(N) if we don't consider the solution matrix for this.

Constraints:
2 <= n <= 50
0 <= maze[i][j] <= 20

############################################################################Solution#############################################################################################
*/

class RatInMaze {
    public static void solve(int[][] maze, int N) {
        int vis[][] = new int[N][N];
        
        if(solveRec(maze,0,0,vis,N))
            printMaze(vis);
        else
            System.out.println(-1);
    }
    
    static boolean solveRec(int[][]maze,int x,int y,int[][]vis,int N){
        if(x==N-1 && y==N-1){
            vis[x][y] = 1;
            return true;
        }
        
        if(isSafe(maze,x,y,N)){
            vis[x][y] = 1;
            for(int i=1;i<=maze[x][y];i++){
                
                if(solveRec(maze,x,y+i,vis,N))
                    return true;
                
                if(solveRec(maze,x+i,y,vis,N))
                    return true;
            }
            vis[x][y] =0;
        }
        return false;
    }
    
    static boolean isSafe(int[][]maze,int x,int y,int N){
        if(x<0 || x>=N || y<0 || y>=N || maze[x][y]==0)
            return false;
            
        return true;
    }
    
    static void printMaze(int [][]vis){
        for(int i=0;i<vis.length;i++){
            for(int j=0;j<vis[i].length;j++)
                System.out.print(vis[i][j]+" ");
            System.out.println();
        }
    }
}
