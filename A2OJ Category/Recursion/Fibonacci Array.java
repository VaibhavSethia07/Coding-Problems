/*
Write a program that reads a number and print the Fibonacci number corresponding to this read number. Remember that the first elements of the Fibonacci series are 0 and 1 and each next term is the sum of the two preceding it. All the Fibonacci numbers calculated in this program must fit in a unsigned 64 bits number.

Input
The first line of the input contains a single integer T, indicating the number of test cases. Each test case contains a single integer N (0 ≤ N ≤ 60), corresponding to the N-th term of the Fibonacci series.

Output
For each test case in the input, print the message "Fib(N) = X", where X is the N-th term of the Fibonacci series.

Input Sample	Output Sample
3
0
4
2

Fib(0) = 0
Fib(4) = 3
Fib(2) = 1

########################################################Solution###########################################################################
*/
import java.io.*;
import java.util.*;

class FibonacciArray {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		
		while(T-->0) {
			int N = Integer.parseInt(br.readLine());
			int []fibo = new int[100000];
			
			fibo[0] = 0;
			fibo[1] = 1;
			fibo[2] = 1;
			
			bw.write("Fibo("+N+") = "+findFibo(N,fibo)+"\n");
			bw.flush();
			
		}
	}
	
	static int findFibo(int N,int fibo[]) {
		if(N==1 || N== 2)
			return 1;
		if(N==0)
			return 0;
		if(fibo[N] != 0)
			return fibo[N];
		else {
			fibo[N] = findFibo(N-1,fibo) + findFibo(N-2,fibo);
			return fibo[N];
		}
	}

}
