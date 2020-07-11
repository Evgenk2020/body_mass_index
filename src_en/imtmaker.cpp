#include "imtmaker.h"

using namespace std;

//================================================================================
//class human
void human::set_age(int temp) {age_group_bm = temp;}
void human::set_bmi(float temp) {body_mass_index_bm = temp;}
void human::age_group_n(string temp) {age_group_name_bm = temp;}
void human::set_delta(float temp) {delta_bm = temp;}
void human::set_explain(int temp) {explain_bm = temp;}
void human::set_gender(int temp) {gender_bm = temp;}
void human::set_interprit(string temp) {interprit_bm = temp;}

void human::answer() {
    CYAN;
    cout << "*** BODY MASS INDEX ***" << endl << endl;
    cout << "Gender: " << Human_Gender_Name[gender_bm] << endl;
    cout << "Age group: " << age_group_name_bm << endl;
    cout << "BMI: " << setprecision(4) << body_mass_index_bm << endl;
    cout << interprit_bm;

    if (interprit_bm != Human_Results_Name[normal])
        cout << setprecision(4) << delta_bm << " kg";

    cout << endl;
    RESET;
}
//================================================================================



//================================================================================
//class human_maker
void human_maker::make_new_human() {human_n = make_unique<human>();}
human* human_maker::get_human() {return human_n.release();}

human_maker::human_maker() {
    u_read_param = make_unique<read_param>();
    ages = make_unique<x_param<int>>();
    wei_hei = make_unique<x_param<float>>();
    d_mass = make_unique<delta_mass>();
    explain = make_unique<explain_bmi>();
}
//================================================================================



//================================================================================
//class male_human
void male_human::make_ager() {
    ages->x_set(u_read_param->get_year(), u_read_param->get_month());
    human_n->set_age(ages->x_get());
}

void male_human::make_bmi() {
    wei_hei->x_set(u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_bmi(wei_hei->x_get());
}

void male_human::make_age_group_n() {
    names = make_unique<x_nam_grp>();
    names->set_param(ages->x_get());
    human_n->age_group_n(names->get_param());
}

void male_human::make_set_delta() {
    d_mass->set_param(MaleBase, wei_hei->x_get(), ages->x_get(), u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_delta(d_mass->get_param());
}

void male_human::make_set_explain() {
    explain->set_param(wei_hei->x_get(), MaleBase, ages->x_get());
    human_n->set_explain(explain->get_param());
}

void male_human::make_set_gender() {
    human_n->set_gender(male);
}

void male_human::make_set_interprit() {
    names = make_unique<x_interprit>();
    names->set_param(explain->get_param());
    human_n->set_interprit(names->get_param());
}
//================================================================================



//================================================================================
//class female_human
void female_human::make_ager() {
    ages->x_set(u_read_param->get_year(), u_read_param->get_month());
    human_n->set_age(ages->x_get());
}

void female_human::make_bmi() {
    wei_hei->x_set(u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_bmi(wei_hei->x_get());
}

void female_human::make_age_group_n() {
    names = make_unique<x_nam_grp>();
    names->set_param(ages->x_get());
    human_n->age_group_n(names->get_param());
}

void female_human::make_set_delta() {
    d_mass->set_param(FemaleBase, wei_hei->x_get(), ages->x_get(), u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_delta(d_mass->get_param());
}

void female_human::make_set_explain() {
    explain->set_param(wei_hei->x_get(), FemaleBase, ages->x_get());
    human_n->set_explain(explain->get_param());
}

void female_human::make_set_gender() {
    human_n->set_gender(female);
}

void female_human::make_set_interprit() {
    names = make_unique<x_interprit>();
    names->set_param(explain->get_param());
    human_n->set_interprit(names->get_param());
}
//================================================================================



//================================================================================
//class make_result
void make_result::open_result() {_human_maker->get_human()->answer();}
void make_result::create_result(human_maker *human_maker) {
    _human_maker = human_maker;
    _human_maker->make_new_human();
    _human_maker->make_ager();
    _human_maker->make_bmi();
    _human_maker->make_age_group_n();
    _human_maker->make_set_delta();
    _human_maker->make_set_explain();
    _human_maker->make_set_gender();
    _human_maker->make_set_interprit();
}
//================================================================================
