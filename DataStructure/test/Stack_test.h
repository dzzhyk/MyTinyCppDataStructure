//
//  Stack_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/4.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _STACK_TEST_
#define _STACK_TEST_

#include <iostream>
#include "../implements/Stack.h"
using namespace std;

void Stack_test(){
    Stack<char>* s = new Stack<char>();
    s->push('a');
    s->push('c');
    s->push('d');
    cout << "s的大小为： " << s->size() << endl;
    cout << "s的栈顶元素为：" << s->topValue() << endl;
    while (!s->isEmpty()) {
        cout << s->pop() << endl;
    }
    s->push('f');
    s->reset();
    if (s->isEmpty()) {
        cout << "经过reset之后s为空" << endl;
    }
    // 销毁
    s->clear();
}

#endif /* Stack_test_h */

