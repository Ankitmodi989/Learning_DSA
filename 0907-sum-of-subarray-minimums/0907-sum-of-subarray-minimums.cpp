class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> right(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

     vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSR = getNSR(arr, n);
        vector<int> NSL = getNSL(arr, n);

        long long sum = 0;

            for (int i = 0; i < n; i++) {
            long long l = i - NSL[i];
            long long r = NSR[i] - i;
            long long total = l * r;

            long long totalsum = arr[i] * total;

            sum = (sum + totalsum) % mod;
        }
        return sum;
    }
};