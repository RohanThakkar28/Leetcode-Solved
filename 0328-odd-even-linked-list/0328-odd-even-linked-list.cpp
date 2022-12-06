/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* ans=new ListNode(0);
        ListNode* a=ans;
        ListNode* h=head;
        int i=0;
        
        while(h!=NULL){
            if(h!=NULL){
                if((i)%2==0){
                    ListNode* tmp=new ListNode(h->val);
                    ans->next=tmp;
                    ans=ans->next;
                    
                }
                i++;
                h=h->next;
            }
        }
        i=0;
        while(head!=NULL){
            if(head!=NULL){
                if((i)%2==1){
                    ListNode* tmp=new ListNode(head->val);
                    ans->next=tmp;
                    ans=ans->next;
                    
                }
                i++;
                head=head->next;
            }
        }
        return a->next;
        
        
    }
};