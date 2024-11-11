//https://neetcode.io/problems/invert-a-binary-tree

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Use postorder traversal with a swap function
class Solution {
public:
    TreeNode* SwapPostorder(TreeNode* node)
    {
        if (node == nullptr)
            return node;

        //First recursion on the left subtree
        SwapPostorder(node->left);

        //Then recursion on the right subtree
        SwapPostorder(node->right);

        //If both right and left aren't nullptr
        if (node->right != nullptr || node->left != nullptr)
        {
            TreeNode* tempNode = node->right;

            node->right = node->left;
            node->left = tempNode;
        }
    }

    //Initial function to invertTree
    TreeNode* invertTree(TreeNode* root)
    {
        //Handles no root
        if (root == nullptr)
            return nullptr;

        //Handles single node tree
        if (root->left == nullptr && root->right == nullptr)
            return root;

        return SwapPostorder(root);
    }
};
