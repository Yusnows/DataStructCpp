#pragma once

#include<iostream>
#include"node.h"

template <class T>
class BinTree
{
public:
	BinTree();
	~BinTree();

	
private:
	BinTreeNode<T>*root;

};

template<class T>
inline BinTree<T>::BinTree()
{
	root = new BinTreeNode<T>;

}

template<class T>
inline BinTree<T>::~BinTree()
{
}
