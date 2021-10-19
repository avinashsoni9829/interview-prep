#pragma GCC optimize("Os")
#pragma GCC target("avx,avx2,fma")
bool _=[]{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();

class Solution {
public:
    int minSetSize(vector<int>& arr) {
       
          sort(arr.begin(),arr.end()); // sort the array to find the frequency of every element
        priority_queue<int> q;
        int cnt = 1,sum = 0,ans = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1])
                cnt++;
            else{
                q.push(cnt); // push the entry into the priority queue
                cnt = 1;
            }
        }
        q.push(cnt);
        while(sum<arr.size()/2){
            sum+=q.top();
            ans++;
            q.pop();
        }
        return ans;
        
        
    }
};
