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
    void set_param(int year, int month, float weight, float height);
    int get_year();
    int get_month();
    float get_weight();
    float get_height();
    ~read_param() {}
};
//================================================================================



//================================================================================
template <typename T>
class x_param {
private:
    std::unique_ptr<writer> is_an_error;
    T temp;

public:
    void x_set(T one, T two);
    T x_get();
    ~x_param() {}
};
//================================================================================



//================================================================================
//class x_param
template <typename T>
T x_param<T>::x_get() {return temp;}
//================================================================================



//================================================================================
class x_names {
protected:
    std::string x_name_res;

public:
    virtual ~x_names() {}
    virtual void set_param(int index) = 0;
    std::string get_param();
};

class x_nam_grp : public x_names {
public:
    ~x_nam_grp() {}
    void set_param(int index) override;
};

class x_interprit : public x_names {
public:
    ~x_interprit() {}
    void set_param(int index) override;
};
//================================================================================



//================================================================================
class delta_mass {
private:
    std::unique_ptr<writer> is_an_error;
    float delta;

public:
    void set_param(const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], float index, int group, float height, float weight);
    float get_param();
    ~delta_mass() {}
};
//================================================================================



//================================================================================
class explain_bmi {
private:
    std::unique_ptr<writer> is_an_error;
    int explain;

public:
    void set_param(float bodindex, const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], int group);
    int get_param();
    ~explain_bmi() {}
};
//================================================================================

#endif // COUNTER_H
