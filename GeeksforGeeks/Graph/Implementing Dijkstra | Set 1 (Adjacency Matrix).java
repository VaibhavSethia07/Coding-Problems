/*
Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix and in the next line are V*V space-separated values, which denote the weight of an edge of the matrix (gr[i][j] represents the weight of an edge from ith node to jth node). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test, case output will be V space-separated integers where the ith integer denotes the shortest distance of the ith vertex from source vertex.

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra() which takes the adjacency matrix of the Graph g, the source vertex src and the number of vertices V as inputs and returns a list containing the minimum distance of all the vertices from the source vertex.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 20 
1 <= V <= 100
0 <= graph[i][j] <= 1000
0 <= s < V

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.

Note:
You must assume that graph[i][j] = 0 means that the path from i to j does not exist.

#######################################################################################Solution##################################################################################
*/

class Solution
{
    static int[] dijkstra(ArrayList<ArrayList<Integer>> g, int src, int V)
    {
        int distance[] = new int[V];
        boolean finalized[] = new boolean[V];
        Arrays.fill(distance,Integer.MAX_VALUE);
        distance[src] = 0;
        
        for(int count=0;count<V-1;count++){
            int u=-1;
            for(int i=0;i<V;i++)
                if(!finalized[i] && (u==-1 || distance[i]<distance[u]))
                    u = i;
                    
            finalized[u] = true;
            
            for(int v=0;v<V;v++){
                int weight = g.get(u).get(v);
                if(!finalized[v] && weight!=0 && distance[v]>distance[u]+weight)
                    distance[v] = distance[u] + weight;    
            }
                
        }
        return distance;
    }
}
