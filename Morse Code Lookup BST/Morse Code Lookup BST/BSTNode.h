#pragma once
#include "Header.h"

//use UserErrorCorrection with template
template <class T>//maybe make string generic vector?
class BSTNode
{
public:
	BSTNode();
	~BSTNode();
	T getData();//maybe static
	BSTNode<T> *& getLeft();
	BSTNode<T> *& getRight();
	string getString() const;
	bool setData(T &newData);
	bool setString(string &newString);
private:
	T data;
	string compareStr;
	BSTNode<T> * LPTR;
	BSTNode<T> * RPTR;
};

template<class T>
BSTNode<T>::BSTNode()
{
	data = '\0';
	compareStr = "";
	LPTR = nullptr;
	RPTR = nullptr;
}

template<class T>
BSTNode<T>::~BSTNode()
{
}

template<class T>
T BSTNode<T>::getData()
{
	return T(data);
}

template<class T>
BSTNode<T> *& BSTNode<T>::getLeft()
{
	return LPTR;
}

template<class T>
BSTNode<T> *& BSTNode<T>::getRight()
{
	return RPTR;
}

template<class T>
string BSTNode<T>::getString() const
{
	return string(compareStr);
}

template<class T>
bool BSTNode<T>::setData(T &newData)
{
	data = newData;
	if(data != newData)
	{
		return false;
	}
	return true;
}

template<class T>
bool BSTNode<T>::setString(string & newString)
{
	compareStr = newString;
	if (compareStr != newString)
	{
		return false;
	}
	return true;
}
