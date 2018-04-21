
#include <stdio.h>
#include <dirent.h>
#include "printfast/includes/printfast.h"

int     main()
{
    DIR* dir;
    struct dirent *file;

    dir = opendir("TEST");
    while ((file = readdir(dir)) != NULL)
    {
        printfast("%s\n", file->d_name);
    }
    closedir(dir);
}