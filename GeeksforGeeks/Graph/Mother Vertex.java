/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers V (number of vertices) and E (number of edges). In the next line are E space separated values u,v denoting an edge from u to v.

Output: For each testcase return the mother vertex of graph (if exists) else return -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMother() which takes a Directed graph and the number of vertices as inputs and returns a Mother Vertex in the Graph. If the graph has multiple Mother Vertices, return the one with the smallest value. If the Mother Vertex does not exist, return -1.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 500
1 <= V <= 500
1 <= E <= 3000
0 <= u, v < N

Example:
Input:
2
5 5
1 0 0 2 2 1 0 3 3 4
3 2
0 1 2 1

Ouput:
0
-1

Explanation:
Testcase 1: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2. But, since we are traversing from node 0, so 0 is the output.

Testcase 2: According to the given edges, no vertices are there from where we can reach all vertices. So, output is -1.

###########################################################################Solution##############################################################################################
*/

class MotherVertex
{
    static int findMother(ArrayList<ArrayList<Integer>> g, int n)
    {
        boolean[] visited = new boolean[n];
        int mother = -1;
        for(int i=0;i<n;i++)
            if(!visited[i]){
                dfs(g,i,visited);
                mother=i;
            }
        
        Arrays.fill(visited,false);
        dfs(g,mother,visited);
        
        for(int i=0;i<n;i++)
            if(!visited[i])
                return -1;
            
        return mother;
    }
    
    static void dfs(ArrayList<ArrayList<Integer>> adj,int u,boolean[]visited){
        visited[u] = true;
        
        for(int v : adj.get(u))
            if(!visited[v])
                dfs(adj,v,visited);
            
    }
    
}
