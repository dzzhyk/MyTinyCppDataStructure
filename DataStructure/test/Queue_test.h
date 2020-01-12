//
//  Queue_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/4.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _QUEUE_TEST_
#define _QUEUE_TEST_

#include <iostream>
#include "../implements/Queue.h"
using namespace std;

void Queue_test(){
    Queue<char>* q = new Queue<char>();
    q->enQueue('e');
    q->enQueue('f');
    q->enQueue('h');
    cout << "q的大小为： " << q->size() << endl;
    cout << "q的首元素为：" << q->frontValue() << endl;
    cout << "q的尾元素为：" << q->endValue() << endl;
    while (!q->isEmpty()) {
        cout << q->deQueue() << endl;
    }
    cout << endl;
    if (q->isEmpty()) {
        cout << "经过reset之后现在q是空的" << endl;
    }
    q->enQueue('d');
    q->reset();
    if (q->isEmpty()) {
        cout << "经过reset之后现在q是空的" << endl;
    }
    // 销毁
    q->clear();
}

#endif /* Queue_test_h */
