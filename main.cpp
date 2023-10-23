#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

void matrix_read(int matrix_one[MAX_SIZE][MAX_SIZE], int matrix_two[MAX_SIZE][MAX_SIZE], int &size, const char *file_name)
{
  ifstream fin(file_name);
  if (!fin.is_open())
  {
    cerr << "Error: Could not open file " << file_name << endl;
    return;
  }

  // sizee
  fin >> size;

  // matrix 1
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> matrix_one[i][j];
    }
  }

  // matrix 2
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> matrix_two[i][j];
    }
  }

  fin.close();
}

void matrix_print(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void matrix_add(int matrix_one[MAX_SIZE][MAX_SIZE], int matrix_two[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result[i][j] = matrix_one[i][j] + matrix_two[i][j];
    }
  }
}

void matrix_multiply(int matrix_one[MAX_SIZE][MAX_SIZE], int matrix_two[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      for (int k = 0; k < size; k++)
      {
        result[i][j] += matrix_one[i][k] * matrix_two[k][j];
      }
    }
  }
}

void matrix_subtract(int matrix_one[][MAX_SIZE], int matrix_two[][MAX_SIZE], int result[][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result[i][j] = matrix_one[i][j] - matrix_two[i][j];
    }
  }
}

int main()
{
  // declare and initialize the empty matrices
  int matrix_one[MAX_SIZE][MAX_SIZE];
  int matrix_two[MAX_SIZE][MAX_SIZE];
  int added_matrices[MAX_SIZE][MAX_SIZE];
  int multiplied_matrices[MAX_SIZE][MAX_SIZE];
  int subtracted_matrices[MAX_SIZE][MAX_SIZE];
  int size = MAX_SIZE;
  matrix_read(matrix_one, matrix_two, size, "matrix_input.txt");

  std::cout << "Morgan Nguyen" << endl;
  std::cout << "Lab #6: Matrix Multiplication" << endl;

  cout << "\nMatrix A:\n";
  matrix_print(matrix_one, size);

  cout << "\nMatrix B:\n";
  matrix_print(matrix_two, size);

  cout << "\nMatrix Sum (A + B):\n";
  matrix_add(matrix_one, matrix_two, added_matrices, size);
  matrix_print(added_matrices, size);

  cout << "\nMatrix Product (A * B):\n";
  matrix_multiply(matrix_one, matrix_two, multiplied_matrices, size);
  matrix_print(multiplied_matrices, size);

  cout << "\nMatrix Difference (A - B):\n";
  matrix_subtract(matrix_one, matrix_two, subtracted_matrices, size);
  matrix_print(subtracted_matrices, size);

  return 0;
}