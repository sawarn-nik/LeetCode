class Solution {
public:
    void solve(int ind,int sum,vector<int> c, int t, vector<vector<int>> &res, vector<int> &temp){
        if(sum == t){
            res.push_back(temp);
            return;
        }
        if(ind == c.size() || sum > t){
            return;
        }

        sum += c[ind];
        temp.push_back(c[ind]);
        solve(ind,sum,c,t,res,temp);

        sum -= c[ind];
        temp.pop_back();
        solve(ind+1,sum,c,t,res,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(0,0,c,t,res,temp);
        return res;
    }
};