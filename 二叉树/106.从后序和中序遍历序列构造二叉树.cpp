/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Trasval(vector<int>& inorder, vector<int>& postorder){
        // 第一步
        if(postorder.size() == 0) return nullptr;

        // 第二步：后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if(postorder.size() == 1) return root;

        // 第三步：找分割点
        int index;
        for(index = 0; index < inorder.size(); index++){
            if(inorder[index] == rootValue) break;
        }

        // 第四步：切割中序数组，得到 中序左数组和中序右数组
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());

        // 第五步：切割后序数组，得到 后序左数组和后序右数组
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());

        // 第六步
        root->left = Trasval(leftInorder, leftPostorder);
        root->right = Trasval(rightInorder, rightPostorder);

        return root;
        
        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return Trasval(inorder, postorder);
    }
};