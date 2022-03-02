#include<iostream>
#include<vector>

using namespace std;

void straight_insertion_sort(vector <int>& a, int n) {
  int val, j;
  for (int i = 1; i < n; i++) {
    val = a[i];
    j = i - 1;
    while (j >= 0 && val < a[j]) {
      a[j + 1] = a[j];
      a[j] = val;
      j--;
    }
  }
}


void print_array (vector<int>& a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << "\n";
}


int main() {
  cout << "Введите число элементов массива\n";
  int n;
  cin >> n;
  vector <int> a(n);

  cout << "Введите элементы массива\n";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << "Исходный массив:\n";
  
  print_array(a, n);
  
  cout << "Отсортированный массив:\n";
  
  straight_insertion_sort(a, n);
  print_array(a, n);

  return 0;
}