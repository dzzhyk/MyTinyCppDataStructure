//
//  MySort.h
//  DataStructure
//
//  Created by dzzhyk on 2019/12/12.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef MySort_h
#define MySort_h
// 这是实现排序算法的头文件
/*
 
 十种标准排序算法：选泡插快归堆希桶计基
 
 除此之外还有改进的排序算法：鸡尾酒排序
 
 */

// 选择排序
template <class T>
void Select_Sort(T *p, int l, int r){
    int temp;
    T b;
    for (int i = l; i < r-1; i++) {
        temp = i;
        for (int j = i+1; j < r; j++) {
            if (p[temp] > p[j]) {
                b = p[j];
                p[j] = p[temp];
                p[temp] = b;
            }
        }
    }
}


// 冒泡排序
template <class T>
void Bubble_Sort(T *p, int l, int r){
    T b;
    for (int i=l+1; i < r; i++) {
        bool flag = true;
        for (int j = l+1; j < r; j++) {
            if (p[j-1] > p[j]) {
                b = p[j-1];
                p[j-1] = p[j];
                p[j] = b;
                flag = false;
            }
        }
        if (flag) return;
    }
}



// 鸡尾酒排序 - 冒泡排序的改良
template <class T>
void Cocktail_Sort(T *p, int l, int r){
    T b;
    for (int i=l+1; i < r; i++) {
        bool flag = true;
        for (int j = l+1; j < r; j++) {
            if (p[j-1] > p[j]) {
                b = p[j-1];
                p[j-1] = p[j];
                p[j] = b;
                flag = false;
            }
        }
        if (flag) return;
        for (int j = r-2; j > l; j--) {
            if (p[j-1] > p[j]) {
                b = p[j-1];
                p[j-1] = p[j];
                p[j] = b;
                flag = false;
            }
        }
        if (flag) return;
    }
}



// 插入排序
template <class T>
void Insertion_Sort(T *p, int l, int r){
    T temp;
    
}

#endif /* MySort_h */
