class Solution {
public:
    bool detectCapitalUse(string word) {
        set<char>s;
        set<char>c;
        char ch1='a';
        char ch2='A';
        for(int i=0;i<26;i++){
            s.insert(('a'+i));
            c.insert(('A'+i));
        }
        
        if(c.find(word[0])==c.end()){
            for(int i=1;i<word.size();i++){
                if(c.find(word[i])==c.end()){
                    
                }
                else{
                    return false;
                }
            }
            
            return true;
        }
        if(word.size()==1){
            return true;
        }
        if(c.find(word[1])==c.end()){
            for(int i=1;i<word.size();i++){
                if(c.find(word[i])==c.end()){
                    
                }
                else{
                    return false;
                }
            }
            return true;
        }
        else{
            for(int i=1;i<word.size();i++){
                if(s.find(word[i])==s.end()){
                    
                }
                else{
                    return false;
                }
            }
            return true;
        }
        
    }
};