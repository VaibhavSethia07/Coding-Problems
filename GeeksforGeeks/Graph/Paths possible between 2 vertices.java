/*
Given a Directed Graph. Count the total number of ways or paths that exist between two vertices in the directed graph. These paths doesn’t contain any cycle.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers V and E. In the next line are E space separated values u,v denoting an edge from u to v. Next line contains the starting node s and the ending node e. (The vertices start from 1)

Output: For each testcase print the total number of paths that exists between the starting and the ending node.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPaths() which takes the adjcency list of the graph, the source vertex (s) and the destination vertex (d) as inputs and returns the number of paths in the graph from the source vertex to the destination vertex.

Expected Time Complexity: O(V!).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
1 <= V <= 100
1 <= E <= (V*(V-1))/2
1 <= u, v, s, e <= V
Graph doesn't contain multiple edges, self loop and cycles.

Example:
Input:
1
5 7
1 2 1 3 1 5 2 4 2 5 3 5 4 3
1 5

Output:
4

Explanation:
Testcase 1 :  
                       There are 4 paths from 1 to 5.
                       1 -> 5
                       1 -> 2 -> 5
                       1 -> 3 -> 5
                       1 -> 2 -> 4 -> 3 -> 5

###################################################################################Solution######################################################################################
*/

class Path {
    static int cnt = 0;
    static int countPaths(ArrayList<ArrayList<Integer>> g, int s, int d) {
        cnt = 0;
        travel(g,s,d);
        
        return cnt;
    }
    
    static void travel(ArrayList<ArrayList<Integer>> adj,int u,int d){
        if(u == d){
            cnt++;
            return;
        }
        
        for(int v : adj.get(u))
            travel(adj,v,d);
    }
}
