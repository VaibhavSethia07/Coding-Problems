/*
Given an array arr[] of N numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an integer N and the second line contains N space separated array elements.

Output:
For each test case, In new line print the required elements in increasing order. if there is no such element present in the array print "-1".

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
3
4 6 7
4
1 2 3 4
5
12 111 34 13 55
Output:
-1
1 2 3
12 13 111

Explanation:
Testcase 1: No elements are there in the array which contains digits 1, 2 or 3.
Testcase 2: 1, 2 and 3 are the only elements in the array which conatins digits as 1, 2 or 3.
Testcase 3: 12 , 13 and111 are the three elements in the array which contains digit as 1 , 2 or 3.

##############################################################Solution##################################################################
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
		    numbersContaining123(arr,N);
		    
		}
	}
	
	private static void numbersContaining123(int arr[],int N) throws Exception{
	    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	    
	    ArrayList<Integer> al = new ArrayList<>();
		    
	    for(int i=0;i<N;i++){
	        String str = String.valueOf(arr[i]);
	        if(str.contains("4") || str.contains("5") || str.contains("6") || str.contains("7") || str.contains("8") || str.contains("9")|| str.contains("0"))
	            continue;
	        al.add(arr[i]);
	    }
	    Collections.sort(al);
	    if(al.size()==0){
	        bw.write(-1+"\n");
	        bw.flush();
	       return;
	    }
	    Iterator itr = al.iterator();
	    
	    while(itr.hasNext())
	        bw.write(itr.next()+" ");
	    bw.write("\n");
	    bw.flush();
	}
}
