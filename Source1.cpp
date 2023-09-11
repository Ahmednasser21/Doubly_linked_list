#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node* prev;
};

class DLlist
{
private:
	node* head;
	node* tail;
public:
	DLlist() {
		head = NULL;
		tail = NULL;
	}
	~DLlist()
	{
		node* temp = head;
		while (temp != NULL)
		{
			node* next = temp->next;
			delete temp;
			temp = next;
		}

	}
	void insertfront(int value)
	{
		node* newnode = new node;
		newnode->data = value;
		newnode->prev = NULL;
		newnode->next = head;
		if (head!= NULL)
		{
			head->prev = newnode;
		}
		else
		{
			tail = newnode;
		}
		head = newnode;
	}
	void insertback(int value)
	{
		node* newnode = new node;
		newnode->data = value;
		newnode->next = NULL;
		newnode->prev = tail;
		if (tail != NULL)
		{
			tail->next = newnode;
		}
		else
		{
			head = newnode;
		}
		tail = newnode;
	}
	void frontprint()
	{
		node* temp = tail;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
	node* Usersearchlist(int key)
	{
		node* newnode = NULL;
		newnode = head;
		while (newnode->data != key)
		{
			newnode = newnode->next;

			if (newnode->data == key)
			{
				cout << "found the key "<< newnode->data <<" that you are searching for " <<endl;
			}
			
			else if (newnode->next == NULL)
			{
				cout << "key you are searching for dosen`t exist in the list" << endl;
				break;
			}
		}
		return newnode;
	}
	node* searchlist(int key)
	{
		node* newnode = NULL;
		newnode = head;
		while (newnode->data != key)
		{
			newnode = newnode->next;
		}
		return newnode;
	}
	int deletnode(int value)
	{
		int ret = 1;
		node* temp = searchlist(value);
		if (!temp)
		{
			cout << "value dosn`t exist" << endl;
			ret = 0; 
		}
		else 
		{
			if (head == tail)
			{
				head = tail = NULL;
			}
			else if (temp == head)
			{
				head = head->next;
				head->prev = NULL;
			}
			else if (temp == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
		}
		delete temp;
		return ret;
	}
};
int main()
{
	DLlist a;
	a.insertfront(2);
	a.insertfront(3);
	a.insertback(12);
	a.deletnode(12);
	a.frontprint();
	return 0;
}