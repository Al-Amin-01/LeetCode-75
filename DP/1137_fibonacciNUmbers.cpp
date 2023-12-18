#include<bits/stdc++.h>
class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(n+1);
        if(n==0) return 0;
        if(n<=2) return 1;

        v[0]=0,v[1]=1,v[2]=1;
        for(int i=3;i<=n;i++){
            v[i]=v[i-3]+v[i-2]+v[i-1];
        }
        return v[n];
    }
};