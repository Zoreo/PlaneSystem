#include "plane.h"
Plane::Plane(){};
Plane::Plane(int id, String plane, const char new_type[20], unsigned flights) : id(id), plane(plane), flights(flights) {}

int Plane::get_id()
{
    return id;
}
String Plane::get_plane()
{
    return plane;
}
const char *Plane::get_type() const
{
    return type;
}
unsigned Plane::get_flights()
{
    return flights;
}

void Plane::read_file(ifstream &in)
{
    in >> id;
    in >> plane;
    in >> type;
    in >> flights;
    in.ignore();
}

void Plane::input()
{
    cin >> id;
    cin >> plane;
    cin >> type;
    cin >> flights;
}

void Plane::write_file(ofstream &out)
{
    out << id << ' ';
    out << plane.get_content() << ' ';
    out << type << ' ';
    out << flights;
}

void Plane::print()
{
    cout << id << ' ' << plane << ' ' << type << ' ' << flights << endl;
}
