#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <vector>

template <typename T>
bool es_par(T value) {
    return value % 2 == 0;
}

template <typename T, size_t base>
bool es_multiplo(T value) {
    return value % base == 0;
}

template <typename T>
class functor_es_multiplo {
    T base{};
public:
    functor_es_multiplo(T base): base(base) {}
    bool operator()(T value) {
        return value % base == 0;
    }
};

void ejemplo_find_if() {
    std::vector v = { 10, 20, 30, 40, 50};
    auto it = std::find_if(std::begin(v), std::end(v), es_par<int>);
    auto it2 = std::find_if(std::begin(v), std::end(v), es_multiplo<int, 3>);
    int base{};
    std::cout << "ingrese la base: "; std::cin >> base;
    auto it3 = std::find_if(std::begin(v), std::end(v), functor_es_multiplo<int>(base));

    // Construyendo los functor
    auto es_multiplo_de_5 = functor_es_multiplo<int>(5);
    auto es_multiplo_de_7 = functor_es_multiplo<int>(7);

    // Llamando a los functors
    std::cout << std::boolalpha << es_multiplo_de_5(7) << std::endl;
    std::cout << std::boolalpha << es_multiplo_de_5(25) << std::endl;
    std::cout << std::boolalpha << es_multiplo_de_7(7) << std::endl;
}

void ejemplo_find_if_lambdas() {
    std::vector v = { 10, 20, 30, 40, 50};
    auto es_multiplo_de_3 = [base=3](auto value) { return value % base == 0; };
    auto it3 = std::find_if(std::begin(v), std::end(v), es_multiplo_de_3);
}

void ejemplos_lambda() {

    auto lambda_1 = [](auto a, auto b) { return a + b; };
    std::cout << lambda_1(10, 30) << std::endl;

    auto base = 3;
    // Parametro de Capture READ/ONLY
    auto lambda_2 = [b=base](auto value) { return value/b; };

    // Parametro del Capture READ/WRITE
    auto lambda_3 = [&base]() {
        base += 10;
    };

    auto var_1 = 10;
    auto var_2 = 20;
    auto var_3 = 50;
    auto lambda_4 = [&var_1, var_2, var_3]() {
        var_1 = var_2 + var_3;
    };
    lambda_4();

    auto var_4 = 60;
    auto lambda_5 = [=, &var_1]() {
        var_1 = var_2 + var_3 + var_4;
    };
    auto var_5 = 0;
    auto lambda_6 = [=, &var_1, &var_5]() {
        var_1 = var_2 + var_3 + var_4;
        var_5 = var_2 * var_3;
    };

    auto var_6 = 0;
    auto lambda_7 = [&, var_1, var_5]() {
        var_2 = var_1 + var_3;
        var_3 = var_5 + var_4;
        var_4 = var_2 * var_3;
        var_6 = var_1 + var_3;
    };





}

int main() {
    ejemplo_find_if();
    return 0;
}
