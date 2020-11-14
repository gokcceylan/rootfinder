#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");

	double a, b, bPrint, c, cPrint, d, x1, x2;
	char bsign = '+', csign = '+';
	fscanf(input, "y=%lfx^2%lfx%lf", &a, &b, &c);
	bPrint = b;
	cPrint = c;

	if (b < 0)
	{
		bsign = '-';
		bPrint *= -1;
	}
	if (c < 0)
	{
		csign = '-';
		cPrint *= -1;
	}
	fprintf(output, "Equation: y=%.2lfx^2%c%.2lfx%c%.2lf\n", a, bsign, bPrint, csign, cPrint);


	d = b * b - (4 * a * c);
	double squareOfDsc = sqrt(d);
	if (d > 0)
	{
		fprintf(output, "Discriminant: %.2lf. Therefore, there are two real roots.\n", d);
		fprintf(output, "1st root: %.2lf.\n", (-b + squareOfDsc) / (2 * a));
		fprintf(output, "2nd root: %.2lf.\n", (-b - squareOfDsc) / (2 * a));
	}
	else if (d == 0)
	{
		fprintf(output, "Discriminant: %lf. Therefore, there is one real root.\n", d);
		fprintf(output, "Root: %.2lf.\n", (-b) / (2 * a));
	}
	else if (d < 0)
	{
		fprintf(output, "Discriminant: %.2lf. Therefore, there are no real roots.\n", d);
	}

	fscanf(input, "%lf\n%lf", &x1, &x2);
	fprintf(output, "For x=%.2lf, y equals to %.2lf.\n", x1, (a * x1 * x1 + b * x1 + c));
	fprintf(output, "For x=%.2lf, y equals to %.2lf.\n", x2, (a * x2 * x2 + b * x2 + c));

	fclose(input);
	fclose(output);
	return 0;
}
