#include "btNode.h"

// Parameters: Root node of a BST, and an integer to be added to the tree
void bst_insert (btNode*& bstRoot, int newInt){
//Pre:  (none)
//Post: Given integer has been added to the tree, maintaining the sorted
//      nature of a BST

    //newNode to be added to the tree, with newInt as the data, and no children
    btNode* newNode = new btNode;
    newNode->data = newInt;
    newNode->left = 0;
    newNode->right = 0;


    //Creates a cursor and precursor to traverse through the tree
    btNode* cursor = bstRoot;

    //Empty tree, new node becomes root
    if (bstRoot == 0){
        bstRoot = newNode;
        return;
    }

    //Find where to insert newNode, and insert it
    while (cursor!=0){

        //newInt is greater than current node's, look to the right
        if (newInt > cursor->data){

            //Empty right child
            if (cursor->right == 0){
                //Right child is now newNode
                cursor->right = newNode;
                break;
            }
            //Non empty right child, traverse right
            else{cursor = cursor->right;}
       }
       //newInt is less than current node's, look to the left
       else if (newInt < cursor->data){

            //Empty left child
            if (cursor->left == 0){
                //Left child is now newNode
                cursor->left = newNode;
                break;
            }
            //Non empty left child, traverse left
            else{cursor = cursor->left;}
       }
       //newInt is equal to current node's
       else{
            //Overwrite the data field with newInt
            cursor->data = newInt;

            //Delete our previously created newNode
            delete newNode;
            break;
       }

    }

}

// Parameters: Root node of a BST, and an integer to be removed from the tree
bool bst_remove (btNode*& bstRoot, int removeInt){
//Pre:  (none)
//Post: Returns true if the integer given was in the tree and has been removed
    
    //If tree is empty
    if (bstRoot == 0){return false;}

    //If removeInt is greater than current node traverse right
    else if(bstRoot->data < removeInt){return bst_remove (bstRoot->right, removeInt);}

    //If removeInt is less than current node traverse left
    else if(bstRoot->data > removeInt){return bst_remove (bstRoot->left, removeInt);}

    //If removeInt is equal to current node
    else{
        //Has no children or only one child
        if (bstRoot->left == 0 || bstRoot->right == 0){
            //Save address of bstRoot in a temp pointer
            btNode* oldBstRoot = bstRoot;

            //No children
            if (bstRoot->left == 0 && bstRoot->right == 0){bstRoot = 0;}
            
            //Right child
            else if (bstRoot->left == 0){bstRoot = bstRoot->right;}
            
            //Left child
            else{bstRoot = bstRoot->left;}
            
            //Delete removeInt and return true
            delete oldBstRoot;
            return true;
        }


        //Has two children
        else{return bst_remove_max(bstRoot->left, bstRoot);}
    }
}

//Parameters (received from parent function bst_insert): The left subtree of a
//node that is being removed, and the address of the node itself
bool bst_remove_max (btNode*& cursor, btNode*& removeNode){
//Pre:  (none)
//Post: Returns true when the given (two child) node has been removed

    // Base case, current node is the max in its subtree
    if (cursor->right == 0){

        //Copy current node to the data field of removeNode
        removeNode->data = cursor->data;

        //Store address of the current node
        btNode* oldCursor = cursor;

        //Replace the current cursor with its left (and only) child
        cursor = cursor->left;

        //Delete the old cursor (whose data is now stored at removeNode)
        delete oldCursor;

        //Success
        return true;
    }

    //Recursive until we hit the max in this subtree
    else{return bst_remove_max(cursor->right, removeNode);}
}




//PROVIDED BY PROFESSOR - NOT OWN WORK
void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
