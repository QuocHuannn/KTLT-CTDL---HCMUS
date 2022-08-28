#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* left;
	NODE* right;
	int height;
};

void leftRotate(NODE*& pRoot) {
	NODE* p = pRoot->right;
	pRoot->right = p->left;
	p->left = pRoot;
	pRoot = p;
}

void rightRotate(NODE*& pRoot) {
	NODE* p = pRoot->left;
	pRoot->left = p->right;
	p->right = pRoot;
	pRoot = p;
}

NODE* createNode(int data) {
	NODE* p = new NODE;
	p->key = data;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}

int Height(NODE* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	else {
		return max(Height(pRoot->left), Height(pRoot->right)) + 1;
	}
}

void Insert(NODE*& pRoot, int x) {
	if (pRoot == NULL) {
		pRoot = createNode(x);
	}
	else if (pRoot->key == x) {
		return;
	}
	else if (pRoot->key > x) {
		Insert(pRoot->left, x);
	}
	else if (pRoot->key < x) {
		Insert(pRoot->right, x);
	}
	int balance = Height(pRoot->left) - Height(pRoot->right);
	if (balance >= 2) {   // left case
		if (Height(pRoot->left->left) > Height(pRoot->left->right)) {  // left left case
			rightRotate(pRoot);
		}
		if (Height(pRoot->left->left) < Height(pRoot->left->right)) {  // left right case
			leftRotate(pRoot->left);
			rightRotate(pRoot);
		}
	}
	if (balance <= -2) {
		if (Height(pRoot->right->right) > Height(pRoot->right->left)) {  // right right case
			leftRotate(pRoot);
		}
		if (Height(pRoot->right->right) < Height(pRoot->right->left)) {  // right left case
			rightRotate(pRoot->right);
			leftRotate(pRoot);
		}
	}

}

void LNR(NODE* pRoot) {   //inOrder
	if (pRoot == NULL) {
		return;
	}
	LNR(pRoot->left);
	cout << pRoot->key << " ";
	LNR(pRoot->right);
}

void Remove(NODE*& pRoot, int x) {
	if (pRoot == NULL) {
		return;
	}
	else if (pRoot->key > x) {
		Remove(pRoot->left, x);
	}
	else if (pRoot->key < x) {
		Remove(pRoot->right, x);
	}
	else if (pRoot->key == x) {
		if (pRoot->right == NULL && pRoot->left == NULL) {
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->left == NULL) {
			pRoot = pRoot->right;
		}
		else if (pRoot->right == NULL) {
			pRoot = pRoot->left;
		}
		else {
			NODE* p = pRoot->left;
			while (p->right != NULL) {
				p = p->right;
			}
			pRoot->key = p->key;
			Remove(pRoot->left, p->key);
		}
	}
	if (pRoot == NULL) {
		return;
	}

	int balance = Height(pRoot->left) - Height(pRoot->right);
	if (balance >= 2) {   // left case
		if (Height(pRoot->left->left) > Height(pRoot->left->right)) {  // left left case
			rightRotate(pRoot);
		}
		if (Height(pRoot->left->left) < Height(pRoot->left->right)) {  // left right case
			leftRotate(pRoot->left);
			rightRotate(pRoot);
		}
	}
	if (balance <= -2) {
		if (Height(pRoot->right->right) > Height(pRoot->right->left)) {  // right right case
			leftRotate(pRoot);
		}
		if (Height(pRoot->right->right) < Height(pRoot->right->left)) {  // right left case
			rightRotate(pRoot->right);
			leftRotate(pRoot);
		}
	}
}

bool isAVL(NODE* pRoot) {
	int balance = Height(pRoot->left) - Height(pRoot->right);
	if (balance >= 2) {   // left case
		return false;
	}
	if (balance <= -2) {
		return false;
	}
	return true;
}

int main() {
	NODE* root = NULL;
	Insert(root, 10);
	Insert(root, 15);
	Insert(root, 13);
	Insert(root, 17);
	Insert(root, 9);
	Insert(root, 14);
	Remove(root, 13);
	LNR(root); 

	/*root = createNode(15);
	root->left = createNode(6);
	root->right = createNode(50);
	root->right->left = createNode(23);
	root->right->right = createNode(71);
	root->left->left = createNode(4);
	root->left->left->left = createNode(3);

	if (isAVL(root)) {
		cout << "true";
	}
	else cout << "false";
	return 0;*/
}