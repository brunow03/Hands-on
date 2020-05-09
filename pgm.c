#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <pgm.h>
#include <string.h>

int pgm_create(pgm_t **image, int width, int height)
{
	if(!image || width < 0 || height < 0) return ERROR_PGM;

	int i, j;

	*image = (pgm_t *)calloc(1, sizeof(pgm_t));

	(*image)->magicNumber[0] = 'P';
	(*image)->magicNumber[1] = '2';
	(*image)->magicNumber[2] = '\0';
	
	(*image)->width = width;
	(*image)->height = height;
	(*image)->color = 255;

	(*image)->pixel = (int **)calloc((*image)->height, sizeof(int *));
	
	for(i = 0; i < height; i++)
		(*image)->pixel[i] = (int *)calloc(width, sizeof(int));

	//preenche tudo de preto, inicialmente
	for(i=0; i < height; i++)
	{
		for(j=0; j < width; j++) 
		{
			set_pixel(*image, j, i, 0);
		}
	}

	return SUCCESS_PGM;
}

int pgm_export(pgm_t *image, char *name)
{
	if(!image || !name) return ERROR_PGM;

	FILE *arq;
	int i, j;

	strcat(name, ".pgm");	//concatena o nome a .pgm

	arq = fopen(name, "w");

	fprintf(arq, "%s\n%d %d\n%d\n", image->magicNumber, image->height, image->width, image->color);

	for(i=0; i<image->height; i++)
	{
		for(j=0; j<image->width; j++) fprintf(arq, "%d ", image->pixel[i][j]);
		fprintf(arq, "\n");
	}
	fclose(arq);

	//liberando espaço
	free_pgm(image);

	return SUCCESS_PGM;
}

void set_pixel(pgm_t *image, int x, int y, int color)
{
	image->pixel[image->height - y - 1][x] = color;
}

//verifica se o ponto ordenado está dentro da imagem
int is_inside(pgm_t *image, int x, int y)
{
	if(x >= 0 && x < image->width && y >= 0 && y < image->height)	
		return 1;
	else	
		return 0;
}

void free_pgm(pgm_t *image)
{
	int i;

	for(i = 0; i < image->height; i++)
		free(image->pixel[i]);
	free(image->pixel);
	free(image);

}