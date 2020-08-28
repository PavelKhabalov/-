/*!
\file
\brief   Solver of quadratic equation.
\authors Pavel Khabalov
\date    28.08.2020
*/



# include <stdio.h>
# include <math.h>
# include <assert.h>


const int INF_NUM_ROOTS = -1;///< This constant stores the designation of an infinite number of roots


const double MIN_DIFF = 1e-19;///< This constant defines the minimum difference at which the numbers are not equal

/*!
 Checks if numbers are approximately equal
\param a, b Compared numbers
\return True if numbers are equal and False if not
*/
bool equal_nums(double a, double b);


/*!
 Solve a linear equation
\param a, b Coefficients of equation a*x + b == 0
\param x Address of variable in which the root value will be put
\return Number of roots
*/
int linearSolver(double a, double b, double* x);


/*!
 Solve a quadratic equation
\param a, b, c Coefficients of equation a*x**2 + b*x + c == 0
\param x1, x2 Addresses of variables in which the roots value will be put
\return Number of roots
*/
int squareSolver(double a, double b, double c, double* x1, double* x2);



/*!
 Main function that output the answer
*/
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

        case 1: printf("x = %lg", x1);
        break;

        case 2: printf("x1 = %lg, x2 = %lg", x1, x2);
        break;

        case INF_NUM_ROOTS: printf("Any numer");
        break;

        default: printf("Error: Unexpected roots_num = %d\n", roots_num);
        return -1;
        }

    return 0;
    }

int squareSolver(double a, double b, double c, double* x1, double* x2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (equal_nums(a, 0))
        {
        int roots_num = linearSolver(b, c, x1);
        return roots_num;
        }
    else
        {
        double d = b*b - 4*a*c;

        if (d < 0)
            {
            return 0;
            }
        else if (equal_nums(d, 0))
            {
            *x1 = -b / (2*a);
            return 1;
            }
        else
            {
            *x1 = (-b - sqrt(d)) / (2*a);
            *x2 = (-b + sqrt(d)) / (2*a);
            return 2;
            }
        }
    }


int linearSolver(double a, double b, double* x)
    {
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x != NULL);

    if (equal_nums(a, 0))
        {
        return (equal_nums(b, 0))? INF_NUM_ROOTS: 0;
        }
    else
        {
        *x = -b / a;
        return 1;
        }
    }

bool equal_nums(double a, double b)
    {
    return (((a - b) > -MIN_DIFF) & ((a - b) < MIN_DIFF));
    }

