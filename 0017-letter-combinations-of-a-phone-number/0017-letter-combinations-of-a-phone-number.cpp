class Solution {
public:
    vector<string>finall;
    string arr[10];
    void solve(string digits,int i,string curr){
        if(curr.size()==digits.size()){
            finall.push_back(curr);
            return;
        }
        string temp=arr[digits[i]-'0'];
        for(int j=0;j<temp.size();j++){
            solve(digits,i+1,curr+temp[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        int count=0;
        //string arr[10];
        for(int i=2;i<=9;i++){
            string temp;
            if(i!=7 && i!=9){
                for(int j=0;j<=2;j++){
                    char t='a'+count;
                    temp.push_back(t);
                    count++;
                }
            }
            else{
                for(int j=0;j<=3;j++){
                    char t='a'+count;
                    temp.push_back(t);
                    count++;
                }
                
            }
            
            arr[i]=temp;
        }
        /*for(int i=2;i<=9;i++){
            cout<<arr[i]<<endl;
        }*/
        int n=digits.size();
        string curr="";
        if(n==0){
            return finall;
        }
        solve(digits,0,curr);
        return finall;
    }
};