/*
Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on right side(even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains single line.

Output:
For each testcase in new line, print the converted number.

User Task:
Your task is to complete the function swapBits() which takes and integer and returns integer with all the odd and even bits swapped.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
23
2

Output:
43
1

Explanation:
Testcase 1: Binary representation of the given number is 00010111 after swapping 00101011 = 43 in decimal.
Testcase 2: Binary representation of the given number is 10 after swapping 01 = 1 in decimal.

##############################################################Solution###################################################################
*/

class Swap{
   
    public static int swapBits(int n) {
	    
	    int eve= n & 0xAAAAAAAA;
	    int odd= n & 0x55555555;
	    
	    eve>>=1;
	    odd<<=1;
	    
	    return eve | odd;
	    
	}
    
}
