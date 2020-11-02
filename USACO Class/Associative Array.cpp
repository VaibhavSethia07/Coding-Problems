/*
You are given an array aa with infinite length. Initially, all elements are 00. Process the following QQ queries in order.

0 kk vv: a[k] \gets va[k]←v
1 kk: Print a[k]a[k]
Constraints
1 \leq Q \leq 10^{6}1≤Q≤10 
6
 
0 \leq k, v \leq 10^{18}0≤k,v≤10 
18

##################################################################################Solution#########################################################################################
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<long,long> associate;
    int Q;
    cin>>Q;
    int b;
    long k;
    long v;
    for(int a=0;a<Q;a++){
        cin>>b;
        if(b==0){
            cin>>k>>v;
            associate[k] = v;
        }else if(b==1){
            cin>>k;
            cout<<associate[k]<<"\n";
        }
    }
    return 0;
}
