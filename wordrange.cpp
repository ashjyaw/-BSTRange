/*
 * AUTHOR: ASH YAW
 * 
 * HW3
 *
 * 
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "bst.h"

int main(int argc, char** argv)
{
  if(argc != 3)
  {
    throw std::invalid_argument("INPROPER NUMBER OF ARGUMENTS\n");
  }
  
  ifstream in;
  ofstream out;
  
  in.open(argv[1]);
  out.open(argv[2]);

  string command;
  char *op,*com;
  string dummy,s1,s2;
  
  BST myBST;
  
  while(getline(in,command))
  {
    if(command.length() == 0)
      continue;
    istringstream ss(command);
    com = strdup(command.c_str());
    op = strtok(com," \t");
    
    if(strcmp(op,"i") == 0)
    {
      ss >> dummy >> s1;
      myBST.insert(s1);
    }
    if(strcmp(op, "r")==0)
    {
      ss >> dummy >> s1 >> s2;
      int count = myBST.findLex(myBST.root,s1,s2);
      out << count << endl;
    } 
  }  
}