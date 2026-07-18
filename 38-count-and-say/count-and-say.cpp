class Solution {
private:
    vector<string> temp;
    string RLE(string s){
        string res = "";
        if(s.size() == 1){
            res += "1";
            res += s[0];
            return res;
        }
        int cnt = 1;
        string temp = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                res += to_string(cnt);
                res += s[i-1];
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res += s.back();
        return res;
    }
    void build(int n){
        temp.push_back("1");
        for(int i = 1; i < n; i++){
            temp.push_back(RLE(temp[i-1]));
        }
    }
public:
    string countAndSay(int n) {
        build(n);
        return temp[n-1];
    }
};