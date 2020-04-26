/*
Given an array of N elements and a number K. The task is to arrange array elements according to the absolute difference with K, i. e., element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of test case contains two space separated integers N and K. Second line of each test case contains N space separated integers.

Output:
For each test case print the given array in the order as described above.

Your Task:
This is a functional problem. You only need to complete the function sortABS(). The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= K <= 105

Example:
Input:
3
5 7
10 5 3 9 2
5 6
1 2 3 4 5
4 5
2 6 8 3
Output:
5 9 10 3 2
5 4 3 2 1
6 3 2 8

Explanation:
Testcase 1: Sorting the numbers accoding to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
Testcase 2: Sorting the numbers according to the absolute difference with 6, we have array elements as 5 4 3 2 1.
Testcase 3: Sorting the numbers according to the absolute difference with 5, we have array elements as 6 3 2 8.

#############################################################Solution###################################################################
*/
//Solution 1
class SortABS
{
    static void sortABS(int arr[], int n,int k)
    {
        Sort[] ar = new Sort[n];
        for(int i=0;i<n;i++)
            ar[i] = new Sort(arr[i],k);
            
        Arrays.sort(ar,new SortbyAbs());
        StringBuilder sb =new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append(ar[i].a);
            sb.append(" ");
        }
        System.out.print(sb);
    }
}

class Sort{
    int a;
    int k;
    Sort(int a,int k){
        this.a = a;
        this.k = k;
    }
}

class SortbyAbs implements Comparator<Sort>{
    public int compare(Sort obj1,Sort obj2){
        return Math.abs(obj1.a-obj1.k)-Math.abs(obj2.a-obj2.k);
    }
}

//Solution 2
class SortABS
{
    static void sortABS(int arr[], int n,int k)
    {
        mergeSort(arr,0,n-1,k);
        for(int i=0;i<n;i++)
            System.out.print(arr[i]+" ");
    }
    
    private static void mergeSort(int arr[],int left,int right,int k){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(arr,left,mid,k);
            mergeSort(arr,mid+1,right,k);
            merge(arr,left,mid,right,k);
        }
    }
    
    private static void merge(int arr[],int left,int mid,int right,int k){
        int n1 = mid-left+1;
        int n2 = right-mid;
        
        int L[] = new int[n1];
        int R[] = new int[n2];
        
        for(int i=0;i<n1;i++)
            L[i] = arr[i+left];
            
        for(int i=0;i<n2;i++)
            R[i] = arr[i+mid+1];
            
        int i=0,j=0,m=left;
        
        while(i<n1 && j<n2){
            if(Math.abs(L[i]-k)<=Math.abs(R[j]-k))
                arr[m++] = L[i++];
            else
                arr[m++] = R[j++];
        }
        
        while(i<n1)
            arr[m++] = L[i++];
        
        while(j<n2)
            arr[m++] = R[j++];
    }
}
