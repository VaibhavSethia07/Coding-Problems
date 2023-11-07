/*
Hashing is very useful to keep track of the frequency of the elements in a list.

You are given an array arr of size n. You need to print the distinct elements as they appear in the array.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains n denoting the size of the array. The second line contains n elements of the array.

Output:
For each testcase, in a new line, print the distinct elements in the order they appear in the array.

Constraints:
1 <= T <= 100
1 <= n <= 103
0 <= arri <= 107

Examples:
Input:
1
10
1 1 2 2 3 3 4 5 6 7
Output:
4 5 6 7

###########################################################################Solution########################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		
	    while(T-->0){
	        int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	        int arr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
	        
	        printDistinct(arr,N);
	    }
	}
	
	private static void printDistinct(int arr[],int N) throws Exception{
	    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	    
	    HashMap<Integer,Integer> hm = new HashMap<>();
	    
	    for(int i=0;i<N;i++){
	        if(!hm.containsKey(arr[i]))
	            hm.put(arr[i],1);
	        else
	            hm.put(arr[i],0);
	    }
	    
	    for(int i=0;i<N;i++){
	        if(hm.get(arr[i]) == 1)
	            bw.write(arr[i]+" ");
	    }
	    bw.write("\n");
	    bw.flush();
	}
}
