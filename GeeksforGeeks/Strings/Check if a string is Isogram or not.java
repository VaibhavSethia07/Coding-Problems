/*
Check if a string is Isogram or not
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Input:
The first line of input contains an integer T denoting the number of test cases. T test cases follow. Each test case consists of one string in 'lowercase' only, in a separate line.

Output:
For each testcase, in a new line, Print 1 if the string is Isogram else print 0.

Your Task:
This is a function problem. You only need to complete the function isIsogram() that takes a string as a parameter and returns either true or false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|.

Constraints:
1 <= T <= 100
1 <= |S| <= 103

Example:
Input:
2
machine
geeks
Output:
1
0
Explanation:
Testcase 1: machine is an isogram as no letter has appeared twice. Hence we print 1.
Testcase 2: geeks is not an isogram as 'e' appears twice. Hence we print 0.

################################################################Solution################################################################
*/

static boolean isIsogram(String data){
    boolean distinctChar[] = new boolean[256];
    
    for(int i=0;i<data.length();i++){
        if(distinctChar[data.charAt(i)]==true)
            return false;
        distinctChar[data.charAt(i)]= true;
    }
    return true;
}
