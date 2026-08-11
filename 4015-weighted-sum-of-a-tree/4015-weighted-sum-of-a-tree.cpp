class Solution {
public:
    long long ans = 0;
    int h=0;

    int findHeight(int node,vector<vector<int>>& adj){
        int maxH =0;
        for(int child : adj[node]){
            maxH = max(maxH,findHeight(child,adj));
        }
        return maxH +1;
    }

    void dfs(int node, int depth, vector<vector<int>>& adj, vector<int>& nums) {

        ans += (long long)nums[node] *(h- depth+1);

        for (int child : adj[node]) {
            dfs(child, depth + 1, adj, nums);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
            } else {
                adj[parent[i]].push_back(i);
            }
        }

        h = findHeight(root,adj);

        dfs(root, 1, adj, nums);

        return ans;
    }
};