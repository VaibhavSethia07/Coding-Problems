/*
Sum of numbers in string
Given a string str containing alphanumeric characters. The task is to calculate the sum of all the numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all the numbers present in the string.

User Task:
The task is to complete the function findSum() which finds and returns the sum of numbers in the string.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 105
1 <= length of the string <= 105
Sum of Numbers <= 10^5

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc
Output:
24
4
100
123

Explanation:
Testcase 1: 1 and 23 are numbers in the string which is added to get the sum as 24.
Testcase 2: 4 is the only number, so the sum is 4.
Testcase 3: 1, 2, 30 and 67 are the numbers in the string which is added to get the sum as 100.
Testcase 4: 123 is a single number, so the sum is 123.

########################################################Solution########################################################################
*/

class SumNumbers{
    public static long findSum(String s){
        
        long sum = 0;
        long value = 0;
        String numStr = "0";
        
        for(int i=0;i<s.length();i++){
            if((s.charAt(i)-'a'>=0 && s.charAt(i)-'a'<26) || (s.charAt(i)-'A'>=0 && s.charAt(i)-'A'<26)){
                value = Long.parseLong(numStr);
                sum+=value;
                numStr = "0";
            }
            else
                numStr+=s.charAt(i);
        }
        
        value = Long.parseLong(numStr);
        sum+=value;
        
        return sum;
    }
}
