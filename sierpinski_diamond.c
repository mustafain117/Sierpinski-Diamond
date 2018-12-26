
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_diamond(char *array[], int original_height, int height, int level,  char unit, int row)
{
    int stars = 1;
    int top = original_height/2 ;
    
    if(level == 1)
    {
       if(row==0)
       {
           for(int i=0; i<height/2+1; i++)
           {
               for(int a=0; a < stars ; a++)
               {
                       array[top + a][i] = unit;
               }
               stars  = stars  + 2;
               top--;
           }
           print_diamond(array, original_height, height, level, '0', row+1);
       }
       if(row!=0)
       {
           if((height/2+1)*pow(2,row) >= original_height)
           {
               return;
           }

            for(int i=0; i< (height/2+1) * pow(2, row -1); i++)
            {
              for(int a= - (height/2+1) * pow(2, row-1)+1 ; a < (height/2+1) * pow(2, row-1) ; a++)
              {
                     array[top + (height/2 +1) * (int)pow(2,row-1) + a][(int)pow(2,row-1)*(height/2+1) + i] = array[top + a][i];
                }
            }
            for(int i=0; i< (height/2+1) * pow(2, row-1); i++)
            {
                for(int a= - (height/2+1) * pow(2, row-1)+1  ; a < (height/2+1) * pow(2, row-1); a++)
                {
                     array[top - (height/2 +1) * (int)pow(2,row-1) + a][(int)pow(2,row- 1)*(height/2+1) + i] = array[top + a][i];
                }
            }
            print_diamond(array, original_height, height, level, '*', row+1);
        }
    }
    else
    {
        print_diamond(array, original_height, height/2, level-1, unit, row);
    } 

}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {                                                              //checking that only one argument exists
        printf("ERROR: Wrong number of arguments. Two arguments required.\n");
        return 0;
    }

    int size;
    int height = atoi(argv[1]);
    int level = atoi(argv[2]);    

    if(level <=0 ){
       printf("ERROR: Bad argument. level must be positive\n");
       return 0;

    }
    if ( height<= 0 || height%2 == 0)
    {
        printf("ERROR: Bad argument. Height must be a positive odd integer\n");
        return 0;
    }

    if (level != 1 && (ceil ( log2(height/2 + 1)) != floor ( log2(height/2 + 1))|| (height/2+1 < (int)pow (2, level-1))))
    {
        printf("ERROR: Height does not allow evenly dividing requested number of levels\n");
        return(0);
    }

    char *array[height];
    for(int z=0; z<height ; z++)
        array[z]=(char *)malloc(sizeof(char)*((height/2)+1) );

    for(int i=0; i<height/2+1; i++)
    {
        for(int a=0; a<height; a++)
        {
             array[a][i]= ' ';
        }
    }

     print_diamond(array, height, height, level, '*', 0);

    for(int i=0; i<height/2+1; i++)
    {
        for(int a=0; a<height; a++)
        {
            printf("%c", array[a][i]);
        }
        printf("\n");
    }
    for(int i=height/2-1; i>=0; i--)
    {
        for(int a=0; a<height; a++)
        {
            printf("%c", array[a][i]);
        }
        printf("\n");
    }
    return 0;
}
    