#include<bits/stdc++.h>
class Solution {
public:
    void call(int ind,vector<int> v[],vector<int> &vis){
        
        for(auto x:v[ind]){
            if(vis[x]==0){
                vis[x]=1;
                call(x,v,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> v[n];
        for(int i=0;i<n;i++){
            v[i]=rooms[i];
        }
        vector<int> vis(n,0);
        vis[0]=1;
        call(0,v,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};