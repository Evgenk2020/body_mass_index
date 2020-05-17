#ifndef COUNTER_H
#define COUNTER_H

#include "data.h"
#include "enums.h"
#include "helper.h"
#include <math.h>

//================================================================================
class read_param  {
private:
    int _years, _months;
    float _weight, _height;

public:
    virtual void set_param(int year, int month, float weight, float height);
    int get_year();
    int get_month();
    float get_weight();
    float get_height();
};
//================================================================================



//================================================================================
class age_group {
private:
    std::unique_ptr<writeln_info> _is_an_error;
    int ages_group;

public:
    virtual ~age_group() {}
    virtual void set_param(int year, int month);
    virtual int get_param();
};
//================================================================================



//================================================================================
class body_mass_index {
private:
    std::unique_ptr<writeln_info> _is_an_error;
    float bmi;

public:
    virtual ~body_mass_index() {}
    virtual void set_param(float body_height, float body_weight);
    virtual float get_param();
};
//================================================================================



//================================================================================
class age_grp_name  {
private:
    std::string age_g_name;

public:
    virtual ~age_grp_name() {}
    virtual void set_param(int index);
    virtual std::string get_param();
};
//================================================================================



//================================================================================
class delta_mass {
private:
    std::unique_ptr<writeln_info> _is_an_error;
    float delta;

public:
    virtual ~delta_mass() {}
    virtual void set_param(const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], float index, int group, float height, float weight);
    virtual float get_param();
};
//================================================================================



//================================================================================
class explain_bmi {
private:
    std::unique_ptr<writeln_info> _is_an_error;
    int explain;

public:
    virtual ~explain_bmi() {}
    virtual void set_param(float bodindex, const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], int group);
    virtual int get_param();
};
//================================================================================


//================================================================================
class interprit_bmi {
private:
    std::unique_ptr<writeln_info> _is_an_error;
    std::string interpritation;

public:
    virtual ~interprit_bmi() {}
    virtual void set_param(int index);
    virtual std::string get_param();
};
//================================================================================

class counters : public age_group, public body_mass_index,
        public age_grp_name, public delta_mass,
        public explain_bmi, public interprit_bmi {};

#endif // COUNTER_H
