//
//  ArrayList.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/6.
//  Copyright © 2020 dzzhyk. All rights reserved.
//

// 线性表的顺序表实现

#ifndef ArrayList_h
#define ArrayList_h
#define MAXN 10000
#include <cstdlib>
#include "common.h"

template <class T>
class ArrayList{
private:
    T table[MAXN];   // 数组的头指针
    int length; // 当前长度
public:
    
    ArrayList();
    ~ArrayList(){};
    T* getItem(int pos);    // 返回元素指针
    int size();
    void insert(T data, int pos);   // 插入
    void remove(int pos);   // 删除
    
};

template <class T>
ArrayList<T>::ArrayList(){
    this->length = 0;   // 初始有效长度为0
}

template <class T>
void ArrayList<T>::insert(T data, int pos){
    Assert((pos>=0 && pos<=length), "out of index");  // i不在可插入范围内
    Assert(length!=MAXN, "ArrayList is full");  // 顺序表已满
    for (int i=length; i>=pos+1; i--) {
        table[i] = table[i-1];
    }
    table[pos] = data;
    length++;
}


template <class T>
void ArrayList<T>::remove(int pos){
    Assert((pos>=0 && pos<length), "out of index");
    Assert(length!=0, "ArrayList is empty");
    for (int i=pos; i<length; i++) {
        table[i] = table[i+1];
    }
    length--;
}


template <class T>
T* ArrayList<T>::getItem(int pos){
    Assert((pos>=0 && pos<length), "out of index");
    Assert(length!=0, "ArrayList is empty");
    T* p = &table[pos];
    return p;
}

template <class T>
int ArrayList<T>::size(){
    return this->length;
}
#endif /* ArrayList_h */
