// 实现了非递归H遍历
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
using namespace std;
struct BTNode {
    char data;
    BTNode *left_child;
    BTNode *right_brother;

    BTNode(char val) : data(val), left_child(nullptr), right_brother(nullptr) {};
    BTNode(char val, BTNode *left, BTNode *right) : data(val), left_child(left), right_brother(right) {};
};
struct StackElement {
    BTNode *node;
    BTNode *child;
    int state;
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

void HTravserse(BTNode *&root) {
    if (root == nullptr)
        return;

    stack<StackElement> st;
    st.push({root, nullptr, 0});

    while (!st.empty()) {
        StackElement &f = st.top();

        if (f.node == nullptr) {
            st.pop();
            continue;
        }

        // 状态 0：处理 left_child
        if (f.state == 0) {
            f.state = 1;
            st.push({f.node->left_child, nullptr, 0});
        }
        // 状态 1：访问当前结点，初始化 child
        else if (f.state == 1) {
            cout << f.node->data << ' ';
            f.child = f.node->left_child;
            f.state = 2;
        }
        // 状态 2：模拟 while(child) 递归兄弟
        else {
            if (f.child == nullptr) {
                st.pop(); // while 结束，相当于 return
            } else {
                BTNode *brother = f.child->right_brother;
                f.child = brother; // child = child->right_brother
                st.push({brother, nullptr, 0});
            }
        }
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
