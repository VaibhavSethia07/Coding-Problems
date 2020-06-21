/*
Case-specific Sorting of Strings
Given a string S consisting of uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the length of string. The second line contains a string S of length N, consisting of uppercase and lowercase characters.

Output:
For each testcase, in a new line, print the answer.

Your Task:
This is a function problem. You only need to complete the function caseSort that returns sorted string.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 103

Example:
Input:
2
12
defRTSersUXI
6
srbDKi
Output:
deeIRSfrsTUX
birDKs

Explanation:
Testcase 1: Sorted form of given string with the same case of character as that in original string.
Testcase 2: Sorted form of given string with the same case of character will result in output as birDKs.

###########################################################Solution#####################################################################
*/
// Solution 1

class solve{
    public static String caseSort(String str) {
        String visited = "";
        String result = "";
        
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)-'a'>=0)
                visited +="L";
            else
                visited +="U";
        }
        
        char arr[] = str.toCharArray();
        quickSort(arr,0,arr.length-1);
        
        int pivot = getPivot(arr,0,arr.length-1);
        
        if(pivot == -1)
            return String.valueOf(arr);
        
        int upper = 0;
        int lower = pivot;
        
        return generateResult(arr,visited,lower,upper); 
    }
    
    static void quickSort(char[] arr,int start,int end){
        if(start<end){
            int pivot = partition(arr,start,end);
            quickSort(arr,start,pivot-1);
            quickSort(arr,pivot+1,end);
        }
    }
    
    static int partition(char[] arr,int start,int end){
        int pivot = end;
        int i = start -1;
        
        for(;start<=end-1;start++){
            if(arr[start]<=arr[pivot]){
                i++;
                swap(arr,i,start);
            }
        }
        i++;
        swap(arr,i,pivot);
        return i;
    }
    
    static void swap(char[] arr,int start,int end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    
    static int getPivot(char[] arr,int start,int end){
        if(start>end)
            return -1;
        
        int mid = start + (end-start)/2;
        
        if((mid==0 || arr[mid-1]-'a'<0) && arr[mid]-'a'>=0)
            return mid;
        else if(arr[mid]-'a'<0)
            return getPivot(arr,mid+1,end);
        else
            return getPivot(arr,start,mid-1);
    }
    
    static String generateResult(char []arr,String visited,int lower,int upper){
        String result = "";
        
        for(int i=0;i<visited.length();i++){
            if(visited.charAt(i) == 'L'){
                result += arr[lower++];
            }else
                result += arr[upper++];
        }
        return result;
    }  
}

// Solution 2
class solve{
    public static String caseSort(String str) {
        int N = str.length();
        boolean visited[] = new boolean[N];
        char lowerArray[] = new char[N];
        char upperArray[] = new char[N];
        
        int x = 0;
        int y = 0;
        
        for(int i=0;i<N;i++){
            if(str.charAt(i)-'a'<0){
                visited[i] = true;
                upperArray[x++] = str.charAt(i); 
            }
            else{
                lowerArray[y++] = str.charAt(i);
            }
            //set false for lower case
        }

        quickSort(upperArray,0,x-1);
        quickSort(lowerArray,0,y-1);
        
        return generateResult(visited,lowerArray,upperArray,N);
        
    }
    
    static void quickSort(char arr[],int start,int end){
        if(start<end){
            int pivot = partition(arr,start,end);
            quickSort(arr,start,pivot-1);
            quickSort(arr,pivot+1,end);
        }
    }
    
    static int partition(char arr[],int start,int end){
        int pivot = end;
        int i = start-1;
        
        for(;start<=end-1;start++){
            if(arr[start]<arr[pivot]){
                i++;
                swap(arr,i,start);
            }
        }
        
        i++;
        swap(arr,i,pivot);
        
        return i;
    }
    
    static void swap(char arr[],int start,int end){
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    
    static String generateResult(boolean visited[],char lowerArray[],char upperArray[],int N){
        String result =  "";
        int x = 0;
        int y = 0;
        for(int i=0;i<N;i++){
            //concatenate upper case letter and lower case letters
            if(visited[i])
                result += upperArray[y++];
            else
                result += lowerArray[x++];
        }
        
        return result;
    }
}
