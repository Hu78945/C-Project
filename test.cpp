#include <iostream>
#include <string.h>
#include <dirent.h>
using namespace std;

int main()
{
    char *path = "D:\\OOP\\Project\\root";
    int NumOfFolder, NumOfFiles;

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        return 1;
    }
    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        // if (entity->d_namlen == 8)
        // {
        //     NumOfFiles++;
        // }
        // else if (entity->d_namlen == 4)
        // {
        //     NumOfFolder++;
        // }
        cout << " " << entity->d_name << endl;
        entity = readdir(dir);
    }
    // cout << "Number of folders " << NumOfFolder << endl;
    // cout << "Number of files " << NumOfFiles << endl;

    closedir(dir);
}