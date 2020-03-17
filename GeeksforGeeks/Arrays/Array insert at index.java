/*
Insertion is a basic but frequently used operation. Arrays in most languages cannnot be dynamically shrinked or expanded. Here, we will work with such arrays and try to insert an element at some index.

You are given an array arr. The size of the array is given by sizeOfArray. You need to insert an element at given index and print the modified array.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input. The first line contains size of the array denoted by sizeOfArray. The second line contains sizeOfArray-1 elements separated by spaces. The third line contains index and the element to be inserted separated by a space.

Output Format:
For each testcase, in a new line, print the modified array.

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function insertAtIndex() that takes arr, sizeOfArray, index, element as input. The printing is done by driver code.

Constraints:
1 <= T <= 100
2 <= sizeOfArray <= 1000
0 <= element, arri <= 106
0 <= index <= sizeOfArray-1

Examples:
Input:
2
6
1 2 3 4 5
5 90
6
1 2 3 4 5
2 90

Output:
1 2 3 4 5 90
1 2 90 3 4 5
*/

###############################################################Solution#################################################################
class Insert
{
    // You need to insert the given element at the given index. 
    // After inserting the elements at index, elements
    // from index onward should be shifted one position ahead
    // You may assume that the array already has sizeOfArray - 1
    // elements.
    public void insertAtIndex(int arr[],int sizeOfArray,int index,int element)
    {
        //Your code here, Geeks
        if(index==sizeOfArray-1)
            arr[index]=element;
        else{
            for(int i=sizeOfArray-2;i>=index;i--)
                arr[i+1]=arr[i];
         arr[index]=element;
        }
    }
}
