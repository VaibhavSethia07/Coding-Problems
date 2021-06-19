/* Problem- https://www.lintcode.com/problem/434/description */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    int N,M;

    const int dx[4]={1,0,-1,0};
    const int dy[4]={0,1,0,-1};

    void make_par(vector<int>& parent,vector<int>& sz){
        for(int i=0;i<(int)parent.size();i++){
            parent[i]=i;
            sz[i]=1;
        }
    }

    int find(int x,vector<int>& parent){
        vector<int> anc;
        while(x!=parent[x]){
            anc.push_back(x);
            x=parent[x];
        }

        for(int i=0;i<(int)anc.size();i++)
            parent[anc[i]]=x;
        return x;
    }

    bool unite(int a,int b,vector<int>& parent,vector<int>& sz){
        if(find(a,parent)==find(b,parent))
            return false;
        a=find(a,parent);
        b=find(b,parent);
         
        if(sz[a]<sz[b])
            swap(a,b);
        sz[a]+=sz[b];
        parent[b]=a;

        return true;
    }

    int rep(int x,int y){
        return x*M+y;
    }

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        
        vector<vector<int>> grid(n,vector<int>(m));
        N=n,M=m;
        int comp=0;
        vector<int> parent(N*M+M);
        vector<int> sz(N*M+M);
        vector<int> result;
        make_par(parent,sz);

        for(int i=0;i<(int)operators.size();i++){
            int x=operators[i].x;
            int y=operators[i].y;
            if(grid[x][y]==1){
                result.push_back(comp);
                continue;
            }
               
            grid[x][y]=1;
            comp++;
            
            for(int j=0;j<4;j++){
                int xx=x+dx[j];
                int yy=y+dy[j];
                if(xx<0 || xx>=N || yy<0 || yy>=M)
                    continue;
                if(grid[xx][yy]==1){
                    if(unite(rep(x,y),rep(xx,yy),parent,sz))
                        comp--;
                }
                    
            }
            result.push_back(comp);
        }

        return result;
    }
};
