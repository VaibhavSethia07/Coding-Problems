/*
Union of two arrays
Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consist of three lines. The first line of each test case contains two space separated integers N and M, where N is the size of array A and M is the size of array B. The second line of each test case contains N space separated integers denoting elements of array A. The third line of each test case contains M space separated integers denoting elements of array B.

Output:
Correspoding to each test case, print the count of union elements of the two arrays.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, M ≤ 105
1 ≤ A[i], B[i] < 105

Example:
Input:
2
5 3
1 2 3 4 5
1 2 3
6 2
85 25 1 32 54 6
85 2
Output:
5
7

Explanation:
Testcase 1: 1, 2, 3, 4 and 5 are the elements which comes in the union set of both arrays.
Testcase 2: 1 , 2 , 6 , 25 , 32 , 54 and 85 are the elements which comes in the union set of both arrays.

################################################################Solution################################################################
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
	    
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		while(T-->0){
		    String ip[] = br.readLine().split(" ");
		    int N = Integer.parseInt(ip[0]);
		    int M = Integer.parseInt(ip[1]);
		    
		    int arr1[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		    int arr2[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		    
		    HashSet<Integer> hs = new HashSet<>();
		    for(int i=0;i<N;i++)
		        hs.add(arr1[i]);
		        
		    for(int i=0;i<M;i++)
		        hs.add(arr2[i]);
		      
		    bw.write(hs.size()+"\n");
		    bw.flush();
		}
	}
}
