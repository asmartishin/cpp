#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

#define endl '\n'


double scalar_product(const vector<double> &v1, const vector<double> &v2) {
    assert(v1.size() == v2.size());
    double result = 0;

    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }

    return result;
}


vector<double> sum_of_vectors(const vector<double> &v1, const vector<double> &v2) {
    assert(v1.size() == v2.size());
    vector<double> result;

    for (size_t i = 0; i < v1.size(); ++i) {
        result.push_back(v1[i] + v2[i]);
    }

    return result;
}


vector<double> multiply_vector_by_number(double number, const vector<double> &v) {
    vector<double> result(v.size());

    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] * number;
    }

    return result;
}


vector<double> inverse_vector(const vector<double> &v) {
    return multiply_vector_by_number(-1, v);
}

bool is_vector_zero(vector<double> &v) {
    bool result = true;

    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] != 0) {
            result = false;
            break;
        }
    }

    return result;
}


void print_matrix(const vector<vector<double> > &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}


void print_vector(const vector<double> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}


double matrix_determinant(vector<vector<double> > &matrix) {
    double max_element, max_row, coefficient, result = 1;
    int n = matrix.size(), determinant_coefficient = 1;

    for (size_t i = 0; i < n; ++i) {
        max_element = matrix[i][i];
        max_row = i;

        // Search for maximum in this column
        for (size_t j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > max_element) {
                max_element = abs(matrix[j][i]);
                max_row = j;
            }
        }

        if (max_row != i)
            determinant_coefficient *= - 1;

        // Swap maximum row with current row (column by column)
        for (size_t j = i; j < n; ++j) {
            swap(matrix[max_row][j], matrix[i][j]);
        }

        // Make all rows below this one 0 in current column
        for (size_t j = i + 1; j < n; ++j) {
            coefficient = -matrix[j][i]/matrix[i][i];

            for (size_t k = i; k < n; ++k) {
                if (i == k) {
                    matrix[j][k] = 0;
                } else {
                    matrix[j][k] += coefficient * matrix[i][k];
                }
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        result *= matrix[i][i];
    }

    return determinant_coefficient * result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;

    cin >> n;

    vector<vector<double> > matrix(n - 1, vector<double>(n));
    vector<double> solution(n, 0);

    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    while (true) {
        vector<double> possible_solution(n, 0);

        for (size_t i = 0; i < n; ++i) {
            possible_solution[i] = rand() % 10;;
        }

        for (size_t j = 0; j < n - 1; ++j) {
            possible_solution = sum_of_vectors(
                possible_solution,
                inverse_vector(
                    multiply_vector_by_number(
                        scalar_product(possible_solution, matrix[j]) / scalar_product(matrix[j], matrix[j]),
                        matrix[j]
                    )
                )
            );
        }

        if (!is_vector_zero(possible_solution))
            solution = possible_solution;
            break;
    }

    matrix.push_back(solution);

    print_vector(multiply_vector_by_number(1 / matrix_determinant(matrix), solution));

    return 0;
}
