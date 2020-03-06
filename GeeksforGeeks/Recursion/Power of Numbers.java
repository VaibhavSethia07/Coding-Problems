/*
Given a number N, let the reverse of the number be R. The task is to print the output of the Expression power(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 109 + 7.

Input:
The first line of the input consists of an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an integer N.

Output:
Corresponding to each test case, print in a new line, the output of the expression pow as described above.

Your Task:
This is a function problem. You just need to complete the function pow that takes two parameters N and R and returns power of (N to R)mod(109 + 7)

Constraints:
1 <= T <= 103
1 <= N <= 105

Example:
Input:
2
2
12
Output:
4
864354781
*/

############################################################Solution####################################################################
class PowerProblem
{
    int  M=1000000000+7;
    long power(long N,long R)
    {
        //Your code here
        if(R==0)
            return 1;
        if(R==1)
            return N%M;
            
        if((R & 1)==1)
            return ((N%M)*power((N%M)*(N%M)%M,R/2))%M;
        
        return  power(((N%M)*(N%M)%M),R/2);
    }
}
