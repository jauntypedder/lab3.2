#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

double f(double x);
double halfed(double x1, double x2, int n_count, int N, const double eps);
double chord(double x1, double x2, int n_count, int N, const double eps);

int main() {

    int N, method, n_count=0;
    double x1, x2;
    const double eps=0.0001;
    double result;
    clock_t time, t_time;

    printf("\t *FIRST STEP: CHOOSE METOD:");
    printf("\n\t 1. HALFED");
    printf("\n\t 2. CHORD\n");
    scanf("%u", &method);
    while (method!=1&&method!=2) {
        printf("\t **WRONG OPTION, PLEASE TRY AGAIN!\n");
        printf("\n\t *CHOOSE METOD (1 or 2)\n");
        scanf("%u", &method);
    }

    printf("*SECOND STEP: INSERT DATA:");
    do {
        printf("\n\tX1: ");
        scanf("%lf", &x1);
        printf("\n\tX2: ");
        scanf("%lf", &x2);
    } while (f(x1)*f(x2) <= 0);

    printf("\n\tN: ");
    scanf("%u", &N);

    system("cls");

    switch(method) {
        case 1:
        {
            result = halfed(x1,x2, n_count, N, eps);
        }
            break;

        case 2:
        {
            result = chord(x1, x2, n_count, N, eps);
        }
            break;

    }
    time=clock()-time;
    t_time = ((double)time)/CLOCKS_PER_SEC;
    printf ("TIME WASTED: %.2lf seconds\n", t_time);
    return 0;
}

double halfed(double x1, double x2, int n_count, int N, const double eps) {

    double xi;
    unsigned int choice, const_n;
    const_n=N;

    do {

        n_count++;
        xi=(x1+x2)/2;
        if(f(xi)*f(x1)>0) {
            x1=xi;
        }
        else {
            x2=xi;
        }

        if (n_count%N==0) {

            printf ("number of iterations: %u", n_count);
            printf ("\n current Õ: %.3lf", xi);
            printf ("\n current f(x)= %.3lf", f(xi));
            printf ("\n\n*CHOOSE NEXT OPTION");

            printf ("\n\t 1 CONTINUE WITH SAME NUMBER OF ITERATIONS");
            printf ("\n\t 2 CONTINUE UNTIL PROGRAM FIND ANSWER");
            printf ("\n\t 3 EXIT WITH CURRENT DATA");

            scanf ("%u", &choice);
            printf ("==============================================================\n");

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N = N+const_n;
                }
                case 2:
                {
                    N=N+n_count;
                }
                case 3:
                {
                    break;
                }
            }

        }
    }while(fabs(x1-x2)>=eps);
    printf("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double chord (double x1, double x2, int n_count, int N, const double eps) {

    double xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do{
        n_count++;
        xl=xi;
        xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
        x1=x2;
        x2=xl;

        if (n_count%N==0) {

            printf ("number of iterations: %u", n_count);
            printf ("\n current Õ: %.3lf", xi);
            printf ("\n current f(x)= %.3lf", f(xi));
            printf ("\n\n*CHOOSE NEXT OPTION");

            printf ("\n\t 1 CONTINUE WITH SAME NUMBER OF ITERATIONS");
            printf ("\n\t 2 CONTINUE UNTIL PROGRAM FIND ANSWER");
            printf ("\n\t 3 EXIT WITH CURRENT DATA");


            scanf ("%u", &choice);
            printf ("==============================================================\n");

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N = N+const_n;
                }
                case 2:
                {
                    N=N+n_count;
                }
                case 3:
                {
                    break;
                }
            }
        }
    }while(fabs(xi-x2)>eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double f (double x) {
    return (((x - pow(10,3)*sin((x+10)/100))-(10*x)+12));
}

