class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int minLength = strs[0].length();

        for (auto& s : strs)
        {
            minLength = min(minLength, (int)s.length());
        }
        
        for (int i = 0; i < minLength; i++)
        {
            char current = strs[0][i];
            for (size_t j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != current) {
                    return strs[j].substr(0,i);
                }
            }
        }
        
        result = strs[0].substr(0,minLength);

        return result;
    }
};