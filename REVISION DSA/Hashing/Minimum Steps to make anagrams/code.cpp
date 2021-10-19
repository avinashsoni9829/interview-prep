class Solution {
public:
    int minSteps(string s, string t) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);
        int arr[26]={0};
        
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                count+=arr[i];
            }
        }
        
        return count;
        
    }
};
