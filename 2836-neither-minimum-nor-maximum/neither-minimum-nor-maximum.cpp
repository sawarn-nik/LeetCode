class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2) return -1;

        sort(nums.begin(),nums.end());
        int s = nums[0],e = nums[nums.size()-1];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != s && nums[i] != e){
                return nums[i];
                break;
            }
        }
        return -1;
    }
};