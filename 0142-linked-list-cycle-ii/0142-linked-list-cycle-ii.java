/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
       // ListNode* ans=NULL;
        Set<ListNode>vis=new HashSet<ListNode>();
        while(head!=null){
            if(vis.contains(head)){
                return head;
            }
            vis.add(head);
            head=head.next;
        }
        return null;
        
    }
}