#include "coordinate.h"

int get_gis(char* file_name, struct coordinate* A, struct coordinate* B) {
	FILE *fp = fopen(file_name, "r");
	int cur = 0;

	while (!feof(fp)) {
		fscanf(fp, "(%d%c, %d%c) (%d%c, %d%c) \n",
			&A[cur].longitude.dms, &A[cur].longitude.direction,
			&A[cur].latitude.dms, &A[cur].latitude.direction,
			&B[cur].longitude.dms, &B[cur].longitude.direction,
			&B[cur].latitude.dms, &B[cur].latitude.direction);

			parse(&A[cur]);
			parse(&B[cur]);
		cur++;
	}

	fclose(fp);
	return cur;
}

int parse(struct coordinate* cord) {
	cord->longitude.degree = cord->longitude.dms / 10000;
	cord->longitude.minute = (cord->longitude.dms - cord->longitude.degree * 10000) / 100;
	cord->longitude.second = cord->longitude.dms - cord->longitude.degree * 10000 - cord->longitude.minute * 100;

	cord->latitude.degree = cord->latitude.dms / 10000;
        cord->latitude.minute = (cord->latitude.dms - cord->latitude.degree * 10000) / 100;
        cord->latitude.second = cord->latitude.dms - cord->latitude.degree * 10000 - cord->latitude.minute * 100;

	return 0;
}
