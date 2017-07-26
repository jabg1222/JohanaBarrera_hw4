#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int fil;
int col;

int **Matriz(void);

// FORMA 1 DE LEER EL ARCHIVO.
/*
int main()
{
	FILE *archivo;
 	int len=372000;
 	//int val;
 	char *caracteres=malloc(len*sizeof(char));
 	
 	archivo = fopen("map_data.txt","r");
 	
 	if (archivo == NULL)
 		exit(1);
 	
 	//printf("\nEl contenido del archivo de prueba es \n\n");
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,len,archivo);
 		//val=atoi(caracteres);
 		printf("%d",val);
 	}
        system("PAUSE");

        fclose(archivo);
	return 0;
}
*/

// SEGUNDA FORMA DE LEER ARCHIVO.

int main()
{

	fil=500;
	col=744;
	int **p=Matriz();
	int i;
	int j;

for ( i = 0; i < fil; ++i)
{
	for (j = 0; j <col ; ++j)
	{
		
			printf("%d\t", p[i][j]);
		
		
	}
	printf("\n");
}




	return 0;
}

int **Matriz()
{
	FILE *file;
    file=fopen("map_data.txt", "r");
    int len=200000;
    char lineas[len];
    char *separar=NULL;
    const char *delim;
    delim=" ";

    
    int val;
    int i=0;
    int j;
    int f;

    int **matriz= malloc(fil*sizeof(int*));

	for ( f = 0; f < fil; ++f)
	{
		matriz[f] = malloc(col*sizeof(int*));
	}


  

// LEE EL ARCHIVO Y LO GUARDA EN LA MATRIZ
  while(fgets(lineas,len,file) )
{
  //printf("%s\n",lineas );
	
  j=0;
  separar=strtok(lineas,delim);
    while(separar !=NULL)
    {
      
      val= atoi(separar);
     
      
      //printf("el trozo es :%s\n", separar );
      
      //printf("en doble es: %d\n", val);
      //if (i<fil && j<col)
      //{
      	matriz[i][j]=val;
      //}
      
      //printf("%d", matriz[i][j] );
      

      
      
      separar=strtok(NULL, delim);
      

    j=j+1;
      
    }
    //printf("\n");
   	
	i=i+1;
    
	}

return matriz;
}

void Libera(int **matrix)
{
    int i;
    for(i = 0; i<fil; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}