/*
Given N in Gray code equivalent. Find its binary equivalent.

Input:
The first line contains an integer T, number of test cases. For each test cases, there is an integer N denoting the number in gray equivalent.

Output:
For each test case, in a new line, the output is the decimal equivalent number N of binary form.

User Task:
Your task is to complete the function grayToBinary() which returns decimal of the binary equivalent of the given gray number.

Constraints:
1 <= T <= 100
0 <= N <= 108

Example:
Input:
3
4
15
0

Output:
7
10
0

Explanation:
Testcase1. 4 is represented as gray 100 and its binary equivalent is 111 whose decimal equivalent is 7.
Testcase2. 15 is represented as gray 1111 and its binary equivalent is 1010 i.e. 10 in decimal.
Testcase3: Zero is zero in gray and in binary and decimal.

##########################################################Solution######################################################################
*/

class BitWise{
    
    public static int grayToBinary(int n) {
        
        int d=n;
        d>>=1;
        
        while(d>0){
            n=d^n;
            d>>=1;
        }
        return n;
        
    }
       
}
