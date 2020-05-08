/*
Given an array of N distinct elements A[ ]. The task is to find the minimum number of swaps required to sort the array. Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 104
 

User Task:
Your task is to complete minSwaps() which should return number of swaps required to make the array elements sorted.

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2

Explanation:
Testcase 1: We need two swaps, swap 1 with 4 and 3 with 2 to make it sorted.

##############################################################Solution##################################################################
*/

class GfG
{
	public static int minSwaps(int[] A, int N)
	{
	    int count =0;
	    for(int i=0;i<N;i++){
	        int min = i;
	        for(int j = i+1;j<N;j++){
	            if(A[min]>A[j])
	                min = j;
	        }
	        if(min != i){
	            int temp = A[i];
	            A[i] = A[min];
	            A[min] = temp;
	            count++;
	        }
	    }
	    return count;
	    
    }
}
