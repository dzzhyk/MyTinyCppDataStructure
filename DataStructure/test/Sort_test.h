//
//  Sort_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/12/12.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef Sort_test_h
#define Sort_test_h
#include <iostream>
#include <cstdlib>
#include "../implements/MySort.h"
#include <random>
#include <ctime>
#include <cstring>
#define N 10000

void Sort_test(){
    double a[N];
    srand(time(NULL));
    memset(a, 0, sizeof(a));
    for (int i=0; i < N; i++) {
        a[i] = rand()%N+1;
    }
    cout << "Original Array: \t";
    for (int i=0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    clock_t start = clock();
    // 各种查找
//    Select_Sort(a, 0, N);
//    Bubble_Sort(a, 0, N);
//    Cocktail_Sort(a, 0, N);
    
    

    clock_t end = clock();
    
    cout << "Sorted Array: \t\t";
    for (int i=0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl << "Consumed time: " << (end-start)/1000 << "ms" << endl;
}

#endif /* Sort_test_h */
