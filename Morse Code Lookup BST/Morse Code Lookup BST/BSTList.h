#pragma once

#include "BSTNode.h"
#include "Header.h"

//MAKE userErrorCorrection a template
//fix tempates
template <class T>
class BSTList
{
public:
	BSTList();
	~BSTList();

	void BSTPrint();
	void BSTSearch();

	BSTNode<T> *& getRoot();

	void setRoot(BSTNode<T>* const newRoot);
	void insert(BSTNode<T> Node);

	void threadedMorseLoop(array<string, 40> &morseArray, std::ifstream &tableFile);
	void threadedInputLoop(vector<char> &convertVector, std::ifstream &inputFile) const;
private:
	BSTNode<T> * rootNode;
	void insert(BSTNode<T> *&rootNode, BSTNode<T> Node); //**rootNode vs *& rootNode?
	void BSTPrint(BSTNode<T> * &rootNode);//ask about pass by reference rootnode.
	void BSTSearch(BSTNode<T> * &rootNode);
};

template<class T>
BSTList<T>::BSTList()
{
	std::ifstream tableFile("MorseTable.txt");
	std::ifstream inputFile("Convert.txt");
	array<string, 40> morseArray;//
	vector<char>convertVector;
	auto i = 0;
	morseArray[0] = "This is a placeholder for my own sanity.";

	while (!tableFile.eof())//maybe thread
	{
		i++;
	BSTNode<T> * Node = new BSTNode<T>;//make this a function
		getline(tableFile, morseArray[i]);//reads whole line.
		morseArray[i].erase(remove_if(morseArray[i].begin(), morseArray[i].end(), isspace), morseArray[i].end());//removes whitespace and then shrinks string length(sourced from Stack Overflow).Remove_if removes predicate value and shuffles data around and returns a pointer to where the end should be.
		Node->setData(morseArray[i][0]);//Reads first character in each string.
		Node->setString(morseArray[i].substr(1, string::npos));//reads morse characters excluding alpha characters.
		insert(Node);
	}
	while (!inputFile.eof)//reads input string
	{
		string temp;
		getline(inputFile, temp);
		for (auto j = 0; j < temp.length(); j++)
		{
			convertVector.push_back(temp[j]);
		}
	}
	//std::thread mLoop(threadedMorseLoop, morseArray, tableFile);
	//std::thread iLoop(threadedInputLoop, convertVector, inputFile);//why do you fail
	//mLoop.join();
	//iLoop.join();


}

template<class T>
void BSTList<T>::BSTPrint()
{
	BSTPrint(this->rootNode);
}

template<class T>
BSTNode<T>*& BSTList<T>::getRoot()
{
	return rootNode;
}

template<class T>
void BSTList<T>::setRoot(BSTNode<T>* const newRoot)
{
	rootNode = newRoot;
}

template<class T>
void BSTList<T>::insert(BSTNode<T> Node)
{
	insert(this->rootNode, Node);
}

template<class T>
void BSTList<T>::threadedMorseLoop(array<string, 40> &morseArray, std::ifstream &tableFile)
{
	auto i = 0;
	while (!tableFile.eof())//maybe thread
	{
		i++;
		BSTNode<T>* Node = new BSTNode<T>;
		getline(tableFile, morseArray[i]);//reads whole line.
		morseArray[i].erase(remove_if(morseArray[i].begin(), morseArray[i].end(), isspace), morseArray[i].end());//removes whitespace and then shrinks string length(sourced from Stack Overflow).Remove_if removes predicate value and shuffles data around and returns a pointer to where the end should be.
		Node->setData(morseArray[i][0]);//Reads first character in each string.
		Node->setString(morseArray[i].substr(1, string::npos));//reads morse characters excluding alpha characters.
		insert(Node);
	}
}

template<class T>
void BSTList<T>::threadedInputLoop(vector<char> &convertVector, std::ifstream &inputFile) const
{
	while (!inputFile.eof)//reads input string
	{
		string temp;
		getline(inputFile, temp);
		for (auto j = 0; j < temp.length(); j++)
		{
			convertVector.push_back(temp[j]);
		}
	}
}

template<class T>
void BSTList<T>::insert(BSTNode<T>*& rootNode, BSTNode<T> Node)
{
	if (rootNode == nullptr)
	{
		rootNode = Node;
	}
	else if (Node.data < rootNode->data)
	{
		insert(rootNode->getLeft(), Node);
	}
	else if (Node.data > rootNode->data)
	{
		insert(rootNode->getRight(), Node);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}

template<class T>
void BSTList<T>::BSTPrint(BSTNode<T>* &rootNode)
{
	if (rootNode != nullptr)
	{
		BSTPrint(rootNode->getLeft());
		cout << rootNode->getData();
		BSTPrint(rootNode->getRight());

	}
}
