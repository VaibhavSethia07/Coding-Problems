/*
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
Expected Time Complexity: O(n)

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15

#################################################################Solution###############################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		 
		while(T-->0){
		    int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		    int arr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int K =  Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		    
		    System.out.println(Kthsmallest(arr,N,K));
		}
	}
	
	private static int Kthsmallest(int arr[],int N,int K){
	    int temp[] = new int[100000];
		    //Making count array
		    for(int i=0;i<N;i++)
		        temp[arr[i]-1]++;
		   
		    
		    //Finding prefix sum array and Kth element
		    for(int i=1;i<100000 && temp[0]!=K;i++){
		        temp[i]+=temp[i-1];
		        if(temp[i]==K || (temp[i-1]<K && K<temp[i]))
		            return i+1;
		    }   
		    return 1;
		    
	}
	
}
