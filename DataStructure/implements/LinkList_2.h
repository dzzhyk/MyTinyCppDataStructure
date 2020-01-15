//
//  LinkList_2.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/14.
//  Copyright © 2020 dzzhyk. All rights reserved.
//


// 线性表的链式实现 - 不带头结点 - 头指针指向第一个元素或者为NULL


#ifndef LinkList_2_h
#define LinkList_2_h

// 头结点类
template <class T>
class LinkNode_2 {
public:
    LinkNode_2<T>* next;
    T data;
};


template <class T>
class LinkList_2 {
private:
    LinkNode_2<T>* head;  // 头指针
    
public:
    
    LinkList_2();
    ~LinkList_2();
    T* getItem(T data); // 查找元素并且返回元素的指针
    void insert(T data);
    void remove(T data);
    int size();
    
};


template <class T>
LinkList_2<T>::LinkList_2(){
    // 构造函数
    this->head = NULL;
}


template <class T>
LinkList_2<T>::~LinkList_2(){
    LinkNode_2<T>* p = this->head;
    while (head != NULL) {
        head = head->next;
        delete(p);
        p = head;
    }
}


template <class T>
T* LinkList_2<T>::getItem(T data){
    LinkNode_2<T>* p = this->head;
    T* temp = NULL;
    while(p!=NULL){
        if (p->data == data) {
            temp = &(p->data);
            break;
        }
        p = p->next;
    }
    return temp;
}


template <class T>
void LinkList_2<T>::insert(T data){
    if (this->head == NULL) {
        head = new LinkNode_2<T>();
        head->next = NULL;
        head->data = data;
    }else{
        LinkNode_2<T>* p = new LinkNode_2<T>();
        p->data = data;
        p->next = head->next;
        head->next = p;
    }
}


template <class T>
void LinkList_2<T>::remove(T data){
    int flag = 0;
    LinkNode_2<T>* p = head;
    LinkNode_2<T>* q = p; // q用来记录上一个p的信息
    while(p != NULL){
        if (p->data == data) {
            q->next = p->next;
            delete(p);
            flag = 1;
            break;
        }
        q = p;
        p = p->next;
    }
    Assert(flag, "remove elem error");
}


template <class T>
int LinkList_2<T>::size(){
    int cnt = 0;
    LinkNode_2<T>* p = this->head;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

#endif /* LinkList_2_h */
