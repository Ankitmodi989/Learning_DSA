class Solution {
public:
    vector<int> getNSR(vector<int>& heights, int n) {
        vector<int> right(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }
    vector<int> getNSL(vector<int>& heights, int n) {
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSR = getNSR(heights, n);
        vector<int> NSL = getNSL(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++) {
            int total = (NSR[i] - NSL[i]-1) * heights[i];
            area = max(area, total);
        }
        return area;
    }
};