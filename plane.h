#pragma once

#include <iostream>
#include <fstream>
#include "string.h"
struct Plane
{
private:
    int id;
    String plane;
    char type[20];
    unsigned flights;

public:
    Plane();
    Plane(int id, String plane, const char type[20], unsigned flights);
    ~Plane();

    int get_id();
    String get_plane();
    const char *get_type() const;
    unsigned get_flights();

    void read_file(ifstream &in);
    void input();
    void write_file(ofstream &out);
    void print();
};
