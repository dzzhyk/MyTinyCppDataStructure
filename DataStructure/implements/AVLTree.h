//
//  AVLTree.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/8.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _DZZHYK_AVLTREE_H_
#define _DZZHYK_AVLTREE_


// AVL树


// AVL节点类
template <class T>
class AVLTreeNode {
public:
    T key;
    int height;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode(T key, AVLTreeNode* l, AVLTreeNode* r): key(key), height(0), left(l), right(r){}
};


template <class T>
class AVLTree {
private:
    AVLTreeNode<T>* mRoot;
    
public:     // 定义外部接口
    AVLTree();
    ~AVLTree();
    
    int height();
    
    int max(int a, int b);
    
    // 三种遍历
    void preOrder();
    void midOrder();
    void postOrder();
    
    // 两种查找实现方式
    AVLTreeNode<T>* Search(T key);
    AVLTreeNode<T>* iterSearch(T key);
    
    // 查找最大最小值
    T maximum();
    T minimum();
    
    void insert(T key);
    
    void remove(T key);
    
    void destroy();
    
    void print();
private:    // 内部实现
    
    int height(AVLTreeNode<T>* tree);
    
    void preOrder(AVLTreeNode<T>* tree) const;
    
    void midOrder(AVLTreeNode<T>* tree) const;
    
    void postOrder(AVLTreeNode<T>* tree) const;
    
    AVLTreeNode<T>* Search(AVLTreeNode<T>* tree, T key) const;
    AVLTreeNode<T>* iterSearch(AVLTreeNode<T>* tree, T key) const;
    
    AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);
    AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
    
    // 四种旋转
    // 左单旋转
    AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);
    // 右单旋转
    AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);
    // 左双旋转
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);
    // 右双旋转
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);
    
    // 插入
    AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);
    
    // 移除
    AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

    void destroy(AVLTreeNode<T>* tree);
    void print(AVLTreeNode<T>* tree, T key, int direction);
};


// 方法实现
// 获取树的高度
template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree){
    if (tree) {
        return tree->height;
    }
    return -1;
}
template <class T>
int AVLTree<T>::height(){
    return height(mRoot);
}


template <class T>
int AVLTree<T>::max(int a, int b){
    return a>b?a:b;
}




template <class T>
void preOrder(AVLTreeNode<T>* tree){
    
}
template <class T>
void preOrder(){
    preOrder(mRoot);
}

template <class T>
void midOrder(AVLTreeNode<T>* tree){
    
}
template <class T>
void midOrder(){
    midOrder(mRoot);
}


template <class T>
void postOrder(AVLTreeNode<T>* tree){
    
}
template <class T>
void postOrder(){
    postOrder(mRoot);
}

#endif /* AVLTree_h */
