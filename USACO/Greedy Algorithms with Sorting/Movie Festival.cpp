/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1≤n≤2⋅105
1≤a<b≤109
Example

Input:
3
3 5
4 9
5 8

Output:
2

######################################################################################Solution#####################################################################################
*/

// Problem: Movie Festival
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1629
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

class Movie{
	public:
	long start;
	long end;
	bool cmp(Movie&,Movie&);
	
};

bool cmp(Movie& m1,Movie& m2){
		if(m1.end==m2.end)
			return m1.start>m2.start;
		return m1.end<m2.end;
	}

int main(){
	long N;
	cin>>N;
	vector<Movie> movies(N);
	for(int i=0;i<N;i++){
		cin>>movies[i].start>>movies[i].end;
	}
	
	sort(begin(movies),end(movies),cmp);
	long ans=0;
	long e=0;
	for(int i=0;i<N;i++){
		if(e<=movies[i].start){
			ans++;
			e=movies[i].end;
		}
	}
	cout<<ans<<"\n";
	
	return 0;	
}
