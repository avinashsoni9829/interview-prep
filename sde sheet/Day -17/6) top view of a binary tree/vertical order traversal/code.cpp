/* vertical order traversal */



bool sortcol( const vector<int>& v1, const vector<int>& v2 ) 
{
    if(v1[0]==v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}
class Solution {
public:
    map<int,vector<vector<int>>> m;
    void dfs(TreeNode* root,int x,int y)
    {
        if(!root) return;
        m[x].push_back({y,root->val});
        dfs(root->left,x-1,y+1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        dfs(root,0,0);
        vector<vector<int>> ans;
        for(auto i:m)
        {
            vector<int> temp;
            sort(i.second.begin(),i.second.end(),sortcol);
            for(int j=0;j<i.second.size();j++) temp.push_back(i.second[j][1]);
            if(temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};
