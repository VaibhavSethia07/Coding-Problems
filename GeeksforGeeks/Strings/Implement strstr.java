/*
Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two strings s and x.

Output:
For each test case, in a new line, output will be an integer denoting the first occurrence of the x in the string s. Return -1 if no match found.

Your Task:
Since this is a function problem, you don't have to take any input. Just complete the strstr() function. The function returns -1 if no match if found else it returns an integer denoting the first occurrence of the x in the string s.

Note : Try to solve the question in constant space complexity.

Constraints:
1 <= T <= 200
1 <= |s|,|x| <= 1000

Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5

###########################################################Solution#####################################################################
*/

class GfG
{
    int strstr(String str, String target)
    {
        int h=1,d=5;
        int q = 1000000007;
        
        int N = str.length();
        int M = target.length();
        
        int t=0;
        int p=0;
        
        if(N<M)
            return -1;
        
        for(int i=1;i<=M-1;i++)
            h = (h*d)%q;
            
        for(int i=0;i<M;i++){
            t = (t*d + str.charAt(i))%q;
            p = (p*d + target.charAt(i))%q;
        }

        for(int i=0;i<N;i++){
            if(t == p){
                
                int j;
                for(j=0;j<M;j++){
                    if(str.charAt(i+j) != target.charAt(j)){
                        break;
                    }
                }
                
                if(j==M)
                    return i;
            
            }
            
            if(i<N-M){
                t = ((t-str.charAt(i)*h)*d + str.charAt(i+M))%q;
                if(t<0)
                    t+=q;
                }
        }
        
        return -1;
    }
}
