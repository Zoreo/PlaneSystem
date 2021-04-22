#include "system.h"
#include "string.h"

System::System() {}

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
    for (int i = 0; i < planes.size(); ++i)
    {
        if (planes[i]->get_id() == search_id)
        {
            planes[i]->print();
        }
        else cout << "Record not found!" << endl;
        return;
    }
    cout << "Record not found!" << endl; //kinda wack but it works
}
//create
//100000 Mig-21 Fighter 100
//105000 A320 Airliner 5000
void System::user_menu()
{
    String option;
    while (true)
    {
        cout << ": ";
        cin >> option;
        if (strcmp(option.get_content(), "create") == 0)
        {
            cout << "> ";
            create();
            save();
        }
        else if (strcmp(option.get_content(), "search") == 0)
        {
            cout << "> ";
            search();
        }
        else if (strcmp(option.get_content(), "exit") == 0)
        {
            break;
        }
        else if (strcmp(option.get_content(), "help") == 0)
        {
            cout << "The following comnds are supported:\n";
            cout << "create    creates a file\n";
            cout << "search    searches for a plane by its unique id\n";
            cout << "exit:     exits the program\n";
            cout << "help:     prints this information\n";
        }
        else
            cout << "try again lmao, type \"help\" for help\n";
    }
}
