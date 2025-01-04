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
* 大致思路是：我要记录这个要删除节点的具体位置的前一个位置（链表的长度-n）,然后是删除操作，p->next = p->next->next;
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        
        // 先计算长度
        ListNode* p = head;
        while(p){
            p = p->next;
            len++;
        }
        if(len == 1){
            return nullptr;
        }

        int index = len - n - 1;
        p = head;

        // 删链表首节点
        if(index < 0){
            return head->next;
        }

        // 删其他位置的节点
        while(index){
            p = p->next;
            index--;
        }
        p->next = p->next->next;

        return head;
    }
};