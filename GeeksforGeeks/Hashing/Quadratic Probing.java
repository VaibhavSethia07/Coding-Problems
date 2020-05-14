/*
Quadratic Probing in Hashing
Quadratic probing is a collision handling technique in hashing. Quadratic probing says that whenever a collision occurs, search for i2 position.

In this question, we'll learn how to fill up the hash table using Quadratic probing technique. You are given hash table size which you'll use to insert elements into their correct position in the hash table. You are also given an array arr[] of size N. You need to fill up the hash table using Quadratic probing and print the resultant hash table.
Note:

All the positions that are unoccupied are denoted by -1 in the hash table.
An empty slot can only be found if load factor < 0.5 and hash table size is a prime number.
The given testcases satisfy the above condition so you can assume that an empty slot is always reachable.
Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains 3 lines of input. The first line contains size of the hashtable. The second line contains size of the array. The third line contains elements of the array.

Output:
For each testcase, in a new line, print the hash table.

Your Task:
This is a function problem. You only need to complete the function QuadraticProbing that takes hash, hashSize, arr, and sizeOfArray as parameters and inserts elements of arr in hash. The printing is done by the driver code.

Constraints:
1 <= T <= 100
2 <= hashSize (prime) <= 97
1 <= sizeOfArray < hashSize*0.5
0 <= Array[] <= 105

Examples:
Input:
2
11
4
21 10 32 43
11
4
880 995 647 172 
Output:
10 -1 -1 32 -1 -1 -1 -1 43 -1 21
880 -1 -1 -1 -1 995 -1 172 -1 647 -1 

Explanation:
Testcase1: 21%11=10 so 21 goes into hashTable[10] position. 10%11=10. hashTable[10] is already filled so we try for (10+12)%11=0 position. hashTable[0] is empty so we put 10 there. 32%11=10. hashTable[10] is filled. We try (32+12)%11=0. But hashTable[0] is also already filled. We try (32+22)%11=3. hashTable[3] is empty so we put 32 in hashTable[3] position. 43 uses (43+33)%11=8. We put it in hashTable[8].
Testcase2: Using the similar approach as used in above explanation we will get the output like 880 -1 -1 -1 -1 995 -1 172 -1 647 -1 .

###############################################################Solution#################################################################
*/

static void quadraticProbing(int hash_table[], int hash_size, int arr[], int array_size)
{
    for(int i=0;i<array_size;i++){
        for(int j=0;j<hash_size;j++){
            int key = (arr[i] + j*j)%hash_size;
            if(hash_table[key] == -1){
                hash_table[key] = arr[i];
                break;
            }
        }
    }
}
