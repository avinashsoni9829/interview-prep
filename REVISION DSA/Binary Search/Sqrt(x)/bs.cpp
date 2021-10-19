class Solution {
public:
    #define ll long long int 
    int mySqrt(int x) {
        
        // find largest mid * mid <=x
        
        ll low = 0 , high = x;
        
        ll ans = -1;
        
        while(low<=high){
            
              ll mid  = (low + high)/2;
            
              if( mid * mid <=x){
                     ans = mid;
                     low = mid + 1;
                 }
                else{
                     high = mid - 1;
                }
        }
        
        return ans;
        
        
    }
};