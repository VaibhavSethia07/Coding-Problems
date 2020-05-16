/*
Winner of an election
Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines input. First line is the number of votes cast N.And second line is the name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. The name and votes are separated by a space.

Your Task:
This is a functional problem. You only need to complete the function winnter() that takes an array of strings arr, and n as parameters and prints the candiate with maximum votes. Newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark
Output:
john 4
andy 1

Explanation:
Testcase1: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.
Testcase2: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.

##########################################################Solution######################################################################
*/

class Election
{
    static void winner(String arr[], int n)
    {
        TreeMap<String,Integer> ballot = new TreeMap<>();
        
        for(int i=0;i<n;i++){
            if(ballot.containsKey(arr[i])){
                int vote = ballot.get(arr[i])+1;
                ballot.put(arr[i],vote);
            }
            else
                ballot.put(arr[i],1);
        }
        
        int maxVote = 0;
        String winner = "";
        Iterator<Map.Entry<String,Integer>> itr = ballot.entrySet().iterator();
        
        while(itr.hasNext()){
            Map.Entry<String,Integer> entry = itr.next();
            if(entry.getValue()> maxVote){
                maxVote = entry.getValue();
                if(entry.getKey().compareTo(winner)>0)
                    winner = entry.getKey();
            }
        }
        System.out.print(winner+" "+maxVote);
    }
}
