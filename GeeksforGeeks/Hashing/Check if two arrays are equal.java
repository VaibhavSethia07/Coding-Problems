/*
Check if two arrays are equal or not
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  Each test case contains 3 lines of input. The first line contains an integer N denoting the size of the array. The second line contains element of array A[]. The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[],B[] <= 1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15
Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1}; Since all the array elements are same. So,
Output : 1
Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15}; Since all the array elements are not same. So,
Output : 0

#############################################################Solution###################################################################
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
		    long N = Long.parseLong(BoundedLineReader.readLine(br, 5_000_000));
		    long arr1[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToLong(Long::parseLong).toArray();
		    long arr2[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToLong(Long::parseLong).toArray();
		    
		    bw.write(isEqual(arr1,arr2,N)+"\n");
		    bw.flush();
		    
		}
		
	}
	
	private static int isEqual(long arr1[],long arr2[],long N){
	    HashMap<Long,Long> hm = new HashMap<>();
		    
		    for(int i=0;i<N;i++){
		        if(!hm.containsKey(arr1[i]))
		            hm.put(arr1[i],1L);
		        else{
		            long val = hm.get(arr1[i])+1;
		            hm.put(arr1[i],val);
		        }
		    }
		    
		    for(int i=0;i<N;i++){
		        if(!hm.containsKey(arr2[i]))
		            return 0;
		        long val = hm.get(arr2[i])-1;
		        hm.put(arr2[i],val);
		    }
		    
		    for(int i=0;i<N;i++)
		        if(hm.get(arr1[i]) !=0L)
		            return 0;
		    return 1;
	}
}
