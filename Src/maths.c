#include "maths.h"

double meas_mean(double * data, uint32_t len)
{
	double sum = 0;

	for(uint32_t i = 0; i < len; i++) 
    {
        sum += data[i];
    }

	return (double)(sum / (double)len);
}
