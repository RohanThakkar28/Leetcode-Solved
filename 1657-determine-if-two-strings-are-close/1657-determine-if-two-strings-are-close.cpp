class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
            
        }
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(auto ch:word1){
            a[ch-'a']++;
        }
        for(auto ch:word2){
            b[ch-'a']++;
        }
        bool ye=true;
        for(int i=0;i<26;i++){
            if(a[i]>0 && b[i]==0){
                return false;
            }
            if(a[i]==0 && b[i]>0){
                return false;
            }
        }
        for(int i=0;i<26;i++){
            bool a1=false;
            for(int j=i;j<26;j++){
                if(a[i]==b[j]){
                    b[j]=b[i];
                    a1=true;
                    break;
                }
            }
            if(!a1){
                ye=false;
                break;
            }
        }
        return ye;
    }
};
/*
a=1
b=3
c=2

a=1;
b=2;
c=3;



*/