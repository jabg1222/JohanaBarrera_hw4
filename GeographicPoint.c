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

void Libera(int **matrix);

//void Calculo_radio(int pt_alea );


int main()
{

	fil=500;
	col=744;
	int **matriz=Matriz();
	int *Num_alea=malloc(2*sizeof(int));
	int i;
	int j;



	//printf("%f\n", radio_max(700,800, matriz) );
	//printf("%d\n", index_j(-1));
	//printf("%d\n", index_i(-1));

	int alea1=Num_alea[0];
	int alea2=Num_alea[1];
	N_alea(Num_alea, matriz);
	//printf("%d , %d\n", alea1,alea2 );

int N=3720; //500*744 tam de la matriz
    int n;
  
    srand48(time(NULL));
    
    int maxmimox;
    int maxmimoy;
    int maxmimor;
   
    //printf("%f\n", beta);
   
   

    double x_new,y_new,r_new;

    

    double alpha;
	double beta;

    float r_old=radio_max(Num_alea[0], Num_alea[1], matriz);
    maxmimor=r_old;
    //printf("%f\n", r_old);


for(n=0;n<N;n++)
    {
        x_new = Num_alea[0] + (-25) + rand() % (26 - 25);
        y_new = Num_alea[1] + (-25) + rand() % (26 - 25);

	


        r_new = radio_max(x_new, y_new, matriz);

        if(r_new>maxmimor)
        {
            maxmimox=x_new;
            maxmimoy=y_new;
            maxmimor=r_new;
        }

        else{
        alpha=(float)r_new/(float)r_old;
        
        if (alpha>=1)
        {
            Num_alea[0]= x_new;
            Num_alea[1]= y_new;
            r_old= r_new;
        }

        else{
            beta=drand48();
            if(alpha<=beta){
                continue;
            }
            
            else{
                Num_alea[0]= x_new;
                Num_alea[1]= y_new;
                r_old= r_new;
                }    
            }
       

        
        //printf("%f\n", x_new);
        //printf("%f\n", y_new);
        //printf("%d\n", indice1);
        //printf("%f\n", indice2);
    }

 }





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

double Calculo_radio(int x0, int x, int y0, int y)
{
	double r;
	r=pow((x0-x),2.0)+pow((y0-y),2.0);

	return pow(r,(1.0/2.0));
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



void Libera(int **matrix)
{
    int i;
    for(i = 0; i<fil; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
