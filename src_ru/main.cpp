#define INP_ARGS 10

#include <string.h>
#include <stdio.h>

#include "imtmaker.h"

using namespace std;

int main(int argc, char *argv[]) {
    writer writeln;

    //check if the program being started without any parameters
    if (argc < 2) {
        writeln.show(error);
    }

    //checking for help call
    if ((argc == 2 && (strncmp(argv[1], "-h", 2)) == 0 ) || (argc == 2 && (strncmp(argv[1], "--help", 6) == 0))) {
        writeln.show(help);
    }

    //------------------------------------------------------------------
    //check if the input data being lost
    if (argc != INP_ARGS) {
        writeln.show(error);
    }

    if ((strncmp(argv[1], "man", 3) != 0) && (strncmp(argv[1], "wom", 3) != 0)) writeln.show(error);
    if (strncmp(argv[3], "y", 1) != 0) writeln.show(error);
    if (strncmp(argv[5], "m", 1) != 0) writeln.show(error);
    if (strncmp(argv[7], "kg", 2) != 0) writeln.show(error);
    if (strncmp(argv[9], "cm", 2) != 0) writeln.show(error);
    //------------------------------------------------------------------

    make_result _make_result;

    if (strncmp(argv[1], "man", 3) == 0) {//for men
        male_human _male_human;
        _male_human.u_read_param->set_param(atoi(argv[2]), atoi(argv[4]), atof(argv[6]), atof(argv[8]));
        _make_result.create_result(&_male_human);
        _make_result.open_result();
    }

    if (strncmp(argv[1], "wom", 3) == 0) {//the same for women
        female_human _female_human;
        _female_human.u_read_param->set_param(atoi(argv[2]), atoi(argv[4]), atof(argv[6]), atof(argv[8]));
        _make_result.create_result(&_female_human);
        _make_result.open_result();
    }

    return 0;
}
