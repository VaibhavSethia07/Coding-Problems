/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

User Task:
The task is to complete the function findMajority() which finds the majority element in the array. If no majority exists, return -1.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3
Output:
3
-1

###########################################################Solution#####################################################################
*/

//Solution 1

class Majority
{
    static int majorityElement(int arr[], int size)
    {
        HashMap<Integer,Integer> countMap = new HashMap<>();
        
        for(int i=0;i<size;i++)
            countMap.put(arr[i],0);
            
            
        for(int i=0;i<size;i++){
            countMap.put(arr[i],countMap.get(arr[i])+1);
            
            if(countMap.get(arr[i])>(size/2))
                return arr[i];
        }
        return -1;
    }
}

//Solution 2

class Majority
{
    static int majorityElement(int arr[], int size)
    {
        // your code here
        int countArray[] = new int[1000001];
        
        for(int i=0;i<size;i++){
            countArray[arr[i]]++;
        }
        
        for(int i=0;i<1000000;i++){
            if(countArray[i]>(size/2))
                return i;
        }
        
        return -1;
    }
}
