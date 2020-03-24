/*
Given an integer an N. The task is to print the position of first set bit found from right side in the binary representation of the number.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. The only line of the each test case contains an integer N.

Output:
For each test case print in a single line an integer denoting the position of the first set bit found form right side of the binary representation of the number. If there is no set bit print "0".

User Task:
The task is to complete the function getFirstSetBit() that takes n as parameter and returns the the position of first set bit.

Constraints:
1 <= T <= 200
0 <= N <= 106

Example:
Input:
3
18
12
0

Output:
2
3
0

##########################################################Solution######################################################################
*/

public static int getFirstSetBitPos(int n){
        if(n!=0)
            return (int)(Math.log(n & ~(n-1))/Math.log(2))+1;
        return 0;
}
