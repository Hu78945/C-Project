#include <iostream>
#include <direct.h>
#include <dirent.h>
#include "FileMangement.h"
using namespace std;

// constructor
FileMangement::FileMangement()
{
    strcpy(full_text, path);
    strcat(full_text, driveName);
    int folder = _mkdir(full_text);
}
// Member functions
char *FileMangement::getRootFolderAdress()
{
    return this->full_text;
}
/* void FileMangement::NumOfEntity(string typeOfFile)
{
    DIR *dir = opendir(full_text);
    if (dir == NULL)
    {
        cout << "There ar no folder here" << endl;
        return;
    }
    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        if (entity->d_namlen == 4)
        {
            numOfFolder++;
        }
        else if (entity->d_namlen == 8)
        {
            numOfFiles++;
        }
    };
    closedir(dir);
} */