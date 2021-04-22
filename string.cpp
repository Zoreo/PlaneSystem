#include "string.h"

unsigned strlength(const char *a)
{
    int i = 0;
    while (a[i] != 0)
    {
        i++;
    }
    return i;
}

int strcmp(const char* s1, const char* s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
void strcopy(char *&b, const char *a)
{
    if (b != nullptr)
        delete[] b;
    b = nullptr;
    if (a == nullptr)
        return;
    int length = strlength(a);
    b = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        b[i] = a[i];
    }
    b[length] = 0;
}


char *String::get_content() { return content; }

void String::set_content(char buf[]){
    strcopy(content, buf);
    len = sizeof(buf)/sizeof(buf[0]);
}

String::String() : content(nullptr), len(0) {}

String::String(const char *a) : content(nullptr)
{
    strcopy(content, a);
    len = strlength(a);
}
String::String(const String &other) : content(nullptr)
{
    strcopy(content, other.content);
    len = other.len;
}
String::~String()
{
    if (content != nullptr)
        delete[] content;
}

char &String::operator[](int a)
{
    return content[a];
}
unsigned String::length() const
{
    return len;
}
ostream &operator<<(ostream &os, String &s)
{
    if (s.content != nullptr)
        cout << s.content;
    return os;

}
istream &operator>>(istream &in, String &a)
{
    int size = 1024;
    char *arr = new char[size];
    in >> arr;
    a.set_content(arr);
    delete arr;
    return in;
}
