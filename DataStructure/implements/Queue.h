//
//  Queue.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/3.
//  Copyright © 2019 dzzhyk. All rights reserved.
//


// 栈的数据结构


#ifndef _DZZHYK_QUEUE_H
#define _DZZHYK_QUEUE_H

#include <cstdlib>
#include "common.h"

template <class T>
class QNode
{
public:
    T data;
    QNode<T> * next;
};


template <class T>
class Queue
{
private:
    int cnt;
    QNode<T> * front;
    QNode<T> * rear;
    
public: // 外部接口
    Queue(){
        cnt = 0;
        front = (QNode<T>*)malloc(sizeof(QNode<T>));
        rear = (QNode<T>*)malloc(sizeof(QNode<T>));
        front = rear = nullptr;
    }
    ~Queue(){
        clear();
    }
    bool isEmpty();
    void enQueue(T);
    T    deQueue();
    void reset();
    void clear();
    int  size(){return cnt;}
    const T&    frontValue();   // 队列首尾值
    const T&    endValue();
    
private:    // 内部实现
    bool isQueueEmpty(Queue<T>*);
    void enQueue(Queue<T>*, T ch);
    T    deQueue(Queue<T>*);
    void resetQueue(Queue<T>*);
    void clearQueue(Queue<T>*);
    const T&    frontValue(Queue<T>*) const;
    const T&    endValue(Queue<T>*) const;
};



template <class T>
bool Queue<T>::isQueueEmpty(Queue<T> * q){
    return ((q->rear==nullptr) && (q->front==nullptr));
}
template <class T>
bool Queue<T>::isEmpty(){
    return (cnt==0 && isQueueEmpty(this));
}


template <class T>
void Queue<T>::enQueue(Queue<T> * q, T ch){
    // 如果队列一开始是空的
    if (isQueueEmpty(q))
    {
        QNode<T> * cur = (QNode<T>*)malloc(sizeof(QNode<T>));
        cur->data = ch;
        q->front = cur;
        q->rear = cur;
        cur->next = NULL;        // 无头节点队列判空的标准：rear==front并且都为NULL
    }else{
        QNode<T> * cur = (QNode<T>*)malloc(sizeof(QNode<T>));
        cur->data = ch;
        q->rear->next = cur;
        q->rear = cur;
        cur->next = NULL;
    }
}
template <class T>
void Queue<T>::enQueue(T data){
    enQueue(this, data);
    this->cnt++;
}


template <class T>
T Queue<T>::deQueue(Queue<T> * q){
    // 如果队列中只有一个元素，此时front==rear
    T ch;
    if (q->front==q->rear)
    {
        ch = q->front->data;
        free(q->front);
        q->rear = q->front = NULL;
        return ch;
    }else{
        ch = q->front->data;
        QNode<T> * t = q->front;
        q->front = q->front->next;
        free(t);
        return ch;
    }
}
template <class T>
T Queue<T>::deQueue(){
    this->cnt--;
    return deQueue(this);
}


template <class T>
void Queue<T>::resetQueue(Queue<T> *q){
    while(!isQueueEmpty(q)){
        deQueue(q);
    }
}
template <class T>
void Queue<T>::reset(){
    this->cnt = 0;
    resetQueue(this);
}


template <class T>
void Queue<T>::clearQueue(Queue<T> * q){
    if (isQueueEmpty(q))
    {
        return;
    }
    QNode<T> * p = q->front->next;
    q->rear = q->front;
    q->front->next = NULL;
    QNode<T> *t;
    while(p){
        t = p->next;
        free(p);
        p = t;
    }
    t = q->front;
    q->front = q->rear = NULL;
    free(t);
    
    /*
     // clear是把不带头节点队列内的元素完全删除掉，回归到initQueue后的状态
     QNode<T> * t;
     while(q->front){
     t = q->front;
     q->front = q->front->next;
     free(t);
     }
     */
}
template <class T>
void Queue<T>::clear(){
    clearQueue(this);
}


template <class T>
const T& Queue<T>::frontValue(Queue<T> * q) const {
    Assert(!q->isEmpty(), "ERROR: Queue is empty");
    return this->front->data;
}
template <class T>
const T& Queue<T>::frontValue(){
    return frontValue(this);
}


template <class T>
const T& Queue<T>::endValue(Queue<T> * q) const {
    Assert(!q->isEmpty(), "ERROR: Queue is empty");
    return this->rear->data;
}
template <class T>
const T& Queue<T>::endValue(){
    return endValue(this);
}

#endif
