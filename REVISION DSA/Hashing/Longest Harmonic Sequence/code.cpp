class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(auto z:nums){
            mp[z]++;
        }
        sort(nums.begin(),nums.end());
        int mx = 0 ;
        auto n = nums.size();
       for(int  i = 0 ; i < n - 1 ; ++i){
           
           if(nums[i] == nums[i+1] - 1){
               mx = max(mp[nums[i]] + mp[nums[i] + 1] , mx);
           }
       }
        
        return mx;
        
        
        
        
        
    }
};
