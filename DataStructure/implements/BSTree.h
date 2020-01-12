//
//  BSTree.h
//  DataStructure
//
//  Created by dzzhyk on 2019/12/3.
//  Copyright © 2019 dzzhyk. All rights reserved.



// 二叉查找树的实现头文件
// 二叉树的操作中有很多重载操作，分开了内部和外部的接口



#ifndef _DZZHYK_BSTREE_H_
#define _DZZHYK_BSTREE_H_

#include <iostream>
#include <iomanip>
using namespace std;

// BST节点
template <class T>
class BSTNode
{
public:

	T data;
	BSTNode * left;
	BSTNode * right;
	BSTNode * parent;

	BSTNode(T value, BSTNode* l, BSTNode* r, BSTNode* p):
		data(value), parent(p), left(l), right(r){}
	
};

// BST
template <class T>
class BSTree
{
private:
	BSTNode<T>* mRoot;	// 根节点

public:
	// 外部调用接口
    BSTree<T>(){};
    ~BSTree<T>(){};

	// 三种遍历方式
	void preOrder();
	void midOrder();
	void postOrder();

	// 两种节点查找方法
	BSTNode<T>* Search(T key);
	BSTNode<T>* iterSearch(T key);

	// 查找最大最小节点 返回键值
	T maximum();
	T minimum();


	// 查找x的后继和前驱节点
	BSTNode<T>* successor(BSTNode<T> *x);
	BSTNode<T>* predecessor(BSTNode<T> *x);

	// 插入节点到二叉树中
	void insert(T key);

	// 删除节点的值
	void remove(T key);

	// 销毁二叉树
	void destroy();

	// 打印二叉树
	void print();

private:
	// 内部实现方法
	void preOrder(BSTNode<T>* tree) const;
	void midOrder(BSTNode<T>* tree) const;
	void postOrder(BSTNode<T>* tree) const;

	BSTNode<T>* Search(BSTNode<T>* x, T key) const;
	BSTNode<T>* iterSearch(BSTNode<T>* x, T key) const;

	BSTNode<T>* maximum(BSTNode<T>* tree);
	BSTNode<T>* minimum(BSTNode<T>* tree);

	// 将节点z插入到二叉树tree中
	void insert(BSTNode<T>* &tree, BSTNode<T> *z);

	// 删除二叉树tree中的节点z
	BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);

	// 打印二叉树
	void print(BSTNode<T>* tree, T key, int direction);

    // 销毁二叉树
    void destroy(BSTNode<T>* &tree);
	
};

// 二叉树的实现
template <class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const {
    if (tree)
    {
        cout << tree->data << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
template <class T>
void BSTree<T>::preOrder(){
    preOrder(mRoot);
}

template <class T>
void BSTree<T>::midOrder(BSTNode<T>* tree) const {
    if (tree) {
        midOrder(tree->left);
        cout << tree->data << " ";
        midOrder(tree->right);
    }
}
template <class T>
void BSTree<T>::midOrder(){
    midOrder(mRoot);
}

template <class T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << " ";
    }
}
template <class T>
void BSTree<T>::postOrder(){
    postOrder(mRoot);
}


// 查找的两种实现
// 1. 非递归实现
template <class T>
BSTNode<T>* BSTree<T>::Search(BSTNode<T>* tree, T key) const {
    while (tree && tree->data != key) {
        if (tree->data > key) {
            tree = tree->left;
        }else{
            tree = tree->right;
        }
    }
    return tree;
}
template <class T>
BSTNode<T>* BSTree<T>::Search(T key){
    return Search(mRoot, key);
}

// 2. 递归实现
template <class T>
BSTNode<T>* BSTree<T>::iterSearch(BSTNode<T>* tree, T key) const {
    if (!tree || tree->data == key) {
        return tree;
    }
    if (tree->data < key) {
        return Search(tree->right, key);
    }
    if (tree->data > key) {
        return Search(tree->left, key);
    }
    return nullptr;
}
template <class T>
BSTNode<T>* BSTree<T>::iterSearch(T key){
    return Search(mRoot, key);
}

