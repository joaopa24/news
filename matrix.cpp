#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int data[10][10]; // Limite de 10x10 para simplificação

public:
    // Construtor para inicializar dimensões
    Matrix(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    // Função para preencher a matriz
    void fillMatrix() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Função para imprimir a matriz
    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Adição de matrizes
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        if (rows == other.rows && cols == other.cols) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
        } else {
            cout << "Error: Matrix dimensions do not match for addition.\n";
        }
        return result;
    }

    // Subtração de matrizes
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        if (rows == other.rows && cols == other.cols) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
        } else {
            cout << "Error: Matrix dimensions do not match for subtraction.\n";
        }
        return result;
    }

    // Multiplicação de matrizes
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        if (cols == other.rows) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    result.data[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
        } else {
            cout << "Error: Matrix dimensions do not match for multiplication.\n";
        }
        return result;
    }
};

int main() {
    int rows, cols;
    
    cout << "Enter the number of rows and columns for matrix A (max 10x10): ";
    cin >> rows >> cols;
    Matrix A(rows, cols);
    A.fillMatrix();

    cout << "Enter the number of rows and columns for matrix B (max 10x10): ";
    cin >> rows >> cols;
    Matrix B(rows, cols);
    B.fillMatrix();

    cout << "\nMatrix A:\n";
    A.printMatrix();
    cout << "\nMatrix B:\n";
    B.printMatrix();

    cout << "\nA + B =\n";
    Matrix C = A + B;
    C.printMatrix();

    cout << "\nA - B =\n";
    Matrix D = A - B;
    D.printMatrix();

    cout << "\nA * B =\n";
    Matrix E = A * B;
    E.printMatrix();

    return 0;
}
