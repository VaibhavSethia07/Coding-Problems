/*
Given a positive integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

Input:
The first line contains T denoting the number of test cases. Each test case contains a single positive integer N.

Output:
Print "YES" if it is a power of 2 else "NO" (Without the double quotes).

User Task:
Your task is to complete the function isPowerofTwo() which takes n as parameter and returns true or false by checking is given number can be represented as power of two or not.

Constraints:
1 <= T <= 100
0 <= N <= 1018

Example:
Input :
2
1
98

Output :
YES
NO

Explanation:
Testcase 1:  1 is equal to 2 raised to 0 (20 == 1).
Testcase2: 98 cannot be obtained by any power of 2.

#######################################################Solution#########################################################################
*/

class PowerCheck{
    
    public static boolean isPowerofTwo(long n){
        
        if(((n & (n-1))==0) && (n!=0))
            return true;
        return false;
    }
    
}
