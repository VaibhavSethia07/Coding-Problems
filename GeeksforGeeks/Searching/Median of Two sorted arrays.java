/*
Given two sorted arrays arr[] and brr[] of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.

Input:
First line of input contains number of testcases T. First line of input contains number of elements in both arrays N and M respectively. Next two lines contains the array elements.

Output:
For each testcase, print the median of two sorted arrays. If there are total even elements, we need to print floor of average of middle two elements.

Constraints:
1 <= T <= 100
1 <= N, M <= 106
1 <= arr[i], brr[i] <= 107

Example:
Input:
4
5 6
1 2 3 4 5
3 4 5 6 7 8
2 3
1 2
2 3 4
4 4
1 2 3 4
11 12 13 14
4 3
1 2 3 4
2 3 4

Output:
4
2
7
3

Explanation:
Testcase 1: After merging two arrays, elements will be as 1 2 3 3 4 4 5 5 6 7 8. So, median is 4.
Testcase 2: After merging two arrays , elements will be 1 2 2 3 4. So, the median is 2.
Testcase 3: After merging two arrays , elemenst will be 1 2 3 4 11 12 13 14 . So the median will be floor of average of middle terms i.e, 7.
Testcase 4: After merging two arrays, elements will be 1 2 2 3 3 4 4. So, the median will be 3.

###########################################################Solution#####################################################################
*/
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0){
		    int input[] = Arrays.stream(br.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int N = input[0];
		    int M = input[1];
		    int arr[] = Arrays.stream(br.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int brr[] = Arrays.stream(br.readLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int merged[] = new int[N+M];
		    merge(merged,arr,brr,N,M);
		    System.out.println(getMedian(merged));
		}
	}
	
	private static void merge(int merged[],int arr[],int brr[],int N,int M){
	    int i=0,j=0,k=0;
	    while(i<N && j<M){
	        if(arr[i]<brr[j]){
	            merged[k++] = arr[i++];
	        }
	        else if(arr[i] == brr[j]){
	            merged[k++] = arr[i++];
	            merged[k++] = brr[j++];
	        }
	        else{
	            merged[k++] = brr[j++];
	        }
	    }
	    
	    while(i<N)
	        merged[k++] = arr[i++];
	   
	    while(j<M)
	        merged[k++] = brr[j++];
	}
	
	private static int getMedian(int merged[]){
	    int n = merged.length;
	    if((n & 1) ==0){
		    return (merged[n/2-1]+merged[n/2])/2; 
		}
		else
		    return merged[n/2];
	}
}
