class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            if(mp.find(temp[i]) != mp.end()) continue;
            mp[temp[i]] = cnt++;
        }
        for(int i =0; i < n; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};

// 0 -30 -20 -10
