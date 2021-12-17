/*
 * AUTHOR: Ash Yaw
 * 
 * FILE: bst.cpp
 * 
 */

#include "bst.h"
#include <iostream>
#include <string>
#include <fstream>

BST::BST()
{
  root = NULL;
}

void BST::insert(string word) 
{
  Node *toAdd = new Node(word);
  if(root == NULL) // if there is no root make it our word
  {
    root = toAdd;
  }
  else // otherwise insert under the bst properties
  {
    insert(root, toAdd);
  }
}

void BST::insert(Node* rt, Node* toAdd)
{
  if(rt == NULL) // if we have no root return
    return;
  if(toAdd->key <= rt->key) // this is to insert on the leftside of the tree
  {
    if(rt->left == NULL)
    {
      rt->left = toAdd;
      toAdd->parent = rt;
      return;
    }
    else// continue to go down the left tree
    {
        insert(rt->left, toAdd);
        return;
    }
  }
  else // this is to go down the rightside of the tree
  {
    if(rt->right == NULL)
      {
        rt->right = toAdd;
        toAdd->parent = rt;
      }
    else // head down right side
    {
        insert(rt->right, toAdd);
        return;
    }
  }
  
} 

int BST::findLex(Node* start, string s1, string s2)
{
  if(start == NULL) // error handling
    return 0;
  
  if(start->key >= s1 && start->key <= s2) // if its inside our range
    return 1 + findLex(start->left,s1,s2) + findLex(start->right,s1,s2); // add 1 to the count and traverse the whole tree
  
  else if(start->key < s1) // basically if the current key is smaller then s1 this doesnt satisfy our standards to traverse right
    return findLex(start->right,s1,s2);
  
  else
    return findLex(start->left,s1,s2); // traverse left otherwise

}
