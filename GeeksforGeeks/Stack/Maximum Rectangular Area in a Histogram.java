/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test case, the first line contains an integer 'N' denoting the size of the array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represent the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

User Task:
The task is to complete the function getMaxArea() which finds the largest rectangular area possible and returns the answer.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
8
7 2 8 9 1 3 6 5
Output:
12
16

Explanation:
Testcase1:

Testcase 2: Maximum size of the histogram will be 8  and there will be 2 consecutive histogram. And hence the area of the histogram will be 8x2 = 16.

#######################################################################################Solution##################################################################################
*/

class solve{
    public static long getMaxArea(long hist[], long n)  {
        Stack<Integer> st = new Stack<>();
        int ps[] = getPreviousSmaller(hist,(int)n,st);
        st.clear();
        int ns[] = getNextSmaller(hist,(int)n,st);
        
        long res = 0;
        for(int i=0;i<n;i++){
            res = Math.max(res,(ns[i]-ps[i]-1)*hist[i]);
        }
        return res;
    }
    
    static int[] getPreviousSmaller(long arr[],int N,Stack<Integer> st){
        int ps[] = new int[N];
        for(int i=0;i<N;i++){
            while(!st.isEmpty() && arr[i]<=arr[st.peek()])
                st.pop();
                
            ps[i] = (st.isEmpty())?-1:st.peek();
            st.push(i);
        }
        return ps;
    }
    
    static int[] getNextSmaller(long arr[],int N,Stack<Integer> st){
        int ns[] = new int[N];
        for(int i=N-1;i>=0;i--){
            while(!st.isEmpty() && arr[i]<=arr[st.peek()])
                st.pop();
                
            ns[i] = (st.isEmpty())?N:st.peek();
            st.push(i);
        }
        
        return ns;
    }   
}
