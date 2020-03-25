/*
Given a number N.  The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set  in the binary representation.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is number 'N'.

Output:
Print '1' if the number is sparse and '0' if the number is not sparse.

User Task:
The task is to complete the function checkSparse() that takes n as parameter and returns true if the number is sparse else returns false.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
3

Output:
1
0

Explanation:
Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number.

################################################################Solution################################################################
*/

class Sparse{
    
    public static boolean isSparse(int n){
        
        if((n & (n>>1))==0)
            return true;
        return false;
        
    }
}
