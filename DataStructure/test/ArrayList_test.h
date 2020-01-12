//
//  ArrayList_test.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/6.
//  Copyright © 2020 dzzhyk. All rights reserved.
//

#ifndef ArrayList_test_h
#define ArrayList_test_h
#include "../implements/ArrayList.h"
#include <iostream>

void ArrayList_test(){
    ArrayList<double>* arr = new ArrayList<double>();
    std::cout << arr->size() << std::endl;
    arr->insert(111, 0);
    arr->insert(222, 1);
    arr->insert(333, 1);
    std::cout << "赋值后的顺序表：\t\t";
    for (int i=0; i<arr->size(); i++) {
        std::cout << *(arr->getItem(i)) << " ";
    }
    std::cout << std::endl;
    arr->remove(2); // 删除
    std::cout << "删除2下标元素后的顺序表：";
    for (int i=0; i<arr->size(); i++) {
        std::cout << *(arr->getItem(i)) << " ";
    }
    std::cout << std::endl;
}

#endif /* ArrayList_test_h */
