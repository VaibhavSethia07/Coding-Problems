/*
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

User Task:
The task is to complete the function stockBuySell() which finds the days of buying and selling stock and print them. The newline is automatically added by the driver code.

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
4
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67
5
4 2 2 2 4
5
5 5 5 5 5

Output:
(0 3) (4 6)
(1 4) (5 9)
(3 4)
No Profit

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.
Testcase 2: We can buy stock on day 1, and sell it on 4th day, which will give us maximum profit. Now, we buy stock on day 5 and sell it on day 9.
Testcase 3: We can buy stock on day 3, and sell it on 4th day, which will give us maximum profit.
Testcase 4: We cannot sell any stock that will give us profit as the price remains same.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.
*/

########################################################Solution########################################################################
class Stock{

    // Function to find the buy and sell days and print them
    static void stockBuySell(int price[], int n) {
        
        int buyPri=price[0];
        int sellPri=price[0];
        int profit=0,j=0,k=0,l=0;
        String days[]=new String [n];
        
        for(int i=1;i<n;i++){
            if(price[i]>sellPri){
                sellPri=price[i];
                k=i;
            }
            else{
                profit+=sellPri-buyPri;
                if(sellPri!=buyPri)
                    days[l++]="("+j+" "+k+")";
            
                buyPri=price[i];
                sellPri=price[i];
                if(i!=n-1){
                    j=i;
                    k=i;
                }
            }
        }
        if(buyPri!=sellPri){
            days[l++]="("+j+" "+k+")";
        }
        profit+=sellPri-buyPri;
        StringBuffer s =new StringBuffer();
        if(profit>0){
            l=0;
            while(l<n && days[l]!=null){
                    s.append(days[l]+" ");
                    l++;
            }
            System.out.print(s);
        }
        else
            System.out.println("No Profit");
    }
}
