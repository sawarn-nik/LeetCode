class Solution {
public:
    int distributeCandies(vector<int>& cT) {
        int n = cT.size();
        unordered_set<int> st(cT.begin(), cT.end());
        return min(n/2,(int)st.size());
    }
};