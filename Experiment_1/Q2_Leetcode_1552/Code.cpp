// https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/2133691554/
class Solution {

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (placeBall(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    bool placeBall(vector<int>& position, int m, int minForce) {
        int count = 1;
        int lastPos = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minForce) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }
};
