#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <math.h>

#define MAXBUF 512

struct geoinfo {
        int degree;
        int minute;
        int second;
        int total_sec;
        int dms;
        char direction;
};

struct coordinate {
        struct geoinfo longitude;
        struct geoinfo latitude;
};

int parse(struct coordinate* cord);
int get_gis(char* file_name, struct coordinate* A, struct coordinate* B);

