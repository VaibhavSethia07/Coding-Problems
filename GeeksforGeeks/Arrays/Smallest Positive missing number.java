/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

User Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.
*/

############################################################Solution####################################################################
class Missing {
   static int missingNumber(int arr[], int size)
    { 
        int i=0,missing=1,min=Integer.MAX_VALUE;
        
        for(i=0;i<size;i++){
            if(arr[i]<=0)
                continue;
            if(arr[i]<min)
                min=arr[i];
        }
        
        if(missing<min)
            return missing;
        else if(missing==min)
            missing++;
        i=0;
        
        while(i<size){
            if(arr[i]<=0){
                i++;
                continue;
            }
            if(missing==arr[i]){
                i=0;
                missing++;
            }
            i++;
        }
        return missing;
    } 
}
