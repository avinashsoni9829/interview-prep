class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        
        int n = a.size();
        
        map<int,int>first_loc,last_loc;
        
        for(int i = 0 ; i < n ; ++i){
             if(first_loc.find(a[i]) == first_loc.end())
             {  
               first_loc[a[i]] = i ; 
             }
             
        }
        
        for(int i = n - 1 ; i>=0 ; i--){
          if(last_loc.find(a[i]) == last_loc.end()){
                last_loc[a[i]] = i ;
          }     
        }
        
        int degree = 0 ;
        
        map<int,int>mp;
        
        for(auto z: a) mp[z] ++ ;
        
        for(auto k : mp){
             degree = max(degree , k .second);
            
        }
        
        int mn = INT_MAX;
        
        for(auto z:mp){
             if(z.second == degree){
                   int len = abs(last_loc[z.first] - first_loc[z.first] + 1);
                   mn = min (mn ,len);
             }
        }
        
        return mn;
        
        
    }
};
