/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 * 计算长度 n, 搞成环状，然后去环
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* iter = head; 
        int n = 1; // 计算长度
        while(iter->next){
            iter = iter->next;
            n++;
        }

       
        int add = n - k % n;
        if(add == n){
            return head;
        }
        iter->next = head;
        // 选定头节点
        while(add--){
            iter = iter->next;
        }
        // 去环
        ListNode* ret = iter->next;
       
        iter->next = nullptr;

        return ret;

    }
};