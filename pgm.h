#ifndef PGM_H_
#define PGM_H_

struct PGM
{
	char magicNumber[3];
	int width;
	int height;
	int color;
	int **pixel;
};
typedef struct PGM pgm_t;

void free_pgm(pgm_t *);

int pgm_export(pgm_t *, char *);

int pgm_create(pgm_t **, int, int);

void set_pixel(pgm_t *, int, int, int);

int is_inside(pgm_t *, int, int);

#endif