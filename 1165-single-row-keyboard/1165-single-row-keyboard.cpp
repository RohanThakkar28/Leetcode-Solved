class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char,int>pos;
        int i=0;
        for(auto ch:keyboard){
            pos[ch]=i;
            i++;
        }
        char curr=keyboard[0];
        int ans=0;
        for(auto ch:word){
            ans+=abs(pos[curr]-pos[ch]);
            curr=ch;
        }
        return ans;
    }
};