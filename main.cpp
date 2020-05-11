#define INP_ARGS 10
#define CYAN std::cout << "\033[96;1m";
#define RESET std::cout << "\033[0m";

#include "mindex.h"
#include <string.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    writeln _user;//help and error interface messages declare
    _data _data;//data operating tools declare

    //check if the program being started without any parameters
    if (argc < 2) {
        _user._error::write();
    }

    //checking for help call
    if ((argc == 2 && (strncmp(argv[1], "-h", 2)) == 0 ) || (argc == 2 && (strncmp(argv[1], "--help", 6) == 0))) {
        _user._help::write();
    }

    //------------------------------------------------------------------
    //check if the input data being lost
    if (argc != INP_ARGS) {
        _user._error::write();
    }

    if ((strncmp(argv[1], "man", 3) != 0) && (strncmp(argv[1], "wom", 3) != 0)) _user._error::write();
    if (strncmp(argv[3], "y", 1) != 0) _user._error::write();
    if (strncmp(argv[5], "m", 1) != 0) _user._error::write();
    if (strncmp(argv[7], "kg", 2) != 0) _user._error::write();
    if (strncmp(argv[9], "cm", 2) != 0) _user._error::write();
    //------------------------------------------------------------------

    int _index =_data._group::index(atoi(argv[2]), atoi(argv[4]));//age group detection
    float _imt = _data._index::index(atof(argv[6]), atof(argv[8]));//mass index detection
    string _name = _data._name::index(_index);//age group name set

    float _delta = 0;
    int _explain = 0;
    int _gender = 0;

    if (strncmp(argv[1], "man", 3) == 0) {//for men
        _delta = _data._delta::index(MaleBase, _imt, _index, atof(argv[8]), atof(argv[6]));//difference
        _explain = _data._explain::explain(_imt, MaleBase, _index);//explain
        _gender = male;//set gender
    }

    if (strncmp(argv[1], "wom", 3) == 0) {//the same for women
        _delta = _data._delta::index(FemaleBase, _imt, _index, atof(argv[8]), atof(argv[6]));
        _explain = _data._explain::explain(_imt, FemaleBase, _index);
        _gender = female;
    }

    string _interprit = _data._interprit::index(_explain);//conclusion

    //printing the results in terminal
    CYAN
    cout << "*** BODY MASS INDEX ***" << endl << endl;
    cout << "Gender: " << Human_Gender_Name[_gender] << endl;
    cout << "Age group: " << _name << endl;
    cout << "BMI: " << setprecision(4) << _imt << endl;
    cout << _interprit;
    if (_interprit != Human_Results_Name[normal]) cout << setprecision(4) << _delta << " kg";
    cout << endl;
    RESET

    return 0;
}
