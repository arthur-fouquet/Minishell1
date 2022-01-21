#include <stdlib.h>

int main(int ac, char **av)
{
    char *str = malloc(sizeof(char) * 1);

    free(str);
    free(str);
    free(str);
    return 0;
}
