/*
STAR3CAS - THE WEIRD STAIRCASE
no tags 
 

Initially you are standing at the 0th step.Find the minimum number of jumps needed to reach the top of the stair case.If there is no way to reach the top of the stair case, print -1 , else print the minimum number of jumps needed to reach the top of the staircase(nth step).If a jump results in a step , which is greater than  n, it is an invalid move.


You are given a representation of a stair case  with 'N' steps (0 to n-1). In every step a number x[i] (for ith step) is written on it. At each step you have two choices. Either you can to proceed to next step(i+1) or you can jump x[i] steps from that step(to i+x[i] th step). If the number wriiten on the step is less than 0 , you can come down that many number of steps or climb one step up. 

Initially you are standing at the 0th step.

Find the minimum number of jumps needed to reach the top of the stair case.

If there is no way to reach the top of the stair case, print -1 , else print the minimum number of jumps needed to reach the top of the staircase(nth step).

If a jump results in a step , which is greater than  n, it is an invalid move.





Input


First line consists of 'T' , the number of test cases . In every test case , the first line consists of 'n' , the number of steps. The next line consists of n integers , x[0] to x[n-1] .

 

Output

Print the minimum number of jumps required to reach the nth step . "Nth Step" is described in the problem statement.

 

Input Constraints:

1<=T<=1000

1<=n<=20

-17<=x[i]<=17 and x[i] != 0

 

Sample Input:

2 

6 

-1 2 1 3 -3 3 

10 

5 1 1 1 6 -1 1 1 1 1 

Sample Output:
3 

3

#############################################################Solution###################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.io.*;
import java.util.Arrays;

class STAR3CAS {
	static int globalJump;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		
		while(T-->0) {
			int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
			int arr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
			globalJump=Integer.MAX_VALUE;
			stairCase(arr,0,0,N);
			bw.write(globalJump+"\n");
			bw.flush();
			
		}
	}
	
	static void stairCase(int arr[],int step,int jump,int N) {
			if( step== N ) {
				globalJump = Math.min(jump, globalJump);
				return;
			}
			
			if(step>N || step<0 || jump>N) {
				return;
			}
			
			stairCase(arr,step+arr[step],jump+1,N);
			stairCase(arr,step+1,jump+1,N);
			return;
	}
}
