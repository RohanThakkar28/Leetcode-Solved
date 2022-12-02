class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1=0;
        int c2=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            
            if((s[i]=='a') || (s[i]=='e') ||(s[i]=='i') ||(s[i]=='o') ||(s[i]=='u') || (s[i]=='A') || (s[i]=='E') ||(s[i]=='I') ||(s[i]=='O') ||(s[i]=='U')){
                c1++;
                
            }
        }
        for(int i=n/2;i<n;i++){
            if((s[i]=='a') || (s[i]=='e') ||(s[i]=='i') ||(s[i]=='o') ||(s[i]=='u') || (s[i]=='A') || (s[i]=='E') ||(s[i]=='I') ||(s[i]=='O') ||(s[i]=='U')){
                c2++;
                
            }
        }
        return c1==c2;
        
    }
};