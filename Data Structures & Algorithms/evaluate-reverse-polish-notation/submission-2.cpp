class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int result = 0;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b;

                stk.push(result);
            } else {
                stk.push(stoi(token));  // Convert number string to int
            }
        }

        return stk.top();  // Final result
    }
};
