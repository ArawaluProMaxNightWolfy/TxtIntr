#include <iostream>
#include <getopt.h>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    try {
        static struct option long_options[] = {
            {"operation", 1, NULL, 'o'},
            {NULL, 0, NULL, 0}
        };

        int opt;
        opt = getopt_long(argc, argv, ":ho:", long_options, NULL);

        if (opt == -1 || (char)opt == 'h') {
            cout << "Малоточный и слабофункциональный калькулятор способен только на две операции:\n";
            cout << "1. Арктангенс\nВызывается параметрами: -o atan или --operation atan\n";
            cout << "Находит арктангенс числа\n";
            cout << "2. Арккотангенс\nВызывается параметрами: -o acot или --operation acot\n";
            cout << "Находит арккотангенс числа\n";
            cout << "ВНИМАНИЕ: в дробных числах должна использоваться точка\n";
        } else if ((char)opt == 'o') {
            if (argc > 4) {
                cout << "Неверное количество аргументов. Пожалуйста, введите число.\n";
                cout << "Пример использования арктангенса: ... -o atan 0.5\n";
                cout << "Пример использования арккотангенса: ... -o acot 2.0\n";
            } else {
                string operation = optarg;
                float x = stof(argv[3]);

                if (operation == "atan") {
                    float result = atan(x);
                    cout << "Арктангенс " << x << " равен " << result << "\n";
                } else if (operation == "acot") {
                    float result = atan(1 / x);
                    cout << "Арккотангенс " << x << " равен " << result << "\n";
                } else {
                    cout << "Данному калькулятору неизвестна эта операция.\n";
                    cout << "Поддерживаемые операции: atan, acot\n";
                }
            }
        }
    } catch (...) {
        cerr << "Ошибка: введены некорректные аргументы.\n";
    }

    return 0;
}
