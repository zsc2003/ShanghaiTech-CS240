#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

inline int read()
{
  int r, s = 0, c;
  for (; !isdigit(c = getchar()); s = c);
  for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48);
  return s ^ 45 ? r : -r;
}

const int N = 210, M = 5010;
const long long inf = 1e18 + 7;

struct edge {
  int to, next;
  long long val;
} mem[M << 1];

int head[N], cnt = 1;

inline void add(int u, int v, long long val)
{
  mem[++cnt].next = head[u];
  mem[cnt].to = v;
  mem[cnt].val = val;
  head[u] = cnt;
}

int multi_edge[N][N];
int n, m, s, t;

bool vis[N];
long long flow[N];
int pre[N]; // store the edge's number

bool bfs()
{
  // find an arguemented path
  for (int i = 1; i <= n; ++i)
    vis[i] = 0;
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  flow[s] = inf;

  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int e = head[u]; e != 0;e=mem[e].next)
    {
      int to = mem[e].to;
      if (vis[to])
        continue;
      if (mem[e].val <= 0)
        continue;
      flow[to] = min(flow[u], mem[e].val);
      pre[to] = e; // store the edge's number
      q.push(to);
      vis[to] = 1;
      if (to == t)
        return true;
    }
  }

  return false;
}

long long ans;

void update()
{
  // update the flow
  int u = t;
  while(u != s)
  {
    int id = pre[u];

    // pre_node : x
    // id : x -> u , id ^ 1 : u -> x

    mem[id].val -= flow[t];
    mem[id ^ 1].val += flow[t];

    u = mem[id ^ 1].to;
  }
  ans += flow[t];
}

int main()
{
  n = read(), m = read(), s = read(), t = read();
  int u, v, w;
  while(m--)
  {
    u = read(), v = read(), w = read();
    if (multi_edge[u][v])
      mem[multi_edge[u][v]].val += w;
    else
    {
      add(u, v, w);
      add(v, u, 0);
      multi_edge[u][v] = cnt - 1;
    }
  }


  while (bfs()) // arguemented path
    update();
  cout << ans;
  return 0;
}