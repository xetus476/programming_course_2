#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    ifstream fin("maze.txt");

    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    vector<string> maze;
    string line;

    while (getline(fin, line)) {
        if (!line.empty())
            maze.push_back(line);
    }

    fin.close();

    int n = maze.size();
    int m = maze[0].size();

    Point start, finish;
    bool foundS = false, foundF = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 's') {
                start = {i, j};
                foundS = true;
            }
            if (maze[i][j] == 'f') {
                finish = {i, j};
                foundF = true;
            }
        }
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Point>> parent(n, vector<Point>(m, {-1, -1}));

    queue<Point> ochered;
    ochered.push(start);

    visited[start.x][start.y] = true;

    bool Nashli = false;

    while(!ochered.empty()){
        Point cur = ochered.front();
        ochered.pop();

        cout << "tekus kletka  "
         << cur.x << ", " << cur.y << "" << endl;


        if(cur.x == finish.x && cur.y==finish.y){
            Nashli = true;
            break;
        }

        for(int k = 0; k< 8; k++){
            int next_x = cur.x + dx[k];
            int next_y = cur.y + dy[k];

            if(next_x >= 0 && next_x <= n && next_y >=0 && next_y <m){
                if (!visited[next_x][next_y] && (maze[next_x][next_y] == '.' ||maze[next_x][next_y] == '-' || maze[next_x][next_y] == 'f')){
                    ochered.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                    parent[next_x][next_y] = cur;
                    cout <<"("<< next_x <<" "<< next_y <<")" ;
                }
            }
        }
        cout <<endl;

    }
    if (!Nashli) {
        cout << "net puti" << endl;
        return 0;
    }

    // Восстановление пути
    Point cur = finish;

    while (!(cur.x == start.x && cur.y == start.y)) {
        Point p = parent[cur.x][cur.y];

        if (!(p.x == start.x && p.y == start.y)) {
            maze[p.x][p.y] = '*';
        }

        cur = p;
    }

    // Вывод лабиринта
    cout << "Кратчайший путь:" << endl;

    for (const auto& row : maze) {
        cout << row << endl;
    }

    return 0;


}