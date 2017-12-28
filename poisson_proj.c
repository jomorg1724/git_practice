#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    int i;
    int j;
    float t;
    float rand_samp;
    int jump_path;
    float h;
    /* int list[100];*/

    /*a = atof(argv[1]);*/
    t = 1.0;
    jump_path = 0;
    h = .01;


    for (j=0;j<1000;j++) {
        for (i=0;i<100;i++) {
            rand_samp = ((float)rand()/(float)(RAND_MAX)) * t;
            /*printf("%f\n", rand_samp);*/
	    if( rand_samp < h ) {
	      jump_path++;
	    }
        }

    }
    printf("%f\n", (float) jump_path/1000);
    return 0;
}
