/*
First Repeating Element
Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Input :
The first line contains an integer T denoting the total number of test cases. In each test cases, First line is number of elements in array N and second its values.

Output:
In each separate line print the index of first repeating element, if there is not any repeating element then print “-1” (without quotes). Use 1 Based Indexing.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 106

Example:
Input:
3
7
1 5 3 4 3 5 6
4
1 2 3 4
5
1 2 2 1 3
Output:
2
-1
1

Explanation: 
Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is less than 3 whose first occuring index is 3.
Testcase 2: None of the elements are occuring twice . So, the answer is -1.
Testcase 3: 1 is appearing twice and its first appearence is at index 1 which is less than 2 whose first occuring is at index 2.

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
		    int N = Integer.parseInt(br.readLine());
		    int arr[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		    bw.write(""+firstRepeating(arr,N)+"\n");
		    bw.flush();
		}
	}
	
	public static int firstRepeating(int arr[],int N){
	    HashMap<Integer,Integer> hm = new HashMap<>();
		int minIndex=Integer.MAX_VALUE;
		for(int i=0;i<N;i++){
		    if(hm.containsKey(arr[i]))
		        minIndex = Math.min(hm.get(arr[i]),minIndex);
		    hm.put(arr[i],i+1);
		}
	 
		return ((minIndex!=Integer.MAX_VALUE)?minIndex:-1);
	}
}
