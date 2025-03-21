#include <bits/stdc++.h>
using namespace std;
int n, a, b;
struct floors
{
	int up, down, step;
	bool visit;
}fs[205];
queue<floors> q;
int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		fs[i].up = i + tmp;
		fs[i].down = i - tmp;
		fs[i].step = -1;
		fs[i].visit = false;
	}
	fs[a].step = 0;
	fs[a].visit = true;
	q.push(fs[a]);
	while(!q.empty())
	{
		floors a = q.front();
		q.pop();
		int u = a.up, d = a.down;
		if(u > 0 && u <= n && fs[u].visit == false)
		{
			fs[u].visit = true;
			fs[u].step = a.step + 1;
			q.push(fs[u]);
		}
		if(d > 0 && d <= n && fs[d].visit == false)
		{
			fs[d].visit = true;
			fs[d].step = a.step + 1;
			q.push(fs[d]);
		}
		if(u == b || d == b) break;
	}
	cout << fs[b].step;
	return 0;
}

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
