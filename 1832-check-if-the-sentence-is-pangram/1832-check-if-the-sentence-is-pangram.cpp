class Solution {
public:
    bool checkIfPangram(string sen) {
        set<char>s;
        int n=sen.size();
        for(int i=0;i<n;i++){
            s.insert(sen[i]);
        }
        return s.size()==26;

        
    }
};