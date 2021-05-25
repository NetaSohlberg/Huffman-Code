//The program use Huffman Code to encode text and decode. 
#include "huffman.h"

HuffmanTree::~HuffmanTree()
{
	//pQueue = NULL;
	
//	delete[] codedTable;
	if (root == NULL)
		return;
	clear(root);
}

//The function encode the text, using the encode functions and print the results 
void HuffmanTree::encode(string text)
{
	build_priority_queue(text);//call 'build_priority_queue' function 
	encode_buildTree();//call 'encode_buildTree' function
	string order = tabsOrder();//call 'tabsOrder' function
	cout << order.length() << endl << order << endl;//print the tabs' number and their order in the tree
	cout << codeTree() << endl;//print the tree's code
	cout << codedText(text) << endl;//print the text's code
	clear(root);
}

//The function decode the code, using the decode functions and print the results 
void HuffmanTree::decode(int n, string tabs, string treeCode, string code)
{
	decode_buildTree(n,treeCode, tabs);//call 'decode_buildTree' function to build a tree
	cout << "The decoded string is: " << discover_the_code(code) << endl;//print the text
	clear(root);
}

//clear the tree from 'p' to the end
void HuffmanTree::clear(HuffmanNode* p)
{
	if (p->left == NULL)
	{
		for (int i = 0; i < 256; i++) codedTable[i] = "";
		t = "";
		TC = "";

		p->frequency = NULL;
		p->str = "";
		//delete p;
		return;
	}
	clear(p->left);
	clear(p->right);
	p->frequency = NULL;
	p->str = "";
	p->left = NULL;
	p->right = NULL;
	delete p;
}

//ENCODE FUNCTIONS:

//the function build a priority queue includes HuffmanNodes with the element in the text and their frequency. 
void HuffmanTree::build_priority_queue(string text)
{
	//An ezer table to count the frequency of every element
	int ezer[256] = { 0 };
	for (int i = 0; i < text.length(); i++)
		ezer[text[i]]++;
	//build a HuffmanNode for every element and push it into the pQueue
	for (int j = 0; j < 256; j++)
	{
		if (ezer[j])
		{
			string str = "";
			str += char(j);
			HuffmanNode* newNode = new HuffmanNode(str, ezer[j]);
			pQueue.push(newNode);
		}
	}
}

//the function build an Huffman Tree
void HuffmanTree::encode_buildTree()
{
	while ( pQueue.size()>1)
	{
		//take from pQueue the elemants with the lowest frequency
		HuffmanNode* left = pQueue.top();
		pQueue.pop();
		HuffmanNode* right = pQueue.top();
		pQueue.pop();
		//create a new HuffmanNode. Its sons are 'left' and 'right'a 
		HuffmanNode* newNode= new HuffmanNode(left->str+right->str,left->frequency+right->frequency);
		newNode->left = left;
		newNode->right = right;
		//push the new node into the queue
		pQueue.push(newNode);
	}
	root = (pQueue.top());
	pQueue.pop();
}

//The function use thr recursive 'build_coded_table' function to build a coded table
void HuffmanTree::build_coded_table()
{
	if (root == NULL) return;//if the tree is empty-return
	build_coded_table(root,"");
}

//This recursive function build a coded table that includes the code of every tab in the tree.
void HuffmanTree::build_coded_table(HuffmanNode* p, string code)
{
	//if p doesn't have sons- insert the code to the correct index in codedTable 
	if (p->left == NULL)
	{
		char element = p->str[0];
		codedTable[element] = code;
		return;
	}
	//if p has sons- call the function for them.   
	build_coded_table(p->left, code + "0");//add "0" to the code of the left son
	build_coded_table(p->right, code + "1");//add "1" to the code of the right son
     
}

//the function use the recursive 'tabsOrder' function to return a string with the order of the tabs in the tree
string HuffmanTree::tabsOrder()
{
	if (root == NULL) return "";//if the tree is empty-return
	return tabsOrder(root);
}

//This recursive function return a string with the order of the tabs in the tree(from left to right)
string HuffmanTree::tabsOrder(HuffmanNode* p)
{
	//if p doesn't have sons-return his str
	if (p->left == NULL)
		return p->str;
	//if p has sons- call the function for them.   
	return tabsOrder(p->left) + tabsOrder(p->right);
}

//The function use the recursive 'codeTree' function to create a code for the tree. 
string HuffmanTree::codeTree()
{
	if (root->left == NULL)//if the tree is empty-return
		return "";
	return codeTree(root, root);
}

//The function create a code for the tree. It's a recursive function 
string HuffmanTree::codeTree( HuffmanNode* p, HuffmanNode* q)
{
	//if (p == NULL) return;
	//if there aren't sons to p- return "1".
	if (p->left == NULL)
		return "1";//+codeTree(q->right,q);
	//if there are sons to p- call the function for them too
	return "0" + codeTree(p->left,p)+codeTree(p->right,p);
}

//the function encode the text, using the codedTable
string HuffmanTree::codedText(string text)
{
	string code = "";
	//call 'build_coded_table' to fill the codedTable
	build_coded_table();
	//add the code of every tab in the text
	for (int i = 0; i < text.size(); i++)
	{
		code += codedTable[text[i]];
	}
	return code;//return the code
}

//DECODE FUNCTIONS:

//The function use the recursive 'decode_buildTree' function to build a Huffman Tree
void HuffmanTree::decode_buildTree(int n,string treeCode, string tabs)
{
	if (treeCode == "" || tabs == "") return;
	root = new HuffmanNode();
	t = tabs;
	TC = treeCode;
	decode_buildTree(root);
}

/*The function get: a string of the tree's code, the order of the tabs and a pointer
and build a Huffman Tree according to them
the function return the number of nodes it arrived to*/
void HuffmanTree::decode_buildTree(HuffmanNode* &p)
{
	if (TC[0]=='1')//if  the first tab in 'TC' is '1'..
	{
		//put the first tab in the current node and return
		p->str = t[0];
		//earse the tabs in the strings that the function has already used
		t.erase(t.begin());
		TC.erase(TC.begin());
		return;
	}
	//if the first tab in 'TC' is '0'- build 2 new nodes
	p->left = new HuffmanNode();
	p->right = new HuffmanNode();
	TC.erase(TC.begin());//earse the first tab in 'TC'- we don't need it anymore
	decode_buildTree(p->left);//call the function for the left son
	decode_buildTree(p->right);//call the function for the right son
	p->str = (p->left)->str + (p->right)->str;//the str of the current node is the sum of its 2 sons' str
}

//The function get a code, decode it and return the text
string HuffmanTree::discover_the_code(string code)
{
	string text = "";
	//string::iterator it = code.begin();
	do
	{//it run from the beginning of the code to the end
		HuffmanNode* p = root;
		while (p->left != NULL)//while p doesn't arrive to an end of the tree
		{
			if (code[0] == '1')
				p = p->right;//if *it is 1- p goes right
			else p = p->left;//if *it is 0- p goes left
			code.erase(code.begin());
		}
		text += p->str;
	} while (code!="");
	return text;
}


