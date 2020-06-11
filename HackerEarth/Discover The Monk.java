/*
You are given an array A of size N, and Q queries to deal with. For each query, you are given an integer X, and you're supposed to find out if X is present in the array A or not.

Input:
The first line contains two integers, N and Q, denoting the size of array A and number of queries. The second line contains N space separated integers, denoting the array of elements Ai. The next Q lines contain a single integer X per line.

Output:
For each query, print YES if the X is in the array, otherwise print NO.

Constraints:
1 <= N, Q <= 105
1 <= Ai <= 109
1 <= X <= 109

SAMPLE INPUT 
5 10
50 40 30 20 10
10
20
30
40
50
60
70
80
90
100
SAMPLE OUTPUT 
YES
YES
YES
YES
YES
NO
NO
NO
NO
NO

###########################################################Solution#####################################################################
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.*;

class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String []input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);
        
        int arr[] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int queries[] = new int[Q];
        Arrays.sort(arr);
        for(int i=0;i<Q;i++)
            queries[i] = Integer.parseInt(br.readLine());
        for(int i=0;i<Q;i++)   
            bw.write(isPresent(arr,queries[i])+"\n");
        bw.flush();

    }

    static String isPresent(int arr[],int X){
        int start = 0;
        int end = arr.length-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] == X)
                return "YES";
            else if(arr[mid]<X)
                start = mid+1;
            else   
                end = mid-1;
        }

        return "NO";
    }
}
