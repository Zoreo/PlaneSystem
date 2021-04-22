#pragma once

#include <iostream>
#include <fstream>
#include "string.h" //so i dont have to do all the dynamic things by hand

// Id - определя еднозначно конкретен самолет (уникално цяло положително число);
// Plane - име на самолет (низ, който е с динамична дължина);
// Type - тип на самолета (изтребител,  военнотранспортен самолет, пътнически самолет и др. Типът на полето е низ, който е с максимална дължина 20 символа);
// Flights 	- брой полети на самолета (цяло положително число);

struct Plane
{
private:
    int id;
    String plane;
    char type[20];
    unsigned flights;

public:
    Plane();
    Plane(int id, String plane, const char type[20], unsigned flights); //dont really need that
    ~Plane();                                                           //dont need that either, the vector and string classes delete themselves

    int get_id();
    String get_plane();
    const char *get_type() const;
    unsigned get_flights();

    void read_file(ifstream &in);
    void input();
    void write_file(ofstream &out);
    void print();
};
