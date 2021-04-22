#pragma once

#include "vector.h"
#include "plane.h"

class System
{
private:
    String file = "Planes.db";
    Vector<Plane *> planes; 
public:
    System();
    String get_file();
    void save();

    void create();
    void search();

    void user_menu();
};
