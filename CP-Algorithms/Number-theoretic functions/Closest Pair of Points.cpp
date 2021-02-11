#include <bits/stdc++.h>
using namespace std;

class Point{
	public:
	int x;
	int y;
};

int distance(Point& p1,Point& p2){
	return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
	
int distCase3(vector<Point>& case3,int count,int midDist){
	
	int minVal = midDist;
	
	for(int i=0;i<count;i++){
		for(int j=i+1;j<min(i+8,count);j++)
			minVal = min(minVal,distance(case3[i],case3[j]));
	}
	
	return minVal;
}

int baseValue(vector<Point>& vX,int count){
	int mn=INT_MAX;
	
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			mn=min(mn,distance(vX[i],vX[j]));
		}
	}
	
	return mn;
}


int closestDistance(vector<Point>& vX,vector<Point>& vY,int count){
	
	if(count<=3){
		return baseValue(vX,vX.size());
	}
	
	int mid=count/2;
	Point& midPoint = vX[mid];
	
	vector<Point> left;
	vector<Point> right;
	
	for(int i=0;i<mid;i++)
		left.push_back(vX[i]);
	
	for(int i=mid;i<(int)vX.size();i++)
		right.push_back(vX[i]);
		
	int distLeft = closestDistance(left,vY,mid);
	int distRight = closestDistance(right,vY,count-mid);
	
	int minDist = min(distLeft,distRight);
	
	vector<Point> case3;
	for(int i=0;i<count;i++){
		if(abs(vY[i].x-midPoint.x)<minDist)
			case3.push_back(vY[i]);
	}
	
	
	return min(minDist,distCase3(case3,case3.size(),minDist));
}
int main(){
	
	int N,a,b;
	cin>>N;
	vector<Point> vX(N);
	vector<Point> vY(N);
	
	for(int i=0;i<N;i++){
		cin>>a>>b;
		vX[i]={a,b};
		vY[i]={a,b};
	}
	
	sort(begin(vX),end(vX),[](const Point& p1,const Point& p2){ return p1.x< p2.x;});
	sort(begin(vY),end(vY),[](const Point& p1,const Point& p2){ return p1.y< p2.y;});
	
	cout<<"The smallest distance is "<<closestDistance(vX,vY,N)<<"\n";
	
	return 0;	
}
