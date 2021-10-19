// for brute use set and put set values in front and return the set size 

/*  

 time :  O(n)
 space : O(1)

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0) return 0 ;
        
        int curr = 0 ;
        
        for(int i = 1 ; i <  n ; ++i)
        {
             if(nums[i]!=nums[curr])
             {
                   curr = curr + 1;
                   nums[curr] = nums[i];
                 
             }
             
        }
        
        return curr + 1;
        
        
        
    }
};
