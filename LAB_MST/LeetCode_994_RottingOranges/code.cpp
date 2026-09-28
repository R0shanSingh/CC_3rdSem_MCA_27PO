// https://leetcode.com/problems/rotting-oranges/submissions/2155753849/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i, j}); 
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int mint=0;
        int direct[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()){
            int size = q.size();
            bool rotten = false;
            for(int i=0;i<size;i++) {
                auto [row,col] = q.front();
                q.pop();
                int r,c;
                for(auto dir :direct) {
                    r=row+dir[0];
                    c=col+dir[1];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1) {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                        rotten=true;
                    }
                }
            }
            if(rotten) mint++;
        }
        if(fresh==0) return mint;
        else return -1;
    }
};
