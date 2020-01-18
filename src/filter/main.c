#include <stdio.h>
#include <stdlib.h>
#include "../imagelib/imagelib.h"

void SelectionSort(int number[], int count){
    int temp;
    for(int i=0;i<count;i++){
      for(int j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }
}

int main(int argc, char *argv[])
{
	/* El programa recibe 2 parametros */
	if(argc != 3)
	{
		printf("Modo de uso: %s <input.png> <output.png>\n", argv[0]);
		printf("\t<input.png> es la imagen a filtrar\n");
		printf("\t<output.png> es donde se guardará la imagen resultante\n");
		return 1;
	}

	/* Leemos la imagen a partir del archivo */
	char* input_file = argv[1];
	Image* img = img_png_read_from_file(input_file);
	Image* img_out = img_png_read_from_file(input_file);

	/* TODO: Filtro de mediana */
	int* ArrayR = malloc(9 * sizeof(int));
	int* ArrayG = malloc(9 * sizeof(int));
	int* ArrayB = malloc(9 * sizeof(int));

	for (int row = 0; row < img -> height; row++)
	{
		for (int col = 0; col < img -> width; col++)
		{
			if (img -> pixels[row][col].R == 255 && img -> pixels[row][col].G == 255 && img -> pixels[row][col].B == 255)
			{
			
			//vértice izq sup
			if(row == 0 && col == 0){
				ArrayR[0] = img -> pixels[row][col].R;
				ArrayR[1] = img -> pixels[row][col].R;
				ArrayR[2] = img -> pixels[row][col].R;
				ArrayR[3] = img -> pixels[row][col].R;
				ArrayR[4] = img -> pixels[row][col + 1].R;
				ArrayR[5] = img -> pixels[row + 1][col].R;
				ArrayR[6] = img -> pixels[row][col + 1].R;
				ArrayR[7] = img -> pixels[row + 1][col].R;
				ArrayR[8] = img -> pixels[row + 1][col + 1].R;

				ArrayG[0] = img -> pixels[row][col].G;
				ArrayG[1] = img -> pixels[row][col].G;
				ArrayG[2] = img -> pixels[row][col].G;
				ArrayG[3] = img -> pixels[row][col].G;
				ArrayG[4] = img -> pixels[row][col + 1].G;
				ArrayG[5] = img -> pixels[row + 1][col].G;
				ArrayG[6] = img -> pixels[row][col + 1].G;
				ArrayG[7] = img -> pixels[row + 1][col].G;
				ArrayG[8] = img -> pixels[row + 1][col + 1].G;

				ArrayB[0] = img -> pixels[row][col].B;
				ArrayB[1] = img -> pixels[row][col].B;
				ArrayB[2] = img -> pixels[row][col].B;
				ArrayB[3] = img -> pixels[row][col].B;
				ArrayB[4] = img -> pixels[row][col + 1].B;
				ArrayB[5] = img -> pixels[row + 1][col].B;
				ArrayB[6] = img -> pixels[row][col + 1].B;
				ArrayB[7] = img -> pixels[row + 1][col].B;
				ArrayB[8] = img -> pixels[row + 1][col + 1].B;
			}
			// vértice der sup
			else if (row == 0 && col == (img -> width - 1))
			{
				ArrayR[0] = img -> pixels[row][col].R;
				ArrayR[1] = img -> pixels[row][col].R;
				ArrayR[2] = img -> pixels[row][col].R;
				ArrayR[3] = img -> pixels[row][col].R;
				ArrayR[4] = img -> pixels[row][col - 1].R;
				ArrayR[5] = img -> pixels[row][col - 1].R;
				ArrayR[6] = img -> pixels[row + 1][col].R;
				ArrayR[7] = img -> pixels[row + 1][col].R;
				ArrayR[8] = img -> pixels[row + 1][col - 1].R;

				ArrayG[0] = img -> pixels[row][col].G;
				ArrayG[1] = img -> pixels[row][col].G;
				ArrayG[2] = img -> pixels[row][col].G;
				ArrayG[3] = img -> pixels[row][col].G;
				ArrayG[4] = img -> pixels[row][col - 1].G;
				ArrayG[5] = img -> pixels[row][col - 1].G;
				ArrayG[6] = img -> pixels[row + 1][col].G;
				ArrayG[7] = img -> pixels[row + 1][col].G;
				ArrayG[8] = img -> pixels[row + 1][col - 1].G;

				ArrayB[0] = img -> pixels[row][col].B;
				ArrayB[1] = img -> pixels[row][col].B;
				ArrayB[2] = img -> pixels[row][col].B;
				ArrayB[3] = img -> pixels[row][col].B;
				ArrayB[4] = img -> pixels[row][col - 1].B;
				ArrayB[5] = img -> pixels[row][col - 1].B;
				ArrayB[6] = img -> pixels[row + 1][col].B;
				ArrayB[7] = img -> pixels[row + 1][col].B;
				ArrayB[8] = img -> pixels[row + 1][col - 1].B;
			}
			// vértice izq inf
			else if(row == (img -> height - 1) && col == 0){
				ArrayR[0] = img -> pixels[row][col].R;
				ArrayR[1] = img -> pixels[row][col].R;
				ArrayR[2] = img -> pixels[row][col].R;
				ArrayR[3] = img -> pixels[row][col].R;
				ArrayR[4] = img -> pixels[row][col + 1].R;
				ArrayR[5] = img -> pixels[row][col + 1].R;
				ArrayR[6] = img -> pixels[row - 1][col].R;
				ArrayR[7] = img -> pixels[row - 1][col].R;
				ArrayR[8] = img -> pixels[row - 1][col + 1].R;

				ArrayG[0] = img -> pixels[row][col].G;
				ArrayG[1] = img -> pixels[row][col].G;
				ArrayG[2] = img -> pixels[row][col].G;
				ArrayG[3] = img -> pixels[row][col].G;
				ArrayG[4] = img -> pixels[row][col + 1].G;
				ArrayG[5] = img -> pixels[row][col + 1].G;
				ArrayG[6] = img -> pixels[row - 1][col].G;
				ArrayG[7] = img -> pixels[row - 1][col].G;
				ArrayG[8] = img -> pixels[row - 1][col + 1].G;

				ArrayB[0] = img -> pixels[row][col].B;
				ArrayB[1] = img -> pixels[row][col].B;
				ArrayB[2] = img -> pixels[row][col].B;
				ArrayB[3] = img -> pixels[row][col].B;
				ArrayB[4] = img -> pixels[row][col + 1].B;
				ArrayB[5] = img -> pixels[row][col + 1].B;
				ArrayB[6] = img -> pixels[row - 1][col].B;
				ArrayB[7] = img -> pixels[row - 1][col].B;
				ArrayB[8] = img -> pixels[row - 1][col + 1].B;
			}
			// vértice der inf
			else if (row == (img -> height - 1) && col == (img -> width - 1))
			{
				ArrayR[0] = img -> pixels[row][col].R;
				ArrayR[1] = img -> pixels[row][col].R;
				ArrayR[2] = img -> pixels[row][col].R;
				ArrayR[3] = img -> pixels[row][col].R;
				ArrayR[4] = img -> pixels[row][col - 1].R;
				ArrayR[5] = img -> pixels[row][col - 1].R;
				ArrayR[6] = img -> pixels[row - 1][col].R;
				ArrayR[7] = img -> pixels[row - 1][col].R;
				ArrayR[8] = img -> pixels[row - 1][col - 1].R;

				ArrayG[0] = img -> pixels[row][col].G;
				ArrayG[1] = img -> pixels[row][col].G;
				ArrayG[2] = img -> pixels[row][col].G;
				ArrayG[3] = img -> pixels[row][col].G;
				ArrayG[4] = img -> pixels[row][col - 1].G;
				ArrayG[5] = img -> pixels[row][col - 1].G;
				ArrayG[6] = img -> pixels[row - 1][col].G;
				ArrayG[7] = img -> pixels[row - 1][col].G;
				ArrayG[8] = img -> pixels[row - 1][col - 1].G;

				ArrayB[0] = img -> pixels[row][col].B;
				ArrayB[1] = img -> pixels[row][col].B;
				ArrayB[2] = img -> pixels[row][col].B;
				ArrayB[3] = img -> pixels[row][col].B;
				ArrayB[4] = img -> pixels[row][col - 1].B;
				ArrayB[5] = img -> pixels[row][col - 1].B;
				ArrayB[6] = img -> pixels[row - 1][col].B;
				ArrayB[7] = img -> pixels[row - 1][col].B;
				ArrayB[8] = img -> pixels[row - 1][col - 1].B;
			}
			// bordes
			else{
				// fila sup
				if (row == 0)
				{
					ArrayR[0] = img -> pixels[row][col].R;
					ArrayR[1] = img -> pixels[row][col].R;
					ArrayR[2] = img -> pixels[row][col - 1].R;
					ArrayR[3] = img -> pixels[row][col - 1].R;
					ArrayR[4] = img -> pixels[row][col + 1].R;
					ArrayR[5] = img -> pixels[row][col + 1].R;
					ArrayR[6] = img -> pixels[row + 1][col].R;
					ArrayR[7] = img -> pixels[row + 1][col - 1].R;
					ArrayR[8] = img -> pixels[row + 1][col + 1].R;

					ArrayG[0] = img -> pixels[row][col].G;
					ArrayG[1] = img -> pixels[row][col].G;
					ArrayG[2] = img -> pixels[row][col - 1].G;
					ArrayG[3] = img -> pixels[row][col - 1].G;
					ArrayG[4] = img -> pixels[row][col + 1].G;
					ArrayG[5] = img -> pixels[row][col + 1].G;
					ArrayG[6] = img -> pixels[row + 1][col].G;
					ArrayG[7] = img -> pixels[row + 1][col - 1].G;
					ArrayG[8] = img -> pixels[row + 1][col + 1].G;

					ArrayB[0] = img -> pixels[row][col].B;
					ArrayB[1] = img -> pixels[row][col].B;
					ArrayB[2] = img -> pixels[row][col - 1].B;
					ArrayB[3] = img -> pixels[row][col - 1].B;
					ArrayB[4] = img -> pixels[row][col + 1].B;
					ArrayB[5] = img -> pixels[row][col + 1].B;
					ArrayB[6] = img -> pixels[row + 1][col].B;
					ArrayB[7] = img -> pixels[row + 1][col - 1].B;
					ArrayB[8] = img -> pixels[row + 1][col + 1].B;
				}
				// col derecha
				else if (col == (img -> width - 1))
				{
					ArrayR[0] = img -> pixels[row][col].R;
					ArrayR[1] = img -> pixels[row][col].R;
					ArrayR[2] = img -> pixels[row - 1][col].R;
					ArrayR[3] = img -> pixels[row - 1][col].R;
					ArrayR[4] = img -> pixels[row + 1][col].R;
					ArrayR[5] = img -> pixels[row + 1][col].R;
					ArrayR[6] = img -> pixels[row - 1][col - 1].R;
					ArrayR[7] = img -> pixels[row][col - 1].R;
					ArrayR[8] = img -> pixels[row + 1][col - 1].R;

					ArrayG[0] = img -> pixels[row][col].G;
					ArrayG[1] = img -> pixels[row][col].G;
					ArrayG[2] = img -> pixels[row - 1][col].G;
					ArrayG[3] = img -> pixels[row - 1][col].G;
					ArrayG[4] = img -> pixels[row + 1][col].G;
					ArrayG[5] = img -> pixels[row + 1][col].G;
					ArrayG[6] = img -> pixels[row - 1][col - 1].G;
					ArrayG[7] = img -> pixels[row][col - 1].G;
					ArrayG[8] = img -> pixels[row + 1][col - 1].G;

					ArrayB[0] = img -> pixels[row][col].B;
					ArrayB[1] = img -> pixels[row][col].B;
					ArrayB[2] = img -> pixels[row - 1][col].B;
					ArrayB[3] = img -> pixels[row - 1][col].B;
					ArrayB[4] = img -> pixels[row + 1][col].B;
					ArrayB[5] = img -> pixels[row + 1][col].B;
					ArrayB[6] = img -> pixels[row - 1][col - 1].B;
					ArrayB[7] = img -> pixels[row][col - 1].B;
					ArrayB[8] = img -> pixels[row + 1][col - 1].B;
				}
				// fila inf
				else if (row == (img -> height - 1))
				{	
					ArrayR[0] = img -> pixels[row][col].R;
					ArrayR[1] = img -> pixels[row][col].R;
					ArrayR[2] = img -> pixels[row][col - 1].R;
					ArrayR[3] = img -> pixels[row][col - 1].R;
					ArrayR[4] = img -> pixels[row][col + 1].R;
					ArrayR[5] = img -> pixels[row][col + 1].R;
					ArrayR[6] = img -> pixels[row - 1][col - 1].R;
					ArrayR[7] = img -> pixels[row - 1][col].R;
					ArrayR[8] = img -> pixels[row - 1][col + 1].R;

					ArrayG[0] = img -> pixels[row][col].G;
					ArrayG[1] = img -> pixels[row][col].G;
					ArrayG[2] = img -> pixels[row][col - 1].G;
					ArrayG[3] = img -> pixels[row][col - 1].G;
					ArrayG[4] = img -> pixels[row][col + 1].G;
					ArrayG[5] = img -> pixels[row][col + 1].G;
					ArrayG[6] = img -> pixels[row - 1][col - 1].G;
					ArrayG[7] = img -> pixels[row - 1][col].G;
					ArrayG[8] = img -> pixels[row - 1][col + 1].G;

					ArrayB[0] = img -> pixels[row][col].B;
					ArrayB[1] = img -> pixels[row][col].B;
					ArrayB[2] = img -> pixels[row][col - 1].B;
					ArrayB[3] = img -> pixels[row][col - 1].B;
					ArrayB[4] = img -> pixels[row][col + 1].B;
					ArrayB[5] = img -> pixels[row][col + 1].B;
					ArrayB[6] = img -> pixels[row - 1][col - 1].B;
					ArrayB[7] = img -> pixels[row - 1][col].B;
					ArrayB[8] = img -> pixels[row - 1][col + 1].B;
				}
				// col izq
				else if (col == 0)
				{	
					ArrayR[0] = img -> pixels[row][col].R;
					ArrayR[1] = img -> pixels[row][col].R;
					ArrayR[2] = img -> pixels[row - 1][col].R;
					ArrayR[3] = img -> pixels[row - 1][col].R;
					ArrayR[4] = img -> pixels[row + 1][col].R;
					ArrayR[5] = img -> pixels[row + 1][col].R;
					ArrayR[6] = img -> pixels[row - 1][col + 1].R;
					ArrayR[7] = img -> pixels[row][col + 1].R;
					ArrayR[8] = img -> pixels[row + 1][col + 1].R;

					ArrayG[0] = img -> pixels[row][col].G;
					ArrayG[1] = img -> pixels[row][col].G;
					ArrayG[2] = img -> pixels[row - 1][col].G;
					ArrayG[3] = img -> pixels[row - 1][col].G;
					ArrayG[4] = img -> pixels[row + 1][col].G;
					ArrayG[5] = img -> pixels[row + 1][col].G;
					ArrayG[6] = img -> pixels[row - 1][col + 1].G;
					ArrayG[7] = img -> pixels[row][col + 1].G;
					ArrayG[8] = img -> pixels[row + 1][col + 1].G;

					ArrayB[0] = img -> pixels[row][col].B;
					ArrayB[1] = img -> pixels[row][col].B;
					ArrayB[2] = img -> pixels[row - 1][col].B;
					ArrayB[3] = img -> pixels[row - 1][col].B;
					ArrayB[4] = img -> pixels[row + 1][col].B;
					ArrayB[5] = img -> pixels[row + 1][col].B;
					ArrayB[6] = img -> pixels[row - 1][col + 1].B;
					ArrayB[7] = img -> pixels[row][col + 1].B;
					ArrayB[8] = img -> pixels[row + 1][col + 1].B;
				}
				//resto de los puntos
				else{
					for (int x = -1; x <= 1; x++)
					{
						for (int y = -1; y <= 1; y++)
						{
							ArrayR[3*(y+1) + x + 1] = img -> pixels[row + x][col + y].R;
							ArrayG[3*(y+1) + x + 1] = img -> pixels[row + x][col + y].G;
							ArrayB[3*(y+1) + x + 1] = img -> pixels[row + x][col + y].B;
						}
					}
				}
			}//else de afuera
			//funcion SelectionSort3(ArrayR, ArrayG, ArrayB)
			SelectionSort(ArrayR, 9);
			SelectionSort(ArrayG, 9);
			SelectionSort(ArrayB, 9);

			img_out -> pixels[row][col].R = ArrayR[4];
			img_out -> pixels[row][col].G = ArrayG[4];
			img_out -> pixels[row][col].B = ArrayB[4];
		}// if pixel es blanco
		}//for col
	}//for row

	/* A modo de ejemplo, damos invertimos los colores de la imagen 
	for (int row = 0; row < img -> height; row++)
	{
		for (int col = 0; col < img -> width; col++)
		{
			img -> pixels[row][col].R = 255 - img -> pixels[row][col].R;
			img -> pixels[row][col].G = 255 - img -> pixels[row][col].G;
			img -> pixels[row][col].B = 255 - img -> pixels[row][col].B;
		}
	}
	
	Guardamos la imagen como un archivo png */
	char* output_file = argv[2];
	img_png_write_to_file(img_out, output_file);



	/* Liberamos los recursos asociados de la imagen */
	free(ArrayR);
	free(ArrayG);
	free(ArrayB);
	img_png_destroy(img);
	img_png_destroy(img_out);

	return 0;
}
