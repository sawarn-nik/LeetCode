class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int it:nums){
            mp[it]++;
        }
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                sum+=nums[i];
            }
            else break;      
        }
        cout<<sum<<endl;
        for(int i = sum; i <= INT_MAX; i++)
        {
            if(mp[i] == 0) return i;
        }
        return 0;
    }
};