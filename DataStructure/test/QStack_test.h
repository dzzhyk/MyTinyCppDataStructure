//
//  QStack_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/4.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _QSTACK_TEST_
#define _QSTACK_TEST_

#include <iostream>
#include "../implements/QStack.h"
using namespace std;

void QStack_test(){
    // 新建一个QStack
    QStack<char>* s = new QStack<char>();
    s->push('a');
    s->push('b');
    s->push('c');
    cout << s->size() << endl;
    while (!s->isEmpty()) {
        cout << s->pop() << endl;
    }
    s->push('d');
    s->push('e');
    s->push('f');
    cout << "栈顶d元素：" << s->topValue() << endl;
    s->reset();
    cout << "经过reset之后，s的size：" << s->size() << endl;
}
#endif
