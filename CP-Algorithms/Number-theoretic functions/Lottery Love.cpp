/*
Lottery Love
One day you and your friends go to a city fair to play a famous lottery game. One lottery ticket costs Rs. 
K
.

The shopkeeper gives you a tree with 
n
 nodes when you buy a ticket. Value of 
i
t
h
 node is given by 
A
i
. He then further asks a number 
P
 from you, he will pay you Rs. 
P
 if the number satisfies some conditions. If the number doesn't satisfy the conditions he pays you nothing.

Child of a node is any node which is directly connected to the node. Let 
C
i
 denotes the 
i
t
h
 child of a node. 
S
i
 denotes the sum of values of nodes in subtree of 
C
i
 ( including the value of 
C
i
).

For a node 
i
, you need to find 
V
i
 = maximum 
(
S
j
−
S
k
)
, where 
S
j
 and 
S
k
 are sum value of any two childs of node 
i
. Note - If node 
i
 has only one child node then, assume 
S
k
=
0
 (one of the sum values of child can be assumed zero in case of only one child node).
special_tree.png
For example in the given image:
If you are calculating  
V
2
 then your child nodes are 4, 5 and 1 and their respective subtree sums are 3, -2, 10+8.
You need to perform exactly one transaction with the shopkeeper.

Condition of shopkeeper: The value of 
P
 should be equal to any of the 
V
i
 , where 
i
 is 
i
t
h
 node of tree.

Profit is given by 
P
r
o
f
i
t
=
P
−
K

If maximum profit 
>
0
  then print "Yes" else print "No". Also print maximum profit you could make in the next line.
Note:
1. Note that it is compulsory to buy the lottery ticket.
2. If no number satisfies the condition of shopkeeper then 
P
 is 
0
.

Input Format
First-line contains two integers 
N
K

Second line contains 
N
 integers denoting 
A
1
,
A
2
,
A
3
.
.
.
.
.
.
A
n

Followed by 
N
−
1
 lines, each line constains 2 space seperated integers 
U
i
 
V
i
 which denotes an edge between 
U
i
 and 
V
i

Output Format
If it is impossible print "No" else print "Yes". Also, print the maximum profit you could make in the next line.

Constraints
1
≤
N
≤
10
5

1
≤
K
≤
10
9

−
10
9
≤
A
i
≤
10
9

Time Limit
1s

Example
Sample input
3 12
22 14 -9
1 2
2 3

Sample Output
Yes
24

Sample test case explanation
V1, V2, V3 are respectively 5,33,36.
Therefore, maximum profit = 36 - 12 = 24.

##################################################################################Solution#######################################################################################
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> tree[N];
long long sub[N];
int a,b;
long long ans;
void dfs(int u,int par){
  
  for(auto& v:tree[u]){
    if(v==par)
      continue;
    dfs(v,u);
    sub[u]+=sub[v];
  }
}

void go(int u,int par){
  vector<long long> child;
  for(auto& v:tree[u]){
    if(v==par)
      continue;
    go(v,u);
    child.push_back(sub[v]);
  }
  
  if(par!=0)
    child.push_back(sub[1]-sub[u]);
    
  if(child.size()==1)
    ans=max(ans,child[0]);
  else if(child.size()==0)
    ans=0;
  else{
      sort(child.begin(),child.end());
      ans=max(ans,child[child.size()-1]-child[0]);
  }
} 

int main()
{
  int n,k;
  cin>>n>>k;
  
  for(int i=1;i<=n;i++)
    cin>>sub[i];
    
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  dfs(1,0);
  go(1,0);
  
  ans-=k;
  if(ans<0)
    cout<<"No\n";
  else
    cout<<"Yes\n";
  cout<<ans<<"\n";
  
  return 0;
}
