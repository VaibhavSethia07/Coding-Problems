/*
Given N * M string array arr of O's and X's. The task is to find the number of 'X' total shapes.
'X' shape consists of one or more adjacent X's (diagonals not included).

Input:
The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, in a new line print the total X shapes.

Your Task:
Complete Shape function that takes string array arr, n, m as arguments and returns the count of total X shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Expected Time Complexity : O(N*M)
Expected Auxilliary Space : O(1)

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.

#################################################################################Solution########################################################################################
*/

public static int Shape(String []arr,int n,int m)
{
    boolean visited[][] = new boolean[n][m];
    int cnt = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i].charAt(j)=='X'){
                cnt++;
                spread(arr,i,j,n,m,visited);
            }
        }
            
    return cnt;
}

static void spread(String arr[],int x,int y,int N,int M,boolean visited[][]){
    visited[x][y] = true;
    
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){
            int xx = x+i;
            int yy = y+j;
            if(i*j == 0 && xx<N && xx>=0 && yy<M && yy>=0 && arr[xx].charAt(yy)=='X' && !visited[xx][yy])
                spread(arr,xx,yy,N,M,visited);
        }
}
