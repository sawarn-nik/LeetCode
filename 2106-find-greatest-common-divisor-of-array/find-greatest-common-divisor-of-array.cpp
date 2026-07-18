class Solution {
public:
    int findGCD(vector<int>& nums) {
        int gcd = 1;
        int mn=1000,mx=1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < mn) mn = nums[i];
            if(nums[i] > mx) mx = nums[i];
        }
        for(int i = 2; i <= mn; i++){
            if(mn % i == 0 && mx % i == 0) gcd = i;
        }
        return gcd;
        // return __gcd(mn,mx);
    }
};