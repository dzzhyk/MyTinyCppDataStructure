//
//  GraphUD_test.h
//  DataStructure
//
//  Created by dzzhyk on 2019/12/2.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

#ifndef GraphUD_test_h
#define GraphUD_test_h
#include "../implements/GraphUD.h"

void GraphUD_test(){
    GraphUD* g = new GraphUD();
    g->BFS();
    g->DFS();
    g->djikstra(1);
    g->kruskal();
    g->checkLoop();
}
#endif /* GraphUD_test_h */
