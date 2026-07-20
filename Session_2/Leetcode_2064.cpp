class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        int output = 0 ;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(dis(n,quantities,mid)){
                output = mid;
                high=mid-1;
            } 
            else low = mid +1;
        }
        return output;
    }
    bool dis(int n, vector<int>& quantities, int mid) {
        int stores = 0;
        for (int q : quantities) {
            stores += (q+mid-1)/mid;
            if (stores>n)
                return false;
        }
        return true;
    }
};
