/*
Given an array arr[] consisting of N positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Your Task:
This is a function problem. You only need to complete the function inversionCount() that takes A and N as parameters and returns inversion count.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
3
5
2 4 1 3 5
5
2 3 4 5 6
3
10 10 10
Output:
3
0
0

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Testcase 2: As the sequence is already sorted so there is no inversion count.
Testcase 3: As all the elements of array are same , so there is no inversion count.4

#############################################################Solution###################################################################
*/

class Inversion_of_Array
{
    
    // Fucntion to count the number of inversions
    // arr[]: input array
    // n: size of array
    static long count=0;
    static long inversionCount(long arr[], long n)
    {
        count=0;
        mergeSort(arr,0,n-1);
        return count;
    }
    
    static void mergeSort(long arr[],long start,long end){
        if(start<end){
            long mid = start + (end-start)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            count+=merge(arr,start,mid,end);
        }
    }
    
    static long merge(long arr[],long start,long mid,long end){
        long n1 = mid-start+1;
        long n2 = end-mid;
        long count=0;
        long L[] = new long[(int)n1];
        long R[] = new long[(int)n2];
        
        for(long i=0;i<n1;i++)
            L[(int)i] = arr[(int)(start+i)];
            
        for(long i=0;i<n2;i++)
            R[(int)i] = arr[(int)(mid+1+i)];
        
        long i=0,j=0,k=start;
        
        while(i<n1 && j<n2){
            if(L[(int)i]<R[(int)j])
                arr[(int)k++] = R[(int)j++];
            else if(L[(int)i]>R[(int)j]){
                // System.out.println(L[(int)i]+" "+R[(int)j]);
                count+=(n2-j);
                arr[(int)k++] = L[(int)i++];
            }
            else {
                arr[(int)k++] = R[(int)j++];
            }
        }
        
        while(i<n1){
            arr[(int)k++] = L[(int)i++];
        }
        
        while(j<n2){
            arr[(int)k++] = R[(int)j++];
        }
            
        return count;
    }
}
