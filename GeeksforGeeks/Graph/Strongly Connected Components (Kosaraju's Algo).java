/*
Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju() which returns an integer denoting the number of strongly connected components in the graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers N and M. In the next line there are M space-separated values u,v denoting an edge from u to v.

Output:
For each test case in a new line output will an integer denoting the no of strongly connected components present in the graph.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 5000
0 <= M <= (N*(N-1))
0 <= u, v <= N-1
Sum of M over all testcases will not exceed 25*106

Example:
Input:
2
5 5
1 0 0 2 2 1 0 3 3 4
3 3
0 1 1 2 2 0

Output:
3
1

Explanation:
Testcase 1:
There is a connected subgraph that includes 0-1-2 which satisfy the condition of strongly connecting components i.e each node is reachable from every other nodes.

Another subgraph includes individual nodes 4 and 3. That gives us a total of 3 subgraphs satisfying the condition of strongly connected components.

#####################################################################################Solution####################################################################################
*/

class Solution
{
    public int kosaraju(ArrayList<ArrayList<Integer>> adj, int N)
    {
        boolean visited[] = new boolean[N];
        Stack<Integer> st = new Stack<>();
        int[] res = new int[N];
        
        for(int i=0;i<N;i++)
            if(!visited[i])
                topologicalDFS(adj,i,visited,st);
                
        int index = 0;       
        while(!st.isEmpty())
            res[index++] =st.pop();
            
        ArrayList<ArrayList<Integer>> transpose = generateTranspose(adj);
        Arrays.fill(visited,false);
        
        int cnt = 0;
        for(int i=0;i<N;i++)
            if(!visited[res[i]]){
                dfs(transpose,res[i],visited);
                cnt++;
            }
        
        return cnt;
    }
    
    public static void topologicalDFS(ArrayList<ArrayList<Integer>> adj,int u,boolean[]visited,Stack<Integer> st){
        visited[u] = true;
        
        for(int v : adj.get(u))
            if(!visited[v])
                topologicalDFS(adj,v,visited,st);
            
        st.push(u);
    }
    
    public static ArrayList<ArrayList<Integer>> generateTranspose(ArrayList<ArrayList<Integer>> graph){
        ArrayList<ArrayList<Integer>> transpose = new ArrayList<>();
        
        for(int i=0;i<graph.size();i++)
            transpose.add(new ArrayList<>());
            
        for(int i=0;i<graph.size();i++)
            for(int v : graph.get(i))
                transpose.get(v).add(i);
                
        return transpose;
    }
    
    public static void dfs(ArrayList<ArrayList<Integer>> adj,int u,boolean[]visited){
        visited[u] = true;
        
        for(int v : adj.get(u))
            if(!visited[v])
                dfs(adj,v,visited);
    }
}
