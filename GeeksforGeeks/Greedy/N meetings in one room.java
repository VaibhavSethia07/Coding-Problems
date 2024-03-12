/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.

###############################################################################Solution##########################################################################################
*/

import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws Exception{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    
	    int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	    while(T-->0){
	        int N = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
	        int startArr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
	        int finishArr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split(" ")).mapToInt(Integer::parseInt).toArray();
	        
	        Meeting meetings[] = new Meeting[N];
	        for(int i=0;i<N;i++)
	            meetings[i] = new Meeting(startArr[i],finishArr[i],i+1);
	            
	       Arrays.sort(meetings);
	       nMeetings(meetings,N);
	    }
	}
	
	static void nMeetings(Meeting meetings[],int N) throws Exception{
	    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	    
	    int prev = 0;
	    bw.write(meetings[0].id+" ");
	    
	    for(int i=1;i<N;i++){
	        if(meetings[i].start>=meetings[prev].finish){
	            bw.write(meetings[i].id+" ");
	            prev = i;
	        }
	    }
	    bw.write("\n");
	    bw.flush();
	} 
}

class Meeting implements Comparable<Meeting>{
    int start;
    int finish;
    int id;
    
    Meeting(int start,int finish,int id){
        this.start = start;
        this.finish = finish;
        this.id = id;
    }
    
    public int compareTo(Meeting other){
        return this.finish-other.finish;
    }
}
