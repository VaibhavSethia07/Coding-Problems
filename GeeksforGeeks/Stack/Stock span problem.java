/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

User Task:
The task is to complete the function calculateSpan() which finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80
Output:
1 1 1 2 1 4 6
1 1 2 4 5 1



Explanation:
Testcase 1: Traversing the given input span for 100 will be 1,80 is smaller than 100 so the span is 1 , 60 is smaller than 80 so the span is 1 , 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.
Testcase 2: Traversing the given input span for 10 will be 1, 4 is smaller than 10 so the span will be 1 , 5 is greater than 4 so the span will be 2 and so on. Hence, the output will be 1 1 2 4 5 1.

######################################################################Solution###################################################################################################
*/

class solve{
    public static int[] calculateSpan(int price[], int n)
    {
        int span[] = new int[n];
        Stack<Integer> stock = new Stack<>();
        
        for(int i=0;i<n;i++){
            while(!stock.isEmpty() && price[i]>=price[stock.peek()])
                stock.pop();
                
            span[i] = (stock.isEmpty())?i+1:i-stock.peek();
            stock.push(i);
        }
        
        return span;
    }
}
