//
//  common.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/5.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _DZZHYK_COMMON_H_
#define _DZZHYK_COMMON_H_

// 常用函数
#include <iostream>
#include <string>

void Assert(bool express, std::string s){   // 如果express表达式为假，就输出信息
    if (!express) {
        std::cout << s << std::endl;
        exit(-1);
    }
}

#endif /* common_h */

