#include "coordinate.h"

int calc_dist(struct coordinate A, struct coordinate B) {
	int A_long = 0;
	int A_lat = 0;
	int B_long = 0;
	int B_lat = 0;

	A_long = A.longitude.degree * 3600 + A.longitude.minute * 60 + A.longitude.second;
	if (A.longitude.direction == 'W') A_long = -A_long;

	A_lat = A.latitude.degree * 3600 + A.latitude.minute * 60 + A.latitude.second;
	if (A.latitude.direction == 'S') A_lat = -A_lat;

	B_long = B.longitude.degree * 3600 + B.longitude.minute * 60 + B.longitude.second;
        if (B.longitude.direction == 'W') B_long = -B_long;

        B_lat = B.latitude.degree * 3600 + B.latitude.minute * 60 + B.latitude.second;
        if (B.latitude.direction == 'S') B_lat = -B_lat;

	int AB_long = A_long - B_long;
	if (AB_long < 0) AB_long = -AB_long;

	int AB_lat = A_lat - B_lat;
	if (AB_lat < 0) AB_lat = -AB_lat;

	return AB_long + AB_lat;
}
	
