/*
Bridge Edge in Graph
Given an undirected graph and an edge, the task is to find if the given edge is a bridge in graph, i.e., removing the edge disconnects the graph.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. 
Description of  test cases is as follows:
The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively.
The Second line of each test case contains M space-separated pairs u and v denoting that there is a bidirectional edge from u to v.
The third line contains two space-separated integers denoting the edge to be removed.

Output:
Output 1 if the edge is a Bridge and output 0 otherwise.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isBridge() which takes the graph g, number of vertices V and the two end vertices s and e of an edge as inputs and returns true if the given edge is a Bridge. Else, it returns false.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 10
1 <= N, M <= 100000
0 <= u, v <= N-1
Example:

Input:

2
4 3
0 1 1 2 2 3
1 2
5 5
1 2 2 0 1 0 3 4 3 0
2 0

Output:

1
0

Note: The Input/Output format and Example is given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.

########################################################################Solution#################################################################################################
*/

class Solution {

    public boolean isBridge(Graph adj, int s, int e) {
        int V = adj.edges.length;
        int index = adj.edges[s].indexOf(e);
        adj.edges[s].remove(index);
        
        boolean visited[] = new boolean[V];
        dfs(adj,s,visited);
        
        return !visited[e];
    }
    
    public static void dfs(Graph adj,int u,boolean visited[]){
        visited[u] = true;
        
        for(int v : adj.edges[u])
            if(!visited[v])
                dfs(adj,v,visited);
    }
}
