/*
You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:Each case begins with a single positive integer N denoting the number of books.The second line contains N space separated positive integers denoting the pages of each book.And the third line contains another integer M, denoting the number of students.

Output:
For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A [ i ] <= 106
1 <= M <= 106

Example:
Input:
2
4
12 34 67 90
2
3
15 17 20
2
Output:
113
32

Explaination:
Testcase 1:Allocation can be done in following ways:
{12} and {34, 67, 90}     Maximum Pages = 191
{12, 34} and {67, 90}     Maximum Pages = 157
{12, 34, 67} and {90}        Maximum Pages = 113

Therefore, the minimum of these cases is 113, which is selected as output.

Testcase 2: Allocation can be done in following ways:
{15} and {17,20} Maximum pages = 37
{17} and {15,20} Maximum Pages = 35
{20} and {15,17} maximum pages = 32.

So, the output will be 32.

###################################################################Solution#############################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws IOException{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	    while(T-->0){
	        int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	        int books[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
	        int M = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	        StringBuffer sb = new StringBuffer();
	        sb.append(allocation(N,books,M));
	        System.out.println(sb);
	        
	    }
	    
		
	}
	
	private static long allocation(int N,int []books,int M){
	    if(N<M)
	        return -1;
	    if(N==M)
	        return findMax(N,books);
	    
	    long start = findMax(N,books);
	    long end = sumOfArray(N,books);
	    long res = -1;
	    
	    while(start<=end){
	        long mid = start + (end-start)/2;
	        
	        if(isValid(N,M,books,mid)){
	            res = mid;
	            end = mid-1;
	        }
	        else
	            start = mid+1;
	    }
	    
	    return res;
	}
	
	private static boolean isValid(int N,int M,int books[],long mid){
	    int students = 1;
	    int sum =0;
	    
	    for(int i=0;i<N;i++){
	        sum += books[i];
	        
	        if(sum>mid){
	            students++;
	            sum = books[i];
	        }
	        
	        if(students>M)
	            return false;
	    }
	    
	    return true;
	}
	
	private static int findMax(int N,int books[]){
	    int max = Integer.MIN_VALUE;
	    for(int pages=0;pages<books.length;pages++)
	        if(books[pages]>max)
	            max = books[pages];
	    return max;
	}
	
	private static long sumOfArray(int N,int books[]){
	    long sum=0;
	    for(int i=0;i<N;i++)
	        sum += books[i];
	    return sum;  
	   
	}
}
