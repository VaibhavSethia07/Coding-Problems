/*
Given a string S consisting of lowercase latin letters, arrange all its letters in lexographical order using Counting Sort.

Input:
The first line of the input contains T denoting number of testcases.Then T test cases follow. Each testcase contains positive integer N denoting the length of string.The last line of input contains the string S.

Output:
For each testcase, in a new line, output the sorted string.

Your Task:
This is a function problem. You only need to complete the function countSort() that takes char array as parameter. The printing is done by driver code.

Constraints:
1 <= T <= 105
1 <= N <= 105

Example:
Input:
2
5
edsab
13
geeksforgeeks
Output:
abdes
eeeefggkkorss

Explanation:
Testcase 1: In lexicographical order , string will be abdes.
Testcase 2: In lexicographical order , string will be eeeefggkkorss.

#####################################################################Solution###########################################################
*/

class GfG
{
    public static void countSort(char seq[])
    {
        byte count[] = new byte[26];
        
        for(int i=0;i<seq.length;i++){
            int ascii = ((byte)seq[i]) -97;
            count[ascii]++;
        }
        
        for(int i=1;i<26;i++)
            count[i]+=count[i-1];
            
        char output[] = new char[seq.length];
        for(int i=seq.length-1;i>=0;i--)
            output[--count[(byte)seq[i]-97]] = seq[i];
        
        for(int i=0;i<seq.length;i++)
            seq[i] = output[i];
    }
}
