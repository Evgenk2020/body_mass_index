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
    cout << "*** ИНДЕКС МАССЫ ТЕЛА ***" << endl << endl;
    cout << "Пол: " << Human_Gender_Name[gender_bm] << endl;
    cout << "Возрастная группа: " << age_group_name_bm << endl;
    cout << "Индекс массы тела: " << setprecision(4) << body_mass_index_bm << endl;
    cout << interprit_bm;
    if (interprit_bm != Human_Results_Name[normal]) cout << setprecision(4) << delta_bm << " кг";
    cout << endl;
    RESET;
}
//================================================================================


//================================================================================
//class human_maker
void human_maker::make_new_human() {human_n = std::make_unique<human>();}
human* human_maker::get_human() {return human_n.release();}

void human_maker::activate() {
    u_read_param = std::make_unique<read_param>();
    u_counters = std::make_unique<counters>();
}
//================================================================================


//================================================================================
//class male_human
void male_human::make_ager() {
    u_counters->age_group::set_param(u_read_param->get_year(), u_read_param->get_month());
    human_n->set_age(u_counters->age_group::get_param());
}

void male_human::make_bmi() {
    u_counters->body_mass_index::set_param(u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_bmi(u_counters->body_mass_index::get_param());
}

void male_human::make_age_group_n() {
    u_counters->age_grp_name::set_param(u_counters->age_group::get_param());
    human_n->age_group_n(u_counters->age_grp_name::get_param());
}

void male_human::make_set_delta() {
    u_counters->delta_mass::set_param(MaleBase, u_counters->body_mass_index::get_param(), u_counters->age_group::get_param(), u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_delta(u_counters->delta_mass::get_param());
}

void male_human::make_set_explain() {
    u_counters->explain_bmi::set_param(u_counters->body_mass_index::get_param(), MaleBase, u_counters->age_group::get_param());
    human_n->set_explain(u_counters->explain_bmi::get_param());
}

void male_human::make_set_gender() {
    human_n->set_gender(male);
}

void male_human::make_set_interprit() {
    u_counters->interprit_bmi::set_param(u_counters->explain_bmi::get_param());
    human_n->set_interprit(u_counters->interprit_bmi::get_param());
}
//================================================================================



//================================================================================
//class female_human
void female_human::make_ager() {
    u_counters->age_group::set_param(u_read_param->get_year(), u_read_param->get_month());
    human_n->set_age(u_counters->age_group::get_param());
}

void female_human::make_bmi() {
    u_counters->body_mass_index::set_param(u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_bmi(u_counters->body_mass_index::get_param());
}

void female_human::make_age_group_n() {
    u_counters->age_grp_name::set_param(u_counters->age_group::get_param());
    human_n->age_group_n(u_counters->age_grp_name::get_param());
}

void female_human::make_set_delta() {
    u_counters->delta_mass::set_param(FemaleBase, u_counters->body_mass_index::get_param(), u_counters->age_group::get_param(), u_read_param->get_height(), u_read_param->get_weight());
    human_n->set_delta(u_counters->delta_mass::get_param());
}

void female_human::make_set_explain() {
    u_counters->explain_bmi::set_param(u_counters->body_mass_index::get_param(), FemaleBase, u_counters->age_group::get_param());
    human_n->set_explain(u_counters->explain_bmi::get_param());
}

void female_human::make_set_gender() {
    human_n->set_gender(female);
}

void female_human::make_set_interprit() {
    u_counters->interprit_bmi::set_param(u_counters->explain_bmi::get_param());
    human_n->set_interprit(u_counters->interprit_bmi::get_param());
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
