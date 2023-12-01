#include<bits/stdc++.h>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int x=0;
        int i=0,j=n-1;
        while(i<j){
            x=(j-i)*min(height[i],height[j]);
            ans=max(x,ans);
            if(height[i]>height[j]) j--;
            else i++;
        }

        return ans;
        
    }
};