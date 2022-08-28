#include <iostream>
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};

void printList(List L) {
	for (NODE* pCur = L.p_head; pCur != NULL; pCur = pCur->p_next) {
		cout << pCur->key << " ";
	}
	cout << endl;
}

NODE* createNode(int data) {
	NODE* cur = new NODE;
	cur->key = data;
	cur->p_next = NULL;
	return cur;
}

bool insert_head(List& L, int data) {
	NODE* current = createNode(data);
	if (current == 0) {
		return 0;
	}
	if (L.p_head == NULL) {
		L.p_head = current;
		L.p_tail = current;
		return 1;
	}
	else {
		current->p_next = L.p_head;
		L.p_head = current;
		return 1;
	}
}

bool addTail(List& L, int data) {
	NODE* node = createNode(data);

	if (node == NULL)
		return false;

	if (L.p_head == NULL)
	{
		insert_head(L, data);
	}
	else
	{
		L.p_tail->p_next = node;
		L.p_tail = node;
	}
	return true;
}

void removeHead(List& L) {
	NODE* current = L.p_head;
	if (L.p_head == NULL) {
		cout << "nothing to remove!";
	}
	else {
		L.p_head = current->p_next;
		delete current;
	}
}

void removeTail(List& L) {
	NODE* current = L.p_head;
	NODE* prev = L.p_head;
	if (L.p_head == NULL) {
		cout << "nothing to remove!";
	}
	if (L.p_head->p_next == NULL) {
		L.p_head = NULL;
		L.p_tail = NULL;
	}
	else {
		while (current->p_next != NULL) {
			prev = current;
			current = current->p_next;
		}
		delete current;
		L.p_tail = prev;
		prev->p_next = NULL;
	}
}

void removeAll(List& L) {
	NODE* current = L.p_head;
	while (current->p_next != NULL) {
		removeHead(L);
		current = L.p_head;
	}
	L.p_head = NULL;
	L.p_tail = NULL;
}

NODE* Search(List L, int x) {
	NODE* current = L.p_head;
	while (current != NULL && current->key != x) {
		current = current->p_next;
	}
	if (current != NULL) {
		return current;
	}
	return NULL;
}

void RemoveAfterQ(List& L, NODE* q)
{
	if (q == NULL) {
		cout << " not found";
	}
	else {
		NODE* p = q->p_next;
		if (p != NULL) {
			if (L.p_tail == p) {
				removeTail(L);
			}
			else {
				q->p_next = p->p_next;
				delete p;
			}
		}
	}
}

void removeQ(List& L, NODE* q) {
	NODE* current = L.p_head;
	NODE* prev = NULL;
	if (L.p_head == q) {
		cout << "no";
	}
	else {
		while (current != NULL && current != q) {
			prev = current;
			current = current->p_next;
		}
		if (current != NULL) {
			prev->p_next = q->p_next;
			delete current;
		}
	}

}

void removeBeforeQ(List& L, NODE* q) {
	NODE* p = L.p_head;
	if (q == NULL) {
		cout << "not found";
	}
	else {
		if (p->p_next == q) {
			removeHead(L);
		}
		else {
			while (p->p_next->p_next != q) {
				p = p->p_next;
			}
			NODE* q = p->p_next;
			p->p_next = q->p_next;
			delete q;
		}
	}
}

void AddAfterQ(List& L, NODE* q, int value) {
	if (q == NULL) {
		insert_head(L, value);
	}
	else {
		NODE* p = new NODE;
		p->key = value;
		if (L.p_tail == q) {
			q->p_next = p;
			L.p_tail = p;

		}
		else {
			p->p_next = q->p_next;
			q->p_next = p;
		}
	}
}

void AddBeforeQ(List& L, NODE* q, int value) {
	if (L.p_head == q) {
		insert_head(L, value);
	}
	else {
		NODE* p = new NODE;
		NODE* current = L.p_head;
		NODE* prev = NULL;
		p->key = value;
		if (L.p_head == q) {
			L.p_head = p;
		}
		else {
			while (current != NULL && current != q) {
				prev = current;
				current = current->p_next;
			}
			if (current != NULL) {
				prev->p_next = p;
				p->p_next = q;
			}
		}
	}
}

int countOccurences(List L, int num) {
	int dem = 0;
	NODE* cur = new NODE;
	cur = L.p_head;
	while (cur != NULL) {
		if (cur->key == num) {
			dem++;
		}
		cur = cur->p_next;
	}
	return dem;
}

