#include <stdio.h>
#include <math.h>
#include <pgm.h>
#include <constants.h>



int draw_circle(pgm_t *image, int x0, int y0, int raio, int color)
{
	if(!image || raio <= 0 || color < 0 || color > MAX_COLOR_VALUE) return ERROR_PGM;

	int i, j, y_up, y_down, x_right, x_left;

	for(i=x0-raio; i<x0+raio; i++)
	{
		y_up = y0 + sqrt(pow(raio, 2) - pow(i - x0, 2));
		y_down = y0 - sqrt(pow(raio, 2) - pow(i - x0, 2));

		if(is_inside(image, i, y_up))
		{
			set_pixel(image, i, y_up, color);
		}
		if(is_inside(image, i, y_down))
		{
			set_pixel(image, i, y_down, color);
		}

	}

	for(j=y0-raio; j<y0+raio; j++)
	{
		x_right = x0 + sqrt(pow(raio, 2) - pow(j - y0, 2));
		x_left = x0 - sqrt(pow(raio, 2) - pow(j - y0, 2));

		if(is_inside(image, x_right, j))
		{
			set_pixel(image, x_right, j, color);
		}
		if(is_inside(image, x_left, j))
		{
			set_pixel(image, x_left, j, color);
		}
	}	

	return SUCCESS_PGM;	
}

int draw_rect(pgm_t *image, int x, int y, int width, int height, int color)
{
	if(!image || width < 0 || height < 0 || color < 0 || color > MAX_COLOR_VALUE) return ERROR_PGM;

	int i, j;

	for(i=x-width/2; i<x+width/2; i++)
	{
		for(j=y-height/2; j<y+height/2; j++)
			if(is_inside(image, i, j))
				set_pixel(image, i, j, color);
	}

	return SUCCESS_PGM;
}

int draw_disk(pgm_t *image, int x0, int y0, int raio, int color)
{
	if(!image || raio < 0 || color < 0 || color > MAX_COLOR_VALUE) return ERROR_PGM;

	int i, j;

	for(i=x0-raio; i<x0+raio; i++)
	{	
		for(j=y0-raio; j<y0+raio; j++)
		{
			if(pow(i-x0, 2) + pow(j-y0, 2) <= pow(raio, 2) && is_inside(image, i, j))	
				set_pixel(image, i, j, color);
		}
	}

	return SUCCESS_PGM;
}

int draw_line(pgm_t *image, int x1, int y1, int x2, int y2, int color)
{
	if(!image || color < 0 || color > MAX_COLOR_VALUE) return ERROR_PGM;

	float i, y;
	float tan;

	if(x1 < x2)
	{
		tan = ((float)y2 - y1)/(x2 - x1);
		for(i=x1; i<x2; i+=0.001){ //0.001 de incremento para a linha parecer contínua quando o ângulo estiver muito
			y = y1 + tan*(i-x1); //próximo de 90º
			if(is_inside(image, i, y))
				set_pixel(image, i, y, color);
		}
	}
	else if(x1 > x2)
	{
		tan = ((float)y1-y2)/(x1-x2);
		for(i=x2; i<x1;i+=0.001) 
		{
			y = y2 + tan*(i-x2);
			if(is_inside(image, i, y))
				set_pixel(image, i, y, color);
		}
	}
	else if(x1 == x2 && y1 != y2) //paralela à base
	{
		if(y1<y2)
		{
			for(i=y1; i<y2; i+=0.001)
				if(is_inside(image, x1, i))
					set_pixel(image, x1, i, color);
		}
		else
			for(i=y2; i<y1; i+=0.001)
				if(is_inside(image, x1, i))
					set_pixel(image, x1, i, color);
	}
	else if(x1 == x2 && y1 == y2 && is_inside(image, x1, y1)) set_pixel(image, x1, y1, color); //ponto

	return SUCCESS_PGM;
}


