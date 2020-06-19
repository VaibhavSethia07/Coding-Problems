/*
Given a string S consisting of lowercase Latin Letters. Find the first non-repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows the description of testcases.
Each testcase contains the string S.

Output:
For each testcase, print the first non-repeating character present in the string. Print -1 if there is no non-repeating character.

Your Task:
This is a function problem. You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .
The driver code automatically appends a newline after the function call.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input :
3
hello
zxvczbtxyzvy
xxyyzz
Output :
h
c
-1

Explanation:
Testcase 1: In the given string, the first character which is non-repeating is h, as it appears first and there is no other 'h' in the string.
Testcase 2: In the given string, 'c' is the character which is non-repeating. 
Testcase 3: In the given string no character is there which is non-repeating.Hence, the output is -1.

#################################################################Solution###############################################################
*/
//Solution 1

class Repeatation
{
    static char nonrepeatingCharacter(String S)
    {
        int count[] = new int[26];
        int result = Integer.MAX_VALUE;
        
        Arrays.fill(count,-1);
        
        for(int i=0;i<S.length();i++){
            if(count[S.charAt(i)-'a'] == -1)
                count[S.charAt(i)-'a'] = i;
            else
                count[S.charAt(i)-'a'] = -2;
        }
        
        for(int i=0;i<26;i++){
            if(count[i]<0)
                continue;
            result = Math.min(result,count[i]);
        }
        
        return (result != Integer.MAX_VALUE)?S.charAt(result):'$';
    }
}

//Solution 2
 Repeatation
{
    static char nonrepeatingCharacter(String S)
    {
        int result = Integer.MAX_VALUE;
        Pair count[] = new Pair[26];
        
        for(int i=0;i<S.length();i++){
            if(count[S.charAt(i)-'a'] == null)
                count[S.charAt(i)-'a'] = new Pair(i,0);
            count[S.charAt(i)-'a'].setFreq(count[S.charAt(i)-'a'].getFreq()+1);
        }
        
        for(int i=0;i<26;i++){
            if(count[i] == null)
                continue;
            if(count[i].getFreq() == 1)
                result = Math.min(result,count[i].getIndex());
        }
        
        return (result != Integer.MAX_VALUE)?S.charAt(result):'$';
    }
}

class Pair{
    int index;
    int freq;
    
    Pair(int index,int freq){
        this.index = index;
        this.freq = freq;
    }
    
    public int getIndex(){
        return index;
    }
    
    public int getFreq(){
        return freq;
    }
    
    public void setIndex(int index){
        this.index = index;
    }
    
    public void setFreq(int freq){
        this.freq = freq;
    }
}
