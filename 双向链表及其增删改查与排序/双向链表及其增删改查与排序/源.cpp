#include<iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node *pNext;
		Node *pLast;
};

class List 
{
	private:
		Node *pHead;
		Node *pTail;
		int length;

	public:
		List(int length) 
		{
			this->length = length;
			pHead = new Node();
			pHead->pLast = NULL;
			pTail = pHead;
			for (int i = 0; i < length; i++) 
			{
				Node *temp = new Node();
				cout << "Please Enter No" << i + 1 << "Node's data:";
				cin >> temp->data;
				temp->pNext = NULL;
				temp->pLast = pTail;
				pTail->pNext = temp;
				pTail = temp;
			}
		}

		void traverseListReturn() 
		{
			Node *p = pTail;

			while (p->pLast != NULL) 
			{
				cout << p->data << endl;
				p = p->pLast;
			}
		}

		void traverseList() 
		{
			Node *p = pHead->pNext;

			while (p!= NULL) 
			{
				cout << p->data << endl;
				p = p->pNext;
			}
		}

		void sortList() 
		{
			Node *p = new Node();
			Node *q = new Node();
			int temp;

			for (p = pHead->pNext; p->pNext != NULL; p = p->pNext) 
			{
				for (q = p->pNext; q != NULL; q = q->pNext) 
				{
					if (q->data < p->data)
					{
						temp = q->data;
						q->data = p->data;
						p->data = temp;
					}
				}
			}
		}

		void sortListbyInsertway() 
		{
			if (pHead->pNext == NULL || pHead->pNext->pNext == NULL) 
			{
				return;
			}
			Node *p2 = pHead->pNext->pNext;
			Node *p1 = pHead;
			pHead->pNext->pNext = NULL;

			while (p2) 
			{

				Node *pN = p2->pNext;

				while (p1->pNext) 
				{
					if (p2->data < p1->pNext->data) 
					{
						p2->pNext = p1->pNext;
						p2->pLast = p1;
						p1->pNext->pLast = p2;
						p1->pNext = p2;
						break;
					}
					p1 = p1->pNext;
				}
				if (p1->pNext == NULL) 
				{
					p2->pNext = NULL;
					p2->pLast = p1;
					p1->pNext = p2;
				}
				p2 = pN;
			}

			Node *pt = pHead;

			while (pt->pNext) 
			{
				pt = pt->pNext;
			}
			pTail = pt;
		}

		void changeList(int num,int position) 
		{
			Node *p = pHead->pNext;

			if (position > length || position < 0) 
			{
				cout << "Over Stack" << endl;
				return;
			}
			for(int i = 0; i < position; i++) 
			{
				p = p->pNext;
			}
			p->data = num;
		}

		void insertList(int num, int position)
		{
			Node *p = pHead->pNext;

			if (position > length || position < 0)
			{
				cout << "Over Stack" << endl;
				return;
			}
			for (int i = 0; i < position; i++)
			{
				p = p->pNext;
			}

			Node *insert = new Node();
			insert->data = num;
			insert->pLast = p->pLast;
			insert->pNext = p;
			p->pLast->pNext = insert;
			p->pLast = insert;
			length++;
		}

		void clearList() 
		{
			Node *p = pHead->pNext;
			Node *q;

			while (p != NULL) 
			{
				q = p;
				p = p->pNext;
				delete q;
			}
			p = NULL;
			q = NULL;
		}

		void deleteList(int position) 
		{
			Node *p = pHead->pNext;

			if (position > length || position < 0) 
			{
				cout << "Over Stack" << endl;
				return;
			}
			for (int i = 0; i < position; i++) 
			{
				p = p->pNext;
			}
			p->pLast->pNext = p->pNext;
			p->pNext->pLast = p->pLast;
			delete p;
			length--;
		}

		int getitemList(int position) 
		{
			Node *p = pHead->pNext;

			if (position > length || position < 0)
			{
				cout << "Over Stack" << endl;
				return 0;
			}
			for (int i = 0; i < position; i++)
			{
				p = p->pNext;
			}
			return p->data;
		}

		~List() 
		{
			Node *p;
			Node *q = pHead->pNext;
			while (q != NULL) 
			{
				p = q;
				q = q->pNext;
				delete p;
			}
			p = NULL;
			q = NULL;
		}
};

int main() 
{
	List list(3);

	list.traverseList();
	cout << "After insert" << endl;
	list.insertList(55, 1);
	list.insertList(32, 1);
	list.insertList(8, 1);
	list.traverseList();
	cout << "After Sort:" << endl;
	list.sortListbyInsertway();
	list.traverseList();
	cout << "After delete:" << endl;
	list.deleteList(1);
	list.traverseList();
	list.deleteList(1);
	list.traverseList();
	cout << "Return Travser:" << endl;
	list.traverseListReturn();
	getchar();
	getchar();
	list.clearList();
	return 0;
}