// 使用递归实现
#include <iostream>
#include <memory>
using namespace std;
struct BTNode {
    char data;
    BTNode *left_child;
    BTNode *right_brother;

    BTNode(char val) : data(val), left_child(nullptr), right_brother(nullptr) {};
    BTNode(char val, BTNode *left, BTNode *right) : data(val), left_child(left), right_brother(right) {};
};

void makeTree(BTNode *&root) {
    BTNode *F = new BTNode('F');
    BTNode *K = new BTNode('K');
    BTNode *J = new BTNode('J', nullptr, K);
    BTNode *I = new BTNode('I', nullptr, J);
    BTNode *H = new BTNode('H', I, nullptr);
    BTNode *G = new BTNode('G', H, nullptr);
    BTNode *D = new BTNode('D', G, nullptr);
    BTNode *C = new BTNode('C', nullptr, D);
    BTNode *E = new BTNode('E', nullptr, F);
    BTNode *B = new BTNode('B', E, C);
    BTNode *A = new BTNode('A', B, nullptr);
    root = A;
}
void HTravserse(BTNode *&node) {
    if (node == nullptr)
        return;
    HTravserse(node->left_child);
    cout << node->data << ' ';
    BTNode *child = node->left_child;
    while (child != nullptr) {
        HTravserse(child->right_brother);
        child = child->right_brother;
    }
}
void freeTree(BTNode *&node) {
    if (node == nullptr)
        return;
    freeTree(node->left_child);
    freeTree(node->right_brother);
    delete node;
}
int main() {
    BTNode *root;
    makeTree(root);
    HTravserse(root);
    cout << endl;
    freeTree(root);
    root = nullptr;
    return 0;
}
