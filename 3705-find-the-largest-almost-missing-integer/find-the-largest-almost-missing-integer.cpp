class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        for(auto it: nums){
            freq[it]++;
        }
        if(k == 1){
            for(int i = freq.size()-1; i >= 0; i--){
                if(freq[i] == 1){
                    return i;
                }
            }
        }
        if(k == nums.size()){
            int mx = 0;
            for(int i = 0; i < nums.size(); i++){
                mx = max(mx,nums[i]);
            }
            return mx;
        }
        else{
            if(freq[nums[0]] == 1 && freq[nums[nums.size()-1]] == 1){
                return max(nums[0],nums[nums.size()-1]);
            }
            else if(freq[nums[0]] == 1){
                return nums[0];
            }
            else if(freq[nums[nums.size()-1]] == 1){
                return nums[nums.size()-1];
            } 
        }
        return -1;
    }
};