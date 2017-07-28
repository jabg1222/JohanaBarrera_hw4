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

double Calculo_radio(int x0, int x, int y0, int y);

void N_alea(int *ind, int **matriz);

int index_i(int i);

int index_j(int j);

float radio_max(int x, int y, int **matriz);

void imprimir_datos(int **matriz);

void Libera(int **matrix);




int main()
{

	fil=500;
	col=744;
	int **matriz=Matriz();
	int *Num_alea=malloc(2*sizeof(int));
	int iter=100; // Numero de iteraciones, es decir que va evaluar el radio en diferentes 1000 numeros aleatorios.
	double x_nuevo,y_nuevo,r_nuevo, r_viejo;
	int i, j, p; // contadores.
	// Variables en donde voy a guardar las coordenadas del punto Nemo.
    	int cord_x; 
    	int cord_y;
    	int max_r; //Radio maximo
	double alfa;
	double beta;
	
	

	imprimir_datos(matriz); // Guarda los datos originales en el archivo mapa.csv

	N_alea(Num_alea, matriz); // Genera numeros aleatorios dentro del tamaño de la matriz.


    	srand48(time(NULL)); // Semilla para generar los numeros aleatorios en beta.
    
	r_viejo=radio_max(Num_alea[0], Num_alea[1], matriz); // Radio generado en el punto aleatorio.

    	max_r=r_viejo;
  


for( p=0; p<iter; p++)
{
	// Variables que guardan un punto aleatorio nuevo.
        x_nuevo = Num_alea[0] + (-25) + rand() % (26 - 25);
        y_nuevo = Num_alea[1] + (-25) + rand() % (26 - 25);

	// Si la posicion en la matriz es igual a 1, debe generar un nuevo punto aleatorio hasta que de un cero.
        while(matriz[index_i(x_nuevo)][index_j(y_nuevo)]==1)
    	{
        	x_nuevo = Num_alea[0] + (-25) + rand() % (26 - 25);
        	y_nuevo = Num_alea[1] + (-25) + rand() % (26 - 25);
	}

        r_nuevo = radio_max(x_nuevo, y_nuevo, matriz);

	// Se hace lo siguiente para que quede guardado siempre el mayor radio posible.
        if(r_nuevo > max_r)
        {
            cord_x=x_nuevo;
            cord_y=y_nuevo;
            max_r=r_nuevo;
        }


        alfa=(float)r_nuevo/(float)r_viejo;
        
        if (alfa>=1)
        {
            Num_alea[0]= x_nuevo;
            Num_alea[1]= y_nuevo;
            r_viejo= r_nuevo;
        }

        else 
	{
            beta=drand48(); // Genera num aleatorios entre 0 y 1.

            if(alfa<=beta)// Si es mayor a alfa siga generando un nuevo num aleatorio.
		{ 
                	continue;
        	}
            
       	    else
		{
             		Num_alea[0]= x_nuevo;
             		Num_alea[1]= y_nuevo;
             		r_viejo= r_nuevo;
         	}          

    	}

 }



	
	printf("%d, %d, %f\n", cord_x, cord_y, max_r);


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

	
  j=0;
  separar=strtok(lineas,delim);
    while(separar !=NULL)
    {
      
      val= atoi(separar);
     

      	matriz[i][j]=val;

      
      separar=strtok(NULL, delim);
      

    j=j+1;
      
    }
   	
	i=i+1;
    
	}

return matriz;
}


void N_alea(int *ind, int **matriz)
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
	//printf("%d , %d\n", a,b);
	ind[0]=a;
	ind[1]=b;
}



int index_i(int i)
{
	int ind=i;
	if ( (ind)>=fil )
	{
		 ind= (i)%500;
	
		
	}

	if ((ind)<0 )
	{
		ind=(i)+fil;
		
	
	}
	
	return ind;
	


}
/*
int index_j(int j)
{

	if ( (j)>(col-1) )
	{
		int b= (j)%744;

		return b;
	}


	if ((j)<0)
	{
		int d=(j)+col;

		return d;
	}
	else{
	return j;
	}
}
*/
int index_j(int j)
{
	int ind;
	if ( (ind)>=col )
	{
		ind= (j)%744;

		
	}


	if ((ind)<0)
	{
		ind=(j)+col;

		
	}
	
	return ind;
	
}


// Calcula el radio maximo.
float radio_max(int x, int y, int **matriz)
{
int r_max;
int r;
int i;
int j;

int pare=0;
for ( r = 1; r < fil; ++r)
{


	for ( i = x-r; i < x+r ; ++i)
	{

		for (j = y-r; j < y+r ; ++j)
		{
		
			if( (pow((pow((x-i),2.0)+pow((y-j),2.0)),0.5) <= r) )
		
			{
			
			
				if(matriz[index_i(i)][index_j(j)]==1 )
				{

				r_max=r;
				pare=1;
				}

			
			}

		if(pare!=0)
		{
		break;
		}


		}

	if(pare!=0)
	{
	break;
	}


	}

	if(pare!=0)
		{
		break;
		}


}

return r_max;
}

// Imprime los datos.
void imprimir_datos(int **matriz)
{
	int i, j;
	FILE*out;
	out=fopen("mapa.csv", "w+");


 for ( i = 0; i < fil; ++i)
 {
 	for (j = 0; j <col ; ++j)
 	{
 		
			
			fprintf(out,"%d\t", matriz[i][j]);
 		
 		
 	}
 	fprintf(out,"\n");
 }

fclose(out);

}
// Libera memoria.

void Libera(int **matrix)
{
    int i;
    for(i = 0; i<fil; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
