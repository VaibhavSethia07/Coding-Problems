/*
Given a Matrix containing 0s and 1s. Find the unit area of the largest region of 1s (refer Your Task for complete details).

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers N and M. Then in the next line are the nxm inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findArea() which takes the number of rows N, the number of columns M and the matrix A, as inputs and returns the unit area of the largest region of connected 1s.
Each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two filled cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M).

Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[ ][ ] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with a total 4 1s (colored in Red).
Testcase 2: Matrix can be shown as follows:
1 1 1
Largest region of 1s in the above matrix is with a total of 3 1s (colored in Red).

#################################################################################Solution########################################################################################
*/

class Area {
    static int findMaxArea(int N, int M, int A[][]) {
        boolean visited[][] = new boolean[N][M];
        int mx = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(A[i][j]==1 && !visited[i][j])
                    mx = Math.max(mx,findMaxAreaUtil(A,i,j,N,M,visited));
            }
        }
            
        return mx;
    }
    
    static int findMaxAreaUtil(int graph[][],int x,int y,int N,int M,boolean[][]visited){
        visited[x][y] = true;
        int cnt = 1;
        int dx[] = {-1,+1,-1,+1,-1,+1, 0, 0};
        int dy[] = {-1,+1,+1,-1, 0, 0,+1,-1};
        
        for(int i=0;i<8;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            
            if(xx>=N || xx<0 || yy>=M || yy<0)
                continue;
            
            if(graph[xx][yy]==1 && !visited[xx][yy]){
                cnt+=findMaxAreaUtil(graph,xx,yy,N,M,visited);
            }
        }
        // System.out.println(cnt);
        return cnt;
    }
}
