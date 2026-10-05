
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<pair<int, string>> symbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"}, {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
        };

        for (auto& [val, sym] : symbols) {
            while(num >= val) {
                res.append(sym);
                num -= val;
            }
        }

        return res;
    }
};