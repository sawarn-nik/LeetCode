class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int len = 0,i = 0, j = 0, n = nums.size();
        unordered_map<int,int> mp;

        while(j < n){
            if(mp.find(nums[j]) == mp.end()){
                mp[nums[j]]++;
                len = max(len,j-i+1);
                j++;
            }
            else if(mp[nums[j]] < k){
                mp[nums[j]]++;
                len = max(len,j-i+1);
                j++;
            }
            else{
                mp[nums[i]]--;
                i++;
            }
        }
        return len;
    }
};