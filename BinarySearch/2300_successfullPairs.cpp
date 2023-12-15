#include<bits/stdc++.h>
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int cnt=0,l=0,r=m-1;
            if(1LL*spells[i]*potions[r]<success) continue;
            while(l<r){
                int mid=(l+r)/2;
                if(1LL*spells[i]*potions[mid]<success){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }
            if(1LL*spells[i]*potions[l]>=success) ans[i]=m-l;
            else ans[i]=m-r;
            
        }
        return ans;
    }
};