bool isPermutation(List L, List N) {
	NODE* cur = new NODE;
	NODE* nur = new NODE;
	cur = L.p_head;
	while (cur != NULL) {
		if (countOccurences(L, cur->key) != countOccurences(N, cur->key)) {
			return false;
			break;
		}
		cur = cur->p_next;
	}
	return true;
}

int countElement(List L) {
	if (L.p_head == NULL) {
		return 0;
	}
	else {
		int dem = 1;
		NODE* cur = L.p_head;
		while (cur->p_next != NULL) {
			dem++;
			cur = cur->p_next;
		}
		return dem;
	}
}

bool addPos(List& L, int data, int pos) //vi tri bat dau tu 1
{
	NODE* cur = L.p_head;
	int dem = 1;
	int n = countElement(L);
	if (pos - n > 1) {
		cout << "out of range";
		return false;
	}
	while (dem != pos) {
		dem++;
		cur = cur->p_next;
	}
	if (dem == 1) {
		insert_head(L, data);
	}
	else if (dem == n +1) {
		addTail(L, data);
	}
	else {
		AddBeforeQ(L, cur, data);
	}
	return true; 
}

void removePos(List& L, int pos) {
	NODE* cur = L.p_head;
	int dem = 1;
	int n = countElement(L);
	if (pos - n > 1) {
		cout << "out of range";
	}
	while (dem != pos) {
		dem++;
		cur = cur->p_next;
	}
	if (dem == 1) {
		removeHead(L);
	}
	else if (dem == n) {
		removeTail(L);
	}
	else {
		NODE* p = cur->p_next;
		removeBeforeQ(L, p);
	}
}

void revers(List& L) {
	NODE* cur = L.p_head;
	NODE* pre = NULL;
	NODE* next = NULL;
	while (cur != NULL) {
		next = cur->p_next;
		cur->p_next = pre;
		if (cur->p_next == NULL) {
			L.p_tail = cur;
		}
		pre = cur;
		cur = next;
	}
	L.p_head = pre;
}

void removeDuplicates(struct NODE* start)
{
	struct NODE* ptr1, * ptr2, * dup;
	ptr1 = start;

	/* Pick elements one by one */
	while (ptr1 != NULL && ptr1->p_next != NULL)
	{
		ptr2 = ptr1;

		/* Compare the picked element with rest
		   of the elements */
		while (ptr2->p_next != NULL)
		{
			/* If duplicate then delete it */
			if (ptr1->key == ptr2->p_next->key)
			{
				/* sequence of steps is important here */
				dup = ptr2->p_next;
				ptr2->p_next = ptr2->p_next->p_next;
				delete(dup);
			}
			else {
				ptr2 = ptr2->p_next;
			}
		}
		ptr1 = ptr1->p_next;
	}
}

bool removeElement(List& L, int key)
{
	NODE* cur = L.p_head;
	NODE* pre = NULL;
	while (cur != NULL) {
		if (cur->key == key) {
			if (cur == L.p_head) {
				removeHead(L);
				cur = L.p_head;
			}
			else if (cur == L.p_tail) {
				removeTail(L);
				cur = L.p_tail;
			}
			else {
				pre->p_next = cur->p_next;
				delete cur;
				cur = pre->p_next;
			}
		}
		pre = cur;
		cur = cur->p_next;
	}
	return true;
}

int main() {
	List L, N;
	L.p_head = NULL;
	L.p_tail = NULL;

	insert_head(L, 4);
	addTail(L, 1);
	printList(L);
	
	removeTail(L);
	removeHead(L);
	insert_head(L, 2);
	printList(L);
	
	insert_head(L, 3);
	removeHead(L);	
	printList(L);
	
	removeTail(L);
	insert_head(L, 8);
	addTail(L, 9);
	addTail(L, 5);
	insert_head(L, 6);
	
	printList(L);

	removeTail(L);
	insert_head(L, 7);
	insert_head(L, 2);
	insert_head(L, 3);
	insert_head(L, 7);
	insert_head(L, 2);


	printList(L);
	removeElement(L, 7);
	printList(L);
	

	

	
	//N.p_head = NULL;
	//N.p_tail = NULL;

	//insert_head(N, 2);
	//addTail(N, 1);
	//insert_head(N, 2);
	//insert_head(N, 4);
	//insert_head(N, 6);
	//addTail(N, 3);
	//addTail(N, 2);
	//printList(N);

}