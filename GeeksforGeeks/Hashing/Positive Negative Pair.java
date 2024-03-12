/*
Given an array arr[] of N positive and negative integer pairs, may not be in sorted order. The task is to pair the positive and negative element in such a way that a positive element is paired with a negative element of same absolute value. If a pair element is not present for an element, then ignore it. The output should contain all pairs in increasing order of absolute values. To print a pair, positive value should be printed before its corresponding negative value.
Note: The elements in array are distinct.

Input:
First line of input contains number of testcases T. For each testcase, first line contains an integer N, number of elements in the array. Next line contains N space separated array elements.

Output:
For each testcase, print the pairs of positive and negative, sorted with positive numbers. If no such pair exists, print 0.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
8
1 3 6 -2 -1 -3 2 7
3
3 2 -3
Output:
1 -1 2 -2 3 -3
3 -3

Explanation:
Testcase 1: 1, 2 and 3 are present pairwirse postive and negative. 6 and 7 have no pair.
Testcase 2: 3 is the only element present pairwise positive and negative.

##################################################################Solution##############################################################
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
		    
		    positiveNegativePair(arr, N);
		}
	}
	
	private static void positiveNegativePair(int arr[],int N) throws Exception{
	    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	    
	    TreeMap<Integer,Integer> pairs = new TreeMap<>();
	    
	    for(int i=0;i<N;i++){
	        int absValue = Math.abs(arr[i]);
	        
	        if(!pairs.containsKey(absValue))
	            pairs.put(absValue,Integer.MIN_VALUE);
	        else{
	            int negValue = -absValue;
	            pairs.put(absValue,negValue);
	        }
	    }
	    
        Iterator<Map.Entry<Integer,Integer>> itr = pairs.entrySet().iterator();
        boolean check = false;
        while(itr.hasNext()){
            Map.Entry<Integer,Integer> entry = itr.next();
            
            if(entry.getValue()== Integer.MIN_VALUE){
                continue;
            }
            check = true;
            bw.write(""+entry.getKey()+" "+entry.getValue()+" ");
        }
        
        if(!check)
            bw.write(""+0);
        bw.write("\n");
        bw.flush();
	}
}
