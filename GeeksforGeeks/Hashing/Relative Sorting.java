/*
Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
2
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
8 4
2 6 7 5 2 6 8 4 
2 6 4 5
Output:
2 2 1 1 8 8 3 5 6 7 9
2 2 6 6 4 5 7 8

Explanation:
Testcase 1: After sorting the resulted output is 2 2 1 1 8 8 3 5 6 7 9.
Testcase 2: After sorting the resulted output is 2 2 6 6 4 5 7 8.
*/


import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		while(T-->0){
		    String ip[] = br.readLine().split(" ");
		    int N = Integer.parseInt(ip[0]);
		    int M = Integer.parseInt(ip[1]);
		    
		    int arr1[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		    int arr2[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		    relativeSorting(arr1,N,arr2,M);
		}
	}
	
	private static void relativeSorting(int arr1[],int N,int arr2[],int M) throws Exception{
	    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	    
	    TreeMap<Integer,Integer> tm = new TreeMap<>();
	   
	    for(int i=0;i<N;i++){
	        if(!tm.containsKey(arr1[i]))
	            tm.put(arr1[i],1);
	        else{
	            int val = tm.get(arr1[i])+1;
	            tm.put(arr1[i],val);
	        }
	    }
	    
	    for(int i=0;i<M;i++){
	        if(tm.containsKey(arr2[i])){
	            int val = tm.get(arr2[i]);
	            while(val-->0){
	                bw.write(""+arr2[i]+" ");
	                
	            }
	            tm.remove(arr2[i]);
	            
	        }
	    }
	    Iterator<Map.Entry<Integer,Integer>> itr = tm.entrySet().iterator();
	    
	    while(itr.hasNext()){
	        Map.Entry<Integer,Integer> entry = itr.next();
	        int key = entry.getKey();
	        int val = entry.getValue();
	        while(val-->0){
	            bw.write(""+key+" ");
	        }
	    }
	    bw.write("\n");
	    bw.flush();
	}
}
