# Huffman-Code

## Overview

This repository implements the **Huffman Coding** algorithm in C++. Huffman Coding is a lossless data compression technique that assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This method ensures efficient data compression by reducing the average code length used to represent the data.

## Files in the Repository

- **HuffmanNode.h**: Defines the `HuffmanNode` class, representing nodes in the Huffman tree. Each node contains a character, its frequency, and pointers to its left and right child nodes.

- **huffman.h**: Declares the `Huffman` class and its associated functions responsible for building the Huffman tree, generating Huffman codes, and encoding/decoding data.

- **huffman.cpp**: Implements the functions declared in `huffman.h`. This includes constructing the Huffman tree based on character frequencies, generating the corresponding Huffman codes, and providing methods for encoding and decoding strings.

- **main.cpp**: Contains the `main` function, serving as the entry point of the program. It demonstrates the usage of the `Huffman` class by encoding and decoding a sample string, showcasing the effectiveness of the Huffman Coding algorithm.

## How Huffman Coding Works (Step by Step)

Huffman coding follows these steps to build an optimal prefix-free encoding scheme. If two nodes have the same frequency, they are ordered alphabetically.

### Example: Encoding "hello"

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

The Huffman tree is built iteratively by merging the two least frequent nodes at each step until a single root node remains. Below is a step-by-step ASCII illustration of how the tree for "hello" is constructed.

a. **Start with individual nodes sorted by frequency (Alphabetical order in case of ties):**
```
   e(1)   h(1)   o(1)   l(2)
```

b. **Merge the two smallest nodes (`e` and `h`)**:
```
     (2)
    /   \
  e(1)  h(1)   o(1)   l(2)
```

c. **Merge `o(1)` with `l(2)`, creating a new node (3):**
```
     (2)        (3)
    /   \      /   \
  e(1)  h(1) o(1) l(2)
```

d. **Merge the two remaining nodes (2 and 3) to create the root node (5):**
```
           (5)
       /        \
     (2)        (3)
    /   \      /   \
  e(1)  h(1) o(1) l(2)
```

Each left branch represents a `0`, and each right branch represents a `1`. This means:
   - `e` → `00`
   - `h` → `01`
   - `o` → `10`
   - `l` → `11`

These binary codes are assigned based on the tree structure by following the path from the root to each leaf node.

4. **Encode the Word "hello"**
   - `h` → `01`
   - `e` → `00`
   - `l` → `11`
   - `l` → `11`
   - `o` → `10`
   - Final Encoded Output: `0100111110`

7. **Encoding Parameters**
     - `n = 4` (number of unique characters)
     - `Letters = ehol` (order of characters in encoding)
     - `Encoded Structure = 0011011` (tree structure)
     - `Encoded Text = 0100111110` (Huffman encoded word)

8. **Decoding**
   - Traverse the tree using binary values to retrieve original characters.
