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
struct BinaTreNode
{
	T data;
	BinaTreNode<T>*left;
	BinaTreNode<T>*right;
	BinaTreNode<T>*parent;

	BinaTreNode() :left(nullptr), right(nullptr),parent(nullptr) {}
	BinaTreNode(T value) :data(value), left(nullptr), right(nullptr),parent(nullptr) {}
};