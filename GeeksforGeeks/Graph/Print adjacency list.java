/*
Given the adjacency list of a bidirectional graph. Your task is to print the adjacency list for each vertex.

Input:
The first line of input is T denoting the number of testcases.Then first line of each of the T contains two positive integer V and E where 'V' is the number of vertex and 'E' is number of edges in graph. Next, 'E' line contains two positive numbers showing that there is an edge between these two vertex.

Output:
For each vertex, print their connected nodes in order you are pushing them inside the list. See the example input-output for the reference of format.

Your Task:
You don't need to read input or print anything. Your task is to complete the function printGraph () which takes the adjacency list of the graph and the number of vertices V as inputs and prints the adjacency list of the Graph.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 200
1 <= V <= 103
1 <= E = V*(V-1)

Example:
Input:
1
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4

Output:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3

Explanation:
Testcase 1: Given graph has 5 nodes and 7 edges. After creating adjacency list of given graph, we have list as:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3

##############################################################################Solution###########################################################################################
*/

class Adjacency 
{
    static void printGraph(ArrayList<ArrayList<Integer>> adj, int V)
	{
	    for(int i=0;i<V;i++){
	        System.out.print(i);
	        for(int v : adj.get(i))
	            System.out.print("-> "+v);
	        System.out.println();
	    }
	}
}
