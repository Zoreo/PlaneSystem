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
    // String operator+(String &); // String a, b.... String c = a + b;
    // String &operator=(const String &);
    // String &operator+=(String &);
    char &operator[](int);
    unsigned length() const;
    friend ostream &operator<<(ostream &, String &);
    friend istream &operator>>(istream &, String &);
};

int strcmp(const char* s1, const char* s2);
void strcopy(char *&b, const char *a);
unsigned strlength(const char *a);


