#include "Folder.h"
using namespace std;
int main()
{
    bool ch = 1;
    while (ch)
    {
        int choice;
        cout << "Press 1 to add a folder " << endl;
        cout << "Press 2 to delete a folder" << endl;
        cout << "Press 3 to get number of folder and files" << endl;
        cout << "Press 4 to cleaer the screen" << endl;
        cout << "Press 0 to exoit the program" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::string folderName;
            cout << "Enter folder name: ";
            cin >> folderName;
            Folder f1(folderName);
            cout << "Right back here" << endl;
            break;
        }
        case 2:
        {
            string folder;
            cout << "Enter Folder Name: ";
            cin >> folder;
            Folder::Remove(folder);
            break;
        }
        case 3:
        {
            system("cls");
            FileMangement f1;
            f1.NumOfEntity();
            break;
        }
        case 4:
        {
            system("cls");
            break;
        }
        case 0:
            cout << "Exting out of the program" << endl;
            ch = 0;
        }
    }
}