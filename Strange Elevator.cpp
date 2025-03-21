#include <bits/stdc++.h>
using namespace std;
int n, a, b;
struct floors
{
	int up, down, step;
	bool visit;
}fs[205];//用结构体记录每一层的移动方案和步数以及是否被调用
queue<floors> q;
int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		fs[i].up = i + tmp;//记录本层上楼到达的层数，即本层的第一种移动方案
		fs[i].down = i - tmp;//记录本层下楼到达的层数，即本层的第二种移动方案
		fs[i].step = -1;//全部初始化为-1
		fs[i].visit = false;//未被访问
	}
	fs[a].step = 0;//起点步数0
	fs[a].visit = true;//起点被调用
	q.push(fs[a]);//起点入队
	while(!q.empty())
	{
		floors a = q.front();
		q.pop();
		int u = a.up, d = a.down;
		if(u > 0 && u <= n && fs[u].visit == false)//判定该层的上楼方案是否合法并且是否被调用
		{
			fs[u].visit = true;//标记
			fs[u].step = a.step + 1;//本层的步数+1
			q.push(fs[u]);//移动后的层数入队
		}
		if(d > 0 && d <= n && fs[d].visit == false)//判定该层的下楼方案是否合法并且是否被调用
		{
			fs[d].visit = true;//标记
			fs[d].step = a.step + 1;//本层步数+1
			q.push(fs[d]);//移动后的层数入队
		}
		if(u == b || d == b) break;//结束条件
	}
	cout << fs[b].step;
	return 0;
}

//广度优先搜索参考模板
//q.push(初始)
//while(!q.empty())
//{
//	a = q.front();
//	q.pop();
//	1.枚举该步所有可达状态
//	2.判定合法
//	3.执行
//	4.q.push() 
//}
