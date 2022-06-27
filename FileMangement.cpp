#pragma once
#include <iostream>
#include <sys\stat.h>
#include <direct.h>
#include <dirent.h>
#include "FileMangement.h"
using namespace std;

// constructor
FileMangement::FileMangement()
{
    strcpy(full_text, path.c_str());
    strcat(full_text, driveName.c_str());
    int folder = _mkdir(full_text);
    string f = "\\";
    strcat(full_text, f.c_str());
}
// Member functionsentity = readdir(dir)
char *FileMangement::getRootFolderAdress()
{
    return this->full_text;
}
void FileMangement::NumOfEntity()
{
    DIR *dir = opendir(full_text);
    if (dir == NULL)
    {
        cout << "There ar no folder here" << endl;
        return;
    }
    struct dirent *entity;
    struct stat dataType;
    for (entity = readdir(dir); entity != NULL; entity = readdir(dir))
    {
        string type = entity->d_name;
        type = full_text + type;
        if (stat(type.c_str(), &dataType) == 0)
        {
            if (dataType.st_mode & S_IFDIR)
            {
                type = "Folder";
                numOfFolder++;
            }
            else if (dataType.st_mode & S_IFREG)
            {
                type = "File";
                numOfFiles++;
            }
        }
    }
    closedir(dir);
    cout << "Number Of Folders: " << numOfFolder - 2 << endl;
    cout << "Number Of Files: " << numOfFiles << endl;
}
void FileMangement::setRootFolderAdress(string adress)
{
    strcpy(full_text, adress.c_str());
}
