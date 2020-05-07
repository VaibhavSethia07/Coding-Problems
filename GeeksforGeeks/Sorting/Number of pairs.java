/*
Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test consists of three lines. The first line of each test case consists of two space separated M and N denoting size of arrays X and Y respectively. The second line of each test case contains M space separated integers denoting the elements of array X. The third line of each test case contains N space separated integers denoting elements of array Y.

Output:
Corresponding to each test case, print in a new line, the number of pairs such that xy > yx.

Your Task:
This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters and returns the total number of pairs.

Constraints:
1 ≤ T ≤ 100
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103

Example:
Input:
2
3 2
2 1 6
1 5
4 3 
2 3 4 5
1 2 3
Output:
3
5

Explanation:
Testcase 1: The pairs which follow xy > yx are as such: 21 > 12,  25 > 52 and 61 > 16 .
Testcase 2: The pairs for the given input are 21 > 12 , 32 > 23 , 41 > 14 , 43 > 34 , 51 > 15 .

##############################################################Solution##################################################################
*/
class Num_of_pair
{
    // Function to count number of pairs of x, y
    // x[], y[]: input array elements
    // n, m: size of arrays x[] and y[] respectively
    static long countPairs(int x[], int y[], int n, int m)
    {  
        quickSort(y,0,m-1);
        
        
        long count = 0;
        
        int freq[] = new int[5];
        for(int i=0;i<m;i++){
          if(y[i]<5)
            freq[y[i]]++;
        }
        
        for(int i=0;i<n;i++){
            
            if(x[i]==0)
                continue;
            if(x[i] == 1){
                count = count+ (long)freq[0];
                continue;
            }
            int index = upperBound(y,0,m-1,x[i]);
            count = count + (long)(m-index) + (long)freq[0]+(long)freq[1] ;
            if(x[i] == 2)
                count = count - (long)freq[3]-(long)freq[4];
            if(x[i] == 3){
                count = count+ (long)freq[2];
            }
        }
        return count;
    }

    
    public static void quickSort(int arr[],int start,int end){
        if(start<end){
            int pivot = partition(arr,start,end);
            quickSort(arr,start,pivot-1);
            quickSort(arr,pivot+1,end);
        }
    }
    
    public static int partition(int arr[],int start,int end){
        int index = start-1;
        int pivot = end;
        
        for(int i=start;i<end;i++){
            if(arr[i]<arr[pivot]){
                index++;
                swap(arr,i,index);
            }
        }
        
        index++;
        swap(arr,end,index);
        return index;
    }
    
    public static int upperBound(int arr[],int start,int end,int x){
        int ans = end+1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(arr[mid]>x){
                ans = mid;
                end = mid -1;
            }
            else
                start = mid+1;
        }
        
        return ans;
    }
    
    public static void swap(int arr[],int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    } 
    
}
