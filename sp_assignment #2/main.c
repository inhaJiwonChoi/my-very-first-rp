#include "coordinate.h"

struct coordinate A[MAXBUF];
struct coordinate B[MAXBUF];

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage: %s <file name> man OR euc\n", argv[0]);
                exit(1);
	}

	int line;
	
	void *handle;
	int (*calc_dist)(struct coordinate A, struct coordinate B);
	
	if (argv[2][0] == 'm') {
		if ((handle = dlopen("./libman.so", RTLD_LAZY)) == NULL) {
			perror("dlopen");
			exit(1);
		}
	}
	else if (argv[2][0] == 'e') {
		if ((handle = dlopen("./libeuc.so", RTLD_LAZY)) == NULL) {
                        perror("dlopen");
                        exit(1);
                }
	}
	else {
		printf("Usage: %s <file name> man OR euc\n", argv[0]);
		exit(1);
	}

	calc_dist = dlsym(handle, "calc_dist");

	if (dlerror() != NULL) {
		perror("dlerror");
		exit(1);
	}

	line = get_gis(argv[1], A, B);
	
	for (int i = 0; i < line; i++) {
		int total_dist = calc_dist(A[i], B[i]);
		int d_dist = total_dist / 3600;
		int m_dist = (total_dist - 3600 * d_dist) / 60;
		int s_dist = total_dist - 3600 * d_dist - 60 * m_dist;
		printf("(%03dd %02dm %02ds %c, %03dd %02dm %02ds %c) ",
				A[i].longitude.degree,
				A[i].longitude.minute,
				A[i].longitude.second,
				A[i].longitude.direction,
				A[i].latitude.degree,
				A[i].latitude.minute,
				A[i].latitude.second,
				A[i].latitude.direction);
		printf("(%03dd %02dm %02ds %c, %03dd %02dm %02ds %c) ",
                                B[i].longitude.degree,
                                B[i].longitude.minute,
                                B[i].longitude.second,
                                B[i].longitude.direction,
                                B[i].latitude.degree,
                                B[i].latitude.minute,
                                B[i].latitude.second,
                                B[i].latitude.direction);
		printf("%06d ", total_dist);
		printf("%03dd %02dm %02ds\n", d_dist, m_dist, s_dist);
	}

	return 0;
}
