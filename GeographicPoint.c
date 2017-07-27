#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

// Variables universales:
int fil;
int col;

// Orden en que se declararon las funciones que se encuentran definidas despues del main.

int **Matriz(void);

void rand(int *ind);

int index_periodic(int i, int j, int count);

double Calculo_radio(int x0, int x, int y0, int y);

void Libera(int **matrix);

//void Calculo_radio(int pt_alea );


int main()
{

	fil=500;
	col=744;
	int **matriz=Matriz();
	int i;
	int j;
/*
for ( i = 0; i < fil; ++i)
{
	for (j = 0; j <col ; ++j)
	{
		
			printf("%d\t", matriz[i][j]);
		
		
	}
	printf("\n");
}
*/
	/*
	int a=0;
	for ( i = 0; i < fil; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			while(matriz[i][j+a]==0 && matriz[i][j-a]==0 && matriz[i+a][j]==0 && matriz[i-a][j]==0)
			{
				
					a=a+1;

			}
		}
	}
	//printf("%e\n", Calculo_radio(1, 2, 1, 2) );
*/
	printf("%d", index_periodic( 499, 300, 1));

	Libera(matriz);
	return 0;
}

// La siguiente funcion retorna los datos map_data.txt guardados en una matriz.
int **Matriz(void)
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
     

      	matriz[i][j]=val;

      
      separar=strtok(NULL, delim);
      

    j=j+1;
      
    }
    //printf("\n");
   	
	i=i+1;
    
	}

return matriz;
}



void rand(int *ind)
{
	int  a, b ;
	srand(time(NULL));
	a=rand()%(500);
	srand(time(NULL));
	b=rand()%(744);
	while(matriz[a][b]!=0){
		a=rand()%(500);
		b=rand()%(744);
	}
	//printf("%d , %d\n", i,j);
	index[0]=a;
	index[1]=b;
}

double Calculo_radio(int x0, int x, int y0, int y)
{
	int r;
	r=pow((x0-x),2.0)+pow((y0-y),2.0);

	return pow(r,(1.0/2.0));
}

int index_periodic(int i, int j, int count)
{
	if ( (i+count)>(fil-count) )
	{
		int a= (i+count)%500;
	
		return a;
	}
	if ( (j+count)>(col-count) )
	{
		int b= (j+count)%744;

		return b;
	}
	if ((i-count)<0 )
	{
		int c=(i-count)+fil;
		
		return c;
	}
	if ((j-count)<0)
	{
		int d=(j-count)+col;

		return d;
	}
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