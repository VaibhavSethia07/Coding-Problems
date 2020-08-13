/*
Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 106

User Task:
You don't need to read input or print anything. Your task is to complete the function minSwaps() which takes the array arr[] and its size N as inputs and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 

Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).

Example(To be used only for expected output):
Input:
2
5
1 5 4 3 2
4
8 9 16 15

Output:
2
1

###################################################################################Solution######################################################################################
*/

// Method 1
class GfG {
    // return the minimum number of swaps required to sort the arra
	public int minSwaps(int[] arr, int N) {
	    Pair pair[] = new Pair[N];
	    boolean visited[] = new boolean[N];
	    
	    for(int i=0;i<N;i++)
	        pair[i] = new Pair(arr[i],i);
	    
	    Arrays.sort(pair);    
	    int swaps=0;
	    
	    for(int i=0;i<N;i++){
	        if(visited[i] || pair[i].second==i)
    	        continue;
    	       
            int index = i;
            int cycleSize = 0;
            while(!visited[index]){
                cycleSize++;
                visited[index] = true;
                index = pair[index].second;
            }
            
            if(cycleSize>0)
                swaps+=cycleSize-1;
    	        
	    }
	    return swaps;
	}
}

// Method 2
class GfG {
    // return the minimum number of swaps required to sort the arra
	public int minSwaps(int[] arr, int N) {
	    Pair pair[] = new Pair[N];
	    boolean visited[] = new boolean[N];
	    
	    for(int i=0;i<N;i++)
	        pair[i] = new Pair(arr[i],i);
	    
	    Arrays.sort(pair,new Comparator<Pair>(){
	        public int compare(Pair t1,Pair t2){
	            if(t1.first==t2.first)
	                return t1.second-t2.second;
	            return t1.first-t2.first;
	        }
	        
	    });    
	    int swaps=0;
	    
	    for(int i=0;i<N;i++){
	        if(visited[i] || pair[i].second==i)
    	        continue;
    	       
            int index = i;
            int cycleSize = 0;
            while(!visited[index]){
                cycleSize++;
                visited[index] = true;
                index = pair[index].second;
            }
            
            if(cycleSize>0)
                swaps+=cycleSize-1;
    	        
	    }
	    return swaps;
	}
	
}

class Pair{
    int first,second;
    
    Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}
