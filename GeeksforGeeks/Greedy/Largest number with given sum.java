/*
A boy lost the password of his super locker. He remembers the number of digits N as well as the sum S of all the digits of his password. He know that his password is the largest number of N digits that can be possible with given sum S. As he is busy doing his homework, help him retrieving his password.

Example 1:

Input:
N = 5, S = 12
Output: 93000
Explanation: Sum of elements is 12.
Largest possible 5 digit number is 93000.
Example 2:

Input:
N = 3, S = 29
Output: -1
Explanation: There is no such three digit
number whose sum is 29.
Your Task : 
Complete the function largestnumber() that returns  the largest possible strings as answer, -1 otherwise.

Constraints:
1 <= N <= 104
0 <= S <= 106

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

##############################################################################Solution#############################################################################################
*/

// Solution 1
class Solution
{
    // Function to return Largest Number
    static String largestNumber(int n, int sum)
    {
        StringBuffer res = new StringBuffer();
        int solve[] = new int[n];
        Arrays.fill(solve,9);
        
        int val = 9*n;
        int i=n;
        while(val>sum){
            i--;
            while(solve[i]!=0 && val>sum){
                solve[i]--;
                val--;
            }
        }
        
        if(val != sum)
            return "-1";
        
        for(int j=0;j<n;j++)
            res.append(solve[j]);
            
        return res.toString();
    }
}
