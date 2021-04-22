#pragma once

#include "vector.cpp"
#include "plane.h"

class System
{
private:
    String file= "Planes.db";
    Vector <Plane *> planes; //what?
public:
    System();
    String get_file();
    void save();

    void create();
    void search();

    void user_menu();
};

