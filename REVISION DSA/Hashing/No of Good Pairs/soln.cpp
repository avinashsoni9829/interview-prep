class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(auto z:nums) mp[z]++;
        int ans = 0 ;
        
        for(auto k : mp)
        {
           ans = ans + (k.second) * (k.second - 1) / 2;
            
        }
        
        return ans;
        
        
    }
};
