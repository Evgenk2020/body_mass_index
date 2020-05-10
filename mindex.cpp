#include "mindex.h"
#include "data.h"
#include "enums.h"

using namespace std;

//================================================================================
void _help::write() {
    cout << "*** Индекс массы тела ***" << endl << endl <<
            "Формат ввода: man[wom] [ ] y [ ] m [ ] kg [ ] cm" << endl << endl <<
            "До 1 года - 0 y [0...11] m" << endl <<
            "До 2 лет - [1, 2] y [0, 3, 6, 9] m" << endl <<
            "До 5 лет - [3, 4] y [0, 6] m" << endl <<
            "С пяти лет [5...] y [0] m" << endl <<
            "Значение роста указывается в сантиметрах" << endl;
    exit(0);
}

void _error::write() {
    cout << "Указывайте необходимые параметры. Справка -h или --help" << endl;
    exit(1);
}
//================================================================================



//================================================================================
float _index::index(float body_weight, float body_height) {
    float index = 0;
    if (body_height <= 0 || body_weight <= 0) _is_an_error->writeln::_error::write();
    body_height /= 100;
    index = body_weight / (pow(body_height, 2));
    return index;
}

int _group::index(int year, int month) {
    int ageindex = justborn;

    if (year == 0 && month <= 11) ageindex = month;
    else if (year == 1 && month < 3) ageindex = one_year;
    else if (year == 1 && (month >= 3 && month < 6)) ageindex = one_year_three_month;
    else if (year == 1 && (month >= 6 && month < 9)) ageindex = one_year_six_month;
    else if (year == 1 && (month >= 9 && month <= 11)) ageindex = one_year_nine_month;
    else if (year == 2 && (month < 6)) ageindex = two_year;
    else if (year == 2 && (month >= 6 && month <= 11)) ageindex = two_year_six_month;
    else if (year == 3 && (month < 6)) ageindex = three_year;
    else if (year == 3 && (month >= 6 && month <= 11)) ageindex = three_year_six_month;
    else if (year == 4 && (month < 6)) ageindex = four_year;
    else if (year == 4 && (month >= 6 && month <= 11)) ageindex = four_year_six_month;
    else if (year == 5 && (month >= 0 && month <= 11)) ageindex = five_year;
    else if (year == 6 && (month >= 0 && month <= 11)) ageindex = six_year;
    else if (year == 7 && (month >= 0 && month <= 11)) ageindex = seven_year;
    else if (year == 8 && (month >= 0 && month <= 11)) ageindex = eight_year;
    else if (year == 9 && (month >= 0 && month <= 11)) ageindex = nine_year;
    else if (year == 10 && (month >= 0 && month <= 11)) ageindex = ten_year;
    else if (year == 11 && (month >= 0 && month <= 11)) ageindex = eleven_year;
    else if (year == 12 && (month >= 0 && month <= 11)) ageindex = twelve_year;
    else if (year == 13 && (month >= 0 && month <= 11)) ageindex = thirteen_year;
    else if (year == 14 && (month >= 0 && month <= 11)) ageindex = fourteen_year;
    else if (year == 15 && (month >= 0 && month <= 11)) ageindex = fifteen_year;
    else if (year == 16 && (month >= 0 && month <= 11)) ageindex = sixteen_year;
    else if (year == 17 && (month >= 0 && month <= 11)) ageindex = seventeen_year;
    else if (year == 18 && (month >= 0 && month <= 11)) ageindex = eighteen_year;
    else if (year == 19 && (month >= 0 && month <= 11)) ageindex = nineteen_year;
    else if (year >= 20 && (month >= 0 && month <= 11)) ageindex = adult;
    else _is_an_error->writeln::_error::write();

    return ageindex;
}

std::string _name::index(int index) {return Human_Ages_Name[index];}

float _delta::index(const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], float index, int group, float height, float weight) {
    if (index == 0 || height == 0 || weight == 0) _is_an_error->writeln::_error::write();
    float delta = 0;
    height /= 100;

    if (index <= base[group][little]) {
        delta = base[group][little] * (pow(height, 2));
    }
    else if (index > base[group][normal]) {
        delta = base[group][normal] * (pow(height, 2));
    }
    delta = weight - delta;

    return delta;
}

int _explain::explain(float bodindex, const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], int group) {
    if (bodindex == 0) _is_an_error->writeln::_error::write();
    int expl = 0;

    if (bodindex <= base[group][few]) expl = few;
    else if (bodindex > base[group][few] && bodindex <= base[group][little]) expl = little;
    else if (bodindex > base[group][little] && bodindex <= base[group][normal]) expl = normal;
    else if (bodindex > base[group][normal] && bodindex <= base[group][much]) expl = much;
    else if (bodindex > base[group][much] && bodindex <= base[group][enough]) expl = enough;
    else if (bodindex > base[group][enough] && bodindex <= base[group][bad]) expl = bad;
    else if (bodindex > base[group][bad]) expl = worst;

    return expl;
}

std::string _interprit::index(int index) {return Human_Results_Name[index];}
//================================================================================
