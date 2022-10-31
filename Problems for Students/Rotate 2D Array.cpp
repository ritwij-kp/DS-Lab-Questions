#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
void rotate(int **matrix, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i; j < n - i - 1; j++)
    {

      int temp = matrix[i][j];
      matrix[i][j] = matrix[n - 1 - j][i];
      matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
      matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
      matrix[j][n - 1 - i] = temp;
    }
  }
}
void print(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  int n;
  cin >> n;
  int **matrix = new int *[n];
  for (int i = 0; i < n; i++)
  {
    matrix[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }
  cout << endl;
  cout << "Rotated matrix is:\n";
  rotate(matrix, n);
  print(matrix, n);
}
