#include <stdio.h>
#include <stdlib.h>

// Ʈ�� ��� ����ü ����
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ���ο� Ʈ�� ��� ����
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���� ��ȸ �Լ� (�ݺ���)
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* current = root;
    struct TreeNode* stack[100]; // ����
    int top = -1; // ������ �� ��

    printf("1. ���� ��ȸ ���\n");

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }

    printf("\n");
}

// Ư�� ����� �θ� ��带 ã�� �Լ�
struct TreeNode* findParent(struct TreeNode* root, int data) {
    if (root == NULL) return NULL;

    if ((root->left != NULL && root->left->data == data) ||
        (root->right != NULL && root->right->data == data)) {
        printf("%d. Node %d�� �θ�:%d\n", data - 3, data, root->data);
        return root;
    }

    struct TreeNode* leftSearch = findParent(root->left, data);
    if (leftSearch != NULL) return leftSearch;

    struct TreeNode* rightSearch = findParent(root->right, data);
    if (rightSearch != NULL) return rightSearch;

    return NULL;
}

int main() {
    // �־��� Ʈ�� ����
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(3);
    root->left->right = createNode(6);
    root->right->left = createNode(8);
    root->right->right = createNode(9);
    root->left->left->left = createNode(4);
    root->left->left->right = createNode(5);
    root->right->right->left = createNode(10);
    root->right->right->right = createNode(11);

    // ���� ��ȸ
    inOrderTraversal(root);

    // �θ� ��� ã��
    findParent(root, 4);
    findParent(root, 5);
    findParent(root, 6);

    // �޸� ����
    free(root->right->right->right);
    free(root->right->right->left);
    free(root->left->left->right);
    free(root->left->left->left);
    free(root->right->right);
    free(root->right->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
