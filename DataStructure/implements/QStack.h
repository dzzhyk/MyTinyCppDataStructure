//
//  QStack.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/4.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

// 使用两个队列实现的栈


#ifndef _DZZHYK_QSTACK_H_
#define _DZZHYK_QSTACK_H_

#include "Queue.h"
#include "common.h"

template <class T>
class QStack {
    
private:
    Queue<T>* A;     // 两个队列
    Queue<T>* B;
    
public: // 外部接口
    QStack(){
        A = new Queue<T>();
        B = new Queue<T>();
    }
    ~QStack(){
        clear();
    }
    void push(T data);
    T    pop();
    bool isEmpty();
    const T& topValue();  // 栈顶值
    int  size();
    void reset();
    void clear();
    
private:    // 内部实现
    void push(QStack<T>*, T);
    T pop(QStack<T>*);
    bool isQStackEmpty(QStack<T>*);
    const T& topValue(QStack<T>*) const;
    int size(QStack<T>*) const;
    void reset(QStack<T>*);
    void clear(QStack<T>*);
};



template <class T>
bool QStack<T>::isQStackEmpty(QStack<T>* s){
    if (s->A->isEmpty() && s->B->isEmpty()) {
        return true;
    }
    return false;
}
template <class T>
bool QStack<T>::isEmpty(){
    return isQStackEmpty(this);
}



template <class T>
void QStack<T>::push(QStack<T>* s, T data){ // 向非空队列里加入元素
    if (s->isEmpty()) { // 如果两个队列都是空的
        s->A->enQueue(data);
    }else if(s->A->isEmpty()){
        s->B->enQueue(data);
    }else{
        s->A->enQueue(data);
    }
}
template <class T>
void QStack<T>::push(T data){
    push(this, data);
}


template <class T>
T QStack<T>::pop(QStack<T>* s){
    Assert(!s->isEmpty(), "ERROR: QStack is empty");  // 如果都为空
    if (!s->A->isEmpty()) {
        while (s->A->size() != 1) {
            s->B->enQueue(s->A->deQueue());
        }
        T temp = s->A->frontValue();
        //        s->B->enQueue(s->A->deQueue());
        s->A->deQueue();
        return temp;
    }else{
        while (s->B->size() != 1) {
            s->A->enQueue(s->B->deQueue());
        }
        T temp = s->B->frontValue();
        //        s->A->enQueue(s->B->deQueue());
        s->B->deQueue();
        return temp;
    }
}
template <class T>
T QStack<T>::pop(){
    return pop(this);
}



template <class T>
const T& QStack<T>::topValue(QStack<T>* s) const {
    Assert(!s->isEmpty(), "ERROR: QStack is empty");  // 判断空
    if (!s->A->isEmpty()) {
        return s->A->endValue();
    }else{
        return s->B->endValue();
    }
    // 2019.11.05 这个地方报错的原因是s：返回了局部变量的引用，局部变量会在结束时销毁
}
template <class T>
const T& QStack<T>::topValue(){
    return topValue(this);
}


template <class T>
int QStack<T>::size(QStack<T>* s) const {
    return s->A->size() + s->B->size();
}
template <class T>
int QStack<T>::size(){
    return size(this);
}



template <class T>
void QStack<T>::reset(QStack<T>* s){
    // 重置
    s->A->reset();
    s->B->reset();
}
template <class T>
void QStack<T>::reset(){
    reset(this);
}



template <class T>
void QStack<T>::clear(QStack<T>* s){
    s->A->clear();
    s->B->clear();
}
template <class T>
void QStack<T>::clear(){
    clear(this);
}
#endif

