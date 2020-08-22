/*
Given a binary matrix. Find the distance of nearest 1 in the matrix for each cell.

Input:
The first line of input is an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains two integers M and N denoting the number of rows and columns of matrix. Then in the next line are N*M space separated values of the matrix (mat) .

Output:
For each test case in a new line print the required distance matrix in a single line separated by space.

Your Task:
You don't need to read input or print anything. Your task is to complete the function nearest() which takes the matrix (mat) and its dimensions (N and M) as inputs and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from mat[i][j].
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M).

Constraints:
1 <= T <= 50
1 <= N, M <= 1000
0 <= mat[i][j] <= 1

Example:
Input:
2
2 2 
1 0 0 1
1 2
1 1

Output:
0 1 1 0
0 0

Explanation:
Testcase 1:
1 0
0 1
0 at {0, 1} and 0 at {1, 0} are at 1 distance from 1s at {0, 0} and {1, 1} respectively.

##############################################################################Solution###########################################################################################
*/

class Distance {
    static ArrayList<ArrayList<Integer>> nearest(ArrayList<ArrayList<Integer>> mat, int N, int M) {
        ArrayList<ArrayList<Integer>> distance= new ArrayList<>(N);
        Queue<Cell> q = new LinkedList<>();
        int temp[][] = new int[N][M];
        
        for(int i=0;i<N;i++)
            distance.add(new ArrayList<>());
            
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat.get(i).get(j)==1){
                    temp[i][j] = 0;
                    q.add(new Cell(i,j));
                }
                else
                    temp[i][j] = Integer.MAX_VALUE;
            }
        }
        
        while(!q.isEmpty())
            bfs(temp,q.poll(),N,M);
         
        for(int i=0;i<N;i++)
            for(int v : temp[i])
                distance.get(i).add(v);
                
        return distance;
    }
    
    static void bfs(int temp[][],Cell cell,int N,int M){
        Queue<Cell> q = new LinkedList<>();
        int x = cell.x;
        int y = cell.y;
        
        boolean visited[][] = new boolean[N][M];
        
        q.add(cell);
        visited[x][y] = true;
        
        int dx[] = {-1,+1, 0, 0};
        int dy[] = { 0, 0,-1,+1};
        
        while(!q.isEmpty()){
            Cell bfsCell = q.poll();
            int a = bfsCell.x;
            int b = bfsCell.y;
            
            for(int i=0;i<4;i++){
                int xx = a+dx[i];
                int yy = b+dy[i];
                
                if(xx>=N || xx<0 || yy>=M || yy<0 || visited[xx][yy])
                    continue;
                visited[xx][yy] = true;
                q.add(new Cell(xx,yy));
                int shortest = Math.abs(x-xx)+Math.abs(y-yy);
                temp[xx][yy] = Math.min(temp[xx][yy],shortest);
            }
        }
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
