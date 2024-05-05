/*
Programmer: Raghib Rizwan Rabani
NU ID: 23K-0012
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Matrix{
protected:
    int col;
    int row;

    vector<vector<T>> arr;

public: 
    Matrix(int row, int col) : row(row), col(col) {
        arr.resize(row);
        for(int i =0; i < row; ++i){
            arr[i].resize(col);
        }
    }

    void setMatrix(int row, int col, T num){
        arr[row][col] = num;
    }
    T getMatrix(int row, int col){
        return arr[row][col];
    }

    Matrix<T> operator+(Matrix<T>& mat){
        Matrix<T> final(row, col);
        for(int i=0;i <row; ++i){
            for(int j=0;j < col; ++j){
                final.arr[i][j] = arr[i][j] + mat.arr[i][j];
            }
        }
        return final;
    }

    Matrix<T> operator-(Matrix<T>& mat){
        Matrix<T> final(row, col);

        for(int i=0;i <row; ++i){
            for(int j=0;j < col; ++j){
                final.arr[i][j] = arr[i][j] - mat.arr[i][j];
            }
        }
        return final;
    }

    Matrix<T> operator*(Matrix<T>& mat){
        Matrix<T> final(row, col);

        for(int i=0;i <row; ++i){
            for(int j=0;j < col; ++j){
                final.arr[i][j] = arr[i][j] * mat.arr[i][j];
            }
        }
        return final;
    }

    virtual void display(){
        cout << "Matrix class " << endl << endl;
        for(int i=0; i< row ; ++i){
            for(int j=0; j < col ; ++j){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
};

template <typename T>
class IntMatrix : public Matrix<T> {
    public:
    IntMatrix(int row, int col) : Matrix<T>(row, col) {}

    void display(){
        cout << "Int Matrix " << endl << endl;
        for(int i=0; i< this->row ; ++i){
            for(int j=0; j < this->col ; ++j){
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <typename T>
class DoubleMatrix : public Matrix<T> {
    public:
    DoubleMatrix(int row, int col) : Matrix<T>(row, col) {}
    void display(){
        cout << "Double Matrix" << endl << endl;
        for(int i=0; i< this->row; ++i){
            for(int j=0; j < this->col; ++j){
                cout << this->arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
    IntMatrix<int> intmat(2,2);
    DoubleMatrix<double> doublemat(2,2);

    intmat.setMatrix(0, 0, 1);
    intmat.setMatrix(0, 1, 2);
    intmat.setMatrix(1, 0, 3);
    intmat.setMatrix(1, 1, 4);

    doublemat.setMatrix(0, 0, 5.0);
    doublemat.setMatrix(0, 1, 6.1);
    doublemat.setMatrix(1, 0, 7.2);
    doublemat.setMatrix(1, 1, 8.3);

    intmat.display();
    doublemat.display();

    Matrix<int> ans1 = intmat + intmat;
    Matrix<double> ans2 = doublemat + doublemat;
    Matrix<int> ans3 = intmat - intmat;
    Matrix<double> ans4 = doublemat - doublemat;
    Matrix<int> ans5 = intmat * intmat;
    Matrix<double> ans6 = doublemat * doublemat;

    ans1.display();
    ans2.display();
    ans3.display();
    ans4.display();
    ans5.display();
    ans6.display();
}
