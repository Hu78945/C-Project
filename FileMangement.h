#include <iostream>
#include <sys\stat.h>
#include <direct.h>
#include <dirent.h>
using namespace std;

class FileMangement
{
private:
    string path = "C:\\";
    string driveName = "root";
    char *full_text = static_cast<char *>(malloc(strlen(path.c_str()) + strlen(driveName.c_str()) + 1));
    int numOfFolder = 0, numOfFiles = 0;

public:
    FileMangement();
    // get drive adress
    char *getRootFolderAdress();
    // get the number of folders and files
    void NumOfEntity();
    // set RootFolderAdress
    void setRootFolderAdress(string adress);
};
