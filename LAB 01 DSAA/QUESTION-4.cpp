#include <iostream>
#include <cstdlib>
using namespace std;

class matrix
{

private:
    int **array;
    int row;
    int col;
    int *rowmajor;
    int *multiply1D;

public:
    matrix(int r, int c){
            row = r;
            col = c;
        array = new int *[row];

        for (int i = 0; i < row; i++){
            array[i] = new int[col];
        }

        rowmajor = new int[row * col];
        multiply1D = new int[row * col];
    }

    void input()
    {

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                array[i][j] = rand()%10;
            }
        }
    }

    void disp2D(){

        for (int i = 0; i < row; i++){

            for (int j = 0; j < col; j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dispRowMajor(){

        for (int i = 0; i < row * col; i++){
            cout << rowmajor[i] << " ";
        }
        cout << endl;
    }

    void convert1D(){
        int k = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                rowmajor[k++] = array[i][j];
            }
        }
    }

    void Multiply_rowMajor(matrix &x){

        for (int i = 0; i < row * col; i++){
            
            multiply1D[i] = x.rowmajor[i] * rowmajor[i];
            
        }
    }

    void rowMajor_2D()
    {

        int k = 0;

        for (int i = 0; i < row; i++){

            for (int j = 0; j < col; j++){
                array[i][j] = multiply1D[k++];
                
            }
        }
    }

    ~matrix(){
        
        for (int i = 0; i < row; i++){

            delete[] array[i];
        }
            delete[] array;
            delete[] rowmajor;
            delete[] multiply1D;
    }
};

int main()
{
    matrix a(4, 3);
    a.input();
        cout << "Matrix 1:" << endl;
    a.disp2D();
    a.convert1D();
    
    cout << endl;

    matrix b(3, 4);
    b.input();
            cout << "Matrix 2:" << endl;
    b.disp2D();
    b.convert1D();
    
        cout << endl;

    cout << "RowMajor 1:" << endl;
    a.dispRowMajor();
    
        cout << endl;
    
    cout << "RowMajor 2:" << endl;
    b.dispRowMajor();
    
        cout << endl;

    cout << "Resultant Matrix:" << endl;
        a.Multiply_rowMajor(b);
        a.rowMajor_2D();
        a.disp2D();
    cout << endl;
    
    return 0;
}