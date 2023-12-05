#include<bits/stdc++.h>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        int x=0;
        for(int i=0;i<n;i++){
            int y=(sum-nums[i]);
            if(y%2==0 && x==y/2) return i;
            x+=nums[i];
        }
        return -1;
    }
};