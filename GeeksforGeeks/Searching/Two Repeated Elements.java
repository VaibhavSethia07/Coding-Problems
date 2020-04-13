/*
You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow Each test case consists of two lines. First line of each test case contains an integer N denoting the range of numbers to be inserted in array of size N+2. Second line of each test case contains the N+2 space separated integers denoting the array elements.

Output:
Print the two elements occuring twice in the array. Order of the two elements must be according to second appearance, i.e., first print the element whose second occurrence arrives first. For example in 1 2 2 1, the output should be 2 1. And for 1 1 2 2, output should be 1 2.

User Task:
The task is to complete the function repeatedElements() which finds the two repeated element in the array and prints them. The newline is added by the driver code automatically.

Constraints:
1 ≤ T ≤ 30
1 ≤ N ≤ 105

Example:
Input:
3
4
1 2 1 3 4 3
2
1 2 2 1
2
1 1 2 2
Output:
1 3
2 1
1 2

##############################################################Solution##################################################################
*/

class Repeated{

    static void twoRepeated(int arr[], int n){
        StringBuffer str = new StringBuffer();
        for(int i=0;i<n+2;i++){
            arr[Math.abs(arr[i])] = -arr[Math.abs(arr[i])];
            if(i>0 && arr[Math.abs(arr[i])]>0){
                str.append(Math.abs(arr[i]));
                str.append(" ");
            }
        }
        System.out.print(str);
    }
}
