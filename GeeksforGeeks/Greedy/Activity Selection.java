/*
Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Example 1:

Input:
N = 5
start[] = {1,3,2,5,8,5}
end[] = {2,4,6,7,9,9}
Output: 4
Explanation:Perform the activites 1,2,4,5
Example 2:

Input:
N = 4
start[] = {1,3,2,5}
end[] = {2,4,3,6}
Output: 4
Explanation:Perform the activities1,3,2,4
Your Task :
 Complete the function activityselection() that recieves start-time array , end-time array and number of activites as parameters and returns the maximum number of activities that can be done.

Constraints:
1 <= N <= 105
1 <= start[i] <= end[i] <= 105

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(1)

########################################################################################Solution###################################################################################
*/

// Method 1 (Using Comparator Interface)
class Activity
{   
    
    static int activitySelection(int start[], int end[], int n)
    {
        Act arr[] = new Act[n];
        for(int i=0;i<n;i++)
            arr[i]=new Act(start[i],end[i]);
        
        Arrays.sort(arr,new MyComp());
        int res = 1;
        int prev = 0;
        
        for(int curr=1;curr<n;curr++){
            if(arr[curr].start>=arr[prev].finish){
                res++;
                prev = curr;
                
            }
        }
        return res;
    }
}

class MyComp implements Comparator<Act>{
    public int compare(Act a1,Act a2){
        return a1.finish-a2.finish;
    }

}

class Act{
    int start;
    int finish;
    
    Act(int start,int finish){
        this.start = start;
        this.finish = finish;
    }
    
    public String toString(){
        return start+" "+finish;
    }
}

// Method 2 (Using Comparable Interface)
class Activity
{   
    
    static int activitySelection(int start[], int end[], int n)
    {
        Act arr[] = new Act[n];
        for(int i=0;i<n;i++)
            arr[i]=new Act(start[i],end[i]);
        
        Arrays.sort(arr);
        int res = 1;
        int prev = 0;
        
        for(int curr=1;curr<n;curr++){
            if(arr[curr].start>=arr[prev].finish){
                res++;
                prev = curr;
                
            }
        }
        return res;
    }
}

class Act implements Comparable<Act>{
    int start;
    int finish;
    
    Act(int start,int finish){
        this.start = start;
        this.finish = finish;
    }
    
    public int compareTo(Act a){
        return this.finish-a.finish;
    }
    
    public String toString(){
        return start+" "+finish;
    }
}
