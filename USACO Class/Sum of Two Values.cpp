/*
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2⋅105
1≤x,ai≤109
Example

Input:
4 8
2 7 5 1

Output:
2 4

######################################################################Solution###############################################################
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,X;
    cin>>N>>X;
    
    int arr[N];
    for(int a=0;a<N;a++) cin>>arr[a];
    bool flag=false;
    set<int>values;
    for(int a=0;a<N;a++){
        if(values.count(X-arr[a])){
            
            for(int b=0;b<a;b++)
                if(X-arr[a]==arr[b]){
                    cout<<b+1<<" "<<a+1<<"\n";
                    flag = true;
                    break;
                }
        }else
            values.insert(arr[a]);
            
        if(flag){
            return 0;
        }
    }
    
    if(!flag)cout<<"IMPOSSIBLE\n";
    
	return 0;
}
