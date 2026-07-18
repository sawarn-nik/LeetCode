class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=1000,mx=1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mn) mn = nums[i];
            if(nums[i] > mx) mx = nums[i];
        }
        return __gcd(mn,mx);
    }
};