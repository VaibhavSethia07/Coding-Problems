/*
You are given a string s. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.

Input:
The first line of input contains T, denoting the number of testcases. T testcases follow. Each testcases contains one line of input containing string s.

Output:
For each testcase, in a new line, print the lexicographically sorted sub-sets of the powerset of s. Each subset is separated by a space. Each subset starts with empty string represented by " "(space).

Your Task:
This is a function problem. You only need to complete the function powerSet that takes string s as parameter and returns a vector/ArrayList of subsets. The lexicographic-sorting and printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= |s| <= 10

Examples:
Input:
2
a
abc
Output:
 a
 a ab abc ac b bc c

Explanation:
Testcase1: space and a are only sets.
Testcase2: space,  a, ab, abc, ac, b, bc, c are the sets.
*/

######################################################Solution##########################################################################
class LexSort
{
    // complete the function
    static ArrayList<String> powerSet(String s)
    {
        // add your code here
        ArrayList<String> res=new ArrayList<String>();
        subSet(s,"",0,res);
        return res;
    }
    
    static void subSet(String s,String curr,int index,ArrayList<String> res){
        if(index==s.length()){
            res.add(curr);
            return;
        }
        subSet(s,curr,index+1,res);
        subSet(s,curr+s.charAt(index),index+1,res);
    }
}
