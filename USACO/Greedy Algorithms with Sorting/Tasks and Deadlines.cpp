/*
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d−f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)

What is your maximum reward if you act optimally?

Input

The first input line has an integer n: the number of tasks.

After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.

Output

Print one integer: the maximum reward.

Constraints
1≤n≤2⋅105
1≤a,d≤106
Example

Input:
3
6 10
8 15
5 12

Output:
2

#################################################################################Solution##########################################################################################
*/

// Problem: Tasks and Deadlines
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1630
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;

#define mp make_pair
#define f first
#define s second

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i<(b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i>=(a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

struct Task{
	int dur,dead;
	
};
bool cmp(const Task& t1,const Task& t2){
	if(t1.dur==t2.dur)
		return t1.dead>t2.dead;
	return t1.dur<t2.dur;
}

int main(){
	int n;
	cin>>n;
	vector<Task> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].dur>>v[i].dead;
	sort(begin(v),end(v),cmp);
	long ans=0,endTime=0;
	for(int i=0;i<n;i++){
		endTime+=v[i].dur;
		ans+=v[i].dead-endTime;
	}
	cout<<ans<<"\n";
	return 0;	
}
