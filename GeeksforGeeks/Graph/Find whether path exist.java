/*
Given a square matrix filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left. (Check Your Task for more details).

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space-separated values of the matrix (M).

Output:
Complete isExist function and return 1 if the path exists from source to destination else return 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function is_possible() which takes a square matrix (M) and its size (N) as inputs and returns true if there's path possible from the source to destination. Else, it returns false. 
You have to start from the Source, traverse through the blank cells and reach the Destination. You can move Up, Down, Right and Left. The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above-given input is:
0 3 2
3 0 0
1 0 0
From the matrix, we can see that there does not exist any path to reach destination 2 from source 1.

#########################################################################################Solution################################################################################
*/

// Method 1 (Using DFS)
class Solution {

    // M : input matrix
    // N : size of the matrix
    public static int is_possible(int graph[][], int M) {
        boolean visited[][] = new boolean[M][M];
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++){
                if(graph[i][j]==1 && findPath(graph,i,j,M,visited))
                    return 1;
            }
            
        return 0;
    }
    
    public static boolean findPath(int graph[][],int x,int y,int M,boolean visited[][]){
        visited[x][y] = true;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++){
                int xx = x+i;
                int yy = y+j;
                
                 if(i*j == 0 && xx<M && xx>=0 && yy<M && yy>=0 && !visited[xx][yy]){
                     if(graph[xx][yy]==2)
                        return true;
                     else if(graph[xx][yy]==0)
                        continue;
                     else{
                        if(findPath(graph,xx,yy,M,visited))
                            return true;
                     }
                 }    
            }
        return false;         
    }
}

// Method 2 (Using BFS)
class Solution {

    // M : input matrix
    // N : size of the matrix
    public static int is_possible(int graph[][], int M) {
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        Queue<Cell> q = new LinkedList<>();
        
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++)
                if(graph[i][j]==1){
                    q.add(new Cell(i,j));
                    break;
                }
            if(!q.isEmpty())
                break;
        }
            
        while(!q.isEmpty()){
            Cell cell = q.poll();
            int x = cell.x;
            int y = cell.y;
            
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                
                if(xx<0 || xx>=M || yy<0 || yy>=M)
                    continue;
                
                if(graph[xx][yy] == 2){
                    graph[xx][yy] = 1;
                    return 1;
                }
                else if(graph[xx][yy]==3){
                    graph[xx][yy] = 1;
                    q.add(new Cell(xx,yy));
                }
            }
        }
        
        return 0;
    }
}

class Cell {
    int x;
    int y;
    
    Cell(int x,int y){
        this.x = x;
        this.y = y;
    }
}
