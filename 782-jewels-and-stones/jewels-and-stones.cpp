class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(char c:jewels){
            mp[c]++;
        }
        int res = 0;
        for(char c:stones){
            if(mp.find(c) != mp.end())
            res++;
        }
        return res;
    }
};