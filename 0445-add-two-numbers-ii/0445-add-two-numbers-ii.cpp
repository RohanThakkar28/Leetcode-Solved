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
    ListNode* reverse(ListNode* l){
        ListNode* head=l;
        ListNode* prev=NULL;
        ListNode* nxt;
        while(head!=NULL){
            nxt=head->next;
            head->next=prev;
            prev=head;
            head=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* ans=new ListNode();
        int sum=0;
        int carry=0;
        while(l1 || l2){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=0;
            cout<<sum<<endl;
            //ListNode* tmp=new ListNode(sum%10);
            ans->val=sum%10;
            carry=sum/10;
            ListNode* head=new ListNode(carry);
            head->next=ans;
            ans=head;
            sum=0;

        
        }
        if(carry==0){
            return ans->next;
        }
        return ans;
        
        
        
    }
};