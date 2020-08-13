/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (knightPos), the target position of Knight (targetPos) and the size of the chess board (N) as inputs and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= knight_pos(X, Y), targer_pos(X, Y) <= N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9

Explanation:
Test Case 1:

Knight takes 3 step to reach from (4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

#############################################################################Solution############################################################################################
*/

class Solution {
    // KnightPos : knight position coordinates
    // targetPos : target position coordinated
    // N : square matrix size
    public int minStepToReachTarget(int knightpos[], int targetpos[], int N) {
        boolean[][] visited = new boolean[N][N];
        Queue<Cell> q = new LinkedList<>();
        
        q.add(new Cell(knightpos[0]-1,knightpos[1]-1));
        q.add(new Cell(-1,-1));
        
        visited[knightpos[0]-1][knightpos[1]-1] = true;
        int steps = 0;
        
        int dx[] = {+2,+1,+2,+1,-2,-2,-1,-1};
        int dy[] = {+1,+2,-1,-2,+1,-1,-2,+2};
        while(q.size()>1){
            Cell cell = q.poll();
            int x = cell.x;
            int y = cell.y;
            
            if(x==-1 && y==-1){
                steps++;
                q.add(new Cell(-1,-1));
                continue;
            }
            if(x==targetpos[0]-1 && y==targetpos[1]-1)
                return steps;
                
            for(int i=0;i<8;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                
                if(xx>=N || xx<0 || yy>=N || yy<0 || visited[xx][yy])
                    continue;
                
                visited[xx][yy] = true;
                q.add(new Cell(xx,yy));
            }
        }
        
        return steps;
    }
}

class Cell{
    int x;
    int y;
    Cell(int x,int y){
        this.x = x;
        this.y = y;
    }
}
