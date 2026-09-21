// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/2148489553/
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> time(n, LLONG_MAX);
        vector<int> count(n, 0);
        pq.push({0, 0});
        time[0] = 0;
        count[0] = 1;

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            long long currT = p.first;
            int currN = p.second;
            for(auto adjacent : adj[currN]) {
                int adj_node = adjacent.first;
                int adj_time = adjacent.second;
                long long newTime = currT + adj_time;
                if(newTime < time[adj_node]) {
                    time[adj_node] = newTime;
                    count[adj_node] = count[currN];
                    pq.push({newTime, adj_node});
                }
                else if(newTime == time[adj_node]) {
                    count[adj_node] =(count[adj_node] + count[currN]) % MOD;
                }
            }
        }
        return count[n-1];
    }
};
