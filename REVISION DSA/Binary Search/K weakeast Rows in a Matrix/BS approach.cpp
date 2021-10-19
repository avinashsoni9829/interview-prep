class Solution {
public:
    
    int bs(vector<int>a,int n)
    {
          int low=0;
          int ans=n;
          int high=n-1;
          
          while(low<=high)
          {
                 int mid = low + (high-low)/2;
              
                 if(a[mid]==0)
                 {
                       ans=mid;
                       high=mid-1;
                 }
                 else
                 {
                        low=mid+1;
                 }
          }
        
        return ans;
    }
    
    
    struct node
    {
        int ones;
        int idx;
    };
    
 static bool  comp(const node &a , const node &b)
    {
           if(a.ones==b.ones)
           {
                return a.idx<b.idx;
           }
           
        return a.ones<b.ones;
    }
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {\
        
        int n=mat.size();
        node ans[n];
        for(int i=0;i<n;++i)
         {
             int x=mat[i].size();
            
              int one=bs(mat[i],x);
              ans[i].ones=one;
              ans[i].idx=(i);
         }
         sort(ans,ans+n,comp);
         vector<int>res;
         for(int i=0;i<k;++i)
            res.push_back(ans[i].idx);
                                                               
             return res;
                                                               
                                                               
                                                               
                                                               
                                                               
        
                                                               
                                                               
                                                                
        
        
    }
};