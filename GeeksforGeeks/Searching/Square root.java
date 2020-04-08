/*
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Input:
First line of input contains number of testcases T. For each testcase, the only line contains the number x.

Output:
For each testcase, print square root of given integer.

User Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Constraints:
1 ≤ T ≤ 1000
1 ≤ x ≤ 107

Example:
Input:
2
5
4
Output:
2
2

###########################################################Solution#####################################################################
*/
class SquareRoot
{
     long floorSqrt(long x)
	 {
	     if(x==0 || x==1)
	        return x;
	        
		long start=1L,end=x;
		long ans=0;
		while(start<=end){
		    long mid = start + (end-start)/2;
		    
		    if(mid*mid == x)
		        return mid;
		        
		    else if(mid*mid>x)
		        end = mid-1;
		      
		    else if(mid*mid<x){
		        start = mid+1;
		        ans=mid;
		    }
		}
		return ans;
	 }
}
