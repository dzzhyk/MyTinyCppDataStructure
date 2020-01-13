//
//  LinkList_test.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/14.
//  Copyright © 2020 dzzhyk. All rights reserved.
//

#ifndef LinkList_test_h
#define LinkList_test_h
#include "../implements/LinkList.h"
#include <iostream>
using namespace std;


void LinkList_test(){
    LinkList<int>* ll = new LinkList<int>();
    cout << ll->size() << endl;
    ll->insert(12);
    ll->insert(11);
    ll->insert(10);
    ll->insert(14);
    cout << ll->size() << endl;
    cout << *(ll->getItem(14)) << endl;
    ll->remove(10);
//    ll->remove(10);
    cout << ll->size() << endl;
}


#endif /* LinkList_test_h */
