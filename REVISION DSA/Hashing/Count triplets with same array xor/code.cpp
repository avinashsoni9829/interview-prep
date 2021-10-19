class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        map<int,vector<int>>mp;
        // store the positions of xor values;
        
        int ans= 0 ;
        int xr = 0 ;
        
        mp[0].push_back(-1);
        
        int n=arr.size();
        
        for(int i = 0  ; i < n ; ++i){
              xr = xr ^ arr[i];
             
            if(mp.find(xr)!=mp.end()){
                
                for(auto  k : mp[xr]){
                     ans = ans + (i - k ) - 1;
                }
            }
            mp[xr].push_back(i);
             
        }
        
        return ans;
        
        
        
    }
};
