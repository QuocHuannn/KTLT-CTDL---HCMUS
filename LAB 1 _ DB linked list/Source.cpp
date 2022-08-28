#include <iostream>

using namespace std;

struct node {
	int key;
	node* next;
	node* prev;
};

struct List
{
	node* head;
	node* tail;
};


node* createNode(int data)
{
	node* temp = new node;
	temp->key = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;
}

List* createList(node* p_node)
{
	List* list = new List;
	if (p_node == nullptr)
	{
		list->head = NULL;
		list->tail = NULL;
		return list;
	}
	list->head = p_node;
	list->tail = p_node;
	return list;
}
bool addHead(List*& L, int data)
{
	if (L == nullptr)
		return false;

	node* temp = createNode(data);
	if (L->head == NULL) {
		L->head = temp;
		L->tail = temp;
	}
	else {

		temp->next = L->head;
		L->head->prev = temp;
		L->head = temp;
		return true;
	}
}

bool addTail(List*& L, int data)
{
	if (L == nullptr)
		return false;

	node* temp = createNode(data);
	if (L->head == NULL) {
		L->head = temp;
		L->tail = temp;
	}
	else {
		temp->prev = L->tail;
		L->tail->next = temp;
		L->tail = temp;
		return true;
	}
}

void removeHead(List*& L)
{
	if (L == nullptr)
		return;
	if (L->head->next == nullptr)
	{
		delete L->head;
		L->head = nullptr;
		L->tail = nullptr;
		return;
	}
	else {
		node* temp = L->head;
		L->head = temp->next;
		delete temp;
		if (L->head == nullptr)
		{
			L->tail = nullptr;
			L = nullptr;

		}
		else
			L->head->prev = nullptr;
	}
}

void removeTail(List*& L)
{
	if (L == nullptr)
		return;
	if (L->head->next == nullptr)
	{
		delete L->head;
		L->head = nullptr;
		L->tail = nullptr;
		return;
	}

	node* temp = L->tail;
	L->tail = L->tail->prev;
	L->tail->next = nullptr;
	delete temp;


}

void removeAll(List*& L)
{
	node* current = L->head;
	while (current->next != NULL) {
		removeHead(L);
		current = L->head;
	}
	if (L->head->next == nullptr)
	{
		delete L->head;
		L->head = nullptr;
		L->tail = nullptr;
	}
	
}

void removeBefore(List*& L, int val)
{
	if (L == nullptr)
		return;
	if (L->head->key == val)
	{
		return;
	}

	node* temp = L->head;
	if (temp->next == nullptr)
		return;
	if (temp->next->key == val)
	{
		removeHead(L);
		return;
	}

	while (temp != nullptr && temp->key != val)
	{
		temp = temp->next;
	}

	if (temp == nullptr)
		return;

	if (temp->key == val)
	{
		node* node_delete = temp;
		temp = temp->prev;
		temp->next = temp->next->next;
		temp->next->prev = temp;
		delete node_delete;
	}

}

void printList(List* L)
{
	if (L == nullptr)
		return;

	node* temp = L->head;
	while (temp != nullptr)
	{
		cout << temp->key << " ";
		temp = temp->next;
	}
	cout << endl;
}

void removeAfter(List*& L, int val)
{
	if (L == nullptr)
		return;

	node* temp = L->head;
	if (temp->next == nullptr)
		return;


	while (temp != nullptr && temp->key != val)
	{
		temp = temp->next;
	}

	if (temp == nullptr)
		return;
	if (temp->key == val)
	{
		if (temp == L->tail)
			return;
		node* node_delete = temp->next;
		temp->next = temp->next->next;
		if (node_delete == L->tail)
			L->tail = temp;
		if (temp->next != nullptr)
			temp->next->prev = temp;
		delete node_delete;
	}

}

bool addPos(List*& L, int data, int pos)
{
	if (L == nullptr)
		return false;
	if (pos == 0)
	{
		addHead(L, data);
		return true;
	}
	node* temp = L->head;
	int i = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		if (temp != nullptr)
			i++;
	}
	if (pos == i + 1)
	{
		addTail(L, data);
		return true;
	}

	if (i < pos)
		return false;
	temp = L->head;
	for (int i = 0; i < pos - 1; i++)
		temp = temp->next;

	node* node_insert = createNode(data);
	node_insert->next = temp->next;
	temp->next->prev = node_insert;
	temp->next = node_insert;
	node_insert->prev = temp;
	return true;
}

