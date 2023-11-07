/*
Nth number made of prime digits
Given a number 'N'. The task is to find the Nth number whose each digit is a prime number i.e 2, 3, 5, 7. In other words, you have to find the nth number of this sequence: 2, 3, 5, 7, 22, 23,.. and so on.

Input:
The first line contains a single integer T i.e. the number of test cases. The first and only line of each test case consists of an integer N. 

Output: 
In one line print the nth number of the given sequence made of prime digits.

Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 100

Examples:
Input:
2
10
21
Output:
33
222

Explanation:
Testcase 1: 10th number in the sequence of numbers whose each digit is prime is 33.
Testcase 2: 21st number in the sequence of numbers whose each digit is prime is 222.

############################################################Solution####################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		String count[] = new String[100];
		count[0] = "2";
		count[1] = "3";
		count[2] = "5";
		count[3] = "7";
		generatePrimeDigits(count);
		while(T-->0){
		    int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		    bw.write(count[N-1]+"\n");
		    bw.flush();
		}
		
		
	}
	
	public static void generatePrimeDigits(String count[]) {
	    for(int i=0;i<24;i++){
	        String tens = count[i];
	        for(int j=0;j<4;j++){
	            count[4*(i+1)+j] = tens + count[j];
	        }
	    }   
	}
}
