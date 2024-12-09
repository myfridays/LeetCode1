/*
*往大的开始比较，然后一直减
*/
class Solution {
    std::vector<int> Int = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::unordered_map<int, string> roman = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                             {400, "CD"}, {100, "C"}, {90, "XC"},
                                             {50, "L"}, {40, "XL"}, {10, "X"},
                                             {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
public:
    string intToRoman(int num) {
        string str = "";
        int i = 0, n = Int.size();
        while(i < n ){
            while(num >= Int[i]){
                num -= Int[i];
                str += roman[Int[i]];
            }
            i++;
        }
        return str;
    }
};