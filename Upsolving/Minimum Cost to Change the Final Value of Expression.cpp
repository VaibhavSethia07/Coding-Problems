#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperationsToFlip(string S) {
        stack<pair<char,int>> st;
        pair<char,int> p;
        for(int i=0;i<(int)S.size();i++){
            if(S[i]=='(' || S[i]=='&' || S[i]=='|')
                st.push({S[i],-1});
            else{
                
                if(S[i]==')'){
                    p=st.top();
                    st.pop();
                    st.pop();
                }else
                    p={S[i],1};
        
                while(!st.empty() && (st.top().first=='&' || st.top().first=='|')){
                    char op=st.top().first;
                    st.pop();
                    
                    char val1=p.first;
                    int cost1=p.second;
                    
                    char val2=st.top().first;
                    int cost2=st.top().second;
                    st.pop();
                    
                    if(val1=='0' && op=='|' && val2=='0')
                        p={'0',min(cost1,cost2)};
                    if(val1=='0' && op=='|' && val2=='1')
                        p={'1',1};
                    if(val1=='1' && op=='|' && val2=='0')
                        p={'1',1};
                    if(val1=='1' && op=='|' && val2=='1')
                        p={'1',1+min(cost1,cost2)};
                    
                    if(val1=='0' && op=='&' && val2=='0')
                        p={'0',1+min(cost1,cost2)};
                    if(val1=='0' && op=='&' && val2=='1')
                        p={'0',1};
                    if(val1=='1' && op=='&' && val2=='0')
                        p={'0',1};
                    if(val1=='1' && op=='&' && val2=='1')
                        p={'1',min(cost1,cost2)};
                }
                st.push(p);
            }
        }
        return st.top().second;
    }
};
