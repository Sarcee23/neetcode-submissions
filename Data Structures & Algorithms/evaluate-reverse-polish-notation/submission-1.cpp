class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        for(const string& c :tokens){
                if(c == "+"){
                    int b = stack.top(); stack.pop();
                    int a = stack.top(); stack.pop();
                    stack.push(a+b);
                }
                else if(c == "-"){
                    int b = stack.top(); stack.pop();
                    int a = stack.top(); stack.pop();
                    stack.push(a-b);
                }

                else if(c == "*"){
                    int b = stack.top(); stack.pop();
                    int a = stack.top(); stack.pop();
                    stack.push(a*b);
                }

                else if(c == "/"){
                    int b = stack.top(); stack.pop();
                    int a = stack.top(); stack.pop();
                    stack.push(static_cast<int>(static_cast<double>(a)/b));
                }
                else{
                    stack.push(stoi(c));
                }
        }
        return stack.top();
    }

};
