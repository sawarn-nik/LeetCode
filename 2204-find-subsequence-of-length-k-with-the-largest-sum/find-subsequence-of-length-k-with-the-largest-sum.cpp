class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        for(int i = 0; i < nums.size(); i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        vector<pair<int,int>> ve;
        for(int i = vec.size()-1; k > 0 && i >= 0; i--){
            ve.push_back({vec[i].second,vec[i].first});
            k--;
        }
        sort(ve.begin(),ve.end());
        vector<int> v;
        for(auto it:ve){
            v.push_back(it.second);
        }
        return v;
    }
};