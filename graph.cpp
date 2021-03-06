// graph.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include"iostream"
#include <queue>
using namespace std;


typedef int elementtype;
const int MaxVertex = 20;
int E, num, dist[MaxVertex];
bool visited[MaxVertex];


typedef struct node {
	int adjvex, data;
	struct node *nextadj;
}ednode;
typedef struct tnode {
	int verdata;
	ednode *firstadj;
}adjlink;
int CurrentVertex;       //当前顶点数

class  Graph
{
public:
	Graph();
	void Travel_DFS();
	void Travel_BFS();
	void dfs(elementtype v);
	void bfs(elementtype v,queue);
	void createadj();                //建立邻接表
	int firstadj(elementtype v);
	int nextadj(elementtype v, elementtype m);
	int numofGC();
	int Enum();
	int visit(int);
	void dijk(int, int &);
	int Key(int i);
private:
	adjlink * p;
	adjlink vertex[MaxVertex];  //顶点结点数组
};
Graph::Graph()
{
	for (int i = 0; i<MaxVertex; i++) {
		vertex[i].verdata = 0;
		vertex[i].firstadj = NULL;
	}
}
int Graph::visit(int v)
{
	num = vertex[v].verdata;
	cout << num;
	return 0;
}
void Graph::Travel_DFS()
{
	int i;
	for (i = 0; i < MaxVertex; i++) {
		visited[i] = false;
	}
	for (i = 0; i < CurrentVertex; i++) {
		if (visited[i] == false) {
			dfs(i);
		}
	}
}
void Graph::Travel_BFS()
{
	int i;
	for (i = 0; i < MaxVertex; i++) {
		visited[i] = false;
	}
	for (i = 0; i < CurrentVertex; i++) {
		if (visited[i] == false) {
			dfs(i);
		}
	}
}
void Graph::dfs(elementtype v)
{
	int w;
	visited[v] = true;
	w = firstadj(v);
	while (w != -1) {
		E++;
		if (visited[w] == false)
			dfs(v);
		w = nextadj(v, w);
	}
}
void Graph::bfs(elementtype v,queue Q)
{
	int w;
	visit(v);
	visited[v]=true;
	Q.append(v);
	while (!Q.empty()) {
		Q.get_front(v);
		Q.serve();
		w = firstadj(v);
		while (w != 0) {
			if (!visited[w])
			{
				visit(w);
				visited[w] = true;
				Q.append(w);
			}
			w = nextadj(v, w);
		}
	}
}
int Graph::numofGC()//无向图连通分量的个数
{
	int i;
	int k = 0;
	for (i = 0; i < MaxVertex; i++) {
		visited[i] = false;
	}
	for (i = 0; i < CurrentVertex; i++) {
		if (visited[i] = false) {
			k++;
			dfs(i);
		}
	}
	return k;
}
int Graph::Enum()//求边数
{
	int i;
	E = 0;
	for (i = 1; i <= CurrentVertex; i++) {
		visited[i] = false;
	}
	for (i = 1; i <= CurrentVertex; i++) {
		if (visited[i] = false) {
			dfs(i);
		}
	}
	return E / 2;
}
void Graph::createadj()//建立邻接表
{
	int i, j, k;
	ednode *s;
	cout << "请输入顶点数" << endl;
	cin >> CurrentVertex;                    //输入顶点个数
	cout << "请输入各顶点的值" << endl;
	for (k = 0; k < CurrentVertex; k++) {
		cin >> vertex[k].verdata;               //输入顶点序列
	}
	cout << "请输入边：i j ，i为-1时结束" << endl;
	cin >> i >> j;
	while (i != -1) {
		s = new ednode;
		s->adjvex = j;
		s->nextadj = vertex[i].firstadj;
		vertex[i].firstadj = s;          //在顶点为i的邻接表中插入顶点为j的邻接点
		s = new ednode;
		s->adjvex = i;
		s->nextadj = vertex[j].firstadj;
		vertex[j].firstadj = s;        //在顶点为j的邻接表中插入顶点为i的邻接点
		cin >> i >> j;
	}
}
int Graph::firstadj(elementtype v)//求顶点v的第一个邻接点
{
	ednode *p;
	if (v != -1) {
		p = vertex[v].firstadj;
		if (p != NULL) {
			return p->adjvex;
		}
	}
	return -1;
}
int Graph::nextadj(elementtype v, elementtype m)//求顶点v的m邻接点后的邻接点
{
	if (v != -1) {
		ednode *p = vertex[v].firstadj;
		while (p != NULL && p->adjvex != m) {
			p = p->nextadj;
		}
		if (p != NULL && p->nextadj != NULL) {
			return p->nextadj->adjvex;
		}
	}
	return  -1;
}
void Graph::dijk(int v0, int &v2)
{
	int w, q;
	ednode*s;
	for (q = 0; q < CurrentVertex - 1;) {
		//使得向下一个node进行;
		if (vertex[v0].firstadj != NULL && visited[v0] == false) {
			visited[v0] = true;
			v2++; q++;
			s = vertex[v0].firstadj;
			w = s->adjvex;
			dist[w] = v2;
			dijk(w, v2);
		}
	}
}
int Graph::Key( int i) 
{
	int k,m=0;
	for (k = 0; k < CurrentVertex; k++) {
		ednode*p = vertex[k].firstadj;
		if (p->data == i)
			m++;
		while (p->nextadj != NULL) {
			p = p->nextadj;
			if (p->data == i)
				m++;
		}
	}
	return m;
}
int main()
{
	int v,k;
	Graph G;
	G.createadj();
	G.Travel_DFS();
	G.Travel_BFS();
	G.dijk(0, v);
	G.Enum();
	cin>>k;
	G.Key(k);
	cout << "success" << endl;
	return 0;
}


