class Solution {
public:
    vector<string> ans;
    void gen(int o,int c,int n,string &cur){
        if(cur.size() == 2*n){
            ans.push_back(cur);
            return;
        }
        if(o < n){
            cur.push_back('(');
            gen(o+1,c,n,cur);
            cur.pop_back();
        }
        if(c < o && c < n){
            cur.push_back(')');
            gen(o,c+1,n,cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        gen(0,0,n,cur);
        return ans;
    }
};