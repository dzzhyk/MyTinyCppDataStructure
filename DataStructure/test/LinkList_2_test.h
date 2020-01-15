//
//  LinkList_2_test.h
//  DataStructure
//
//  Created by dzzhyk on 2020/1/15.
//  Copyright © 2020 dzzhyk. All rights reserved.
//

#ifndef LinkList_2_test_h
#define LinkList_2_test_h
#include "../implements/LinkList_2.h"
#include <iostream>
using namespace std;


void LinkList_2_test(){
    LinkList_2<int>* ll = new LinkList_2<int>();
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


#endif /* LinkList_2_test_h */
