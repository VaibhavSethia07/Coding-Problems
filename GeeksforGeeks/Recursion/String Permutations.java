/*
Given a string S. The task is to print all permutations of a given string.

Input Format:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output Format:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Your Task:
This is a function problem. You only need to complete the function permutation that takes S as parameter and prints the permutations in lexicographically increasing order. The newline is automatically added by driver code.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
*/

#########################################################Solution#######################################################################
class Permutation
{
    public void permutation(String S)
    {
        //Your code here
        ArrayList<String> arr=new ArrayList<>();
        permute(S,0,S.length()-1,arr);
        Collections.sort(arr);
        for(int i=0;i<arr.size();i++)
            System.out.print(arr.get(i)+" ");
    }
    
    public static void permute(String S,int l,int r,ArrayList<String> arr){
        if(l==r){
            arr.add(S);
            return;
        }
        for(int i=l;i<=r;i++){
            S=swap(S,l,i);
            permute(S,l+1,r,arr);
            S=swap(S,l,i);
        }
        return;
    }
    
    public static String swap(String S,int j,int i){
        char temp;
        char charArray[]=S.toCharArray();
        temp=charArray[i];
        charArray[i]=charArray[j];
        charArray[j]=temp;
        
        return String.valueOf(charArray);
    }
	   
}
