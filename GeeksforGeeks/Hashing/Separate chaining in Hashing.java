/*
Separate chaining in Hashing
Separate chaining technique in hashing allows to us to use a linked list at each hash slot to handle the problem of collisions. That is, every slot of the hash table is a linked list, so whenever a collision occurs, the element can be appened as a node to the linked list at the slot.

In this question, we'll learn how to fill up the hash table using Separate chaining technique. You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr. The size of the array is denoted by sizeOfArray. You need to fill up the hash table using Separate chaining and print the resultant hash table.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You need to complete the function separateChaining that takes hashTable, hashSize, arr, and sizeOfArr as parameters and inserts elements of arr in the hashTable at positions by using arr[i]%hashSize. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
2 <= hashSize <= 103
1 <= sizeOfArray <= 103
0 <= arri <= 107

Examples:
Input:
2
10
6
92 4 14 24 44 91
10
5
12 45 36 87 11
Output:
1->91
2->92
4->4->14->24->44
1->11
2->12
5->45
6->36
7->87

Explanation:
Testcase1: 92%10=2 so 92 goes to slot 2. 4%10=4 so 4 goes to slot 4. 14%10=4. But 4 is already occupied so we make a linked list at this position and add 14 after 4 in slot 4 and so on.
Testcase2: 12%10=2 so 12 goes to slot 2. 45%10=5 goes to slot 5. 36%10=6 goes to slot 6. 87%10=7 goes to slot 7 and finally 11%10=1 goes to slot 1.

###################################################################Solution#############################################################
*/

public static void separateChaining(int arr[], int n, ArrayList<ArrayList<Integer>> hashTable, int hashSize)
{
    int key = 0;
    
    for(int index=0;index<n;index++){
        key = arr[index]%hashSize;
        hashTable.get(key).add(arr[index]);
    }
}
