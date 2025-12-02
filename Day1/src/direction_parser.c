#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "direction_parser.h"

static int count_zero_hits_in_rotation(int current, Rotation r) {
    int d = r.distance;
    if (d <= 0) return 0;

    if (r.is_left) {
        if (current == 0) {

            return d / 100;
        } else {
            if (d < current) return 0;
            return 1 + (d - current) / 100;
        }
    } else {
        if (current == 0) {

            return d / 100;
        } else {
            int first = 100 - current;
            if (d < first) return 0;
            return 1 + (d - first) / 100;
        }
    }
}

bool parse_rotation_line(const char *line, Rotation *out) {
    while (*line && isspace((unsigned char)*line)) {
        line++;
    }

    if (*line != 'L' && *line != 'R') return false;
    out->is_left = (*line == 'L');
    line++;

    while (*line && isspace((unsigned char)*line)) {
        line++;
    }

    int dist = 0;
    if (!isdigit((unsigned char)*line)) return false;

    while (*line && isdigit((unsigned char)*line)) {
        dist = dist * 10 + (*line - '0');
        line++;
    }

    out->distance = dist;
    return true;
}

int apply_rotation(int current, Rotation r) {
    int mod = 100;
    if (r.is_left) {
        current = (current - r.distance) % mod;
    } else {
        current = (current + r.distance) % mod;
    }
    if (current < 0) current+= mod;
    return current;
}

int count_zero_landings(FILE *file, int start) {
    char buf[100];
    int dial = start;
    int count = 0;

    while (fgets(buf, sizeof(buf), file) != NULL) {
         Rotation r;
         if (!parse_rotation_line(buf, &r)) {
            continue;
         }
         // Count all zero hits during the rotation
         count += count_zero_hits_in_rotation(dial, r);
         // Then update the dial to its final position after this rotation
         dial = apply_rotation(dial, r);
    }
    return count;
}