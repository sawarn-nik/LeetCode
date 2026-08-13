class Solution {
public:
    struct Node {
        int pref, suff, best, len;
        char leftChar, rightChar;
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            seg[idx] = {1,1,1,1,s[l],s[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(idx*2,l,mid,s);
        build(idx*2+1,mid+1,r,s);

        seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
    }

    void update(int idx,int l,int r,int pos,char ch){
        if(l==r){
            seg[idx]={1,1,1,1,ch,ch};
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid)
            update(idx*2,l,mid,pos,ch);
        else
            update(idx*2+1,mid+1,r,pos,ch);

        seg[idx]=merge(seg[idx*2],seg[idx*2+1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        int n=s.size();

        seg.resize(4*n+5);

        build(1,0,n-1,s);

        vector<int> ans;

        for(int i=0;i<queryIndices.size();i++){

            update(1,0,n-1,queryIndices[i],queryCharacters[i]);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};