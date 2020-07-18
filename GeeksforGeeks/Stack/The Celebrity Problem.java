/*
You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consist of 2 lines. The first line of each test case contains a number denoting the size of the matrix M. Then in the next line are space separated values of the matrix M.

Output:
For each test case output will be the id of the celebrity if present (0 based index). Else -1 will be printed.

User Task:
You will be given a square matrix M[][] where if an element of row i and column j  is set to 1 it means ith person knows jth person. You need to complete the function getId() which finds the id of the celebrity if present else return -1. The function getId() takes two arguments, the square matrix M and its size N.

Note: 
M[i][i] will be equal to zero always.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 50
2 <= N <= 501
0 <= M[][] <= 1

Example:
Input :
2
3
0 1 0 0 0 0 0 1 0
2
0 1 1 0
Output :
1
-1

Explanation :
Testcase 1:
For the above test case the matrix will look like
0 1 0 
0 0 0
0 1 0
Here,  the celebrity is the person with index 1 ie id 1
Testcase 2:
The matrix will look like
0 1
1 0
Here, there is no such person who is a celebrity (a celebrity should know no one).

###########################################################################Solution##############################################################################################
*/

// Naive Solution
class Celebrity
{
    // The task is to complete this function
    int getId(int M[][], int n)
    {
        Stack<Integer> stranger = new Stack<>();
        Stack<Integer> known = new Stack<>();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(M[i][j]==0 && M[j][i]==1){
                    if(stranger.isEmpty() || known.search(i)<0)
                        stranger.push(i);
                    if(!stranger.isEmpty() && stranger.peek()==j)
                        stranger.pop();
                    known.push(j);
                }
                
                else if(M[j][i]==0 && M[i][j]==1){
                    if(stranger.isEmpty() || known.search(j)<0)
                        stranger.push(j);
                    if(!stranger.isEmpty() && stranger.peek()==i)
                        stranger.pop();
                    known.push(i);
                }
                    
            }
        }
        
        return (stranger.isEmpty())?-1:stranger.pop();
    }
}

// Efficient Solution
class Celebrity
{
    // The task is to complete this function
    int getId(int M[][], int n)
    {
        Stack<Integer> candidates = new Stack<>();
        for(int i=0;i<n;i++)
            candidates.push(i);
            
        while(candidates.size()>=2){
            int can1 = candidates.pop();
            int can2 = candidates.pop();
            
            if(M[can1][can2]==1)
                candidates.push(can2);
            else
                candidates.push(can1);
        }
        
        int potnCandidate = candidates.pop();
        
        for(int i=0;i<n;i++){
            if(i!=potnCandidate)
                if(M[potnCandidate][i]==1 || M[i][potnCandidate]==0)
                    return -1;
        }
        return potnCandidate;
    }
}
