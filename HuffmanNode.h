//The program use Huffman Code to encode text and decode. 
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
using namespace std;
#include <iostream>
#include <string>

class compareNode;

class HuffmanNode
{
protected:
public:
	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;

	HuffmanNode() { str = ""; left, right = NULL; }
	HuffmanNode(string s, int f) { str = s; frequency = f; left, right = NULL; }

	friend class compareNode;
};


class compareNode 
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{
		return n1->frequency > n2->frequency;
	}
};



#endif // !HUFFMANNODE

