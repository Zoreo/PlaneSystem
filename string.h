#pragma once
#include <iostream>
using namespace std;

class String
{
private:
    char *content;
    unsigned len;
    // char s[250];

public:
    String();
    String(const String &);
    String(const char *); // String a = "asd";
    ~String();
    char *get_content();
    void set_content(char buf[]);
    char &operator[](int);
    unsigned length() const;
    friend ostream &operator<<(ostream &, String &);
    friend istream &operator>>(istream &, String &);
};

void strcopy(char *&b, const char *a);
int strcmp(const char *s1, const char *s2);
unsigned strlength(const char *a);
