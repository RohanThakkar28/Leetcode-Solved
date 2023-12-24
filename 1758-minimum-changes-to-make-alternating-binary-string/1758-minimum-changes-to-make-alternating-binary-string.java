class Solution {
    public int minOperations(String s) {
        
        int a1=0;
        int a2=0;
        int e1=0;
        int e2=1;
        for(int i=0;i<s.length();i++){
           // int a=Character.getNumericValue(s.charAt(i));
            int a=(int)s.charAt(i)-48;
            System.out.println(a);
            if(a!=e1){
                a1++;
            }
            if(a!=e2){
                a2++;
            }
            e1=1-e1;
            e2=1-e2;
        }
        return Math.min(a1,a2);
        
    }
}