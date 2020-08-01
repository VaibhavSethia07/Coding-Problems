/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
Your Task:
You are required to complete 3 methods insertHeap() which takes 1 argument, balanceHeaps() and getMedian() and returns the current median.
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

################################################################################Solution#########################################################################################
*/

class FindMedian
{
    static PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());
    static PriorityQueue<Integer> min = new PriorityQueue<>();
    
    // Function to insert heap
    public static void insertHeap(int x)
    {
        if(max.isEmpty()){
            max.add(x);
            return;
        }
        if( max.size()>min.size()){
            if(x<=max.peek()){
                min.add(max.poll());
                max.add(x);
            }
            else
                min.add(x);  
        }
        else{
            if(x<min.peek())
                max.add(x);
            else{
                max.add(min.poll());
                min.add(x);
            }
        }
    }
    
    
    // function to getMedian
    public static double getMedian()
    {
        if(max.size()==min.size())
            return ((max.peek()+min.peek())/(2.0));
        return max.peek();
    }
    
}
