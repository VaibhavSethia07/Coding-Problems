/*
Given an connected undirected graph of N edges and a node X is given. The task is to find the level of X. if X does not exist in the graph then print -1.
 


Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes and edges N and E. Next E lines contais U and V, which represents that there is an edge between U and V. The final line contains X whose level we have to find.

Output:
For each testcase, print the level of the given node X.

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
0 <= U, V < N
1 <= X <= 104
Graph doesn't contain multiple edges and self loops.

Example:
Input:
1
8 8
0 1
0 2
1 3
1 4
1 5
2 6
6 7
2 5
7

Output:
3

Explanation:
Testcases 1: In the given graph(above), 7 is at 3rd level starting from source node 0 which is at 0th level.

###############################################################################Solution##########################################################################################
*/

class Level_of_Nodes
{
    
    static int levels(ArrayList<ArrayList<Integer>> list, int x, int in)
    {
        boolean visited[] = new boolean[list.size()];
        
        Queue<Integer> q = new LinkedList<>();
        q.add(in);
        q.add(-1);
        visited[in] = true;
        int level = 0;
        
        while(q.size()!=1){
            int u = q.poll();
            
            if(u == -1){
                level++;
                q.add(-1);
                continue;
            }
            
            visited[u] = true;
            if(u == x)
                return level;
            
            for(int v : list.get(u)){
                if(!visited[v])
                    q.add(v);
            }
            
        }
        return -1;
    }
}
