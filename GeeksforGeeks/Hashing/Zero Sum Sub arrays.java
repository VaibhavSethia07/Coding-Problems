/*
Zero Sum Subarrays
You are given an array A of size N. You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1 <= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7
Output:
6
4

Explanation:
Testcase 1: There are 6 subarrays present whose sum is zero. The starting and ending indices are:
(0,0) (1,1) (0,1) (4,4) (5,5) (4,5)
Testcase 2: There are 4 subarrays present whose sum is zero. The starting and ending indices are:
(1,3) (4,5) (1,5) (5,8)

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
		    bw.write(""+zeroSumSubarrays(arr,N)+"\n");
		    bw.flush();
		}
	}
	
	private static int zeroSumSubarrays(int arr[],int N){
	    HashMap<Integer,Integer> hm = new HashMap<>();
	    
	    int count=0;
	    int prefixSum=0;
	    hm.put(0,1);
        
        for(int i=0;i<N;i++){
            prefixSum += arr[i];
            
            if(!hm.containsKey(prefixSum))
                hm.put(prefixSum,1);
            else{
                int value = hm.get(prefixSum);
                count += value;
                hm.put(prefixSum,value+1);
            }
        }	    
	    return count;
	}
}
