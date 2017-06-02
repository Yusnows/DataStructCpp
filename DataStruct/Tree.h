#pragma once

#include<iostream>
#include"node.h"

template <class T>
class BinaTree
{
public:
	BinaTree();
	~BinaTree();

	
private:
	BinaTreeNode<T>*root;

};

template<class T>
inline BinaTree<T>::BinaTree()
{
	root = new BinaTreeNode<T>;

}

template<class T>
inline BinaTree<T>::~BinaTree()
{
}
