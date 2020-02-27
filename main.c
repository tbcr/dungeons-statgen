#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

	#if defined(__WIN32) || defined(_WIN64)
		#define PLATFORM "windows"
	#endif
	
	#if defined(__APPLE__) || defined(__mach__) || defined(__unix__) || defined(__linux__) || defined(__BEOS__) || defined(__HAIKU__)
		#define PLATFORM "not-windows"
	#endif

struct players
{
    int rstat[6];
    int r[6];
};

int main()
{	
    struct players p[4];
    int i,b,spot[6],w,spin;
    
    int teb,tea,tec,temp[6];
    
    time_t t;

	if(PLATFORM == "windows")
	{
		system("cls");
	}
	else if(PLATFORM == "not-windows")
	{
		system("clear");
	}

    for(b=0;b<4;b++)
    {
        //Putting the set seed here because putting it in the second for loop will make player 1 and 4 stats the same
        srand((unsigned)time(&t));

        memset(spot,0,sizeof(spot));
        
        printf("PLAYER %d STATS ARE....\n", b+1);
        printf("---------------------\n");
        
        printf("Numbers Rolled: ");
        
        //6 Iterations of 3d6, storing value in temp array.
        for(i=0;i<6;i++)
        {
        	tea=rand() % 6;
        	teb=rand() % 6;
        	tec=rand() % 6;
			
			temp[i]=tea+teb+tec; 
				
			printf("%d ",temp[i]);
        }
        
		printf("\n");
        w= 6;
        i= 0;
        
		while(w > 0)
		{
			 spin=rand() % 6;
			 
			 if(spot[spin] != 1)
			 {
			 	p[b].rstat[spin] = temp[i];
			 	spot[spin]= 1;
			 	i++;
			 	w--;
			 }
		}
        printf("STR: %d\n", p[b].rstat[0]);
        printf("DEX: %d\n", p[b].rstat[1]);
        printf("CON: %d\n", p[b].rstat[2]);
        printf("INT: %d\n", p[b].rstat[3]);
        printf("WIS: %d\n", p[b].rstat[4]);
        printf("CHA: %d\n\n", p[b].rstat[5]);
        sleep(1);
    }
    return 0;

}

