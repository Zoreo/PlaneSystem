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

int strcmp(const char* s1, const char* s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char *String::get_content() { return content; }
// void String::set_len
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
// String &String::operator=(const String &other)
// {
//     strcopy(content, other.content);
//     len = other.len;
//     return *this;
// }

char &String::operator[](int a)
{
    return content[a];
}
// String String::operator+(String &other)
// {
//     char *str = new char[other.len + len + 1];
//     for (int i = 0; i < len; i++)
//     {
//         str[i] = content[i];
//     }
//     for (int i = 0; i < other.len; i++)
//     {
//         str[len + i] = other[i];
//     }
//     str[other.len + len] = 0;
//     len = other.len + len;
//     String a(str);
//     return a;
// }
// String &String::operator+=(String &other)
// {
//     String c = *this + other;
//     *this = c;
//     return *this;
// }
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
    in >> arr; //so that it only gets the first word
    a.set_content(arr);
    delete arr;
    return in;
}

// int main()
// {
//     String a = "abcd";
//     String b;
//     cout << "b default: " << b << endl;
//     b = a;
//     cout << "b operator =" << b << endl;
//     String c = b;
//     cout << "c copy constructor: " << c << endl;
//     String d = "zzz";
//     String str = c + d;
//     cout << "str operator + " << str << endl;
//     String h = "ttt";
//     str += h;
//     cout << "str operator += " << str << endl;
//     cout << "str length: " << str.length() << endl;
//     return 0;
// }
