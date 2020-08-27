#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:

	void preOrder(Node *root) {
		if (root == NULL) return;

		std::cout << root->data << " ";

		preOrder(root->left);
		preOrder(root->right);
	}

	Node * insert(Node * root, int data) {
        Node *current = root;

        if (root == NULL) {
            root = new Node(data);
            return root;
        }

        while (current != NULL) {
            if (current->data > data) {
                if (current->left != NULL)
                    current = current->left;
                else {
                    current->left = new Node(data);
                    break;
                }
            } else if (current->data <= data) {
                if (current->right != NULL)
                    current = current->right;
                else {
                    current->right = new Node(data);
                    break;
                }
            }
        }
        return root;
    }
   
};

int main() {
	Solution myTree;
	Node *root = NULL;

	int t;
	int data;

	std::cin >> t;

	while(t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.preOrder(root);

	return 0;
}