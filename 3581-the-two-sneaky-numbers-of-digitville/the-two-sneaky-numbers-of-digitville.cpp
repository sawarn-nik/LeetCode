class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(100,0);
        vector<int> res;
        for(int i = 0; i < n; i++){
            temp[nums[i]]++;
            cout<<nums[i]<<"->"<<temp[nums[i]]<<endl;
        }
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == 2) res.push_back(i);
        }
        return res;
    }
};