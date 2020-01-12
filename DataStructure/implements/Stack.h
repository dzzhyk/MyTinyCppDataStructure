//
//  Stack.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/3.
//  Copyright © 2019 dzzhyk. All rights reserved.
//


// 栈的数据结构


#ifndef _DZZHYK_STACK_H_
#define _DZZHYK_STACK_H_

#include <cstdlib>
#include "common.h"

template <class T>
class Node
{
public:
    T data;
    Node* next;
};

template <class T>
class Stack
{
private:
    Node<T>* top;

public:         // 外部接口
    Stack(){
        top = (Node<T>*)malloc(sizeof(Node<T>));
        top->next = nullptr;
    };
    ~Stack(){
        clear();
    }
    bool isEmpty();
    void push(T);
    T    pop();
    void reset();   // 重置
    void clear();   // 删除
    int size();
    const T& topValue();    // 栈顶元素

private:        // 内部实现
    bool isStackEmpty(Node<T>*);
    void push(Node<T>*, T data);
    T    pop(Node<T>*);
    void reset(Node<T>*);
    void clear(Node<T>*);
    int size(Node<T>*);
    const T& topValue(Node<T>*);
};

template <class T>
bool Stack<T>::isStackEmpty(Node<T>* s){
    return s->next == nullptr;
}
template <class T>
bool Stack<T>::isEmpty(){
    return isStackEmpty(top);
}


template <class T>
void Stack<T>::push(Node<T>* s, T data){
    Node<T> * cur = (Node<T>*)malloc(sizeof(Node<T>));
    cur->data = data;
    cur->next = s->next;
    s->next = cur;
}
template <class T>
void Stack<T>::push(T data){
    push(top, data);
}


template <class T>
T Stack<T>::pop(Node<T>* s){
    Node<T>* t = s->next;
    T ch = t->data;
    s->next = t->next;
    free(t);
    return ch;
}
template <class T>
T Stack<T>::pop(){
    return pop(top);
}


template <class T>
void Stack<T>::reset(Node<T>* s){
    while(!isStackEmpty(s)){
        pop(s);
    }
}
template <class T>
void Stack<T>::reset(){
    reset(top);
}


template <class T>
void Stack<T>::clear(Node<T>* s){
    reset(s);
    free(s);
}
template <class T>
void Stack<T>::clear(){
    clear(top);
}


template <class T>
int Stack<T>::size(Node<T>* s){
    int count = 0;
    Node<T>* temp = s;
    while(temp->next){
        count ++;
        temp = temp->next;
    }
    return count;
}
template <class T>
int Stack<T>::size(){
    return size(top);
}


template <class T>
const T& Stack<T>::topValue(Node<T> * s){
    Assert(!isEmpty(), "ERROR: Stack is empty");
    return top->next->data;
}
template <class T>
const T& Stack<T>::topValue(){
    return topValue(top);
}

#endif
