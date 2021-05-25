
/*
Huffman Code/ Neta Sohlberg

The program use Huffman Code to encode text and decode.
*/
 
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"


int main()
{
	int choice;

	HuffmanTree* t = new HuffmanTree();
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	do
	{
		cin >> choice;
		string word;
		switch (choice)
		{
		case 1:
			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is:" << endl;
			t->encode(word);
			//delete t;
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.

			break;
		case 2:
			cout << "enter n ";
			int n;
			cin >> n;
			cout << "enter the letters ";
			string letters,code,treeCode;
			cin >> letters;
			cout << "enter the encoded structure ";
			cin >> treeCode;
			cout << "enter the encoded text ";
			cin >> code;
			t->decode(n, letters, treeCode, code);
			break;
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 

		}

	} while (choice != 3);
	return 0;
}

/*
example:
enter 1 to encode a text
enter 2 to decode a text
enter 3 to exit
1
enter the original text
hello
The encoded string is:
4
ehol
0011011
0100111110
2
enter n 4
enter the letters ehol
enter the encoded structure 0011011
enter the encoded text 0100111110
The decoded string is: hello
3
*/
