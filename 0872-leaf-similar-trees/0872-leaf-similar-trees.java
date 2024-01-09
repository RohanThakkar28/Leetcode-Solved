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
import java.util.ArrayList;
import java.util.List;
class Solution {
    void sol(TreeNode root,List<Integer>a){
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            a.add(root.val);
            return;
        }
        sol(root.left,a);
        sol(root.right,a);
    }
    static <T> boolean areListsEqual(List<T> list1, List<T> list2) {
        // Check for null references and size differences
        if (list1 == null || list2 == null || list1.size() != list2.size()) {
            return false;
        }

        // Compare elements one by one
        for (int i = 0; i < list1.size(); i++) {
            if (!list1.get(i).equals(list2.get(i))) {
                return false;
            }
        }

        // If all elements are equal, the lists are considered equal
        return true;
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer>a=new ArrayList<>();
        List<Integer>b=new ArrayList<>();
        sol(root1,a);
        sol(root2,b);
        return areListsEqual(a,b);

        
    }
}