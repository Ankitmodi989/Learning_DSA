class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>temp;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                temp.push(s[i]);
            }else{
                if(temp.empty()){
                    count++;
                }else {
                    temp.pop();
                }
            }
        }
        return count+temp.size();
    }
};