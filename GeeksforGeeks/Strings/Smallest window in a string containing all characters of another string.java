/*
Given two strings. Find the smallest window in the first string consisting of all the characters of the second string.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines having a string S (the first string) and next line contains a string P (the second string).

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as inputs and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case there's no such window present. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza
Output:
toprac
apzo

Explanation:
Testcase 1: toprac is the smallest subset in which toc can be found.
Testcase 2: To find oza in the zoomlazapzo the smallest subset is apzo.

###################################################################Solution#############################################################
*/

class solve
{
    public static String smallestWindow(String S, String P){
        if(S.length()<P.length())
            return "-1";
        
        int start = 0;
        int end = P.length()-1;
        
        int startRes = 0;
        int endRes = 0;
        
        int visited[] = new int[26];
        int pattern[] = new int[26];
        int minLength = Integer.MAX_VALUE;
        
        for(int i=0;i<=end;i++){
            visited[S.charAt(i)-'a']++;
            pattern[P.charAt(i)-'a']++;
        }
        
        if(compareWindows(visited,pattern))
            return generateResult(S,start,end);
            
        end++;
        visited[S.charAt(end)-'a']++;
        
        while(start<=end && end<S.length()){
            if(compareWindows(visited,pattern) && start<S.length()){
                visited[S.charAt(start)-'a']--;
                if(end-start+1<minLength){
                    startRes = start;
                    endRes = end;
                    minLength = end-start+1;
                }
                
                start++;
            }
            else{
                end++;
                if(end<S.length())
                    visited[S.charAt(end)-'a']++;
            }
        }
        
        return (minLength != Integer.MAX_VALUE)?generateResult(S,startRes,endRes):"-1";
    }
    
    public static boolean compareWindows(int visited[],int pattern[]){
        for(int i=0;i<26;i++){
            if(visited[i] == 0 && pattern[i] == 0)
                continue;
            if(visited[i]<pattern[i])
                return false;
        }
        return true;
    }
    
    public static String generateResult(String str,int start,int end){
        String result = "";
        for(int i=start;i<=end;i++)
            result+=str.charAt(i);
            
        return result;
    }
}
