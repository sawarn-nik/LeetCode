class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> temp(2048,0);
        unordered_set<int>st;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                temp[nums[i] ^ nums[j]] = 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 2048; j++) {
                if(temp[j]){
                    st.insert(nums[i] ^ j);
                }
            }
        }

        return st.size();
    }
};