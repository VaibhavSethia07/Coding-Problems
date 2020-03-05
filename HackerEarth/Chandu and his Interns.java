/*
Chandu is a very strict mentor. He always gives a lot of work to his interns. So his interns decided to kill him. There is a party in the office on Saturday Night, and the interns decided to kill him on the same day. In the party, there are N beer bottles. Each bottle has a integer X written on it. Interns decided to mix poison in some of the beer bottles. They made a plan that they will add poison into a bottle only if the integer on the beer bottle has number of divisors strictly less than 4. Chandu came to know about the plan of the interns. So he needs to your help to save his life. Tell Chandu if he can drink the beer or not.

Input:
First line of contains an integer N, denoting the number of bottles.
Each test case contains an integer X, denoting the number on the beer bottle.

Output:
For each beer bottle, print YES if Chandu can drink that beer, otherwise print NO.

Constraints:
1 <= N <= 105
1 <= X <= 107

SAMPLE INPUT 
3
2
3
6
SAMPLE OUTPUT 
NO
NO
YES
*/

#######################################################Solution############################################################################
import java.util.Scanner;

class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc=new Scanner(System.in);
        
        int N=sc.nextInt();
        long M=10000000;
        boolean isPoisoned[]=new boolean[(int)M];
        boolean isPrime[]=new boolean[(int)M];
        for(long i=2;i<M;i++){
            isPoisoned[(int)i]=true;
            isPrime[(int)i]=true;
        }
        isPoisoned[0]=true;
        isPoisoned[1]=true;
        
        isPrime[0]=false;
        isPrime[1]=false;
        
        for(long i=2;i*i<=M;i++){
            if(isPoisoned[(int)i]){
                for(long j=i*i;j<M;j+=i){
                    isPoisoned[(int)j]=false;
                    isPrime[(int)j]=false;
                }
                if(isPrime[(int)i]==true) 
                    isPoisoned[(int)(i*i)]=true;
            }
        }
        
        for(long i=0;i<N;i++){
            if(isPoisoned[(int)sc.nextLong()]==false)
                System.out.println("YES");
            else
                System.out.println("NO");
        }

    }
}
