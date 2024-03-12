/*
You are given a string S of alphabet characters and the task is to find its matching decimal representation as on the shown keypad. Output the decimal representation corresponding to the string. For example: if you are given “amazon” then its corresponding decimal representation will be 262966.



Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing a string.

Output:
For each test case, print in a new line, the corresponding decimal representation of the given string.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: N = |S|.

Constraints:
1 ≤ T ≤ 100
1 ≤ length of String ≤ 100

Example:
Input:
2
geeksforgeeks
geeksquiz
Output:
4335736743357
433577849

Explanation:
Testcase 1: In geekforgeeks, decimal representation for g is 4, e is 3, k is 5, s is 7 and so on. Hence the output for the given input will be 4335736743357.
Testcase 2: In geeksquiz, decimal representation for g is 4, e is 3, k is 5, s is 7, q is 7, u is 8, i is 4 and z is 9. Hence, output for the given input will be 433577849.

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
	    int ascii[] = new int[26];
		
		for(int i=0;i<26;i++){
		    if(i<=2)
		        ascii[i] = 2;
		    else if(i<=5)
		        ascii[i] = 3;
		    else if(i<=8)
		        ascii[i] = 4;
		    else if(i<=11)
		        ascii[i] = 5;
		    else if(i<=14)
		        ascii[i] = 6;
		    else if(i<=18)
		        ascii[i] = 7;
		    else if(i<=21)
		        ascii[i] = 8;
		    else if(i<=25)
		        ascii[i] = 9;
		}
		
	    int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	    while(T-->0){
	        String str = BoundedLineReader.readLine(br, 5_000_000);
	        bw.write(keypadTyping(str,ascii)+"\n");
	        bw.flush();
	    }
	}
	
	static String keypadTyping(String str,int ascii[]){
	    String result="";
	    for(int i=0;i<str.length();i++)
	        result+=ascii[str.charAt(i)-'a'];
	   return result;
	}
}
