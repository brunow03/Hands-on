#include <stdio.h>
#include <pgm.h>
#include <constants.h>
#define TRUE	1
#define FALSE	0


int main(int argc, char const *argv[])
{
	int option, width, height, quit, check;
	int x1, x2, y1, y2, radius, color;
	pgm_t *image;
	char *name;

	quit = FALSE;
	while(quit == FALSE)
	{
		while(quit == FALSE)
		{
			printf("Entre com a largura: \n");
			scanf("%d", &width);

			printf("Entre com a altura da imagem:\n");
			scanf("%d", &height);

			check = pgm_create(&image, width, height);
			
			if(check == SUCCESS_PGM) 
				quit = TRUE;
			else 
				printf("Erro ao montar a figura. Tente novamente.\n");		
		}
		quit = FALSE;

		printf("Escolha a opção:\n");
		
		while(quit == FALSE)
		{
			printf("1. Circulo:\n");
			printf("2. Disco:\n");
			printf("3. Linha:\n");
			printf("4. Retangulo:\n");
			printf("0. Finalizar:\n");
			scanf("%d", &option);

			switch(option)
			{
				//Círculo
				case 1:
					while(quit == FALSE)
					{
						printf("Centro (x e y):\n");
						scanf("%d %d", &x1, &y1);
						printf("Raio: \n");
						scanf("%d", &radius);
						printf("Cor:\n");
						scanf("%d", &color);
						check = draw_circle(image, x1, y1, radius, color);
						if(check == SUCCESS_PGM) 
							quit = TRUE;
						else 
							printf("Erro ao montar a figura. Tente novamente.\n");
					}
					quit = FALSE;		
				break;
				//Disco
				case 2:
					while(quit == FALSE)
					{
						printf("Centro:\n");
						scanf("%d %d", &x1, &y1);
						printf("Raio:\n");
						scanf("%d", &radius);
						printf("Cor:\n");
						scanf("%d", &color);
						draw_disk(image, x1, y1, radius, color);
						if(check == SUCCESS_PGM) 
							quit = TRUE;
						else 
							printf("Erro ao montar a figura. Tente novamente.\n");	
					}
					quit = FALSE;
				break;
				//Linha
				case 3:
					while(quit == FALSE)
					{
						printf("Ponto P1 (x e y):\n");
						scanf("%d %d", &x1, &y1);
						printf("Ponto P2 (x e y):\n");
						scanf("%d %d", &x2, &y2);
						printf("Cor:\n");
						scanf("%d", &color);
						draw_line(image, x1, y1, x2, y2, color);
						if(check == SUCCESS_PGM) 
							quit = TRUE;
						else 
							printf("Erro ao montar a figura. Tente novamente.\n");		
					}
					quit = FALSE;
				break;
				//Retângulo
				case 4:
					while(quit == FALSE)
					{
						printf("Centro (x e y):\n");
						scanf("%d %d", &x1, &y1);
						printf("Largura:\n");
						scanf("%d", &width);
						printf("Altura:\n");
						scanf("%d", &height);
						printf("Cor:\n");
						scanf("%d", &color);
						check = draw_rect(image, x1, y1, width, height, color);
						if(check == SUCCESS_PGM) 
							quit = TRUE;
						else 
							printf("Erro ao montar a figura. Tente novamente.\n");
					}
					quit = FALSE;
				break;

				case 0:
					quit = TRUE;
				break;

				default:
					printf("Nenhuma opção válida foi selecionada. Tente novamente: \n");
			}
		}

		printf("Entre com o nome da imagem:\n");
		scanf("%s", name);

		pgm_export(image, name);

		printf("1. Sair\n0. Fazer outra:\n");
		scanf("%d", &quit);

	}

	printf("\n");
	
	return 0;
}