//The program use Huffman Code to encode text and decode. 
#ifndef HUFFMAN_H
#define HUFFMAN_H
using namespace std;
#include <iostream>
#include <string>
#include <list>
#include "HuffmanNode.h"
#include <queue>
#include <vector>

class HuffmanTree
{
private:
	HuffmanNode* root;
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue; 
	string codedTable[256] = { "" };
	string t, TC;
public:
	HuffmanTree() { root = new HuffmanNode(); }
	~HuffmanTree();

	void encode(string text);
	void decode(int n, string tabs, string treeCode, string code);
private:
	void clear(HuffmanNode* p);
	//encode functions:
	void encode_buildTree();
	void build_priority_queue(string text);
	void build_coded_table();
	void build_coded_table(HuffmanNode* p, string code);
	string tabsOrder();
	string tabsOrder(HuffmanNode* p);
	string codeTree();
	string codeTree( HuffmanNode* p, HuffmanNode* q);
	string codedText(string text);
	//decode functions:
	void decode_buildTree(int n,string treeCode, string tabs);
	void decode_buildTree( HuffmanNode* &p);
	string discover_the_code(string code);
};

#endif