void removeElement(List*& L, int val)
{
	if (L == nullptr)
		return;
	if (L->head->key == val)
	{
		removeHead(L);
		return;
	}

	node* temp = L->head;
	if (temp->next == nullptr)
		return;

	while (temp->next != nullptr && temp->next->key != val)
	{
		temp = temp->next;
	}



	if (temp->next != nullptr && temp->next->key == val)
	{

		node* node_delete = temp->next;
		temp->next = temp->next->next;
		if (temp->next != nullptr)
			temp->next->prev = temp;
		if (L->tail == node_delete)
			L->tail = temp;
		delete node_delete;
		return;
	}

}

void removePos(List*& L, int pos)
{
	if (L == nullptr)
		return;
	if (pos == 0)
	{
		removeHead(L);
		return;
	}


	node* temp = L->head;
	int n = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		if (temp != nullptr)
			n++;
	}

	if (pos > n)
		return;

	if (pos == n)
	{
		removeTail(L);
		return;
	}
	temp = L->head;

	for (int i = 0; i < pos - 1; i++)
		temp = temp->next;

	node* node_delete = temp->next;
	temp->next = temp->next->next;
	temp->next->prev = temp;
	delete node_delete;

}

bool addBefore(List*& L, int data, int val)
{
	if (L == nullptr)
		return false;
	node* temp = L->head;
	if (L->head->key == val)
	{
		addHead(L, data);
		return true;
	}


	while (temp->next != nullptr && temp->next->key != val)
		temp = temp->next;

	if (temp->next == nullptr)
		return false;

	node* node_insert = createNode(data);
	node_insert->next = temp->next;
	node_insert->next->prev = node_insert;
	temp->next = node_insert;
	node_insert->prev = temp;
	return true;
}

bool addAfter(List*& L, int data, int val)
{
	if (L == nullptr)
		return false;

	node* temp = L->head;

	while (temp != nullptr && temp->key != val)
		temp = temp->next;

	if (temp == nullptr)
		return false;

	node* node_insert = createNode(data);
	node_insert->next = temp->next;
	// check truong hop add vao cuoi
	if (temp->next != nullptr)
		temp->next->prev = node_insert;
	else
		L->tail = node_insert;

	temp->next = node_insert;
	node_insert->prev = temp;
	return true;
}

int countElements(List* L)
{
	if (L == nullptr)
		return 0;
	node* temp = L->head;
	int n = 0;
	while (temp != nullptr)
	{
		n++;
		temp = temp->next;
	}
	return n;

}

void removeDuplicate(List*& L)
{
	if (L == nullptr)
		return;
	node* temp1 = L->head;
	node* temp2 = temp1;

	while (temp1 != nullptr && temp1->next != nullptr)
	{
		temp2 = temp1;
		while (temp2->next != nullptr)
		{
			if (temp1->key == temp2->next->key)
			{
				node* temp = temp2->next;
				temp2->next = temp2->next->next;
				if (temp2->next != nullptr)
					temp2->next->prev = temp2;
				if (L->tail == temp)
					L->tail = temp2;
				delete temp;
			}
			else
				temp2 = temp2->next;
		}


		temp1 = temp1->next;
	}

}


List* reverseList(List* L)
{
	if (L == nullptr)
		return nullptr;
	node* temp = L->head;
	int n = countElements(L);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = temp->key;
		temp = temp->next;
	}

	node* tail = createNode(a[0]);
	List* list = createList(tail);
	for (int i = 1; i < n; i++)
	{
		addHead(list, a[i]);
	}
	
	return list;
}


void print_reverse_list(List* L)
{
	if (L == nullptr)
		return;

	node* temp = L->tail;
	while (temp != nullptr)
	{
		cout << temp->key << " ";
		temp = temp->prev;
	}
}



int main() {
	List* L;
	node* n = createNode(10);
	L = createList(n);
	addHead(L, 5);
	addHead(L, 1);
	addHead(L, 4);
	addTail(L, 7);
	addTail(L, 3);
	addHead(L, 5);
	printList(L);

	removeAfter(L, 5);
	removeAfter(L, 7);
	removeBefore(L, 10);
	printList(L);

	addAfter(L, 2, 5);
	addBefore(L, 8, 7);
	addAfter(L, 1, 7);


	printList(L);
	removeDuplicate(L);
	printList(L);

	List *N = reverseList(L);
	printList(N);
	

}