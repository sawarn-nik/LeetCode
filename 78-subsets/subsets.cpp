class Solution {
public:
    void solve(vector<int> &temp,vector<vector<int>> &res, vector<int> &nums, int ind){
        if(ind == nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(temp,res,nums,ind+1);
        temp.pop_back();
        solve(temp,res,nums,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(temp,res,nums,0);

        return res;
    }
};