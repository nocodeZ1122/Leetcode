
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr_max = nums[0];
        int max_all = nums[0];

        int curr_min = nums[0];
        int min_all = nums[0];

        int n = nums.size();

        for(int i = 1; i < n; i++) {
            curr_max = max(nums[i], curr_max + nums[i]);
            max_all = max(max_all, curr_max);

            curr_min = min(nums[i], curr_min + nums[i]);
            min_all = min(min_all, curr_min);
        }

        return max(max_all, abs(min_all));
    }
};

