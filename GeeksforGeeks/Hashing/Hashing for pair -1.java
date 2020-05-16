/*
Hashing for pair - 1
You are given an array A (distinct integers) of size N, and you are also given a sum. You need to find if two numbers in A exists that have sum equal to the given sum.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input. The first line contains N denoting the size of the array A. The second line contains N elements of the array. The third line contains element sum.

Output:
For each testcase, in a new line, print  "1"(without quotes) if any pair found, othwerwise print "0"(without quotes) if not found.

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function sumExists.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= Ai <= 106
1 <= sum <= 1000

Examples:
Input:
2
10
1 2 3 4 5 6 7 8 9 10
14
2
2 5
10
Output:
1
0

Explanation:
Testcase 1: arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} and sum = 14.  There is a pair {4, 10} with sum 14.
Testcase 2: arr[]  = {2, 5} and sum = 10. There is no pair with sum 10.

###########################################################Solution#####################################################################
*/

class Geeks
{
    //Complete this function, Geeks
    public static int sumExists(int arr[], int sizeOfArray, int sum)
    {
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i=0;i<sizeOfArray;i++){
            if(hs.contains(sum-arr[i]))
                return 1;
            hs.add(arr[i]);
        }
        return 0;
    }
}
