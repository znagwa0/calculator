#include <iostream>
#include <functional>
#include <unordered_map>

int main() {
    double a, b;
    char op;
    std::unordered_map<char, std::function<double(double, double)>> ops = {
        {'+', std::plus<double>()}, {'-', std::minus<double>()},
        {'*', std::multiplies<double>()}, {'/', [](double x, double y) { return y != 0 ? x / y : throw std::runtime_error("Division by zero"); }}
    };

    std::cout << "Enter expression (ex 3 + 4) : ";
    std::cin >> a >> op >> b;

    if (ops.find(op) != ops.end()) {
        try {
            std::cout << "Result: " << ops[op](a, b) << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid operator." << std::endl;
    }

    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
