class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& v) {
        vector<vector<int>> res;
        sort(v.begin(), v.end());
        do {
            vector<int> t;
            for (int x : v)
                t.push_back(x);
            // if(st.find(t) == st.end())
            // {   
            //     st.insert(t);
            res.push_back(t);
            // }
        } while (next_permutation(v.begin(), v.end()));
        return res;
    }
};