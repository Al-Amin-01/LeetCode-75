class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> ans(n,false);
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,candies[i]);
        }
        for(int i=0;i<n;i++){
            if(mx<=candies[i]+extraCandies) ans[i]=true;
        }
        return ans;
        
    }
};