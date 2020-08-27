# include <stdio.h>
# include <math.h>
# include <assert.h>


const int inf_num_roots = -1;


int squareSolver(double a, double b, double c, double* x1, double* x2)
    {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1!=NULL);
    assert (x2!=NULL);
    assert (x1!=x2);

    if (a == 0)
        {
        if (b == 0)
            {
            if (c == 0)
                {
                return inf_num_roots;
                }
            else
                {
                return 0;
                }
            }
        else
            {
            *x1 =  -c / b;
            return 1;
            }
        }
    else
        {
        double d = b*b - 4*a*c;

        if (d < 0)
            {
            return 0;
            }
        else if (d == 0)
            {
            *x1 = -b / (2*a);
            return 1;
            }
        else
            {
            *x1 = (-b - sqrt(d)) / (2 * a);
            *x2 = (-b + sqrt(d)) / (2 * a);
            return 2;
            }
        }
    }



 int main()
    {
    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int roots_num = squareSolver(a, b, c, &x1, &x2);

    switch(roots_num)
        {
        case 0: printf("No roots");
        break;

        case 1: printf("x = %f", x1);
        break;

        case 2: printf("x1 = %f, x2 = %f", x1, x2);
        break;

        case inf_num_roots: printf("Any numer");
        break;

        default: printf("Error: Unexpected roots_num = %d\n", roots_num);
        return 1;
        }

    return 0;
    }






