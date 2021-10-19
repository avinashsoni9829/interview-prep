/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 
 time : O(n)
 
 space : O(1)
 
 
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL or k == 1) return head;
        
        ListNode * dummy = new ListNode(0);
        
        dummy -> next = head;
        
        ListNode * curr = dummy;
         
        ListNode * nex = dummy;
        
        ListNode * pre  = dummy;
        
        
        int len = 0 ;
        
        while(curr -> next!=NULL){
            curr = curr -> next;
            len = len + 1;
        }
        
        while(len>=k){
            
             curr = pre -> next;
             nex = curr -> next;
            // for  k  reversal k-1 links are there 
            for(int i = 1 ; i < k ; ++i){
                
                 curr -> next = nex-> next;
                 nex -> next = pre -> next;
                 pre-> next = nex;
                 nex = curr -> next ;
                   
             }
            
             pre = curr;
             len = len - k;
            
            
            
             
        }
        
        return dummy -> next;
        
        
    }
};
