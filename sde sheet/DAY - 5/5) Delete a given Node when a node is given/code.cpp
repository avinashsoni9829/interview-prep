/*  Delete A given Node  */ 
time :  O(1)  
space : O(1)


1.

class Solution {
public:
    void deleteNode(ListNode* node) {
        
         node->val  = node->next->val;
        node->next= node->next->next;
        
        
    }
};

 

2.

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        *node = *(node->next);
        
    }
};
