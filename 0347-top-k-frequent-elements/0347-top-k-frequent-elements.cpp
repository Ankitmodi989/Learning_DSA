class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto& ele : mp) {
            pq.push({ele.second, ele.first});
        }
        while (pq.size() > k) {
            pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};