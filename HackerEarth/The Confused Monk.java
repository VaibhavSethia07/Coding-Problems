/*
The Monk wants to teach all its disciples a lesson about patience, since they are always in a hurry to do something crazy. To teach them this, he gives them a list of N numbers, which may or may not be distinct. The students are supposed to solve a simple Mathematical equation based on the array of these N numbers.

g(x) - GCD (a[ 0 ], a[ 1 ], a[ 2 ]... a[n-1] )
f(x) - (a[ 0 ] * a[ 1 ] * a[ 2 ]... * a[n-1] )
The value of the MonkQuotient is: 109 + 7.

The equation to be solved is: ( f(x)g(x) ) % MonkQuotient

Input constraints:
The first line of input will contain an integer — N. The next line will contain N integers denoting the elements of the list.

Output constraints:
Print the required answer of the equation.

Constraints:
1 ≤ N ≤ 50
1 ≤ Ai ≤ 103

SAMPLE INPUT 
2
2 6
SAMPLE OUTPUT 
144
*/

##############################################################Solution#####################################################################
import java.util.Scanner;

class TestClass {
    
    static long result=1;
    static int monkQ=1000000000+7;
    
    public static long euclidsAlgo(long a,long b){
        if(b==0)
            return a;
        long gcd=euclidsAlgo(b,a%b);
        return gcd;
    }
    
    public static long gx(int arr[],long a,long b,int i){
        if(i==arr.length-1)
            return euclidsAlgo(a,b);
        
        return gx(arr,euclidsAlgo(a,b),arr[i+1],i+1);
    }
    
    public static long binaryExponentiation(long F,long G){
        
        if(G==0)
            return 1;
            
        if(G==1)
            return F;
        
        if((G & 1)==1)
            return ((F%monkQ)*(binaryExponentiation(((F)%monkQ*(F)%monkQ)%monkQ,G/2)%monkQ))%monkQ;
        else
            return (binaryExponentiation(((F%monkQ)*(F%monkQ))%monkQ,G/2))%monkQ;
        
    }
    
    public static void main(String args[] ) throws Exception {
        
       Scanner sc=new Scanner(System.in);
       int N=sc.nextInt();
       int arr[]=new int[N];
       
       long F=1;
       
       for(int i=0;i<N;i++){
            long element=sc.nextLong();
            arr[i]=(int)element;
            F=((F%monkQ)*(element%monkQ))%monkQ;
       }
       if(N!=1){
            long G=gx(arr,arr[0],arr[1],1);
            System.out.println(binaryExponentiation(F,G));
       }
       else
            System.out.println(binaryExponentiation(F,F));
    }
}
