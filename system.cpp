#include "system.h"

System::System(){}

String System::get_file() { return file; }

void System::save()
{
    ofstream out(this->get_file().get_content());
    if (out.is_open())
    {
        for (int i = 0; i < planes.size(); ++i)
        {
            planes[i]->write_file(out);
            if (i != planes.size() - 1)
                out << endl;
        }
    }
    else
    {
        perror(this->get_file().get_content());
    }
}

void System::create()
{
    {
        Plane *p = new Plane();
        p->input();
        planes.push_back(p);
    }
}

void System::search()
{
    int search_id;
    cin >> search_id;
    cin.ignore();
    for (int i = 0; i < planes.size(); ++i)
    {
        if (planes[i]->get_id() == search_id)
            planes[i]->print();
    }
}

void System::user_menu()
{
    String option;
    while (true)
    {
        cout << ": ";
        cin >> option;
        if (option.get_content() == "create")
        {
            cout << "> ";
            create();
            save();
        }
        else if (option.get_content() == "search")
        {
            cout << "> ";
            search();
        }
        else if (option.get_content() == "exit")
        {
            break;
        }
        else if (option.get_content() == "help")
        {
            cout << "The following commands are supported:\n";
            cout << "create    creates a file";
            cout << "search    searches for a plane by its unique id";
            cout << "exit:     exits the program\n";
            cout << "help:     prints this information\n";
        }
        else
            cout << "try again lmao, type \"help\" for help";
    }
}
