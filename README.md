# BinarySearchTree_Implementation
A binary search tree implemented with an iterative insert function, a recursive remove function, and a recursive remove max helper function. These files come from an assignment in my Data Structures and Algorithms class, taught by Dr. Lee S. Koh, at Texas State University. The header file was given by professor, implementation was to be (partially) filled out by the student.

These files show not only my understanding of one of the building block structures in C++, but also my ability to code and comment in a neat and concise fashion.

## Purpose

Implements basic binary searh tree functions for testing and utilization, such as:
```
bst_insert - Mutator
An iterative (to demonstrate my understanding of a BST) insert function that adds a node to the tree while retaining the sorted 
nature of a BST

bst_remove - Mutator
A recursive removal function, that locates the value that is to be removed, and removes it - calling a helper function if that 
node has two children

bst_remove_max - Mutator
A recursive removal helper function, called when removing a node with two children. The function swaps the node to be removed 
with the maximum node from its left subtree, and then removes the node from its new position 
```
