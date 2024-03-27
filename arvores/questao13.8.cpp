#include <iostream>

struct TreeNode {
    char op;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c, int v) : op(c), val(v), left(NULL), right(NULL) {}
};

int valor(TreeNode* root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL) 
        return root->val;
    
    int esquerda = valor(root->left);
    int direita = valor(root->right);

    switch (root->op) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            return esquerda / direita;
        default:
            std::cerr << "Operador inválido: " << root->op << std::endl;
            return 0;
    }
}

int main() {
    TreeNode* root = new TreeNode('*', 0);
    root->left = new TreeNode('/', 0);
    root->left->left = new TreeNode('+', 0);
    root->left->left->left = new TreeNode('5', 5);
    root->left->left->right = new TreeNode('3', 3);
    root->left->right = new TreeNode('4', 4);
    root->right = new TreeNode('-', 0);
    root->right->left = new TreeNode('6', 6);
    root->right->right = new TreeNode('1', 1);

    std::cout << "O valor da expressão é: " << valor(root) << std::endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
