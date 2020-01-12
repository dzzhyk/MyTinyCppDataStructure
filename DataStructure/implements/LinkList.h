//
//  LinkList.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/6.
//  Copyright © 2020 dzzhyk. All rights reserved.
//


// 线性表的链式实现



#ifndef LinkList_h
#define LinkList_h


// 头结点类
template <class T>
class LinkNode {
public:
    T data;
};


template <class T>
class LinkList {
private:
    LinkNode<T>* head;  // 头指针
    
public:
    
    LinkList();
    ~LinkList();
    
    
};

#endif /* LinkList_h */
