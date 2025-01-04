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
* 一个哑节点去删除重复元素的第一个元素，然后使用变量去一个一个比较删除
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                int x = cur->next->val;
                while(cur->next && x == cur->next->val){
                    cur->next = cur->next->next;
                }
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};