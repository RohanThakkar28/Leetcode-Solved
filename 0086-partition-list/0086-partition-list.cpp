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
    ListNode* partition(ListNode* head, int x) {
        ListNode * h=new ListNode(0);
        ListNode* ans=h;
        ListNode* n=new ListNode(0);
        ListNode* tn=n;
        ListNode* temp=head;
        while(head!=NULL){
            
            if(head->val<x){
                ListNode* ttt=new ListNode(head->val);
                ttt->next=NULL;
                h->next=ttt;
                
                h=h->next;
             //   cout<<h->val<<endl;
                
            }
            else{
                ListNode* ttt=new ListNode(head->val);
                ttt->next=NULL;
                n->next=ttt;
                n=n->next;
            }
            head=head->next;
        }
        h->next=tn->next;
       
        
        
        return ans->next;
        
        
    }
};