#include<bits/stdc++.h>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    
                    q.push({{i,j},0});
                }
            }
        }
        int x[]={1,0,-1,0};
        int y[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            auto p=q.front();
            int i=p.first.first;
            int j=p.first.second;
            int o=p.second;
            
            q.pop();
            
            for(int c=0;c<4;c++){
                
                int xx=i+x[c];
                int yy=j+y[c];
                if(!(xx>=0 && xx<n && yy>=0 && yy<m)) continue;
                if(grid[xx][yy]==1){
                    
                    grid[xx][yy]=2;
                    q.push({{xx,yy},o+1});
                    ans=max(ans,o+1);
                }
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
               
            }
        }
        return ans;
        
    }
};