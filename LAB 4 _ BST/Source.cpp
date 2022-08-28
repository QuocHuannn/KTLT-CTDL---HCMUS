#include <iostream>
#include <queue>
using namespace std;

struct NODE {
	int key;
	NODE* left;
	NODE* right;
};

NODE* createNode(int data) {
	NODE* cur = new NODE;
	cur->key = data;
	cur->left = NULL;
	cur->right = NULL;
	return cur;
}

void Insert(NODE*& pRoot, int x) {
	if (pRoot == NULL) {
		pRoot = createNode(x);
		return;
	}
	if (x < pRoot->key) {
		if (pRoot->left == NULL) {
			pRoot->left = createNode(x);
			return;
		}
		Insert(pRoot->left, x);
	}
	if (x > pRoot->key) {
		if (pRoot->right == NULL) {
			pRoot->right = createNode(x);
			return;
		}
		Insert(pRoot->right, x);
	}
}

void NLR(NODE* pRoot) {   //preOrder
	if (pRoot == NULL) {
		return;
	}
	cout << pRoot->key << " ";
	NLR(pRoot->left);
	NLR(pRoot->right);
}

void LNR(NODE* pRoot) {   //inOrder
	if (pRoot == NULL) {
		return;
	}
	LNR(pRoot->left);
	cout << pRoot->key << " ";
	LNR(pRoot->right);
}

void LRN(NODE* pRoot) {   //postOrder
	if (pRoot == NULL) {
		return;
	}
	LRN(pRoot->left);
	LRN(pRoot->right);
	cout << pRoot->key << " ";
}

void LevelOrder(NODE* pRoot) {
	queue <NODE*> q;
	q.push(pRoot);
	while (!q.empty()) {
		NODE* p = q.front();
		q.pop();
		if (p->left != NULL) {
			q.push(p->left);
		}
		if (p->right != NULL) {
			q.push(p->right);
		}
		cout << p->key << " ";
	}
}

int Height(NODE* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	else {
		int leftIndex = Height(pRoot->left);
		int rightIndex = Height(pRoot->right);
		if (leftIndex >= rightIndex) {
			return leftIndex + 1;
		}
		else {
			return rightIndex + 1;
		}
	}
}

int countNode(NODE* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}

int sumNode(NODE* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}

NODE* Search(NODE* pRoot, int x) {
	if (pRoot == NULL) {
		return pRoot;
	}
	else {
		if (pRoot->key == x) {
			return pRoot;
		}
		if (pRoot->key > x) {
			Search(pRoot->left, x);
		}
		else {
			Search(pRoot->right, x);
		}
	}
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
}

NODE* createTree(int a[], int n) {
	NODE* pRoot = NULL;
	for (int i = 0; i < n; i++) {
		Insert(pRoot, a[i]);
	}
	return pRoot;
}

void removeTree(NODE*& pRoot) {
	if (pRoot == NULL) {
		return;
	}
	else {
		removeTree(pRoot->left);
		removeTree(pRoot->right);
		delete pRoot;
	}
}

int heightNode(NODE* pRoot, int value) {
	if (pRoot == NULL) {
		return 0;
	}
	else if (pRoot->key > value) {
		return heightNode(pRoot->left, value);
	}
	else if (pRoot->key < value) {
		return heightNode(pRoot->right, value);
	}
	else if (pRoot->key == value) {
		return Height(pRoot);
	}
}

int Level(NODE* pRoot, NODE* p) {
	int level = 1;
	while (pRoot->key != p->key && pRoot != NULL) {
		if (pRoot->key > p->key) {
			pRoot = pRoot->left;
		}
		if (pRoot->key < p->key) {
			pRoot = pRoot->right;
		}
		level++;
	}
	if (pRoot == NULL) {
		return -1;
	}
	if (pRoot->key == p->key) {
		return level;
	}
}

int countLeaf(NODE* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	if (pRoot->left == NULL && pRoot->right == NULL) {
		return 1;
	}
	return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}

int countLess(NODE* pRoot, int x) {
	if (pRoot == NULL) {
		return 0;
	}
	if (pRoot->key < x) {
		return 1 + countLess(pRoot->left, x) + countLess(pRoot->right, x);
	}
	if (pRoot->key >= x) {
		return countLess(pRoot->left, x) + countLess(pRoot->right, x);
	}
}

int countGreater(NODE* pRoot, int x) {
	if (pRoot == NULL) {
		return 0;
	}
	if (pRoot->key > x) {
		return 1 + countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
	}
	if (pRoot->key <= x) {
		return countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
	}
}

int findMin(NODE* pRoot) {
	if (pRoot == NULL) {
		return INT_MAX;
	}
	int val = pRoot->key;
	int Lval = findMin(pRoot->left);
	int Rval = findMin(pRoot->right);

	if (val > Rval) {
		val = Rval;
	}
	if (val > Lval) {
		val = Lval;
	}
	return val;
}

int findMax(NODE* pRoot) {
	if (pRoot == NULL) {
		return INT_MIN;
	}
	int val = pRoot->key;
	int Lval = findMax(pRoot->left);
	int Rval = findMax(pRoot->right);

	if (val < Rval) {
		val = Rval;
	}
	if (val < Lval) {
		val = Lval;
	}
	return val;
}

bool isBST(NODE* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	if (pRoot->left != NULL && findMax(pRoot->left) > pRoot->key) {
		return false;
	}
	if (pRoot->right != NULL && findMin(pRoot->right) < pRoot->key) {
		return false;
	}
	if (!isBST(pRoot->left) || !isBST(pRoot->right)) {
		return false;
	}
	return true;
}

bool isFullTree(NODE* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	if (pRoot->left != NULL && pRoot->right == NULL) {
		return false;
	}
	if (pRoot->right != NULL && pRoot->left == NULL) {
		return false;
	}
	if (pRoot->left != NULL && pRoot->right != NULL) {
		return isFullTree(pRoot->left) && isFullTree(pRoot->right);
	}
	return true;
}

bool isFullBST(NODE* pRoot) {
	if (isBST(pRoot) && isFullTree(pRoot)) {
		return true;
	}
	return false;
}

int main() {
	/*NODE* root = NULL;
	int a[8] = {34,17,66,25,50,71,68,94};
	root = createTree(a, 8);
	NODE* p = createNode(17);*/
	NODE* root = NULL;
	root = createNode(4);
	root->left = createNode(2);
	root->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(7);
	root->left->left = createNode(1);
	root->left->right = createNode(3);

	if (isFullTree(root)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}





