#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "direction_parser.h"

int main(int argc, char *argv[]) {

    FILE* file = fopen("src/input.txt", "r");
    if (file == NULL) {
        perror("fopen input.txt");
        return 1;
    }

    int start = 50;
    int zeros = count_zero_landings(file, start);
    printf("Times dial lands on 0: %d\n", zeros);

    fclose(file);
    return 0;
}