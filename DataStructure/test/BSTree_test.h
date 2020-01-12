//
//  BSTree_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/11/3.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef _BSTREE_TEST_
#define _BSTREE_TEST_

#include <iostream>
#include "../implements/BSTree.h"
using namespace std;

int a[7] = {3, 6, 2, 1, 4, 7, 11};

void BSTree_test() {
    
    BSTree<int>* bst = new BSTree<int>();
    for (int i = 0; i < 7; i++) {
        bst->insert(a[i]);
    }
    bst->preOrder();
    cout << endl;
    bst->midOrder();
    cout << endl;
    bst->postOrder();
    cout << endl;
    bst->print();
    cout << "最大值：" << bst->maximum() << endl;
    cout << "最小值：" << bst->minimum() << endl;
    
    cout << "在bst中查找：" << endl;
    int a;
    cin >> a;
    BSTNode<int>* p = bst->iterSearch(a);
    if (p) {
        cout << "在BST中找到了：" << p->data << endl;
        BSTNode<int>* l = bst->predecessor(p);
        BSTNode<int>* r = bst->successor(p);
        if(l) cout << a << "的前驱是：" << l->data << endl;
        if(r) cout << a << "的后继是：" << r->data << endl;
        // 接下来在BST中删除a值
        bst->remove(a);
        // 重新打印二叉树
        bst->print();
    }
    else{
        cout << "没有找到" << a << endl;
    }
    
    // 销毁二叉树
    bst->destroy();
}
#endif
