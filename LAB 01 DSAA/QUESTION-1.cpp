#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
   int rows, cols;
   cout << "Enter rows and columns:";
   cin >> rows >> cols;
   int Array2D[rows][cols];
   int Array1D[rows * cols];
   // Assigning random values
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         Array2D[i][j] = (rand() % 10) + 1;
      }
   }
   // Printing 2D Array
   cout << "Elements Of 2D Array" << endl;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cout << Array2D[i][j] << " ";
      }
      cout << endl;
   }
   // Assigning values of 2D array to 1D Array (column major order)
   int index_Array1D = 0;
   for (int i = 0; i < cols; i++)
   {
      for (int j = 0; j < rows; j++)
      {
         Array1D[index_Array1D] = Array2D[j][i];
         index_Array1D++;
      }
   }
   // Printing 1D Array
   cout << "Elements Of 1D Array(column major order)" << endl;
   for (int k = 0; k < rows * cols; k++)
   {
      cout << Array1D[k] << "\n";
   }
}