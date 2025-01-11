#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class BooleanFunction {
public:
    BooleanFunction(int numberOfVariables, std::vector<int> minterms) {
        _numberOfVariables = numberOfVariables;
        _minterms = minterms;
    }

    BooleanFunction() {
        int numberOfVariables;
        std::cout << "Enter the number of variables: ";
        std::cin >> numberOfVariables;

        int numberOfMinterms;
        std::cout << "Enter the minterms: ";
        std::cin >> numberOfMinterms;

        _minterms.resize(numberOfMinterms);
        for (int i = 0; i < numberOfMinterms; i++) {
            std::cout << "Enter minterm " << i + 1 << ": ";
            std::cin >> _minterms[i];
        }

        _numberOfVariables = numberOfVariables;
    }

    void print() {
        std::string functionExpression = "";

        for (int i = 0; i < _minterms.size(); i++) {
            std::string term = "";

            if (i != 0) {
                functionExpression += " + ";
            }

            for (int j = 0; j < _numberOfVariables; j++) {
                if (_minterms[i] & (1 << j)) {
                    term += (char)('A' + _numberOfVariables - 1 - j);
                } else {
                    term += (char)('A' + _numberOfVariables - 1 - j);
                    term += "'";
                }
            }

            functionExpression += term;
        }

        std::cout << functionExpression << std::endl;
    }


private:
    int _numberOfVariables;
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