/*
 * AUTHOR: Ash Yaw
 * 
 * FILE: bst.h
 * 
 */


#ifndef BST_H
#define BST_H

#include <string>


using namespace std;

class Node
{
  public:
    string key;
    int height;
    Node *left,*right,*parent;
    
    Node()
    {
      left = right = parent = NULL;
    }
    
    Node(string k)
    {
      key = k;
      left = right = parent = NULL;
    }

};


class BST
{    
   public:
     Node *root;
     BST();
     void insert(string);
     void insert(Node*, Node*);
     int findLex(Node*,string, string);       

};

#endif