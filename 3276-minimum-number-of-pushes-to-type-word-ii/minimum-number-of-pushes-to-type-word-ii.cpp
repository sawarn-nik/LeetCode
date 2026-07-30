class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        vector<pair<int,char>> temp;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                temp.push_back({freq[i],i+'a'});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,char>>());
        int res = 0;
        int p = 0;
        int mul = 1;
        for(int i = 0; i < temp.size(); i++){
            res += (temp[i].first * mul);
            p++;
            if(p == 8){
                mul++;
                p = 0;
            }
        }
        return res;
    }
};