/*
Intersection of two arrays
Given two arrays A and B respectively of size N and M. The task is to print the count of elements in the intersection (or common elements) of the two arrays.
For this question, intersection of two arrays can be defined as the set containing distinct common elements between the two arrays.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N and M, N is the size of array A and M is size of array B. The second line of each test case contains N input A[i].
The third line of each test case contains M input B[i].

Output:
Print the count of intersecting elements.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, M ≤ 105
1 ≤ A[i], B[i] ≤ 105

Example:
Input:
4
5 3
89 24 75 11 23
89 2 4
6 5
1 2 3 4 5 6
3 4 5 6 7
4 4
10 10 10 10
20 20 20 20
3 3
10 10 10
10 10 10
Output:
1
4
0
1

Explanation:
Testcase 1: 89 is the only element in the intersection of two arrays.
Testcase 2: 3 4 5 and 6 are the elements in the intersection of two arrays.
Testcase 3: Non of the elements are common so the output will be -1.
Testcase 4: 10 is the only element which is in the intersection of two arrays.

############################################################Solution####################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		while(T-->0){
		    String[] ip = BoundedLineReader.readLine(br, 5_000_000).split(" ");
		    int N = Integer.parseInt(ip[0]);
		    int M = Integer.parseInt(ip[1]);
		    int []arr1 = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
		    int []arr2 = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
		    bw.write(""+intersection(arr1,N,arr2,M)+"\n");
		    bw.flush();
		}
	}
	
	public static int intersection(int arr1[],int N,int arr2[],int M){
	    HashSet<Integer> hs1 = new HashSet<>();
    	for(int i=0;i<N;i++)
	        hs1.add(arr1[i]);
	    
	    HashSet<Integer> hs2 = new HashSet<>();
	    for(int i=0;i<M;i++)
	        hs2.add(arr2[i]);
	    
	    int count=0;
	    Iterator<Integer> itr = hs1.iterator();
	    
	    while(itr.hasNext()){
	        if(hs2.contains(itr.next()))
	            count++;
	    }
	    
	    return count;
	}
}
