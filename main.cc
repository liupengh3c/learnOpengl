
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
    else if (strcmp(argv[1], "color") == 0)
    {
        color();
    }
    else if (strcmp(argv[1], "light") == 0)
    {
        basic_lighting();
    }
    else if (strcmp(argv[1], "material") == 0)
    {
        material ::materials();
    }
    else if (strcmp(argv[1], "lightmap") == 0)
    {
        lightmap ::lightmap();
    }
    return 0;
}
