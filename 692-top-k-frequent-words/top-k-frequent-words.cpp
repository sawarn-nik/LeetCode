class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int> mp;
        for(auto word : words){
            mp[word]++;
        }
        vector<pair<int,string>> temp;
        for(auto it : mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(), temp.end(), [](pair<int,string> &a, pair<int,string> &b){
            if(a.first != b.first)
                return a.first > b.first;      // higher frequency first
            return a.second < b.second;        // lexicographically smaller first
        });
        for(int i = 0; i < k; i++){
            res.push_back(temp[i].second);
        }
        return res;
    }
};