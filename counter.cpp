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
//class age_group
void age_group::set_param(int year, int month) {
    ages_group = justborn;
    if (year == 0 && month <= 11) ages_group = month;
    else if (year == 1 && month < 3) ages_group = one_year;
    else if (year == 1 && (month >= 3 && month < 6)) ages_group = one_year_three_month;
    else if (year == 1 && (month >= 6 && month < 9)) ages_group = one_year_six_month;
    else if (year == 1 && (month >= 9 && month <= 11)) ages_group = one_year_nine_month;
    else if (year == 2 && (month < 6)) ages_group = two_year;
    else if (year == 2 && (month >= 6 && month <= 11)) ages_group = two_year_six_month;
    else if (year == 3 && (month < 6)) ages_group = three_year;
    else if (year == 3 && (month >= 6 && month <= 11)) ages_group = three_year_six_month;
    else if (year == 4 && (month < 6)) ages_group = four_year;
    else if (year == 4 && (month >= 6 && month <= 11)) ages_group = four_year_six_month;
    else if (year == 5 && (month >= 0 && month <= 11)) ages_group = five_year;
    else if (year == 6 && (month >= 0 && month <= 11)) ages_group = six_year;
    else if (year == 7 && (month >= 0 && month <= 11)) ages_group = seven_year;
    else if (year == 8 && (month >= 0 && month <= 11)) ages_group = eight_year;
    else if (year == 9 && (month >= 0 && month <= 11)) ages_group = nine_year;
    else if (year == 10 && (month >= 0 && month <= 11)) ages_group = ten_year;
    else if (year == 11 && (month >= 0 && month <= 11)) ages_group = eleven_year;
    else if (year == 12 && (month >= 0 && month <= 11)) ages_group = twelve_year;
    else if (year == 13 && (month >= 0 && month <= 11)) ages_group = thirteen_year;
    else if (year == 14 && (month >= 0 && month <= 11)) ages_group = fourteen_year;
    else if (year == 15 && (month >= 0 && month <= 11)) ages_group = fifteen_year;
    else if (year == 16 && (month >= 0 && month <= 11)) ages_group = sixteen_year;
    else if (year == 17 && (month >= 0 && month <= 11)) ages_group = seventeen_year;
    else if (year == 18 && (month >= 0 && month <= 11)) ages_group = eighteen_year;
    else if (year == 19 && (month >= 0 && month <= 11)) ages_group = nineteen_year;
    else if (year >= 20 && (month >= 0 && month <= 11)) ages_group = adult;
    else _is_an_error->error();
}

int age_group::get_param(){return  ages_group;}
//================================================================================



//================================================================================
//class body_mass_index
void body_mass_index::set_param(float body_height, float body_weight) {
    if (body_height <= 0 || body_weight <= 0) _is_an_error->error();

    body_height /= 100;
    bmi = body_weight / (pow(body_height, 2));
}

float body_mass_index::get_param() {return bmi;}
//================================================================================



//================================================================================
//class age_grp_name
void age_grp_name::set_param(int index) {age_g_name = Human_Ages_Name[index];}
string age_grp_name::get_param() {return age_g_name;}
//================================================================================



//================================================================================
//class delta_mass
void delta_mass::set_param(const float (*base)[6], float index, int group, float height, float weight) {
    if (index == 0 || height == 0 || weight == 0) _is_an_error->error();

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
    if (bodindex == 0) _is_an_error->error();

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



//================================================================================
//class interprit_bmi
void interprit_bmi::set_param(int index) {interpritation = Human_Results_Name[index];}
string interprit_bmi::get_param() {return interpritation;}
//================================================================================
