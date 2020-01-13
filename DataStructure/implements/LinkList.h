//
//  LinkList.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/6.
//  Copyright © 2020 dzzhyk. All rights reserved.
//


// 线性表的链式实现 - 带头结点 - 头指针指向头结点



#ifndef LinkList_h
#define LinkList_h
#include "common.h"


// 头结点类
template <class T>
class LinkNode {
public:
    LinkNode<T>* next;
    T data;
};


template <class T>
class LinkList {
private:
    LinkNode<T>* head;  // 头指针
    
public:
    
    LinkList();
    ~LinkList();
    T* getItem(T data): // 查找元素并且返回元素的指针
    void insert(T data);
    T remove(T data);
    int size();
    
};


template <class T>
LinkList<T>::LinkList(){
    head = new LinkNode<T>();
    head->next = NULL;
}


template <class T>
LinkList<T>::~LinkList(){
    LinkNode<T>* p = this->head;
    while(head->next){
        p = head;
        head = head->next;
        delete(p);
    }
    delete(head);
}


template <class T>
void LinkList<T>::insert(T data){
    LinkNode<T>* p = new LinkNode<T>();
    p->data = data;
    p->next = head->next;
    head->next = p;
}


template <class T>
T LinkList<T>::remove(T data){
    LinkNode<T>* q = head;  // q记录p的上一个指向的位置
    LinkNode<T>* p = q->next;
    T temp;
    int flag = 0;
    Assert(p!=NULL, "LinkList is Empty");   // 判断链表是否为空
    while (p) {
        if (p->data == data) {
            // 如果找到了当前的元素
            q->next = p->next;
            temp = p->data;
            flag = 1;
            delete(p);
            break;
        }
        q = p;
        p = p->next;
    }
    if (flag) {
        return temp;
    }else{
        return nullptr;
    }
}


template <class T>
int LinkList<T>::size(){
    LinkNode<T>* p = head->next;
    if (p==NULL) {return 0;}
    int cnt = 1;
    while (p->next) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

    
template <class T>
T* LinkList<T>::getItem(T data){
    LinkNode<T>* p = head->next;
    T* temp = NULL;
    if (p==NULL) {return NULL;}
    int flag = 0;
    while (p->next) {
        if (p->data == data) {
            temp = &(p->data);
            break;
        }
        p = p -> next;
    }
    return temp;
}

#endif /* LinkList_h */
