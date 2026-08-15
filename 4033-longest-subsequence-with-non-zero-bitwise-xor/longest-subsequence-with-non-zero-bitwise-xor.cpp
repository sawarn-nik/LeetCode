class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] == 0)return 0;
            return 1;
        }
        bool flag = false;
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1] == 0) flag = true;
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res ^= nums[i];
        }
        if(flag) return 0;
        else if(res) return nums.size();
        else return nums.size()-1;
    }
};