/*
You will be given an array of N integers. Write a recursive function to calculate its summation.

Input
Input starts with an integer T (T ≤ 100), the number of test cases.

Each of the next T lines will start with an integer N (1 <= N <= 100), number of integers followed by N space separated. Each of these N integers will be between -1000 and 1000 (inclusive).

Output
For each test case, output one line in the format “Case x: a” (quotes for clarity), where x is the case number and a is the summation of the integers.

Example
Input:
2
5 10 5 -2 3 0
3 100 -10 34


Output:
Case 1: 16
Case 2: 124

#################################################################Solution##################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.io.*;


class HelloRecursion {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		int t=1;
		while(t<=T) {
			int input[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
			int N = input[0];
			bw.write("Case "+t+": "+summation(input, N)+"\n");
			t++;
		}
		bw.flush();
	}
	
	static int summation(int arr[],int N) {
		
		if(N==0)
			return 0;
		else
			return arr[N]+summation(arr,N-1);
	}

}
