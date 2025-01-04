/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
* 哈希表
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> node;
        Node* p = head;
        while(p){
            node.insert({p, new Node(p->val)});
            p = p->next;
        }
        p = head;
        while(p){
            node[p]->next = node[p->next];
            node[p]->random = node[p->random];
            p = p->next;
        }

        return node[head];
    }
};