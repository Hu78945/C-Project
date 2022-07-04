#include "Folder.h"
#include <string>
using namespace std;
int main()
{
    // make folder in the userFolder
    string path = "C:\\root\\Database\\";
    string username, password;

    bool LoginStat = 1;
    bool quit = 1;
    while (quit)
    {
        cout << "Press 1 To Login" << endl;
        cout << "Press 2 to register" << endl;
        cout << "Press 0 to Gust Mode" << endl;
        cout << "Plese enter your choice: " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "Enter username: " << endl;
            cin >> username;
            cout << "Enter passowrd: " << endl;
            cin >> password;
            Login li(username, password);
            LoginStat = li.isLoggedIn;
            quit = 0;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Enter username : " << endl;
            cin >> username;
            cout << "Enter password: " << endl;
            cin >> password;
            Register r1(username, password);
            break;
        }
        case 0:
            cout << "Opeing in the public mode " << endl;
            quit = 0;
            break;
        }
    }
    LoginStat == 0 ? path += username + "\\" : "";
    //////////////////////////////////////////////////////////
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
        cout << "Press 11 to make a file public" << endl;
        cout << "Press 12 to copy file to public" << endl;
        cout << "Press 13 to rename a file" << endl;
        cout << "Press 14 to make folder public " << endl;
        cout << "Press 15 to rename a folder" << endl;
        cout << "Press 0 to exoit the program" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (LoginStat == 0)
            {
                string folderName;
                cout << "Enter folder name: ";
                cin >> folderName;
                Folder f1;
                cout << "Do you want to make th folder public: (y/n)";
                char choice;
                cin >> choice;
                if (choice == 'n')
                {
                    f1.SetRootPath(path);
                    f1.CreateFolder(folderName);
                }
                else
                {
                    f1.CreateFolder(folderName);
                }
                cout << "Right back here" << endl;
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 2:
        {
            if (LoginStat == 0)
            {
                string folder;
                cout << "Enter Folder Name: ";
                cin >> folder;
                Folder f1;
                cout << "Do you want to delete the folder public: (y/n)";
                char choice;
                cin >> choice;
                if (choice == 'n')
                {
                    f1.SetRootPath(path);
                    f1.Remove(folder);
                }
                else
                {
                    f1.Remove(folder);
                }
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
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
            if (LoginStat == 0)
            {
                string fileName;
                cout << "Enter the fileName: " << endl;
                cin >> fileName;
                File f1;
                cout << "Do you want to make it public (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n')
                {
                    f1.setPath(path);
                    f1.CreateFile(fileName);
                }
                else
                {
                    f1.CreateFile(fileName);
                }
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 6:
        {
            if (LoginStat == 0)
            {
                system("cls");
                string fileName, fileContent;
                cout << "Enter the file name which you want to write" << endl;
                cin >> fileName;
                cout << "Enter the contet you want to write in the file" << endl;
                cin.ignore();
                getline(cin, fileContent, 'x');
                File f1;
                cout << "Do you want to make it public (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n')
                {
                    f1.setPath(path);
                    f1.WriteFile(fileName, fileContent);
                }
                else
                {
                    f1.WriteFile(fileName, fileContent);
                }
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 7:
        {
            system("cls");
            string fileName;
            cout << "Enter the file name which you want to read" << endl;
            cin >> fileName;
            File f1;
            if (LoginStat == 0)
            {
                cout << "Do you want to make it public (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n')
                {

                    f1.setPath(path);
                    f1.ReadFile(fileName);
                }
                else
                {
                    f1.ReadFile(fileName);
                }
                break;
            }
            else
            {
                f1.ReadFile(fileName);
                break;
            }
        }
        case 8:
        {
            if (LoginStat == 0)
            {
                system("cls");
                string fileName;
                cout << "Enter the file name which you want to clear" << endl;
                cin >> fileName;
                File f1;
                cout << "Do you want to make it public (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n')
                {

                    f1.setPath(path);
                    f1.ClearFile(fileName);
                }
                else
                {
                    f1.ClearFile(fileName);
                }
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 9:
        {
            if (LoginStat == 0)
            {
                system("cls");
                string fileName;
                cout << "Enter the file name: " << endl;
                cin >> fileName;
                File f1;
                cout << "Do you want to delte it from public (y/n)" << endl;
                char choice;
                cin >> choice;
                if (choice == 'n')
                {

                    f1.setPath(path);
                    f1.RemoveFile(fileName);
                }
                else
                {
                    f1.RemoveFile(fileName);
                }
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 10:
        {
            if (LoginStat == 0)
            {
                system("cls");
                string folderName;
                cout << "Enter the folder Name you want to open" << endl;
                cin >> folderName;
                Folder f1;

                cout << "Do you want to make th folder public: (y/n)";
                char choice;
                cin >> choice;
                if (choice == 'n')
                {
                    f1.SetRootPath(path);
                    f1.OpenFolder(folderName);
                }
                else
                {

                    f1.OpenFolder(folderName);
                }
                break;
            }
            else
            {
                cout << "Please login to do that operation" << endl;
                break;
            }
        }
        case 11:
        {
            if (LoginStat == 0)
            {
                system("cls");
                cout << "Enter the file name which you want to public:" << endl;
                string fileName;
                cin >> fileName;
                FileOperation p1(fileName, path);
                p1.MakeFilePublic();
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 12:
        {
            if (LoginStat == 0)
            {
                system("cls");
                cout << "Enter the file name which you want to copy to public folder" << endl;
                string fileName;
                cin >> fileName;
                FileOperation f1(fileName, path);
                f1.CopyFileToPublic();
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 13:
        {
            if (LoginStat == 0)
            {
                system("cls");
                cout << "Enter the file which you want to rename" << endl;
                string fileName;
                cin >> fileName;
                cout << "Enter the new name whoch you want ot give to your file" << endl;
                string newName;
                cin >> newName;
                FileOperation f1(fileName, path);
                f1.RenameFile(newName);
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 14:
        {
            if (LoginStat == 0)
            {
                cout << "Enter the folder name which you want to make public" << endl;
                string folderName;
                cin >> folderName;
                FolderOperation f1(folderName, path);
                f1.MakeFolderPublic();
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }
        case 15:
        {
            if (LoginStat == 0)
            {
                cout << "Enter the folder name which you want to rename" << endl;
                string folderName;
                cin >> folderName;
                cout << "Enter the new Folder name" << endl;
                string newName;
                cin >> newName;
                FolderOperation f1(folderName, path);
                f1.RenameFolder(newName);
                break;
            }
            else
            {
                cout << "Plese restart and login to do these operations" << endl;
                break;
            }
        }

        case 0:
            cout << "Exting out of the program" << endl;
            ch = 0;
        }
    }
}
