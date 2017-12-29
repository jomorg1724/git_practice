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
    int jump_totals_array[1000];
    int loop;

    /*a = atof(argv[1]);*/
    t = 1.0;
    h = .01;

    /* This is the number of Trajectories */
    for (j=0;j<1000;j++) {

      jump_path = 0;

      /* This is the movement along a single trajectory */
        for (i=0;i<100;i++) {

	  /* This takes the random sample at the i'th segment of a trajectory */
            rand_samp = ((float)rand()/(float)(RAND_MAX)) * t;

	    /* This tests the sample. If sample less than h, add one to the collection of jumps for the current trajectory */
	    if( rand_samp < h ) {
	      jump_path++;
	    }
	}

	/* Append the jump total for each trajectory to an array */
	jump_totals_array[j] = jump_path;
    }
    printf("%f\n", (float) jump_path/j);

    /* A for loop to print the list out, will need to direct this to output file */
    for(loop = 0; loop < j; loop++)
      printf("%d ", jump_totals_array[loop]);
    return 0;
}
