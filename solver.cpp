#include <TXLib.h>
#include <stdio.h>
#include <math.h>

// Square equations solver
int main(void) {
    float a, b, c;
    printf ("Coefficients (with \"enter\"):\n");
    scanf ("%f\n%f\n%f", &a, &b, &c);

    // zero coefficients
    if (a == 0) {
        float x;
        if (b != 0) {
            x = -c / b;
            printf ("One root:\n%.2f", x);
            return 0;
        }
        else if (c == 0) {
            printf ("Infinite amount of roots");
            return 0;
        }
        else {
            printf ("Zero roots");
            return 0;
        }
    }

    float discr;
    discr = b * b - 4 * a * c;

    // Checking discriminant
    if (discr < 0) {
        printf ("Zero rational solutions");
        return 0;
    }
    else if (discr == 0) {
        float x;
        x = -b / (2 * a);
        printf ("One root:\n%.3f", x);
        return 0;
    }
    else {
        float x1, x2;
        x1 = (sqrt(discr) - b) / (2 * a);
        x2 = (-sqrt(discr) - b) / (2 * a);
        printf ("Two roots:\n%.3f\n%.3f", x1, x2);
        return 0;
    }
}
