/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 time : O(n log k)
 space : O(n + k)
 
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty() or lists.size() == 0){
             return NULL;
        }
        
        auto comp = [&] (ListNode *a ,ListNode*b){
              return a -> val > b -> val;
        };
        
        
        priority_queue<ListNode * , vector<ListNode*>,decltype(comp)>pq(comp);
        
        
        for(int i = 0 ; i < lists.size() ; ++i){
            
            if(lists[i]){
                  pq.push(lists[i]);
            }
             
        }
        
        ListNode dummy(0);
        ListNode * tail = &dummy;
        
        while(!pq.empty()){
              
            auto temp = pq.top();
            pq.pop();
            
            tail -> next = temp;
            
            tail = tail -> next;
            
            if(temp -> next){
                   pq.push(temp -> next);
            }
        }
        
        tail -> next = NULL;
        
        return dummy.next;
        
        
    }
};
