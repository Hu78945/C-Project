#include "Folder.h"
#include <string>
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
        cout << "Press 4 to content the screen" << endl;
        cout << "Press 5 to create a new file" << endl;
        cout << "Press 6 to write to a file" << endl;
        cout << "Press 7 to read a file" << endl;
        cout << "Press 8 to clear data from a file" << endl;
        cout << "Press 9 to delte a file" << endl;
        cout << "Press 10 to open a folder" << endl;
        cout << "Press 11 to open folder menue" << endl;
        cout << "Press 12 to register a user" << endl;
        cout << "Press 13 to Login" << endl;
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
        case 5:
        {
            string fileName;
            cout << "Enter the fileName: " << endl;
            cin >> fileName;
            File f1;
            f1.CreateFile(fileName);
            break;
        }
        case 6:
        {
            system("cls");
            string fileName, fileContent;
            cout << "Enter the file name which you want to write" << endl;
            cin >> fileName;
            cout << "Enter the contet you want to write in the file" << endl;
            cin.ignore();
            getline(cin, fileContent, 'x');
            File f1;
            f1.WriteFile(fileName, fileContent);
            break;
        }
        case 7:
        {
            system("cls");
            string fileName;
            cout << "Enter the file name which you want to read" << endl;
            cin >> fileName;
            File f1;
            f1.ReadFile(fileName);
            break;
        }
        case 8:
        {
            system("cls");
            string fileName;
            cout << "Enter the file name which you want to clear" << endl;
            cin >> fileName;
            File f1;
            f1.ClearFile(fileName);
            break;
        }
        case 9:
        {
            system("cls");
            string fileName;
            cout << "Enter the file name: " << endl;
            cin >> fileName;
            File f1;
            f1.RemoveFile(fileName);
            break;
        }
        case 10:
        {
            system("cls");
            string folderName;
            cout << "Enter the folder Name you want to open" << endl;
            cin >> folderName;
            Folder::OpenFolder(folderName);
            break;
        }
        case 11:
        {
            system("cls");
            string folder;
            cout << "Enter the folder name you want to open" << endl;
            cin >> folder;
            Folder::OpenFolder(folder);
            break;
        }
        case 12:
        {
            system("cls");
            string userName, password;
            cout << "Enter username : " << endl;
            cin >> userName;
            cout << "Enter password: " << endl;
            cin >> password;
            Register r1(userName, password);
            break;
        }
        case 13:
        {
            system("cls");
            string username, password;
            cout << "Enter username: " << endl;
            cin >> username;
            cout << "Enter passowrd: " << endl;
            cin >> password;
            Login li(username, password);
            break;
        }

        case 0:
            cout << "Exting out of the program" << endl;
            ch = 0;
        }
    }
}
