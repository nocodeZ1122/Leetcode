class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ; 
        int max_all = nums[0] ; 
        int curr_max = nums[0] ; 
        for(int i =1 ; i<n ; i++){
            curr_max = max(nums[i] , curr_max + nums[i]);
            max_all = max(max_all , curr_max) ; 
        }
        return max_all ; 
    }
};