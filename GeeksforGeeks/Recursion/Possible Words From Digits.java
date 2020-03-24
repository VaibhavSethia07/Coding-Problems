/*
Given a keypad as shown in diagram, and an N digit number. List all words which are possible by pressing these numbers.



Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line of each test case is N, N is the number of digits. The second line of each test case contains D[i], N number of digits.

Output:
Print all possible words from phone digits with single space.

Your Task:
This is a function problem. You just need to complete the function possibleWords that takes an array as parameter and prints all the possible words. The newline is automatically added by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 10
2 <=  D[i] <= 9

Example:
Input:
2
3
2 3 4
3
3 4 5
Output:
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi
dgj dgk dgl dhj dhk dhl dij dik dil egj egk egl ehj ehk ehl eij eik eil fgj fgk fgl fhj fhk fhl fij fik fil

Explanation:
Testcase 1: When we press 2,3,4 then adg,adh,adi , ......,cfi are the list of possible words.
Testcase 2: When we press 3,4,5 then dgj,dgk,dgl,.......,fil are the list of possible words.

########################################################Solution########################################################################
*/

class PhoneDigit
{
    static void possibleWords(int a[], int N)
    {
        String []qwerty = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        String []dial = new String[N];
        
        for(int i=0;i<N;i++)
            dial[i]=qwerty[a[i]];
        int l=0;
        int j=0;
        char charArray[]=new char[11];
        ArrayList<String> result = new ArrayList<>();
        generate(dial,charArray,l,j,result);
        
        for(int i=0;i<result.size();i++){
            if(i!=result.size()-1)
                System.out.print(result.get(i)+" ");
            else
                System.out.print(result.get(i));
        }
        
    }
    
    static void generate(String dial[],char charArray[],int l,int j,ArrayList<String> result){
        int i=0;
        if(j==dial.length)
                result.add(String.valueOf(charArray));
            return;
        }
            
        for( i=l;i<dial[j].length();i++){
            charArray[j]=dial[j].charAt(i);
            generate(dial,charArray,l,j+1,result);
            // charArray[j]=' ';
        }
    }
}
