#include <iostream>
#include <direct.h>
#include <dirent.h>
using namespace std;

class FileMangement
{
private:
    char *path = "D:\\OOP\\Project\\";
    char *driveName = "root";
    char *full_text = static_cast<char *>(malloc(strlen(path) + strlen(driveName) + 1));
    int numOfFolder, numOfFiles;

public:
    FileMangement();
    // get drive adress
    char *getRootFolderAdress();
    // get the number of folders and files
    void NumOfEntity(string typeOfFile);
};
