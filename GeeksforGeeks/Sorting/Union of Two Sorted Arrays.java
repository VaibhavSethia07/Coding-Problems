/*
Given two sorted arrays arr[] and brr[] of size N and M respectively. The task is to find the union of these two arrays.
Union of two arrays can be defined as the common and distinct elements in the two arrays.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of testcases T. For each testcase, first line of input contains size of two arrays N and M. Next two line contains N and M elements.

Output:
For each testcase, print the union (common and distinct) of two arrays in a single line. You need to print the union in sorted order.

Your Task:
This is a function problem. You only need to complete the function findUnion() that takes N and M as parameter and prints the union of two arrays. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N, M <= 105
1 <= arr[i], brr[i] <= 106

Example:
Input:
3
5 3
1 2 3 4 5
1 2 3
5 5
2 2 3 4 5
1 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2
Output:
1 2 3 4 5
1 2 3 4 5
1 2

Explanation:
Testcase 1: Distinct elements including both the arrays are: 1 2 3 4 5.
Testcase 2: Distinct elements including both the arrays are: 1 2 3 4 5.
Testcase 3: Distinct elements including both the arrays are: 1 2.

#######################################################Solution#########################################################################
*/

class Union
{
    static void findUnion(int arr1[], int arr2[], int n, int m)
    {   int arr[] = new int[n+m];
    
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                if(k==0 || (k>0 && arr[k-1]!=arr2[j]))
                    arr[k++] = arr2[j++];
                else
                    j++;
            }
            else if(arr1[i]<arr2[j]){
                if(k==0 || (k>0 && arr[k-1]!=arr1[i]))
                    arr[k++] = arr1[i++];
                else
                    i++;
            }
            else{
                if(k==0 || (k>0 && arr[k-1]!=arr1[i])){
                    arr[k++] = arr1[i++];
                    j++;
                }else{
                    i++;
                    j++;
                }
            }
        }
        
        while(i<n && k>0){
            if(arr[k-1] != arr1[i])
                arr[k++] = arr1[i++];
            else 
                i++;
        }
        
        while(j<m && k>0){
            if(arr[k-1] != arr2[j])
                arr[k++] = arr2[j++];
            else
                j++;
        }
        int a=0;
        while(true){
            if(arr[a]==0)
                break;
             System.out.print(arr[a++]+" ");
        }   
    }
}
