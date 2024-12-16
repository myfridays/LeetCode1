/* 法一 哈希表
*哈希表来判断这个数是否重新出现过，取个位数
*时间复杂度：O(N), 空间复杂度：O(N)
*/
class Solution {
public:
    bool isHappy(int n) {
        int m = n;
        unordered_map<int, int> mp;
        while(true){
            int x = 0;
            while(m != 0){
                int i = m % 10;
                m = m / 10;
                x += i*i;
            }
            
            if(x == 1){
                return true;
            }
            if(mp.count(x)){
                return false;
            }
            mp[x] = 1;
            m = x;
        }
        return false; 
    }
};

/* 法二 快慢指针
*“快指针” 每次走两步，“慢指针” 每次走一步，当二者相等时，即为一个循环周期
*时间复杂度：O(N), 空间复杂度：O(1)
*/
class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};

