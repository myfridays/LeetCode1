 /**
 * 第一种方法
 * 思路： 两个指针，一个用来找要插入的位置，一个用来找要插入的元素
 * 复杂度： O(M*N)
 **/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0; // 该指针指向nums1数组插入的位置
        int p2 = 0; // nums1数组要插入的元素，nums2的元素
        if (n == 0) // 如果n没有元素，则合并结束
        {
            return;
        }

        while (p2 < n) { // 要插入的元素个数，插完就结束
            while (nums2[p2] > nums1[p1] && p1 < m) {
                // 去寻找要插入元素的位置
                p1++;
            }
            for (int i = m; i > p1; i--) {
                // 对要插入的位置后移动一个位置
                nums1[i] = nums1[i - 1];
            }
            nums1[p1] = nums2[p2]; // 插入元素
            m++;                   // 更新nums1数组长度
            p2++;                  // 更新插入的元素
        }
        return;
    }
};
