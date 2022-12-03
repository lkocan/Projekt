typedef struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

void insertNode(BstNode** node, int data);
struct BstNode* deleteNode(struct BstNode* root, int data);
