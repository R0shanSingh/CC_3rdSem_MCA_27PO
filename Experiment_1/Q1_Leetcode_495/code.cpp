// https://leetcode.com/problems/construct-the-rectangle/submissions/2133673312/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> output;
        int width = sqrt(area);
        while(area%width){
            width--;
        }
        int length = area/width;
        output.push_back(length);
        output.push_back(width);
        return output;
    }
};
