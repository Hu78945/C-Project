#include <iostream>
#include <sys\stat.h>
#include <string.h>
#include <dirent.h>
#include <conio.h>
using namespace std;

int main()
{
    char *path = "D:\\OOP\\Project\\root\\";
    int NumOfFolder = 0, NumOfFiles = 0;

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        return 1;
    }
    struct dirent *entity;
    struct stat dst;
    if (dir != NULL)
    {
        for (entity = readdir(dir); entity != NULL; entity = readdir(dir))
        {
            string type = entity->d_name;
            type = path + type;
            if (stat(type.c_str(), &dst) == 0)
            {
                if (dst.st_mode & S_IFDIR)
                {
                    type = "is a folder";
                    NumOfFolder++;
                }
                else if (dst.st_mode & S_IFREG)
                {
                    type = "is a file";
                    NumOfFiles++;
                }
            }
            cout << entity->d_name << endl
                 << type << endl;
        }
        closedir(dir);
    }
    else
    {
        cout << "Error" << endl;
    }
    cout << "Folders " << NumOfFolder << endl
         << "Files " << NumOfFiles << endl;
}