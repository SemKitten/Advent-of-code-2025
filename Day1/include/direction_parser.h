#ifndef DIRECTION_PARSER_H
#define DIRECTION_PARSER_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool is_left;
    int distance;   
} Rotation;

static int count_zero_hits_in_rotation(int current, Rotation r);

bool parse_rotation_line(const char *line, Rotation *out);

int apply_rotation(int current, Rotation r);

int count_zero_landings(FILE *file, int start);


#endif