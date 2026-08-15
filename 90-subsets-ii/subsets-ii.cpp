class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int>& nums,int ind,vector<int>& temp){
        if(ind == nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        int next = ind+1;
        solve(res,nums,next,temp);
        temp.pop_back();
        while(next < nums.size() && nums[next] == nums[ind]){
            next++;
        }
        solve(res,nums,next,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(res,nums,0,temp);

        return res;
    }
};