class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
          vector<int>ans;
          
          stack<int>s;
          
          int L[n+1], R[n+1];
          
          for(int  i = 0 ; i  < n ; ++i){
               L[i] = -1;
               R[i] = n;
          }
          
          
          // finding next greater element
          
          for(int i = 0  ; i < n ; ++i){
                while(!s.empty() and arr[s.top()] >= arr[i]){
                      s.pop();
                      
                }
                
                if(!s.empty()){
                     L[i] = s.top();
                }
                
                s.push(i);
          }
          
          
          while(!s.empty()){
               s.pop();
          }
          
          // filling elements in right
          
          for(int i = n - 1 ; i  >= 0 ; i -- ){
               while(!s.empty() and arr[s.top()] >= arr[i]){
                    s.pop();
               }
               
               if(!s.empty()){
                    R[i] = s.top();
               }
               
               s.push(i);
               
              
          }
          
          int anss[n+1];
          for(int i =  0 ; i <=  n ; ++i) anss[i] = 0; 
          
          for(int i = 0 ; i < n ; ++i){
                int len = R[i] - L[i] - 1;
                
                anss[len] = max(anss[len] , arr[i]);
          }
          
          for(int  i =  n -  1; i >= 1; i--){
               anss[i] = max(anss[i] , anss[i+1]);
          }
          
          
          for(int i = 1 ; i<= n ; ++i){
                ans.push_back(anss[i]);
          }
          
          return ans;
          
          
         
    }
};
