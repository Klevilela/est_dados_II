#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Função auxiliar para realizar a travessia em ordem decrescente
void exibe_dec_aux(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    // Travessia na ordem direita, raiz e esquerda
    exibe_dec_aux(root->right);
    std::cout << root->val << " ";
    exibe_dec_aux(root->left);
}

// Função principal que exibe os itens da árvore de busca binária em ordem decrescente
void exibe_dec(TreeNode* root) {
    exibe_dec_aux(root);
    std::cout << std::endl;
}

int main() {
    // Construção de uma árvore de busca binária para teste
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    std::cout << "Itens da árvore em ordem decrescente: ";
    exibe_dec(root);

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
