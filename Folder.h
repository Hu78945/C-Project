#pragma once
#include "FileMangement.h"
#include "File.h"
#include <iostream>
#include <string.h>
#include <direct.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include "Register.h"
#include "Login.h"
using namespace std;
class Folder : public FileMangement
{
private:
    char *folderName;

public:
    Folder(std::string folderName) : FileMangement()
    {
        char *RootPath = FileMangement::getRootFolderAdress();
        char *NewFolderPath = static_cast<char *>(malloc(strlen(RootPath) + strlen(folderName.c_str()) + 1));
        strcpy(NewFolderPath, RootPath);
        strcat(NewFolderPath, folderName.c_str());
        int folder = _mkdir(NewFolderPath);
        if (folder == -1)
        {
            perror("Error");
        }
        else
        {
            string f = "\\";
            strcat(NewFolderPath, f.c_str());
            this->folderName = NewFolderPath;
            cout << "Folder have been created" << endl;
        }
    };
    void static Remove(std::string folderName)
    {
        FileMangement f1;
        char *NewFolderPath = static_cast<char *>(malloc(strlen(folderName.c_str()) + strlen(f1.getRootFolderAdress()) + 1));
        strcpy(NewFolderPath, f1.getRootFolderAdress());
        strcat(NewFolderPath, folderName.c_str());
        cout << NewFolderPath << endl;
        string c = (string)NewFolderPath;
        string a = "rmdir /s /q " + c;
        system(a.c_str());
    }
    bool static IsPathExist(std::string folder)
    {
        // struct stat buffer;
        // return (stat(s.c_str(), &buffer) == 0);
        DIR *dir = opendir(folder.c_str());
        if (dir)
        {
            /* Directory exists. */
            closedir(dir);
            return 0;
        }
        else if (ENOENT == errno)
        {
            /* Directory does not exist. */
            return 1;
        }
        else
        {
            /* opendir() failed for some other reason. */
        }
    }

    void static OpenFolder(std::string folderName)
    {
        FileMangement f1;
        char *NewFolderPath = static_cast<char *>(malloc(strlen(folderName.c_str()) + strlen(f1.getRootFolderAdress()) + 1));
        strcpy(NewFolderPath, f1.getRootFolderAdress());
        strcat(NewFolderPath, folderName.c_str());
        string f = "\\";
        strcat(NewFolderPath, f.c_str());
        // after opening the folder

        if (IsPathExist(NewFolderPath))
        {
            std::cout << "The folder doesn't exist" << std::endl;
        }
        else
        {
            bool che = 1;
            int choice;
            while (che)
            {
                cout << "Now you are in " << NewFolderPath << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Press 1 to create a file" << endl;
                cout << "Press 2 to delete a file" << endl;
                cout << "Press 3 to write a file" << endl;
                cout << "Press 4 to read a file" << endl;
                cout << "Press 5 to clear you screen" << endl;
                cout << "Press 99 to go back to main menue" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Please Enter you choice :" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    string fileName;
                    cout << "Enter the fileName: " << endl;
                    cin >> fileName;
                    File file1;
                    file1.setPath(NewFolderPath);
                    file1.CreateFile(fileName);
                    break;
                }
                case 2:
                {
                    system("cls");
                    string fileName;
                    cout << "Enter the file name: " << endl;
                    cin >> fileName;
                    File file1;
                    file1.setPath(NewFolderPath);
                    file1.RemoveFile(fileName);
                    break;
                }
                case 3:
                {
                    system("cls");
                    string fileName, fileContent;
                    cout << "Enter the file name which you want to write" << endl;
                    cin >> fileName;
                    cout << "Enter the contet you want to write in the file" << endl;
                    cin.ignore();
                    getline(cin, fileContent, 'x');
                    File file1;
                    file1.setPath(NewFolderPath);
                    file1.WriteFile(fileName, fileContent);
                    break;
                }
                case 4:
                {
                    system("cls");
                    string fileName;
                    cout << "Enter the file name which you want to read" << endl;
                    cin >> fileName;
                    File file1;
                    file1.setPath(NewFolderPath);
                    file1.ReadFile(fileName);
                    break;
                }
                case 5:
                {
                    system("cls");
                    break;
                }

                case 99:
                {
                    che = 0;
                    break;
                }
                }
            }
        }
    }
};
