#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//takes two doubles and returns a double
double calc_chill(double T, double V)
{ //equation from instructions
    return 35.74 + 0.6215 * T - 35.75 * pow(V, 0.16) + 0.4275 * T * pow(V, 0.16);
}

//takes no inputs, just prints header
void print_header() {
    printf("  Temp   Wind  Chill\n");
    printf(" -----  -----  -----\n");
}


int main(int argc, char *argv[])
{//check argc counts
    if (argc == 1)
    { //no arguments-- print full table
        print_header();

        for (int T = -10; T <= 40; T += 10)
        {
            for (int V = 5; V <= 15; V += 5)
            {
                printf(" %5.1f  %5.1f  %5.1f\n",(double)T, (double) V, calc_chill(T, V));
            }
            printf("\n");
        }
    }
    else if (argc == 2)
    {//one argument -- temp only
     	double T = atof(argv[1]);
	
	//check in range
        if (T >= 50 || T <= -99 )
		
        {
            printf("Error: Formula valid only for -99 < T < 50.\n");
            return 1;
        }

	//print results
        print_header();
        for (double V = 5; V <= 15; V += 5) {
            printf(" %5.1f  %5.1f  %5.1f\n", T, V, calc_chill(T, V));
        }

        return 1;
    }
    else if (argc == 3)
    {//two args-- T and V
        //compute single wind chill
	double T = atof(argv[1]);
        double V = atof(argv[2]);
        
	//check in range
	if (T >= 50 || T <= -99)
        {
            fprintf(stderr, "./chill: Temperature must be less than or equal to 50.0 and greater than -99.0\n");
            return 1;
        }
	
	if (V < 0.5) {
            fprintf(stderr, "./chill: Wind velocity must be greater than or equal to 0.5 MPH\n");
            return 1;
        }

        print_header();
        printf(" %5.1f  %5.1f  %5.1f\n", T, V, calc_chill(T, V));
    }
    else
    {
        fprintf(stderr, "usage: %s [temperature [velocity]]\n", argv[0]);
        return 1;
    }

    return 0;
}

