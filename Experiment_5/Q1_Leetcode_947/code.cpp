// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/2188038673/

class Solution {
public:
    void dfs(int u,vector<vector<int>> &stones,vector<bool> &visited){
        visited[u]=true;
        for(int v=0;v<stones.size();++v){
            if(!visited[v]){
                if(stones[v][0]==stones[u][0] || stones[v][1]==stones[u][1]){
                    dfs(v,stones,visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>> &stones){
        int n=stones.size();
        vector<bool> visited(n,false);
        int componentCount = 0;
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i,stones,visited);
                componentCount++;
            }
        }
        return n-componentCount;
    }
};
