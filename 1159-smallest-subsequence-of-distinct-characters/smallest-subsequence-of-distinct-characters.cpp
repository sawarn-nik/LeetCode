class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        vector<int> last(26);
        vector<int> vis(26,0);
        for(int i = 0; i < s.size(); i++){
            last[s[i]-'a'] = i;
        }   
        for(int i = 0; i < s.size(); i++){      
            char ch = s[i];
            if(vis[ch-'a']) continue;

            while(!res.empty() && res.back() > ch && last[res.back()-'a'] > i){
                vis[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(ch);
            vis[ch-'a'] = 1;
        }   

        return res;
    }
};