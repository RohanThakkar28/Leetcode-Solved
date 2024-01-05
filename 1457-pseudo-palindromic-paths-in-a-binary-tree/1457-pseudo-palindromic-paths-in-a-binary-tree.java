/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static boolean isPowerOfTwo(int number) {
        // Check if the number is positive and has only one set bit (1) in its binary representation
        return (number > 0) && ((number & (number - 1)) == 0);
    }
    public int sol(TreeNode root,int mask){
        if(root==null){
            
            return 0;
        }
        int ans=0;
        mask^=(1<<(root.val-1));
        if(root.left==null && root.right==null){
            if(mask==0 || isPowerOfTwo(mask)){
                return 1;
            }
            return 0;
        }
        ans+=sol(root.left,mask)+sol(root.right,mask);
        return ans;
    }
    public int pseudoPalindromicPaths (TreeNode root) {        
        int ans=sol(root,0);
        
        return ans;
    }
}