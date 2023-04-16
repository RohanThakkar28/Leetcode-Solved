class Solution {
public:
    int addMinimum(string word) {
        int i=0;
        int n=word.size();
        int ans=0;
        while(i<n){
            if(word[i]=='a'){
                i++;
                if(i<n){
                    if(word[i]=='b'){
                        i++;
                        if(word[i]!='c'){
                            ans++;
                            
                            
                        }
                        else{
                            i++;
                        }
                    }
                    else if(word[i]=='c'){
                        i++;
                        ans+=1;
                    }
                    else{
                        ans+=2;
                    }
                    
                    
                }
                else{
                    ans+=2;
                }
                
            }
            else{
                if(word[i]=='b'){
                    i++;
                    ans++;
                    if(i==n){
                        ans++;
                        break;
                    }
                    if(word[i]=='c'){
                        i++;
                        //ans+=1
                    }
                    else{
                        ans+=1;
                    }
                    
                    
                }
                else{
                    ans+=2;
                    i++;
                }
                
            }
        }
        return ans;
        
    }
};