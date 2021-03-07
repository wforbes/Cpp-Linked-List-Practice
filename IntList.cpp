#include <iostream>
#include <time.h>
using namespace std;

#include "IntList.h"

IntList::IntList(IntNode* head) {
	this->head = head;
	this->tail = nullptr;
	this->listSize = 0;
}

void IntList::AddSequentialValues(int min, int max) {
	for (int i = min; i < max+1; i++) {
		this->PushBack(new IntNode(i));
	}
}

void IntList::AddRandomValues(int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		this->PushBack(new IntNode(rand()));
	}
}

int IntList::GetSize() {
	return this->listSize++;
}

void IntList::InsertAfter(IntNode* nodePtr, IntNode* newNode) {
	nodePtr->InsertAfter(newNode);
	this->listSize++;
}

void IntList::PushBack(IntNode* newNode) {
	if (this->tail == nullptr) {
		this->tail = newNode;
		this->head->InsertAfter(this->tail);
	}
	else {
		this->tail->InsertAfter(newNode);
		this->tail = newNode;
	}
	this->listSize++;
}

void IntList::PushFront(IntNode* newNode) {
	this->head->InsertAfter(newNode);
	this->listSize++;
}

IntNode* IntList::GetNodeByVal(int val) {
	IntNode* currNode = head;
	while (currNode != nullptr) {
		if (currNode->GetDataVal() == val) {
			return currNode;
		}
		currNode = currNode->GetNext();
	}
	return currNode;
}

void IntList::DeleteNode(IntNode* nodePtr) {
	IntNode* currNode = this->head;
	while (currNode != nullptr) {
		if (currNode->GetNext() == nodePtr) {
			if (nodePtr->GetNext() != nullptr) {
				currNode->SetNext(nodePtr->GetNext());
			}
			else {
				currNode->SetNext(nullptr);
				this->tail = nullptr;
			}
			delete nodePtr;
			this->listSize--;
			return;
		}
		currNode = currNode->GetNext();
	}
}

void IntList::ClearList() {
	IntNode* currNode = this->head;
	IntNode* nextNode;
	while (currNode != nullptr) {
		nextNode = currNode->GetNext();
		this->DeleteNode(currNode);
		currNode = nextNode;
		//left off here
	}
	this->listSize = 0;
}

void IntList::PrintList() {
	IntNode* currNode = head;
	while (currNode != nullptr) {
		cout << currNode->GetDataVal() << endl;
		currNode = currNode->GetNext();
	}
}

int IntList::GetMinValue() {
	IntNode* currObj = this->head->GetNext();
	int minVal = currObj->GetDataVal();
	while (currObj != nullptr) {
		if (currObj->GetDataVal() < minVal) {
			minVal = currObj->GetDataVal();
		}
		currObj = currObj->GetNext();
	}
	return minVal;
}

int IntList::GetMaxValue() {
	IntNode* currObj = this->head->GetNext();
	int maxVal = currObj->GetDataVal();
	while (currObj != nullptr) {
		if (currObj->GetDataVal() > maxVal) {
			maxVal = currObj->GetDataVal();
		}
		currObj = currObj->GetNext();
	}
	return maxVal;
}

double IntList::GetMedianValue() {
	IntNode* currObj = this->head->GetNext();
	int sum = 0;
	while (currObj != nullptr) {
		sum += currObj->GetDataVal();
		currObj = currObj->GetNext();
	}
	return static_cast<double>(sum) / static_cast<double>(this->listSize);
}