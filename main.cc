
#include <string.h>
#include <iostream>
#include "steps.h"
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "please input the right param\n"
                  << std::endl;
        return -1;
    }
    if (strcmp(argv[1], "shader") == 0)
    {
        shader();
    }
    else if (strcmp(argv[1], "coordinate") == 0)
    {
        coordinate();
    }
    else if (strcmp(argv[1], "camera") == 0)
    {
        camera();
    }
    return 0;
}
