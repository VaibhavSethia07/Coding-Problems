/*
Due to the increase in the number of students of Berland State University it was decided to equip a new computer room. You were given the task of buying mouses, and you have to spend as little as possible. After all, the country is in crisis!

The computers bought for the room were different. Some of them had only USB ports, some — only PS/2 ports, and some had both options.

You have found a price list of a certain computer shop. In it, for m mouses it is specified the cost and the type of the port that is required to plug the mouse in (USB or PS/2). Each mouse from the list can be bought at most once.

You want to buy some set of mouses from the given price list in such a way so that you maximize the number of computers equipped with mouses (it is not guaranteed that you will be able to equip all of the computers), and in case of equality of this value you want to minimize the total cost of mouses you will buy.

Input
The first line contains three integers a, b and c (0 ≤ a, b, c ≤ 105)  — the number of computers that only have USB ports, the number of computers, that only have PS/2 ports, and the number of computers, that have both options, respectively.

The next line contains one integer m (0 ≤ m ≤ 3·105)  — the number of mouses in the price list.

The next m lines each describe another mouse. The i-th line contains first integer vali (1 ≤ vali ≤ 109)  — the cost of the i-th mouse, then the type of port (USB or PS/2) that is required to plug the mouse in.

Output
Output two integers separated by space — the number of equipped computers and the total cost of the mouses you will buy.

Example
inputCopy
2 1 1
4
5 USB
6 PS/2
3 PS/2
7 PS/2
outputCopy
3 14
Note
In the first example you can buy the first three mouses. This way you will equip one of the computers that has only a USB port with a USB mouse, and the two PS/2 mouses you will plug into the computer with PS/2 port and the computer with both ports.

#####################################################################################Solution######################################################################################
*/

// Problem: B. USB vs. PS/2
// Contest: Codeforces - Educational Codeforces Round 17
// URL: https://codeforces.com/contest/762/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int main(){
	int a,b,c,m;
	cin>>a>>b>>c>>m;
	vector<long> usb;
	vector<long> ps2;
	for(int i=0;i<m;i++){
		long c;
		string type;
		cin>>c>>type;
		if(type=="USB")
			usb.push_back(c);
		else
			ps2.push_back(c);
	}
	sort(usb.begin(),usb.end());
	sort(ps2.begin(),ps2.end());
	long long cost=0,cnt=0;
	int i=0,j=0,x=(int)usb.size(),y=(int)ps2.size();
	while(i<x && a>0){
		cost+=usb[i];
		i++;
		a--;
		cnt++;
	}
	while(j<y && b>0){
		cost+=ps2[j];
		j++;
		b--;
		cnt++;
	}
	while(c>0 && i<x && j<y){
		if(usb[i]<=ps2[j]){
			cost+=usb[i];
			i++;
		}else if(usb[i]>ps2[j]){
			cost+=ps2[j];
			j++;
		}
		c--;
		cnt++;
	}
	while(i<x && c>0){
		cost+=usb[i];
		i++;
		c--;
		cnt++;
	}
	while(j<y && c>0){
		cost+=ps2[j];
		j++;
		c--;
		cnt++;
	}
	cout<<cnt<<" "<<cost<<"\n";
	return 0;	
}
