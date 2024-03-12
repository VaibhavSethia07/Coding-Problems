
import io.github.pixee.security.BoundedLineReader;
import java.io.*;
import java.util.*;

class FibonacciArray {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		
		while(T-->0) {
			int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
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
