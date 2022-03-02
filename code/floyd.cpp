#include<iostream>
#include<vector>

using namespace std;

#define INF 10e5

vector <int> ans;

void floyd_algorithm (vector<vector<int>>& dst, int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dst[i][k] < INF && dst[k][j] < INF) 
          dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
      }
    }
  }
}

void print_matrix(vector<vector<int>>& dst) {

  for (int i = 0; i < dst.size(); i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < dst[i].size(); j++) {
      if (dst[i][j] == INF) 
        dst[i][j] = 0;
      cout << dst[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int n, x;
  cout << "Введите число элементов\n";
  cin >> n;
  vector <vector<int>> dst(n);
  cout << "Введите значения матрицы\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x == 0 && i != j) 
        dst[i].push_back(INF);
      else 
        dst[i].push_back(x);
    }
  }

  floyd_algorithm(dst, n);

  cout << "Матрица кратчайших путей:\n";
  print_matrix(dst);
  return 0;
}
