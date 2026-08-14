class Solution {
public:
void solve(int k,int ind,int sum,vector<int> &c, int n, vector<vector<int>> &res, vector<int> &temp){
        if(sum == n && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(ind == c.size() || sum > n || temp.size() > k){
            return;
        }

        sum += c[ind];
        temp.push_back(c[ind]);
        solve(k,ind+1,sum,c,n,res,temp);

        sum -= c[ind];
        temp.pop_back();
        solve(k,ind+1,sum,c,n,res,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> c = {1,2,3,4,5,6,7,8,9};
        solve(k,0,0,c,n,res,temp);
        return res;
    }
};