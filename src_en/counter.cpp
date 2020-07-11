#include "counter.h"

using namespace std;

//================================================================================
//class read_param
void read_param::set_param(int year, int month, float weight, float height) {
    _years = year;
    _months = month;
    _weight = weight;
    _height = height;
}

int read_param::get_year() {return _years;}
int read_param::get_month() {return _months;}
float read_param::get_weight() {return  _weight;}
float read_param::get_height() {return _height;}
//================================================================================



//================================================================================
//class x_param
template <>
void x_param<int>::x_set(int year, int month) {
    temp = justborn;

    bool _month = (year == 0 && month <= 11);
    bool _one_year = (year == 1 && month < 3);
    bool _one_year_three_month = (year == 1 && (month >= 3 && month < 6));
    bool _one_year_six_month = (year == 1 && (month >= 6 && month < 9));
    bool _one_year_nine_month = (year == 1 && (month >= 9 && month <= 11));
    bool _two_year = (year == 2 && (month < 6));
    bool _two_year_six_month = (year == 2 && (month >= 6 && month <= 11));
    bool _three_year = (year == 3 && (month < 6));
    bool _three_year_six_month = (year == 3 && (month >= 6 && month <= 11));
    bool _four_year = (year == 4 && (month < 6));
    bool _four_year_six_month = (year == 4 && (month >= 6 && month <= 11));
    bool _five_year = (year == 5 && (month >= 0 && month <= 11));
    bool _six_year = (year == 6 && (month >= 0 && month <= 11));
    bool _seven_year = (year == 7 && (month >= 0 && month <= 11));
    bool _eight_year = (year == 8 && (month >= 0 && month <= 11));
    bool _nine_year = (year == 9 && (month >= 0 && month <= 11));
    bool _ten_year = (year == 10 && (month >= 0 && month <= 11));
    bool _eleven_year = (year == 11 && (month >= 0 && month <= 11));
    bool _twelve_year = (year == 12 && (month >= 0 && month <= 11));
    bool _thirteen_year = (year == 13 && (month >= 0 && month <= 11));
    bool _fourteen_year = (year == 14 && (month >= 0 && month <= 11));
    bool _fifteen_year = (year == 15 && (month >= 0 && month <= 11));
    bool _sixteen_year = (year == 16 && (month >= 0 && month <= 11));
    bool _seventeen_year = (year == 17 && (month >= 0 && month <= 11));
    bool _eighteen_year = (year == 18 && (month >= 0 && month <= 11));
    bool _nineteen_year = (year == 19 && (month >= 0 && month <= 11));
    bool _adult = (year >= 20 && (month >= 0 && month <= 11));

    if (_month)
        temp = month;

    else if (_one_year)
        temp = one_year;

    else if (_one_year_three_month)
        temp = one_year_three_month;

    else if (_one_year_six_month)
        temp = one_year_six_month;

    else if (_one_year_nine_month)
        temp = one_year_nine_month;

    else if (_two_year)
        temp = two_year;

    else if (_two_year_six_month)
        temp = two_year_six_month;

    else if (_three_year)
        temp = three_year;

    else if (_three_year_six_month)
        temp = three_year_six_month;

    else if (_four_year)
        temp = four_year;

    else if (_four_year_six_month)
        temp = four_year_six_month;

    else if (_five_year)
        temp = five_year;

    else if (_six_year)
        temp = six_year;

    else if (_seven_year)
        temp = seven_year;

    else if (_eight_year)
        temp = eight_year;

    else if (_nine_year)
        temp = nine_year;

    else if (_ten_year)
        temp = ten_year;

    else if (_eleven_year)
        temp = eleven_year;

    else if (_twelve_year)
        temp = twelve_year;

    else if (_thirteen_year)
        temp = thirteen_year;

    else if (_fourteen_year)
        temp = fourteen_year;

    else if (_fifteen_year)
        temp = fifteen_year;

    else if (_sixteen_year)
        temp = sixteen_year;

    else if (_seventeen_year)
        temp = seventeen_year;

    else if (_eighteen_year)
        temp = eighteen_year;

    else if (_nineteen_year)
        temp = nineteen_year;

    else if (_adult)
        temp = adult;

    else
        is_an_error->show(error);
}

template <>
void x_param<float>::x_set(float body_height, float body_weight) {
    bool _error = (body_height <= 0 || body_weight <= 0);
    if (_error)
        is_an_error->show(error);

    body_height /= 100;
    temp = body_weight / (pow(body_height, 2));
}
//================================================================================



//================================================================================
//class x_names
string x_names::get_param() {return x_name_res;}
void x_nam_grp::set_param(int index) {x_name_res = Human_Ages_Name[index];}
void x_interprit::set_param(int index) {x_name_res = Human_Results_Name[index];}
//================================================================================



//================================================================================
//class delta_mass
void delta_mass::set_param(const float (*base)[6], float index, int group, float height, float weight) {
    bool _error = (index == 0 || height == 0 || weight == 0);
    if (_error)
        is_an_error->show(error);

    height /= 100;

    bool _less_weit = (index <= base[group][little]);
    bool _more_weit = (index > base[group][normal]);

    if (_less_weit)
        delta = base[group][little] * (pow(height, 2));

    else if (_more_weit)
        delta = base[group][normal] * (pow(height, 2));


    delta = weight - delta;
}

float delta_mass::get_param() {return delta;}
//================================================================================



//================================================================================
//class explain_bmi
void explain_bmi::set_param(float bodindex, const float (*base)[6], int group) {
    bool _error = (bodindex == 0);
    if (_error)
        is_an_error->show(error);

    bool _few = (bodindex <= base[group][few]);
    bool _little = (bodindex > base[group][few] && bodindex <= base[group][little]);
    bool _normal = (bodindex > base[group][little] && bodindex <= base[group][normal]);
    bool _much = (bodindex > base[group][normal] && bodindex <= base[group][much]);
    bool _enough = (bodindex > base[group][much] && bodindex <= base[group][enough]);
    bool _bad = (bodindex > base[group][enough] && bodindex <= base[group][bad]);
    bool _worst = (bodindex > base[group][bad]);

    if (_few)
        explain = few;

    else if (_little)
        explain = little;

    else if (_normal)
        explain = normal;

    else if (_much)
        explain = much;

    else if (_enough)
        explain = enough;

    else if (_bad)
        explain = bad;

    else if (_worst)
        explain = worst;
}

int explain_bmi::get_param() {return explain;}
//================================================================================
