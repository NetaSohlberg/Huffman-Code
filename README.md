# Huffman-Code

## Overview

This repository implements the **Huffman Coding** algorithm in C++. Huffman Coding is a lossless data compression technique that assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This method ensures efficient data compression by reducing the average code length used to represent the data.

## Files in the Repository

- **HuffmanNode.h**: Defines the `HuffmanNode` class, representing nodes in the Huffman tree. Each node contains a character, its frequency, and pointers to its left and right child nodes.

- **huffman.h**: Declares the `Huffman` class and its associated functions responsible for building the Huffman tree, generating Huffman codes, and encoding/decoding data.

- **huffman.cpp**: Implements the functions declared in `huffman.h`. This includes constructing the Huffman tree based on character frequencies, generating the corresponding Huffman codes, and providing methods for encoding and decoding strings.

- **main.cpp**: Contains the `main` function, serving as the entry point of the program. It demonstrates the usage of the `Huffman` class by encoding and decoding a sample string, showcasing the effectiveness of the Huffman Coding algorithm.

## How Huffman Coding Works (Step by Step)

Let's encode the word **"hello"** using Huffman Coding:

1. **Calculate Character Frequencies**
   - `h`: 1
   - `e`: 1
   - `l`: 2
   - `o`: 1

2. **Build a Min-Heap of Nodes** (smallest frequency at the top)
   - Each character is a node with its frequency.
   - Merge the two smallest nodes iteratively to form a tree.

3. **Construct the Huffman Tree**
   - Merge `h` (1) and `e` (1) → new node (2)
   - Merge `o` (1) and `l` (2) → new node (3)
   - Merge nodes (2) and (3) → root node (5)

4. **Assign Binary Codes**
   - Traverse the tree:
     - `h`: `00`
     - `e`: `01`
     - `l`: `10`
     - `o`: `11`

5. **Encode the Word "hello"**
   - `h` → `00`
   - `e` → `01`
   - `l` → `10`
   - `l` → `10`
   - `o` → `11`
   - Final Encoded Output: `0001101011`

6. **Decoding**
   - Traverse the tree using binary values to retrieve original characters.
