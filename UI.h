#pragma once
#include "Folder.h"
class UI
{
public:
    UI()
    {
        bool ch = 1;
        while (ch)
        {
            int choice;
            cout << "Press 1 to add a folder " << endl;
            cout << "Press 2 to delete a folder" << endl;
            cout << "Press 0 to exoit the program" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                char *folderName;
                cout << "Enter folder name: ";
                cin >> folderName;
                Folder f1(folderName);
                cout << "Right back here" << endl;
                break;
            }
            case 2:
            {
                char *folderName;
                cout << "Enter Folder Name: ";
                cin >> folderName;
                Folder::Remove(folderName);
                break;
            }
            case 0:
                ch = 0;
            }
        }
    };
};
