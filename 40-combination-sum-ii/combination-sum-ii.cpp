class Solution {
private:
    void pf(int ind,vector<vector<int>> &res, vector<int> c, int t,int sum,vector<int>& temp){
        if(sum == t){
            res.push_back(temp);
            return;
        }
        if (ind == c.size() || sum > t)
            return;

        temp.push_back(c[ind]);
        int next = ind+1;
        pf(next,res,c,t,sum+c[ind],temp);
        temp.pop_back();

        while (next < c.size() &&
               c[next] == c[ind]) {
            next++;
        }

        pf(next,res,c,t,sum,temp);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(c.begin(), c.end());

        pf(0,res,c,t,0,temp);

        return res;
    }
};