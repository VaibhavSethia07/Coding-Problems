/*
Given three sorted arrays A, B and C of size N, M and P respectively. The task is to merge them into a single array which must be sorted in increasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains size of three arrays N, M and P. Next three lines contains N, M and P elements for arrays.

Output:
Output the merged sorted array.

Your Task:
This is a function problem. You only need to complete the function mergeThree() that takes A,B,C as parameters. The function returns an array or vector.

Constraints:
1 <= T <= 100
1 <= N, M, P <= 106
1 <= A[i], B[i], C[i] <= 106

Example:
Input:
2
4 5 6
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
2 3 4
1 2
2 3 4
4 5 6 7
Output:
1 1 1 2 2 2 3 3 3 4 4 4 5 5 6
1 2 2 3 4 4 5 6 7

Explanation:
Testcase 1: Merging these three sorted arrays, we have elements as 1 1 1 2 2 2 3 3 3 4 4 4 5 5 6.
Testcase 2: Merging three sorted arrays , we have elements as 1 2 2 3 4 4 5 6 7.

################################################
*/

class MergeThree
{
    // Function to merge three sorted arrays
    // A[], B[], C[]: input arrays
    static ArrayList<Integer> merge3sorted(int A[], int B[], int C[])
    {
        // add ypur code here
        
        int i=0,j=0,k=0;
        int N = A.length;
        int M = B.length;
        int P = C.length;
         ArrayList<Integer> al = new ArrayList<>(); 
        while((i<N) && (j<M) || (j<M) && (k<P) || (k<P) && (i<N)){
            int min = Integer.MAX_VALUE;
            if(i<N && min>=A[i])
                min = A[i];
            if(j<M && min>=B[j])
                min = B[j];
            if(k<P && min>=C[k])
                min  = C[k];
            
            if(i<N && min==A[i])
                i++;
            else if(j<M && min==B[j])
                j++;
            else if(k<P && min==C[k])
                k++;
            al.add(min);
        }
        
        while(i<N)
            al.add(A[i++]);
        
        while(j<M)
            al.add(B[j++]);
            
        while(k<P)
            al.add(C[k++]);
        
        return al;
    }
}
