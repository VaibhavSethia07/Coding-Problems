/*
Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array N. Next line contains the array elements.

Output:
For each testcase, there will be a single line containing the element which is repeated and the number of times it is repeated, seperated by space.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 1015

Input:
2
5
1 2 3 3 4
5
2 3 4 5 5

Output:
3 2
5 2

Example:
Testcase 1: In the given array, 3 is occuring two times.So the output is 3 2.
Testcase 2: In the given array, 5 is occuring two times.So the output is 5 2.

###############################################################Solution##################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000).trim());
		
		while(T-->0){
		    int n = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000).trim());
		    int arr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    
		    findFreq(arr,0,n-1,n);
		}
	}
		public static void findFreq(int arr[],int start,int end,int n){
		    if(start>end)
		        return;
		        
		    int mid = start + (end-start)/2;
		    int left=mid,right=mid;
		    if(mid>0 && arr[mid]==arr[mid-1])
		        left = findLeftMost(arr,start,mid-1,mid,arr[mid]);
		 
		    if(mid<n-1 && arr[mid]==arr[mid+1])
		        right = findRightMost(arr,mid+1,end,mid,arr[mid],n);
		    int freq = right - left +1;
		        
		    if(freq>1){
		        System.out.println(arr[mid]+" "+freq);
		        return;
		    }
		        
		    findFreq(arr,start,mid-1,n);
		    findFreq(arr,mid+1,end,n);
		    return;
		}
		
		private static int findLeftMost(int arr[],int start,int end,int pivot,int x){
		    if(start>end){
		        return pivot;
		    }
		    int mid = start + (end-start)/2;
		    
		    if(arr[mid] == x && (mid==0 || arr[mid-1]!=x ))
		        return mid;
		    else if(arr[mid]>=x)
		        return findLeftMost(arr,start ,mid-1,pivot,x);
		    else
		        return findLeftMost(arr,mid+1,end,pivot,x);
		}
	
	   private static int findRightMost(int arr[],int start,int end,int pivot,int x,int n){
	       if(start>end)
	            return pivot;
	       int mid = start + (end-start)/2;
	       
	       if(arr[mid] == x && (mid==n-1 || arr[mid+1]!=x))
	            return mid;
	       else if(arr[mid]<=x)
	            return findRightMost(arr,mid+1,end,pivot,x,n);
	       else
	            return findRightMost(arr,start,mid-1,pivot,x,n);    
	   }
}
