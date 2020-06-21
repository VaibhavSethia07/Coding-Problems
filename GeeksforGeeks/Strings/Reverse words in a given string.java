/*
Reverse words in a given string
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

User Task:
The task is to complete the function reverseWords() which reverse words from the given string and prints the answer. The newline is automatically appended by the driver code.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno
Output:
much.very.program.this.like.i
mno.pqr

Explanation:
Testcase 1: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.
Testcase 2: After reversing the whole string , the input string becomes mno.pqr.

################################################################Solution################################################################
*/

// Solution 1
class Reverse {

    public void reverseWords(String sd) {
        String words[]= sd.split("\\.");
        int start = 0;
        int end = words.length-1;
        String temp;
        String result = "";
        
        while(start<=end){
            temp = words[start];
            words[start] = words[end];
            words[end] = temp;
            start++;
            end--;
        }
        
        for(int i=0;i<words.length;i++){
            result+=words[i];
            if(i<words.length-1)
                result+=".";
        }
        
        System.out.print(result);
    }
}

// Solution 2
class Reverse {

    public static void reverseWords(String sd) {
        String words[] = sd.split("\\.");
        
        String result = "";
        
        for(int i=words.length-1;i>=0;i--){
            result+=words[i];
            if(i!=0)
                result+=".";
        }
        
        System.out.print(result);
    }
}
