class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> mp(501,0);
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it%2) return false;
        }
        return true;
    }
};