#include <iostream>
#include<vector>

using namespace std;


void print_system(vector<vector<double>>& a, vector<double>& y, int n)
{
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++) 
    {
      cout << a[i][j] << "*x" << j + 1;
      if (j < n - 1)
        cout << " + ";
    }
    cout << " = " << y[i] << endl;
  }
  return;
}

pair<vector<double>, bool> gauss(vector<vector<double>>& a, vector<double>& y, int n)
{
  vector<double> x(n);
  double max, tmp;
  int k, index;
  const double eps = 10e-6;
  k = 0;
  while (k < n) {
    // Поиск строки с максимальным a[i][k]
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++) {
      tmp = abs(a[i][k]);
      if (tmp > max) {
        max = tmp;
        index = i;
      }
    }
    if (max < eps) {
      // нет ненулевых диагональных элементов
      cout << "Решение получить невозможно из-за нулевого столбца ";
      cout << index << " матрицы A" << endl;
      return make_pair(x, false);
    }
    
    // Перестановка строк
    for (int j = 0; j < n; j++) {
      swap(a[k][j], a[index][j]);
    }
    
    swap(y[k], y[index]);
    // Нормализация уравнений
    for (int i = k; i < n; i++) {
      tmp = a[i][k];
      if (abs(tmp) < eps) continue; // для нулевого коэффициента пропустить
      for (int j = 0; j < n; j++) 
        a[i][j] = a[i][j] / tmp;
      y[i] = y[i] / tmp;
      if (i == k)  continue; // уравнение не вычитать само из себя
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = n - 1; k >= 0; k--) {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return make_pair(x, true);
}


int main() {
  int n;
  cout << "Введите количество уравнений: ";
  cin >> n;
  vector<vector<double>> a(n);
  vector<double> y(n);
  pair<vector<double>, bool>  ans;
  double tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "a[" << i + 1 << "][" << j + 1<< "]= ";
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << "y[" << i + 1 << "]= ";
    cin >> y[i];
  }
  print_system(a, y, n);
  ans = gauss(a, y, n);
  if (ans.second) {
    for (int i = 0; i < n; i++) 
      cout << "x[" << i + 1 << "]=" << ans.first[i] << endl;
  }
  return 0;
}