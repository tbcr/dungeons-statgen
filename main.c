#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

	#if defined(__WIN32) || defined(_WIN64)
		#define PLATFORM "windows"
	#endif
	
	#if defined(__APPLE__) || defined(__mach__) || defined(__unix__) || defined(__linux__) || defined(__BEOS__) || defined(__HAIKU__)
		#define PLATFORM "not-windows"
	#endif

struct players
{
    int rstat[6];
};

int main()
{	
    struct players p[4];
    int i,b;
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

        printf("PLAYER %d STATS ARE....\n", b+1);
        printf("---------------------\n");

            for(i=0;i<6;i++)
            {
                p[b].rstat[i] = rand() % 18 + 1;
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

