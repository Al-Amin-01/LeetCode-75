#include<bits/stdc++.h>

class Solution {
     
public:
    int call(int i,int prv,vector<int> &prices,int fee,vector<int> &dp){
        if(i>=prices.size()) return 0;
        if(dp[prv]!=-1) return dp[prv];
        if(prices[i]<=prices[prv]){
           
            
            return dp[prv]=call(i+1,i,prices,fee,dp);
        }
        int case1=call(i+1,prv,prices,fee,dp);
        int case2=prices[i]-prices[prv]-fee+call(i+2,i+1,prices,fee,dp);
        return dp[prv]=max(case1,case2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(prices.size(),-1);
        return call(1,0,prices,fee,dp);
    }
};