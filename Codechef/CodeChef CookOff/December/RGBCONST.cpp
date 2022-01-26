class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int,int>>> graph(n);  
        for(auto& v:red) graph[v[0]].push_back({v[1], 0});
        for(auto& v:blue) graph[v[0]].push_back({v[1], 1});
        vector<vector<int>> ans(n, vector<int>(2,-1));
        queue<pair<int,int>> q;
        q.push({0,0});  q.push({0,1});
        ans[0] = {0,0};
        while(!q.empty()){
            auto [i, c1] = q.front(); q.pop();
            for(auto [j, c2] : graph[i]){
                if(ans[j][c2] != -1 || c1 == c2) continue;
                ans[j][c2] = 1 + ans[i][c1];
                q.push({j, c2});
            }
        }
        vector<int> res;
        for(auto& v : ans) {
            sort(v.begin(), v.end());
            res.push_back(v[0] != -1 ? v[0] : v[1]);
        }
        return res;
    }
};