class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int st = nums[0];
        int end = nums[0];
        vector<string> r;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == end+1){
                end = nums[i];
            }
            else{
                string res = to_string(st);
                if(st != end)
                res+= "->"+to_string(end);
                st = nums[i];
                end = st;
                r.push_back(res);
            }
        }
        string res = to_string(st);
        if (st != end)
            res += "->" + to_string(end);
        r.push_back(res);
        return r;
    }
};