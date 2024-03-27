#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Função para verificar se duas árvores são iguais
bool igual(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return (a->val == b->val) && igual(a->left, b->left) && igual(a->right, b->right);
}

TreeNode* criarNo(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root1 = criarNo(1);
    root1->left = criarNo(2);
    root1->right = criarNo(3);

    TreeNode* root2 = criarNo(1);
    root2->left = criarNo(2);
    root2->right = criarNo(3);
    //root2->left = criarNo(4);

    if (igual(root1, root2))
        std::cout << "As árvores são iguais." << std::endl;
    else
        std::cout << "As árvores são diferentes." << std::endl;

    delete root1;
    delete root2;

    return 0;
}
