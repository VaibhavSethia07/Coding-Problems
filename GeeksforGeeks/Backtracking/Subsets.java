/*
Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

Example 1:

Input: N = 3, arr[] = {1,2,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)
Example 2:

Input: N = 4, arr[] = {1,2,3,3}
Output: (),(1),(1 2),(1 2 3)
(1 2 3 3),(1 3),(1 3 3),(2),(2 3)
(2 3 3),(3),(3 3)
Your Task:
Your task is to complete the function AllSubsets() which takes the array arr[] and N as input parameters and returns list of all possible unique subsets. 

Expected Time Complexity: O(2N).
Expected Auxiliary Space: O(2N * X), X = Length of each subset.

Constraints:
1 ≤ N ≤ 12
1 ≤ arr[i] ≤ 9

############################################################################Solution#############################################################################################
*/

class solve{

    public static ArrayList <ArrayList <Integer>> AllSubsets(int arr[], int n){
        ArrayList<ArrayList<Integer>> res=new ArrayList<>();
        ArrayList<Integer> subset = new ArrayList<>();
        subsets(arr,subset,res,0);
        return res;
    }
    
    public static void subsets(int arr[],ArrayList<Integer> subset,ArrayList<ArrayList<Integer>>res,int index){
        if(index==arr.length)
            return;
            
        subset.add(arr[index]);
        if(!res.contains(subset))
            res.add(new ArrayList<>(subset));
        subsets(arr,subset,res,index+1);
        subset.remove(subset.size()-1);
        subsets(arr,subset,res,index+1);
        
    }
}
