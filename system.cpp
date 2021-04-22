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
    for (int i = 0; i < planes.size(); i++)
    {
        if (planes[i]->get_id() == search_id)
        {
            planes[i]->print();
            return;
        }
    }
    cout << "Record not found!" << endl;
}
//create
//100000 Mig-21 Fighter 100
//105000 A320 Airliner 5000
void System::user_menu()
{
    String option;
    cout << "type \"help\" for help" << endl;
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
            cout << "The following commands are supported:\n";
            cout << "create    creates an entry for a given plane\n";
            cout << "search    searches for a plane by its unique id\n";
            cout << "exit:     exits the program\n";
            cout << "help:     prints this information\n";
        }
        else
            cout << "you messed up, press Ctrl + C to stop and try again";
    }
}
