class Solution {
    public boolean isPathCrossing(String path) {
        Set<String>s=new HashSet<>();
        s.add("0 0");
        int x=0;
        int y=0;
        
        for(int i=0;i<path.length();i++){
            if(path.charAt(i)=='N'){
                y--;
            }
            else if(path.charAt(i)=='S'){
                y++;
            }
            else if(path.charAt(i)=='W'){
                x--;
            }
            else{
                x++;
            }
            String s1=Integer.toString(x)+" "+Integer.toString(y);
            if(s.contains(s1)){
                return true;
            }
            s.add(s1);
            
        }
        return false;
    
        
    
        
        
    }
}