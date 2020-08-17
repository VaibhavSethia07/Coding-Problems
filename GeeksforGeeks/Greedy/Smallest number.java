/*
The task is to find the smallest number with given sum of digits as s and number of digits as d.

Expected Time Complexity: O(d)

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of a single line containing two space separated integers s and d, where s is digit sum and d is number of digits.

Output:
Corresponding to each test case, in a new line, print the smallest number if possible, else print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ s ≤ 100
1 ≤ d ≤ 6

Example:
Input
3
9 2
20 3
63 3

Output
18
299
-1

#############################################################################Solution##############################################################################################
*/

import java.util.*;
import java.io.*;

class Solution{
	long mod = 998_244_353L; // (long) 1e9 + 7 || (long) 1e9 + 9
    
	public static void main(String args[])throws Exception{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int T = in.nextInt();
		
		while(T-->0){
			int S = in.nextInt();
			int D = in.nextInt();
			
			int smallest = 1;
			int limit = 9;
			for(int i=1;i<D;i++){
				smallest*=10;
				limit=limit*10+9;
			}
			
			int sum=1;
			int begin = sum;
			while(sum<S && smallest<=limit){
			 //   w.println(smallest+" "+sum);
				sum++;
				smallest++;
				
				if(smallest%10==0){
					int N = smallest/10;
					sum = 0;
					while(N>0){
					    sum+=N%10;
					    N/=10;
					}
				}
			}
			
			if(sum==S)
				w.println(smallest);
			else
				w.println(-1);
		}
		w.close();
	}
	
	void shuffleInt(int[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }

    void shuffleLong(long[] a) {
        Random random = new Random();
        for (int i = a.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            long swap = a[j];
            a[j] = a[i];
            a[i] = swap;
        }
    }

    
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long binpow(long a, long n) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = res * a;
            a *= a;
            n /= 2;
        }
        return res;
    }

    long binpowmod(long a, long n) {
        long res = 1;
        a %= mod;
        n %= mod - 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    }
    
    	static class InputReader {
 
		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
 
		public InputReader(InputStream st) {
			this.stream = st;
		}
 
		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int nextInt() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public long nextLong() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}
 
		public String readString() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
	}
}

