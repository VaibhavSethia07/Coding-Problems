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

################################################################Solution################################################################
*/

class Missing{
    
    static int missingNumber(int arr[], int size)
    {
        int shift = segregate(arr,size);
        int arr2 []= new int[size-shift];
        int j=0;
        for(int i=shift;i<size;i++){
            arr2[j]=arr[i];
            j++;
        }
        return findMissingPositive(arr2,arr2.length);
        
    }
    
    private static int segregate(int arr[],int size){
        int j=0;
        for(int i=0;i<size;i++){
            if(arr[i]<=0){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
        return j;
    }
    
    
    private static int findMissingPositive(int arr[],int size){
        for(int i=0;i<size;i++){
            if(Math.abs(arr[i])-1<size && arr[Math.abs(arr[i])-1]>0)
                arr[Math.abs(arr[i])-1] = -arr[Math.abs(arr[i])-1];
        }
        
        for(int i=0;i<size;i++){
            if(arr[i]>0)
                return i+1;
        }
        return size+1;
    }
}
