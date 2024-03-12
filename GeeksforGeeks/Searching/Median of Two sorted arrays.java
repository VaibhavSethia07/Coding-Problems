
import io.github.pixee.security.BoundedLineReader;
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(BoundedLineReader.readLine(br, 5_000_000));
		
		while(T-->0){
		    int input[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int N = input[0];
		    int M = input[1];
		    int arr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int brr[] = Arrays.stream(BoundedLineReader.readLine(br, 5_000_000).split("\\s+")).mapToInt(Integer::parseInt).toArray();
		    int merged[] = new int[N+M];
		    merge(merged,arr,brr,N,M);
		    System.out.println(getMedian(merged));
		}
	}
	
	private static void merge(int merged[],int arr[],int brr[],int N,int M){
	    int i=0,j=0,k=0;
	    while(i<N && j<M){
	        if(arr[i]<brr[j]){
	            merged[k++] = arr[i++];
	        }
	        else if(arr[i] == brr[j]){
	            merged[k++] = arr[i++];
	            merged[k++] = brr[j++];
	        }
	        else{
	            merged[k++] = brr[j++];
	        }
	    }
	    
	    while(i<N)
	        merged[k++] = arr[i++];
	   
	    while(j<M)
	        merged[k++] = brr[j++];
	}
	
	private static int getMedian(int merged[]){
	    int n = merged.length;
	    if((n & 1) ==0){
		    return (merged[n/2-1]+merged[n/2])/2; 
		}
		else
		    return merged[n/2];
	}
}
