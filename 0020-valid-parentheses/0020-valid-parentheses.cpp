class Solution {
public:

map<char, char> closingBracket = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};

bool isValid(string s) {
        stack<char> parenthesis;

        for(char c : s) {
            if(parenthesis.empty()) {
                if(closingBracket.count(c)) {
                    return false;
                }
                parenthesis.push(c);
                continue;
            }

            if(closingBracket.count(c)) {
                if(parenthesis.top() == closingBracket[c]) {
                    parenthesis.pop();
                }
                else {
                    return false;
                }
            }
            else {
                parenthesis.push(c);
            }
        }

        return parenthesis.empty();
    }
};