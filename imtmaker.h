#ifndef IMTMAKER_H
#define IMTMAKER_H

#include <iomanip>
#include "counter.h"



//================================================================================
class human {
private:
    int age_group_bm;
    float body_mass_index_bm;
    std::string age_group_name_bm;
    float delta_bm;
    std::string explain_bm;
    int gender_bm;
    std::string interprit_bm;

public:
    void set_age(int temp);
    void set_bmi(float temp);
    void age_group_n(std::string temp);
    void set_delta(float temp);
    void set_explain(int temp);
    void set_gender(int temp);
    void set_interprit(std::string temp);
    void answer();
};
//================================================================================



//================================================================================
class human_maker {
protected:
    std::unique_ptr<human> human_n;

public:
    read_param _read_param;
    counters _counters;

    virtual ~human_maker() {}
    virtual void make_ager() = 0;
    virtual void make_bmi() = 0;
    virtual void make_age_group_n() = 0;
    virtual void make_set_delta() = 0;
    virtual void make_set_explain() = 0;
    virtual void make_set_gender() = 0;
    virtual void make_set_interprit() = 0;

    void make_new_human();
    human* get_human();
};
//================================================================================



//================================================================================
class male_human : public human_maker {
public:
    ~male_human() {}
    void make_ager() override;
    void make_bmi() override;
    void make_age_group_n() override;
    void make_set_delta() override;
    void make_set_explain() override;
    void make_set_gender() override;
    void make_set_interprit() override;
};
//================================================================================



//================================================================================
class female_human : public human_maker {
public:
    ~female_human() {}
    void make_ager() override;
    void make_bmi() override;
    void make_age_group_n() override;
    void make_set_delta() override;
    void make_set_explain() override;
    void make_set_gender() override;
    void make_set_interprit() override;
};
//================================================================================



//================================================================================
class make_result {
private:
    human_maker* _human_maker;

public:
    void open_result();
    void create_result(human_maker* human_maker);
};
//================================================================================

#endif // IMTMAKER_H
