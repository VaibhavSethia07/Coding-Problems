/*
Check if string is rotated by two places
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. In the next two lines are two string a and b respectively.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

User Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor
Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make it as azonam.
Testcase 2: If we rotate geeksforgeeks by two place in any direction , we won't get geeksgeeksfor.

#############################################################Solution###################################################################
*/

class Rotation{
    public static boolean isRotated(String s1, String s2){
        if(s1.length() != s2.length())
            return false;
            
        int N = s1.length();
            
        char arr[] = s2.toCharArray();
    
        if(N>2){
            reverse(arr,0,1);
            reverse(arr,2,N-1);
            reverse(arr,0,N-1);
        }
        if(s1.equals(String.valueOf(arr)))
            return true;
        
        arr = s2.toCharArray();
        
        if(N>=4){
            reverse(arr,N-2,N-1);
            reverse(arr,0,N-3);
            reverse(arr,0,N-1);
        }
        
        if(s1.equals(String.valueOf(arr)))
            return true;
        
        return false;
    }
    
    static void reverse(char arr[],int start,int end){
        char temp;
        while(start<end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}
