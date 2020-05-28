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
    if (year == 0 && month <= 11) temp = month;
    else if (year == 1 && month < 3) temp = one_year;
    else if (year == 1 && (month >= 3 && month < 6)) temp = one_year_three_month;
    else if (year == 1 && (month >= 6 && month < 9)) temp = one_year_six_month;
    else if (year == 1 && (month >= 9 && month <= 11)) temp = one_year_nine_month;
    else if (year == 2 && (month < 6)) temp = two_year;
    else if (year == 2 && (month >= 6 && month <= 11)) temp = two_year_six_month;
    else if (year == 3 && (month < 6)) temp = three_year;
    else if (year == 3 && (month >= 6 && month <= 11)) temp = three_year_six_month;
    else if (year == 4 && (month < 6)) temp = four_year;
    else if (year == 4 && (month >= 6 && month <= 11)) temp = four_year_six_month;
    else if (year == 5 && (month >= 0 && month <= 11)) temp = five_year;
    else if (year == 6 && (month >= 0 && month <= 11)) temp = six_year;
    else if (year == 7 && (month >= 0 && month <= 11)) temp = seven_year;
    else if (year == 8 && (month >= 0 && month <= 11)) temp = eight_year;
    else if (year == 9 && (month >= 0 && month <= 11)) temp = nine_year;
    else if (year == 10 && (month >= 0 && month <= 11)) temp = ten_year;
    else if (year == 11 && (month >= 0 && month <= 11)) temp = eleven_year;
    else if (year == 12 && (month >= 0 && month <= 11)) temp = twelve_year;
    else if (year == 13 && (month >= 0 && month <= 11)) temp = thirteen_year;
    else if (year == 14 && (month >= 0 && month <= 11)) temp = fourteen_year;
    else if (year == 15 && (month >= 0 && month <= 11)) temp = fifteen_year;
    else if (year == 16 && (month >= 0 && month <= 11)) temp = sixteen_year;
    else if (year == 17 && (month >= 0 && month <= 11)) temp = seventeen_year;
    else if (year == 18 && (month >= 0 && month <= 11)) temp = eighteen_year;
    else if (year == 19 && (month >= 0 && month <= 11)) temp = nineteen_year;
    else if (year >= 20 && (month >= 0 && month <= 11)) temp = adult;
    else is_an_error->show(error);
}

template <>
void x_param<float>::x_set(float body_height, float body_weight) {
    if (body_height <= 0 || body_weight <= 0) is_an_error->show(error);

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
    if (index == 0 || height == 0 || weight == 0) is_an_error->show(error);

    height /= 100;
    if (index <= base[group][little]) {
        delta = base[group][little] * (pow(height, 2));
    }
    else if (index > base[group][normal]) {
        delta = base[group][normal] * (pow(height, 2));
    }

    delta = weight - delta;
}

float delta_mass::get_param() {return delta;}
//================================================================================



//================================================================================
//class explain_bmi
void explain_bmi::set_param(float bodindex, const float (*base)[6], int group) {
    if (bodindex == 0) is_an_error->show(error);

    if (bodindex <= base[group][few]) explain = few;
    else if (bodindex > base[group][few] && bodindex <= base[group][little]) explain = little;
    else if (bodindex > base[group][little] && bodindex <= base[group][normal]) explain = normal;
    else if (bodindex > base[group][normal] && bodindex <= base[group][much]) explain = much;
    else if (bodindex > base[group][much] && bodindex <= base[group][enough]) explain = enough;
    else if (bodindex > base[group][enough] && bodindex <= base[group][bad]) explain = bad;
    else if (bodindex > base[group][bad]) explain = worst;
}

int explain_bmi::get_param() {return explain;}
//================================================================================
