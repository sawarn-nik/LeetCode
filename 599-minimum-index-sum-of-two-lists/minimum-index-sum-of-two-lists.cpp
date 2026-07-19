class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<pair<string,int>> t;
        stack<string> st;
        vector<string> ans;
        int m = INT_MAX;
        for(int i = 0; i < list1.size(); i++){
            t.push_back({list1[i],i});
        }
        for(int i = 0; i < list2.size(); i++){
            t.push_back({list2[i],i});
        }
        sort(t.begin(),t.end());
        for(int i = 1; i < t.size(); i++){
            if(t[i].first == t[i-1].first && t[i].second + t[i-1].second <= m){
                if(t[i].second + t[i-1].second < m){
                    while(!st.empty()){
                        st.pop();
                    }
                }
                st.push(t[i].first);
                m = t[i].second + t[i-1].second;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};