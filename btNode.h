#ifndef BT_NODE_H
#define BT_NODE_H

struct btNode
{
   int data;
   btNode* left;
   btNode* right;
};

// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree) and portArray has the base address of an array large
//       enough to hold all the data items in the binary search tree
// post: The binary search tree has been traversed in-order and the data
//       values are written (as they are encountered) to portArray in
//       increasing positional order starting from the first element
void portToArrayInOrder(btNode* bst_root, int* portArray);
void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex);

// pre:  (none)
// post: dynamic memory of all the nodes of the tree rooted at root has been
//       freed up (returned back to heap/freestore) and the tree is now empty
//       (root pointer contains the null address)
void tree_clear(btNode*& root);

// pre:  (none)
// post: # of nodes contained in tree rooted at root is returned
int bst_size(btNode* bst_root);

/////////////////////////////////////////////////////////////////////////////

// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree)
// post: If no node in the binary search tree has data equals insInt, a
//       node with data insInt has been created and inserted at the proper
//       location in the tree to maintain binary search tree property.
//       If a node with data equals insInt is found, the node's data field
//       has been overwritten with insInt; no new node has been created.
//       (Latter case seems odd but it's to mimick update of key-associated
//       data that exists in more general/real-world situations.)

void bst_insert (btNode*& bstRoot, int newInt);

// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree)
// post: If remInt was in the tree, then remInt has been removed, bst_root
//       now points to the root of the new (smaller) binary search tree,
//       and the function returns true. Otherwise, if remInt was not in the
//       tree, then the tree is unchanged, and the function returns false.

bool bst_remove (btNode*& bstRoot, int removeInt);

// pre:  bst_root is root pointer of a non-empty binary search tree
// post: The largest item in the binary search tree has been removed, and
//       bst_root now points to the root of the new (smaller) binary search
//       tree. The reference parameter, removed, has been set to a copy of
//       the removed item.

bool bst_remove_max (btNode*& cursor, btNode*& bstRoot);

#endif
