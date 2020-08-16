/*
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input Format:

Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output: 2 60
Explanation: 2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:2 127
Explanation: 2 jobs can be done with
maximum profit of 127 (100+27).
Your Task :

Complete the function jobscheduling() that returns count of jobs and maximum profit.

Constraints:
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)

##############################################################################Solution###########################################################################################
*/

class solve{
    // return an array of size 2 having the 0th element equal to the count
    // and 1st element equal to the maximum profit
    int[] JobScheduling(Job arr[], int n){
        Arrays.sort(arr,(job1,job2)->(job2.profit-job1.profit));
        
        int timeline[] = new int[100000];
        int profit=0;
        int jobs=0;
        for(int i=0;i<n;i++){
            int j = arr[i].deadline-1;
            while(j>=0 && timeline[j]!=0)
                j--;
            
            if(j>=0 && timeline[j]==0){
                timeline[j] = arr[i].id;
                profit+=arr[i].profit;
                jobs++;
            }
        }
        
        return new int[]{jobs,profit};
    }
}
