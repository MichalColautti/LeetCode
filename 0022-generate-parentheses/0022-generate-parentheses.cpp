class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        add_parenthesis("",0,0,n,result);

        return result;
    } 

    void add_parenthesis(string current, int opened, int closed, int n, vector<string>& result) {
        if(n * 2 == (int) current.size()) {
            result.push_back(current);
            return;
        }

        if(n > opened ) {
            add_parenthesis(current + '(', opened+1, closed, n, result);
        }
        
        if(opened > closed) {
            add_parenthesis(current + ')', opened, closed + 1, n, result);
        }
    }
};