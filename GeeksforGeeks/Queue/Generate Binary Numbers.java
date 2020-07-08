/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Input:
The first line of input contains an integer T denoting the number of test cases. There will be a single line for each testcase which contains N.

Output:
Print all binary numbers with decimal values from 1 to N in a single line.

Your Task:
This is a function problem. You only need to complete the function generate that takes N as parameter and returns vector of strings denoting binary numbers.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ T ≤ 106
1 ≤ N ≤ 106

Example:
Input:
2
2
5
Output:
1 10
1 10 11 100 101

Explanation:
Testcase 1: Binary numbers from 1 to 2 are 1 and 10.
Testcase 2: Binary numbers from 1 to 5 are 1 , 10 , 11 , 100 and 101.

##########################################################################Solution###############################################################################################
*/

class solve{
    static ArrayList<String> generate(long n)
    {
        Queue<String> q = new LinkedList<>();
        ArrayList<String> al =new ArrayList<>();
        
        q.add("1");
        
        for(int i=0;i<n;i++){
            String curr = q.poll();
            al.add(curr);
            q.add(curr+"0");
            q.add(curr+"1");
        }
        
        return al;
    }
}
