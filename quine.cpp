#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class BooleanFunction {
public:
    BooleanFunction(int n, std::vector<int> minterms) {
        _n = n;
        _minterms = minterms;
    }

    BooleanFunction() {
        int n;
        std::cout << "Enter the number of variables: ";
        std::cin >> n;

        std::vector<int> minterms(n);
        std::cout << "Enter the minterms: ";
        for (int i = 0; i < n; i++) {
            std::cin >> _minterms[i];
        }

        _n = n;
        _minterms = minterms;
    }

    void print() {
        std::string functionExpression = "";
        std::string term = "";
        for (int i = 0; i < _minterms.size(); i++) {
            term = "";

            if (i != 0) {
                functionExpression += " + ";
            }

            for (int j = 0; j < _n; j++) {
                if (_minterms[i] & (1 << j)) {
                    term += (char)('A' + _n - 1 - j);
                } else {
                    term += (char)('A' + _n - 1 - j) + "'";
                }
            }

            functionExpression += term;
        }

        std::cout << functionExpression << std::endl;
    }


private:
    int _n;
    std::vector<int> _minterms;
};


class QuineMcClusky {
public:


private:
};


int main() {
    BooleanFunction* f = new BooleanFunction();
    f->print();

    return 0;
}