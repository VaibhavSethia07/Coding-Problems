/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
The first line of input will be the number of test cases. Then T test cases follow. Each Test case contains 2 lines. The first line will contain an integer N denoting the number of petrol pumps and in the next line are N space separated values petrol and distance denoting the amount of petrol every petrol pump has and the distance to next petrol pump respectively .

Output:
The output of each test case will be the index of the the first point from where a truck will be able to complete the circle otherwise -1 .

Your Task:
Your task is to complete the function tour() which takes the required data as inputs and returns an integer denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). If there exists multiple such starting points, then the function must return the first one out of those.

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(N)

Constraints:
1 <= T <= 100
1 <= N <= 10000
1 <= petrol, distance <= 1000

Example (To be used only for expected output)
Input:
1
4
4 6 6 5 7 3 4 5
Output:
1

Explanation:
Testcase 1: there are 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is 2nd petrol pump. Output in this case is 1 (index of 2nd petrol pump).

###############################################################################Solution##########################################################################################
*/

// Solution 1
class GfG
{
    int tour(int petrol[], int distance[])
    {
        Deque<Integer> dq = new LinkedList<>();
        
        int currPetrol = 0;
        int N = petrol.length;
        
        for(int start=0,end=0;start<N;){
            currPetrol += petrol[end]-distance[end];
            dq.offerLast(end);
            
            while(currPetrol<0){
                currPetrol-=petrol[start%N]-distance[start%N];
                dq.pollFirst();
                start++;
            }
            end = (end + 1)%N;
            
            if(dq.size()==N)
                return start;
        }
        return -1;
    }
}

// Solution 2
class GfG
{
    int tour(int petrol[], int distance[])
    {
        int currPetrol = 0;
        int prevPetrol = 0;
        int start = 0;
        int N = petrol.length;
        
        for(int i=0;i<N;i++){
            currPetrol += petrol[i]-distance[i];
            if(currPetrol<0){
                start = i+1;
                prevPetrol += currPetrol;
                currPetrol = 0;
            }
        }
        return(currPetrol+prevPetrol>=0)?start:-1;
    }
}
