#include "helper.h"

using namespace std;

void writeln_info::help() {
    cout << "*** Индекс массы тела ***" << endl << endl <<
            "Формат ввода: man[wom] [ ] y [ ] m [ ] kg [ ] cm" << endl << endl <<
            "До 1 года - 0 y [0...11] m" << endl <<
            "До 3 лет - [1, 2] y [0, 3, 6, 9] m" << endl <<
            "До 5 лет - [3, 4] y [0, 6] m" << endl <<
            "С пяти лет [5...] y [0] m" << endl <<
            "Значение роста указывается в сантиметрах" << endl;
    exit(0);
}

void writeln_info::error() {
    cout << "Указывайте необходимые параметры. Справка -h или --help" << endl;
    exit(1);
}
