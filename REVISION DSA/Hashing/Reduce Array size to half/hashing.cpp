class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        ios_base::sync_with_stdio(false);
 	    cin.tie(NULL);
        
        int n  = arr.size();
        
        unordered_map<int,int>mp;
        for(auto z:arr){
            mp[z]++;
        }
        
        vector<int>freq;
        
        for(auto z:mp){
            freq.push_back(z.second);
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int req = 0;
        
        int ans = 0 ;
        int  i= 0 ;
        while(!(req>=n/2)){
            
            req  = req + freq[i];
            i = i + 1;
            ans = ans + 1;
            
        }
        
        return ans;
        
    }
};
