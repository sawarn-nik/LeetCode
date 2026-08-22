class Solution {
public:
    bool isP(string s,int i, int j){
        for(; i <= j; i++,j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    void solve(int ind,vector<vector<string>> &res,string str,vector<string> &temp){
        if(ind == str.size()){
            res.push_back(temp);
        }
        for(int i = ind; i < str.size(); i++){
            if(isP(str,ind,i)){
                temp.push_back(str.substr(ind,i-ind+1));
                solve(i+1,res,str,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(0,res,s,temp);
        return res;
    }
};