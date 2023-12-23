class Solution {
    public boolean isPathCrossing(String path) {
        int x=0;
        int y=0;
        Set<Pair<Integer,Integer>>s=new HashSet<>();
        s.add(new Pair(0,0));
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
            if(s.contains(new Pair(x,y))){
                return true;
            }
            s.add(new Pair(x,y));
        }
        return false;
    
        
    
        
        
    }
}