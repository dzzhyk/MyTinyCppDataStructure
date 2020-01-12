//
//  GraphUD.h
//  DataStructure
//
//  Created by dzzhyk on 2019/12/2.
//  Copyright © 2019 dzzhyk. All rights reserved.
//

// 使用邻接矩阵构建无向图

#ifndef GraphUD_h
#define GraphUD_h
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAXN 100
#define INF 0x3f3f3f3f
using namespace std;

typedef struct _edge { int u, v, cost;}edge;

bool edge_comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

class GraphUD {
private:
    
    int degree[MAXN];
    edge G[MAXN];   // 边集
    int V;  // 顶点数
    int E;  // 边数
    int mp[MAXN+1][MAXN+1]; //邻接矩阵
    
public:
    GraphUD();
    ~GraphUD(){};
    void DFS();
    void BFS();
    void djikstra(int start);        // 单源最短路
    void kruskal();         // 最小生成树
    void checkLoop();       // 判断是否存在环
    void EularLoop();       // 欧拉回路
    
private:
    void DFS_iter(int i, int* visited);
    bool checkLoop_iter(int v, int* visited, int* father, bool flag);
};
// 并查集模板

int par[MAXN];
int _rank[MAXN];

// 初始化n个元素
void init(int n){
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        _rank[i] = 0;
    }
}

// 查询树的根
int find(int x){
    if (par[x] == x)
    {
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

// 合并x和y所属的集合
void join(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (_rank[x] < _rank[y])
    {
        par[x] = y;
    }else{
        par[y] = x;
        if (_rank[x] == _rank[y]) _rank[x]++;
    }
}

// 判断x和y是否属于同一个集合
bool same(int x, int y){
    return find(x)==find(y);
}

GraphUD::GraphUD(){
    // 创建一个图
    // 初始化
    V = E = 0;
    memset(degree, 0, sizeof(degree));
    for (int i=1; i <= MAXN; i++) {
        for (int j=1; j <= MAXN; j++) {
            mp[i][j] = INF;
        }
        G[i] = {0, 0, 0};
    }
    cin >> V >> E;
    int tempS, tempE, tempW;
    for (int i=1; i<=E; i++) {
        cin >> tempS >> tempE >> tempW;
        mp[tempS][tempE] = tempW;
        mp[tempE][tempS] = tempW;
        G[i] = {tempS, tempE, tempW};
        degree[tempS]++;
        degree[tempE]++;
    }
}

void GraphUD::DFS(){
    int visited[MAXN+1];
    memset(visited, 0, sizeof(visited));
//    cout << "DFS结果：";
    for (int i=1; i <= V; i++) {
        if (!visited[i]) {
            DFS_iter(i, visited);
        }
    }
    cout << endl;
}

void GraphUD::DFS_iter(int i, int *visited){
    visited[i] = 1; // 标记已经访问了
    cout << i << " ";
    for (int j=1; j<=V; j++) {
        if (mp[i][j]!=INF && !visited[j]) {
            DFS_iter(j, visited);
        }
    }
}

void GraphUD::BFS(){
    queue<int> q;   // 创建节点队列
    int visited[MAXN];
    memset(visited, 0, sizeof(visited));
//    cout << "BFS结果：";
    
    q.push(1);  // 先将节点1加入队列
    visited[1] = 1; // 节点1已经遍历过了
    while (!q.empty()) {    // 如果队列不为空
        for (int i=1; i<=V; i++) {
            if (mp[q.front()][i]!=INF && !visited[i]) { // 如果还有节点i没有遍历到
                visited[i] = 1;
                q.push(i);
            }
        }
        if (q.size()==1) {
            cout << q.front();
        }else{
            cout << q.front() << " ";
        }
        q.pop();
    }
    cout << endl;
}

void GraphUD::djikstra(int start){
    int dis[MAXN], used[MAXN];
    memset(dis, 0, sizeof(dis));
    memset(used, 0, sizeof(used));
    used[start] = 1;
    // 初始化dis
    for (int i=1; i<=V; i++) {
        dis[i] = mp[start][i];
        if (i==start) {
            dis[i] = 0;
        }
    }
    for (int i=1; i<=V; i++) {
        int min = INF, pos=-1;
        for (int j=1; j<=V; j++) {
            if (used[j]==0 && dis[j]<min) {
                min = dis[j];
                pos = j;
            }
        }
        used[pos] = 1;
        for (int j=1; j<=V; j++) {
            if (mp[j][pos]>0 && used[j]==0 && dis[j]>min+mp[j][pos]) {
                dis[j] = min + mp[j][pos];
            }
        }
    }
//    cout << "Shortest Path from "<< start <<" to " << end << " is: " << dis[end] << endl;
    for (int i=2; i <= V; i++) {
        cout << start << " " << i << " " << dis[i] << endl;
    }
}

void GraphUD::kruskal(){
    sort(G+1, G+E+1, edge_comp);    // 按照边权从大到小排序边集
    init(V);    // 初始化并查集
    int res = 0;
//    cout << "Minimum-Cost Spanning Tree: " << endl;
    for (int i=1; i <= E; i++) {
        edge e = G[i];
        if (!same(e.u, e.v)) {
            join(e.u, e.v);
            res += e.cost;
            cout << e.u << " " << e.v << " " << e.cost << endl;
        }
    }
//    cout << "Total cost: " << res << endl;
}


void GraphUD::checkLoop(){
    // 利用dfs
    int visited[MAXN], father[MAXN];    // 记录是否访问k和该节点的父节点
    memset(visited, 0, sizeof(visited));
    memset(father, -1, sizeof(father));
    bool flag = false;
    for (int i=1; i <= V; i++) {
        if (!visited[i]) {
            flag = checkLoop_iter(i, visited, father, false);
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

bool GraphUD::checkLoop_iter(int v, int *visited, int* father, bool flag){
    visited[v] = 1;
    for (int i=1; i <= V; i++) {
        if (i!=v && mp[v][i]!=INF) {
            if(visited[i] == 1 && father[v] != i)   //vi不是父节点，而且还访问过(而且为状态1，说明不是回溯过来的顶点)，说明存在环(判断i不是v的父节点)
            {
                return true;
//                int temp = v;
//                while(temp != i)
//                {
//                    cout<<temp<<"<-";//输出环
//                    temp = father[temp];
//                }
//                cout<<temp<<endl;
            }else{
                if(visited[i] == 0)
                {
                    father[i] = v;  //更新father数组
                    return checkLoop_iter(i, visited, father, flag);
                }
            }
        }
    }
    visited[v] = 2;
    return false;
}


void GraphUD::EularLoop(){
    init(E); // 初始化并查集
    for (int i=1; i<=E; i++) {
        join(G[i].u, G[i].v);
    }
    int cnt=0;//记录连通分量
    cout << "EularLoop: ";
    for(int i=1;i<=V;i++)
        if(find(i)==i)
            cnt++;
    if(cnt!=1)//若cnt大于1，说明图不连通
        cout << "NO" << endl;
    else{
        int num=0;//统计度数为奇数的点
        for(int i=1;i<=V;i++)
            if(degree[i]&1)
                num++;
        if(num==0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
#endif /* GraphUD_h */
