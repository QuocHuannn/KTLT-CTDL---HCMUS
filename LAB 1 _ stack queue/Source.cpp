#include <iostream> 
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};

struct Stack {
	NODE* pTop;
};

struct Queue {
	NODE* pFront;
	NODE* pRear;
};

bool isEmpty(Stack S) {
	if (S.pTop == NULL) {
		return 1;
	}
	return 0;
}

void printStack(Stack S) {
	for (NODE* current = S.pTop; current != NULL; current = current->pNext) {
		cout << current->key << " ";
	}
}

void printQueue(Queue Q) {
	for (NODE* current = Q.pFront; current != NULL; current = current->pNext) {
		cout << current->key << " ";
	}
	cout << endl;
}

int push(Stack& S, int data) {
	NODE* current = new NODE;
	current->key = data;
	current->pNext = NULL;
	if (S.pTop == NULL) {
		S.pTop = current;
		return 1;
	}
	else {
		current->pNext = S.pTop;
		S.pTop = current;
		return 1;
	}
}

int pop(Stack& S) {
	NODE* current = S.pTop;
	if (current == NULL) {
		return 0;
	}
	else {
		S.pTop = current->pNext;
		delete current;
	}
}

int count(Stack S) {
	NODE* current = S.pTop;
	int dem = 0;
	while (current != NULL) {
		current = current->pNext;
		dem++;
	}
	return dem;
}

int countQ(Queue q) {
	NODE* current = q.pFront;
	int dem = 0;
	while (current != NULL) {
		current = current->pNext;
		dem++;
	}
	return dem;
}

int enqueue(Queue& Q, int data) {
	NODE* current = new NODE;
	current->key = data;
	current->pNext = NULL;
	if (Q.pFront == NULL) {
		Q.pFront = current;
		Q.pRear = current;
	}
	else {
		Q.pRear->pNext = current;
		Q.pRear = current;
	}
	return 1;
}

int dequeue(Queue& Q) {
	NODE* current = Q.pFront;
	if (countQ(Q) == 1) {
		Q.pFront = NULL;
		Q.pRear = NULL;
	}
	else {
		Q.pFront = current->pNext;
		delete current;
	}
	return 1;
}

int main() {
	/*Queue Q;
	Q.pFront = NULL;
	Q.pRear = NULL;

	enqueue(Q, 7);
	enqueue(Q, 10);
	enqueue(Q, 18);

	dequeue(Q);
	enqueue(Q, 7);

	dequeue(Q);
	enqueue(Q, 7);

	printQueue(Q);
	cout << countQ(Q);
	*/
	Stack s;
	s.pTop = NULL;
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	pop(s);
	push(s, 6);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	push(s, 2);

	printStack(s);
	
	return 0;
}