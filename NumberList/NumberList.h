// Specification file for the NumberList class
#pragma once
#include <iostream>
using namespace std;

class NumberList
{
private:
	// Declare a structure for the list
	struct ListNode 
	{
		int value;           // The value in this node
		struct ListNode *next;  // To point to the next node
	};

	ListNode *head;            // List head pointer

	ListNode *tail;

public:
	// Constructor
	NumberList()
	{
		head = nullptr;
	}

	// Copy Constructor
	NumberList(const NumberList &obj)
	{
		ListNode *nodePtr = new ListNode;
		int num = 0;
		if (this != &obj)
		{
			this->head = nullptr;
			nodePtr = obj.head;
			while (nodePtr->next)
			{
				num++;
				this->appendNode(nodePtr->value);
				nodePtr = nodePtr->next;
				if (nodePtr->next)
				{
					this->appendNode(nodePtr->value);
					cout << "in if" << endl;
				}
			}
		}
	}

	const NumberList operator=(const NumberList &right)
	{
		ListNode *nodePtr = new ListNode;
		if (this != &right)
		{
			this->head = nullptr;
			nodePtr = right.head;
			while (nodePtr->next)
			{
				this->appendNode(nodePtr->value);
				nodePtr = nodePtr->next;
				if (nodePtr == nullptr)
				{
					this->appendNode(nodePtr->value);
					cout << "in if" << endl;
				}
			}
		}
		return *this;
	}

	// Destructor
	~NumberList();

	// Linked list operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;
};

