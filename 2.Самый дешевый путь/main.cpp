#include <iostream>
#include "trip.hpp"

int main() {
    using namespace std;

    int n{}, m{};
    if (!(cin >> n >> m)) {  // Проверка ввода
        cerr << "Invalid input\n";
        return 1;
    }

    if (n <= 0 || m <= 0) {  // Проверка размеров
        cerr << "Invalid dimensions\n";
        return 1;
    }

    // Выделение памяти
    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new int[m]{};
        for (int j = 0; j < m; ++j) {
            if (!(cin >> mat[i][j])) {  // Проверка ввода матрицы
                cerr << "Invalid matrix data\n";
                // Освобождаем уже выделенную память
                for (int k = 0; k <= i; ++k) {
                    delete[] mat[k];
                }
                delete[] mat;
                return 1;
            }
        }
    }

    // Вызов функции (если она есть)
    int result = low_cost_trip(n, m, mat);
    cout << "Result: " << result << endl;

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}