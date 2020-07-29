/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
The first line of input contains the number of test cases, then T test cases follow. Each test case will contain an integer K denoting the number of sorted arrays(each with size K). Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9 
4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

Output:
1 2 3 4 5 6 7 8 9
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Testcase 2:
Above test case has 4 sorted arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],

             [3, 3, 4, 4],

             [5, 5, 6, 6]

             [7, 8, 9, 9 ]]
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].

#################################################################################Solution########################################################################################
*/

// Naive Solution
class Solution{
    public static ArrayList<Integer> mergeKArrays(int[][] arrays,int k) 
    {
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                res.add(arrays[i][j]);
        
        Collections.sort(res);
        return res;
        
        
    }
}

// Efficient Solution
  // Method 1
class Solution{
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int k) 
    {
        Comparator<Triplet> compareTrip = new Comparator<>(){
            public int compare(Triplet t1, Triplet t2){
                return t1.value-t2.value;
            }
        };
        
        Queue<Triplet> minHeap = new PriorityQueue<>(compareTrip);
        ArrayList<Integer> res = new ArrayList<>();
        
        
        for(int i=0;i<k;i++)
            minHeap.add(new Triplet(arr[i][0],i,0));
        
        while(!minHeap.isEmpty()){
            Triplet trip = minHeap.poll();
            res.add(trip.value);
            
            int arrIndex = trip.arrIndex;
            int valueIndex = trip.valueIndex;
            
            if(valueIndex<k-1)
                minHeap.add(new Triplet(arr[arrIndex][valueIndex+1],arrIndex,valueIndex+1));
        }
        
        return res;
    }
}

class Triplet{
    int value;
    int arrIndex;
    int valueIndex;
    
    Triplet(int value,int arrIndex,int valueIndex){
        this.value = value;
        this.arrIndex = arrIndex;
        this.valueIndex = valueIndex;
    }
}

  // Method 2
  class Solution{
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int k) 
    {
        Comparator<Triplet> compareTrip = ((t1,t2)->t1.value-t2.value);

        Queue<Triplet> minHeap = new PriorityQueue<>(compareTrip);
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int i=0;i<k;i++)
            minHeap.add(new Triplet(arr[i][0],i,0));
        
        while(!minHeap.isEmpty()){
            Triplet trip = minHeap.poll();
            res.add(trip.value);
            
            int arrIndex = trip.arrIndex;
            int valueIndex = trip.valueIndex;
            
            if(valueIndex<k-1)
                minHeap.add(new Triplet(arr[arrIndex][valueIndex+1],arrIndex,valueIndex+1));
        }
        
        return res;
    }
  }
  
  // Method 3
  class Solution{
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int k) 
    {
        Comparator<Triplet> compareTrip = Comparator.comparing(Triplet::getValue);

        Queue<Triplet> minHeap = new PriorityQueue<>(compareTrip);
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int i=0;i<k;i++)
            minHeap.add(new Triplet(arr[i][0],i,0));
        
        while(!minHeap.isEmpty()){
            Triplet trip = minHeap.poll();
            res.add(trip.value);
            
            int arrIndex = trip.arrIndex;
            int valueIndex = trip.valueIndex;
            
            if(valueIndex<k-1)
                minHeap.add(new Triplet(arr[arrIndex][valueIndex+1],arrIndex,valueIndex+1));
        }
        
        return res;
    }
}

class Triplet{
    int value;
    int arrIndex;
    int valueIndex;
    
    Triplet(int value,int arrIndex,int valueIndex){
        this.value = value;
        this.arrIndex = arrIndex;
        this.valueIndex = valueIndex;
    }
    
    int getValue(){
        return this.value;
    }
}
