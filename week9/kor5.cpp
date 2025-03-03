#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS(vector<vector<char> > &grid, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    char target = grid[x][y];
    char replace = 'G';

    if (target == replace)
    {
        return;
    }

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    grid[x][y] = replace;
    int count = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == target)
            {
                grid[nx][ny] = replace;
                count++;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << count << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int x, y;

    cin >> x >> y;

    x--;
    y--;

    BFS(grid, x, y);
}