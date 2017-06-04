#pragma once
#include<iostream>

template<class T>
struct node
{
	T data;
	node<T>*next;

	node() :next(nullptr) {}
	node(T t) :data(t), next(nullptr) {}
};

template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T>*left;
	BinTreeNode<T>*right;
	BinTreeNode<T>*parent;

	BinTreeNode() :left(nullptr), right(nullptr),parent(nullptr) {}
	BinTreeNode(T value) :data(value), left(nullptr), right(nullptr),parent(nullptr) {}
};