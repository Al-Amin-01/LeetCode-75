#include<bits/stdc++.h>
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double d=values[i];

            graph[a].push_back({b,d});
            graph[b].push_back({a,1.0/d});
        }
        vector<double> v;
        for(auto query:queries){
            unordered_set<string> visited;
            string a=query[0];
            string b=query[1];
            v.push_back(dfs(a,b,visited));

        }
        return v;
    }

    double dfs(string src,string dst,unordered_set<string> &visited){
        if(graph.find(src)==graph.end()) return -1;
        if(src==dst) return 1;

        for(auto x:graph[src]){
            string y=x.first;
            if(visited.count(y)) continue;
            visited.insert(y);
            double z=dfs(y,dst,visited);
            if(z!=-1) return z*x.second;
        }
        return -1;
    }
};