#include <iostream>
#include <sys\stat.h>
#include <direct.h>
#include <dirent.h>
using namespace std;

class FileMangement
{
private:
    char *path = (char *)"D:\\OOP\\Project\\";
    char *driveName = (char *)"root";
    char *full_text = static_cast<char *>(malloc(strlen(path) + strlen(driveName) + 1));
    int numOfFolder = 0, numOfFiles = 0;

public:
    FileMangement();

    // get drive adress
    char *getRootFolderAdress();
    // get the number of folders and files
    void NumOfEntity();
};