// 查找最大值和最小值
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T> *tree){
    // 注意判空
    if (!tree) {
        return nullptr;
    }
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}
template <class T>
T BSTree<T>::maximum(){
    BSTNode<T>* p = maximum(mRoot);
    if (p) {
        return p->data;
    }else{
        return NULL;
    }
}

template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T> *tree){
    // 注意判空
    if (!tree) {
        return nullptr;
    }
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}
template <class T>
T BSTree<T>::minimum(){
    BSTNode<T>* p = minimum(mRoot);
    if (p) {
        return p->data;
    }else{
        return NULL;
    }
}

// 寻找当前节点的前驱和后继, 返回节点的指针
/*
 注意：
 1. 节点的前驱是比当前节点小的节点中最大的一个
 2. 节点的后继是比当前节点大的节点中最小的d一个
 */
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x){  // 前驱
    if (!x) {
        cout << "null" << endl;
        return nullptr;
    }
    if (x->left) {
        return maximum(x->left);
    }
    BSTNode<T>* p = x->parent;
    while (p && (x==p->left)) {
        x = p;
        p = p->parent;
    }
    return p;
}

template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x){    // 后继
    if (!x) {
        cout << "null" << endl;
        return nullptr;
    }
    if (x->right) { // 如果x存在右节点
        return minimum(x->right);
    }
    // 如果x没有右节点，有两种情况
    // 1. x是左儿子if
    // 2. x是右儿子
    BSTNode<T>* p = x->parent;
    while(p && (x==p->right)){  // 如果x是右儿子的情况
        x = p;
        p = p->parent;
    }
    return p;
}

// 插入节点z
template <class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T> *z){
    BSTNode<T>* x = tree;
    BSTNode<T>* y = nullptr;
    // 查找z的插入位置
    while(x){
        y = x;
        if (x->data > z->data) {
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if (!y) {
        tree = z;
    }else if (y->data > z->data) {
        y->left = z;
    }else{
        y->right = z;
    }
}
template <class T>
void BSTree<T>::insert(T key){
    BSTNode<T>* z;
    // 如果节点创建失败就返回
    if ((z = new BSTNode<T>(key, nullptr, nullptr, nullptr)) == NULL) {
        return;
    }
    insert(mRoot, z);
}

// 删除二叉树中的节点
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T> *&tree, BSTNode<T> *z){    // 将要删除的节点从树上取下并且返回
    
    BSTNode<T> *x=NULL;
    BSTNode<T> *y=NULL;
    
    if ((z->left == NULL) || (z->right == NULL) )
        y = z;
    else
        y = successor(z);
    
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    
    if (x != NULL)
        x->parent = y->parent;
    
    if (y->parent == NULL)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    if (y != z)
        z->data = y->data;
    
    return y;
}
template <class T>
void BSTree<T>::remove(T key){
    BSTNode<T> *z, *node;
    if ((z = iterSearch(mRoot, key)) != nullptr) {    // 如果确实找到了key值,将这个节点传递给z
        if ((node = remove(mRoot, z)) != nullptr) {  // 如果确实返回了要删除的节点
            delete node;    // 删除节点
        }
    }
}

// 打印二叉树
template <class T>
void BSTree<T>::print(BSTNode<T> *tree, T key, int direction){
    if (tree) {
        if (direction == 0) {
            cout << setw(2) << tree->data << " is root" << endl;
        }else{
            cout << setw(2) << tree->data << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;
        }
        print(tree->left, tree->data, -1);
        print(tree->right, tree->data, 1);
    }
}
template <class T>
void BSTree<T>::print(){
    if (mRoot != nullptr) {
        print(mRoot, mRoot->data, 0);
    }
}

// 销毁二叉树
template <class T>
void BSTree<T>::destroy(BSTNode<T>* &tree){
    if (tree == nullptr) {
        return;
    }
    if (tree->left) {
        return destroy(tree->left);
    }
    if (tree->right) {
        return destroy(tree->right);
    }
    delete tree;
    tree = nullptr;
}
template <class T>
void BSTree<T>::destroy(){
    destroy(mRoot);
}

#endif
