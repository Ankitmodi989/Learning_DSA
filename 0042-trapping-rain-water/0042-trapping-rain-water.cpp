class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        stack<int>st;

        int sum =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int middle_index = st.top();
                st.pop();

                if(st.empty()) break;

                int left_index = st.top();

                int width = i - left_index -1;
                int bounded_height = min(height[left_index],height[i])-height[middle_index];

                sum += width* bounded_height;
            }
            st.push(i);
        }
        return sum;
    }
};