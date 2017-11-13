#include <bits/stdc++.h>

using  namespace std;

bool outOfBounds(int x, int y, int n, int m){
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void printSpiral(vector< vector<int> >& mat, int x, int y){

    cout << mat[x][y] << " ";
    int cnt = 1;
    x--;
    if(x >= 0) {
        cout << mat[x][y] << " ";
        cnt++;
    }
    int n = static_cast<int>(mat.size());
    int m = static_cast<int>(mat[0].size());
    int multi = 1;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};
    while(cnt < n*m){

        int sizes[] = {2*multi-1, 2*multi, 2*multi, 2*multi+1};
        multi++;
        for(int sizes_i = 0; sizes_i < 4; sizes_i++){

            for(int k = 0; k < sizes[sizes_i]; k++){

                x = x + dx[sizes_i];
                y = y + dy[sizes_i];
                if(!outOfBounds(x, y, n, m)){
                    cout << mat[x][y] << " ";
                    cnt++;
                }
            }
        }
    }
}

int main() {

    srand(static_cast<unsigned int>(time(NULL)));

    int n, m;
    n = rand()%10 + 1;
    m = rand()%10 + 1;
    vector< vector<int> > mat;
    mat.resize(n);
    cout << n << " " << m << endl;
    for(int i = 0; i < n; i++){
        mat[i].resize(m);
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%10;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int x, y;
    x = rand()%n;
    y = rand()%m;
    cout << x << " " << y << endl;

    printSpiral(mat, x, y);


    return 0;
}