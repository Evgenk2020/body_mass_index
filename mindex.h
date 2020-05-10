#ifndef M_index_H
#define M_index_H

#include <iostream>
#include <math.h>
#include "data.h"


//================================================================================
//help and error interface messages declare
class write_lines {
public:
    virtual ~write_lines() {}
    virtual void write() = 0;
};

class _help : public write_lines {
public:
    virtual ~_help() {}
    virtual void write() override;
};

class _error : public write_lines {
public:
    virtual ~_error() {}
    virtual void write() override;
};

class writeln : public _help, public _error {};
//================================================================================



//================================================================================
//cout of indexes and results settings
class ageindex {
public:
    virtual ~ageindex() {}
    int index();
};

class _index : public ageindex {
private:
    std::unique_ptr<writeln> _is_an_error;

public:
    virtual ~_index() {}
    using ageindex::index;
    float index(float body_height, float body_weight);
};

class _group : public ageindex {
private:
    std::unique_ptr<writeln> _is_an_error;

public:
    virtual ~_group() {}
    using ageindex::index;
    int index(int year, int month) ;
};

class _name : public ageindex {
public:
    virtual ~_name() {}
    using ageindex::index;
    std::string index(int index);
};

class _delta : public ageindex {
private:
    std::unique_ptr<writeln> _is_an_error;

public:
    virtual ~_delta() {}
    using ageindex::index;
    float index (const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], float index, int group, float height, float weight);

};

class _explain : public ageindex {
private:
    std::unique_ptr<writeln> _is_an_error;

public:
    virtual ~_explain() {}
    using ageindex::index;
    int explain(float bodindex, const float base[MAX_GEND_INDEX][MAX_AGE_INDEX], int group);
};

class _interprit : public ageindex {
public:
    virtual ~_interprit() {}
    using ageindex::index;
    std::string index(int index);
};

class _data : public _index, public _group,
        public _name, public _delta, public _explain,
        public _interprit {};
//================================================================================

#endif // M_index_H
