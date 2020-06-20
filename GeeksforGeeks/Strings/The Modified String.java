/*
Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rules to make it valid:

The string should not have three consecutive same characters (Refer example for explanation).
He can add any number of characters anywhere in the string.
Find the minimum number of characters which Ishaan must insert in the string to make it valid.

Input: 
The first line of input contains a single integer T denoting the number of test cases. The only line of each test case contains a string S consisting of lowercase English Alphabets.

Output: 
For each test case, in a new line,  print the required answer in a new line.

Your Task:
This is a function problem. You only need to complete the function modified that returns the answer.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints : 
1 <= T <= 100
1 <= Length of S <= 105

Example : 
Input : 
3
aabbbcc
aaaaa
abcddee
Output : 
1
2
0
Explanation : 
Testcase 1: In aabbbcc 3 b's occur consecutively, we add a 'd',and Hence, output will be aabbdbcc.
Testcase 2: In aaaaa 5 a's occur consecutively, we need to add 2 'b', and Hence, the output will be aababaa.
Testcase 3: In abcddee, No character occurs 3 times, so no need to add anything.

#################################################################Solution###############################################################
*/

class solve{
    public static long modified(String a){
        int start = 0;
        int end = 0;
        int count = 0;
        long result = 0;
        
        while(start<=end && end<a.length()){
            if(a.charAt(start)==a.charAt(end)){
                end++;
                count++;
            }
            else{
                count = 0;
                start = end;
            }
            
            if(count == 3){
                result++;
                end--;
                start = end;
                count = 0;
            }
        } 
        return result;
    }
}

