#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("oui", O_RDONLY);
    if (fd < 0) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    
    char *line;
    while ((line = get_next_line(fd))) {
        printf("%s\n", line);
        free(line);
    }
    
    close(fd);
    return 0;
}
