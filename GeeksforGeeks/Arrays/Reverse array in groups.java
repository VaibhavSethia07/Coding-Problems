/*
Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Input Format:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines of input. The first line of each test case consists of an integer N(size of array) and an integer K separated by a space. The second line of each test case contains N space separated integers denoting the array elements.

Output Format:
For each test case, in a new line, print the modified array.

User Task:
The task is to complete the function reverseInGroups() which reverses elements of the array in groups and returns the array. The printing of array is done by drivercode.

Constraints:
1 ≤ T ≤ 200
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018

Example:
Input
4
5 3
1 2 3 4 5
4 3
5 6 8 9
4 7
5 6 8 9
8 3
1 2 3 4 5 6 7 8

Output
3 2 1 5 4
8 6 5 9
9 8 6 5
3 2 1 6 5 4 8 7

Explanation:
Testcase 1: Reversing groups in size k = 3, first group consists of elements 1, 2, 3. Reversing this group, we have elements in order as 3, 2, 1.
Testcase 2: Our array is 5 6 8 9. The value of k is 3. So we reverse it in groups of 3.  After reversing, it becomes 8 6 5 9.
Testcase 3: Our array is 5 6 8 9. The value of k is 7. After reversing, it becomes 9 8 6 5.
Testcase 4: Our array is 1 2 3 4 5 6 7 8. The value of k is 3. After reversing, it becomes 3 2 1 6 5 4 8 7.
*/

#################################################################Solution##################################################################
class Reverse{
   public static ArrayList<Integer> reverseInGroups(ArrayList<Integer> mv, int n, int k) {
        // add your code here
        
        int pairs=n/k;
        
        for(int i=0;i<pairs;i++){
            reverse(mv,k*i,k*(i+1)-1);
        }
        
        if(pairs!=0)
            reverse(mv,k*pairs,n-1);
        else
            reverse(mv,0,n-1);
            
        return mv;
    }
    
    private static void reverse(ArrayList<Integer> mv,int start,int end){
        int temp=0;
        while(start<end){
            temp=mv.get(start);
            mv.set(start,mv.get(end));
            mv.set(end,temp);
            start++;
            end--;
        }
    }   
}
