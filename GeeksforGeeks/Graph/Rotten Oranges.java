/*
Given a matrix of dimension RxC where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers R and C, where R is the number of rows and C is the number of columns in the matrix[][]. Next line contains space separated RxC elements.

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

User Task:
Complete the function rotOranges which takes the RxC matrix, R and C as input and returns the minimum time required to rot all oranges.

Constraints:
1 <= T <= 100
1 <= R <= 1000
1 <= C <= 1000
0 <= matrix[i][j] <= 2

Expected Time Complexity : O(r*c)

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will rot oranges at {0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time. And, during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}. Hence, total 2 unit of time is required to rot all oranges.

####################################################################################Solution#####################################################################################
*/

class Solution
{
    public int rotOranges(int graph[][],int r, int c)
    {
        int time = 0;
        Queue<Cell> q = new LinkedList<>();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(graph[i][j] == 2)
                    q.add(new Cell(i,j));
                    
        q.add(new Cell(-1,-1));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = { 0, 0, 1,-1};
        
        
        while(q.size()>1){
            Cell cell = q.poll();
            int x = cell.x;
            int y = cell.y;
            
            if(x==-1 && y==-1){
                time++;
                q.add(new Cell(-1,-1));
                continue;
            }
            
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                
                if(xx<0 || xx>=r || yy<0 || yy>=c)
                    continue;
                    
                if(graph[xx][yy]==1){
                    graph[xx][yy] = 2;
                    q.add(new Cell(xx,yy));
                }
            }
        }
        
        // Check if all oranges have rotten or not
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                if(graph[i][j]==1)
                    return -1;
        }
        return time;
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
