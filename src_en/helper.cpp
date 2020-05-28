#include "helper.h"

using namespace std;

void help() {
    cout << "*** BODY MASS INDEX ***" << endl << endl <<
            "Input format: man[wom] [ ] y [ ] m [ ] kg [ ] cm" << endl << endl <<
            "Before 1 year - 0 y [0...11] m" << endl <<
            "Before 3 years - [1, 2] y [0, 3, 6, 9] m" << endl <<
            "Before 5 years - [3, 4] y [0, 6] m" << endl <<
            "From 5 years [5...] y [0] m" << endl <<
            "The height must be given in centimeters" << endl;
    exit(0);
}

void error() {
    cout << "Specify the necessary parameters. For help use -h --help" << endl;
    exit(1);
}

void writer::show(void (*func)()) {
    func = *func;
    func();
}
