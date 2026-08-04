class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> cnt(101,-1);
        for(auto it: nums){
            cnt[it] = 1;
        }
        vector<int>res;
        int st = 0,en = 0;
        for(int i = 0; i < 101; i++){
            if(cnt[i] == 1) 
            {
                st = i;
                break;
            }
        }
        for(int i = 100; i >= 0; i--){
            if(cnt[i] == 1) 
            {
                en = i;
                break;
            }
        }
        for(int i = st; i <= en; i++){
            if(cnt[i] == -1) res.push_back(i);
        }
        return res;
    }
};