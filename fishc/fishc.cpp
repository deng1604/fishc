#include <iostream>
#include <queue>
using namespace std;

const int MAX_VERTEX = 30;      // 图的最大顶点数
const int MAX_INT = 0X7fffffff; // 无穷大

/* 无向图的邻接矩阵类 */
template <class DataType>
class MGraph
{
private:
    DataType vertex[MAX_VERTEX];     // 顶点数组 (储存顶点的编号或名字)
    int arc[MAX_VERTEX][MAX_VERTEX]; // 点和点之间的关系
    int vertexNum;                   // 顶点个数
    int arcNum;                      // 边的个数
public:
    /* 构造函数 (参数: 顶点数组, 顶点个数, 边的个数) */
    MGraph(DataType v[], int n, int e)
    {
        vertexNum = n;
        arcNum = e;
        // 1.初始化顶点数组
        for (int i = 0; i < vertexNum; i++)
        {
            vertex[i] = v[i];
        }

        // 2.初始化邻接矩阵
        for (int i = 0; i < vertexNum; i++)
        {
            for (int j = 0; j < vertexNum; j++)
            {
                arc[i][j] = 0;
            }//
        }

        // 3.依次输入每一条边依附的两个顶点的编号
        for (int i = 0; i < arcNum; i++)
        {
            int vi, vj;
            cin >> vi >> vj; // 输入边依附的两个顶点的编号 (起点和终点)
            arc[vi][vj] = 1; // 边的设置
            arc[vj][vi] = 1;
        }
    }

    /* 析构函数 (由于是静态数组, 可以不写析构函数) */
    ~MGraph() {
    }

    /* Dijkstra算法 (参数: 计算的起点) */
    void Dijkstra(int start)
    {
        // 1.初始化dist数组和path数组
        for (int i = 0; i < vertexNum; i++)
        {
            dist[i] = arc[start][i];
            if (dist[i] == MAX_INT)
            {
                path[i] = -1;
            }
            else
            {
                path[i] = start;
            }
        }

        // 2.初始化集合s
        int s[MAX_VERTEX] = { 0 }; // 将集合s初始化为0 
        s[start] = 1;              // 将顶点放入集合s (1代表在集合中, 0代表不在集合中)

        // 3.
        for (int num = 1; num < vertexNum; num++)
        {
            int min = findMinDist(dist, s, vertexNum); // 在dist数组中查找s[i]为0的最小值元素
            s[min] = 1;                                // 将新找到的重点加入集合s
            for (int i = 0; i < vertexNum; i++)
            {
                // 用已经找到的最短路径修改dist数组和path数组
                if (s[i] == 0 && dist[i] > dist[min] + arc[min][i])
                {
                    dist[i] = dist[min] + arc[min][i];
                    path[i] = min;
                }
            }
        }

        displayPath(dist, path, s, start, vertexNum); // 打印起点到各顶点的最短路径
    }
};

int main()
{
    int v[MAX_VERTEX] = { 0 };       // 顶点数组
    int vertexNum;                   // 顶点个数
    int arcNum;                      // 边的个数

    cout << "1.请输入顶点个数、边的个数: " << endl;
    cin >> vertexNum >> arcNum;
    cout << "\n2.请输入长度为" << vertexNum << "的顶点数组: " << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        cin >> v[i];
    }
    cout << "\n3.循环输入" << arcNum << "次边依附的两个顶点的编号: " << endl;

    MGraph<int> myGraph(v, vertexNum, arcNum);

    return 0;
}

/*
测试数据:
4 4
0 1 2 3
0 1
0 3
1 2
1 3
*/
