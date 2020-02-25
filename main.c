#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

struct players
{
    int rstat[6];
};

int main()
{
    struct players p[4];
    for(int b = 0; b < 4;b++)
    {
        printf("PLAYER %d STATS ARE....\n", b+1);
        printf("---------------------\n");

            for(int i=0;i<6;i++)
            {
                srand(time(NULL));
                p[b].rstat[i] = rand() % 18 + 1;

                sleep(1);
            }

        printf("STR: %d\n", p[b].rstat[0]);
        printf("DEX: %d\n", p[b].rstat[1]);
        printf("CON: %d\n", p[b].rstat[2]);
        printf("INT: %d\n", p[b].rstat[3]);
        printf("WIS: %d\n", p[b].rstat[4]);
        printf("CHA: %d\n\n", p[b].rstat[5]);
    }
    return 0;

}

