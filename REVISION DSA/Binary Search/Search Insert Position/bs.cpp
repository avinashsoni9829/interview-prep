class Solution {
public:
    
    #define deb(...) debug(#__VA_ARGS__, __VA_ARGS__);
template <typename T>
void debug(string s, T x)
{
   cout << s << " = " << x << "\n";
   cout<<"----------------------------------------------"<<endl;
}
template <typename T, typename... Args>
void debug(string s, T x, Args... args)
{
   cout << s.substr(0, s.find(',')) << " = " << x<<endl;
   
   debug(s.substr(s.find(',') + 1), args...);
   
}
    
    
    
    
    
    int bs(vector<int>a,int n,int target){
        
        int low = 0 , high = n - 1;
       
        while(low<=high){
         
            int mid = (low + high) / 2 ;
            
            if(a[mid] == target){
                return mid;
            }
            else
            if(a[mid]>target){
                // search in left half     ---------- target      mid
                high = mid - 1;
            }
            else
            {
                 low = mid + 1;
            }
            
        
        }
        
        return -1;
    }
    
    int closestToRight(vector<int>a,int n,int target){ 
        
        if(a[0]>target){
            return 0;
        }
        else
            if(a[n-1]<target){
                return n;
            }
    
      int low = 0 ;
      int high = n - 1;
        
      int ans = 0;
        
        while(low<=high){

          int mid = (low + high) / 2;
          
          if(a[mid]>target){
              
              ans = mid;
              high = mid-1;
              
          }
          else
          {
              low = mid + 1;
          }
            
        }
        
        return ans;
        

    
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        int idx = bs(nums,n,target);
        
        if(idx!=-1){
         return idx;
         }
         else
         {
             int idx2 =  closestToRight(nums,n,target);
             return idx2;    
         }

        
    return -1;
        
        
    }
};