#pragma once
#ifndef INTLIST_H
#define INTLIST_H

#include "IntNode.h";

class IntList {
public:
	IntList(IntNode* head = nullptr);
	void AddSequentialValues(int start, int size);
	void AddRandomValues(int size);
	int GetSize();
	void InsertAfter(IntNode* nodePtr, IntNode* newNode);
	void PushBack(IntNode* nodePtr);
	void PushFront(IntNode* nodePtr);
	void DeleteNode(IntNode* nodePtr);
	void ClearList();
	IntNode* GetNodeByVal(int val);
	void PrintList();
	int GetMinValue();
	int GetMaxValue();
	double GetMedianValue();
private:
	IntNode* head;
	IntNode* tail;
	int listSize;
};

#endif