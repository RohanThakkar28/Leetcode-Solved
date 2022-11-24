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
    ListNode* swapPairs(ListNode* head) {
        vector<int>a;
        while(head!=NULL){
            if(head->next==NULL){
                a.push_back(head->val);
                break;
            }
            else{
                a.push_back(head->next->val);
                
                a.push_back(head->val);
                head=head->next->next;
            }
        }
        ListNode* h=new ListNode(0);
        ListNode* ans=h;
        int i=0;
        while(i<a.size()){
            ListNode* tmp=new ListNode(a[i]);
            h->next=tmp;
            h=h->next;
            i++;
            
        }
        if(ans->next){
            return ans->next;
        }
        return NULL;
        
        
        
    }
};