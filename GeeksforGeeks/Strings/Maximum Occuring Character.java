/*
Maximum Occuring Character
Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consists of a string in 'lowercase' only in a separate line.

Output:
For each testcase, in a new line, print the lexicographically smaller character which occurred the maximum number of time.

User Task:
The task is to complete the function getMaxOccuringChar() which returns the character which is most occurring.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 100

Example:
Input:
2
testsample
output
Output:
e
t

Explanation:
Testcase 1: e is the character which is having the highest frequency.
Testcase 2: t and u are the characters with the same frequency, but t is lexicographically smaller.

########################################################Solution########################################################################
*/

class MaxOccur{
    
    public static char getMaxOccuringChar(String line){
        int count[] = new int[256];
        int maxFreq = 0;
        int result = 0;
        
        for(int i=0;i<line.length();i++)
            count[line.charAt(i)]++;
            
        for(int i=255;i>=0;i--){
            if(count[i]>=maxFreq){
                maxFreq = count[i];
                result = i;
            }
        } 
        return (char)result;
    }  
}
