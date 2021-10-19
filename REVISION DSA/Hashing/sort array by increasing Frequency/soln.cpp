class Solution {
    
  static const   bool comp(pair<int,int>&a ,pair<int,int>&b)
    {
           if(a.second == b.second)
           {
             return a.first >  b.first;
           }
        return a.second < b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int,int>mp;
        for(auto z:nums) mp[z]++;
        
        vector<pair<int,int>>p;
        
        for(auto z:mp)
        {
           pair<int,int>p1 ;
            p1.first = z.first;
            p1.second = z.second;
            
            p.push_back(p1);
        }

        sort(p.begin(),p.end(),comp);
        
        vector<int>ans;
        
        for(auto z:p)
        {
            int x = z.second;
            while(x--)
         ans.push_back(z.first); 
        }
        
        return ans;
        
        
    }
};
