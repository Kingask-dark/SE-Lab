#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

float calculate_mean(int input[]);
float sd_from_mean(float mean, int input[]);
bool test_mean(float mean, float actualmean);
bool test_sd(float sd, float actualsd);

int main()
{
	int a1[4] = {1, 2, 3, 4}, a2[4] = {5, 6, 7, 8}, a3[4] = {-2, -4, 9, 3};
	float  mean1, mean2, mean3, sd1, sd2, sd3;
	bool meantest1, meantest2, meantest3, sdtest1, sdtest2, sdtest3;

	// get mean for first input data set a1,a2,a3 let it be mean1,mean2.mean3
	mean1 = calculate_mean(a1);
	mean2 = calculate_mean(a2);
	mean3 = calculate_mean(a3);

	// get sd_from_mean for input data set a1,a2,a3 and let it be sd1,sd2,sd3
	sd1 = sd_from_mean(mean1, a1);
	sd2 = sd_from_mean(mean2, a2);
	sd3 = sd_from_mean(mean3, a3);

	// validate / test the result for mean
	meantest1 = test_mean(mean1, 2.5);
	meantest2 = test_mean(mean2, 6.5);
	meantest3 = test_mean(mean3, 1.5);
	if ( meantest1 == true && meantest2 == true && meantest3 == true)
	{
		printf("Mean Test is successfull\n");
	}
	else
	{
		printf("Mean Test isn't successfull\n");
	}

	// Validate / test the result for standard deviation
	sdtest1 = test_sd(sd1, 1.118034F);
	sdtest2 = test_sd(sd2, 1.118034F);
	sdtest3 = test_sd(sd3, 5.0249378105604F);

	if(sdtest1 == true && sdtest2 == true && sdtest3 == true){
		printf("Standard Deviation Test is Successfull\n");
	}
	else{
		printf("Standard Deviation Test is Unsuccessfull\n");
	}
  return 0;
}

// this method returns the mean for the given input array
float calculate_mean(int input[])
{
	int sum = 0;
	float mean;
	for (int i = 0; i < 4; i++)
	{
		sum += input[i];
	}
	mean = sum / (float)4;
	// printf("Mean = %f\n ",mean);
	return mean;
}

// this method returns the sd from mean for the given input array
float sd_from_mean(float mean, int input[])
{
	float deviation = 0, sumsqr = 0, variance, stddeviation;
	for (int i = 0; i <= 3; i++)
	{
		deviation = input[i] - mean;
		sumsqr = sumsqr + pow(deviation, 2);
	}
	variance = sumsqr / (float)4;
	stddeviation = sqrt(variance);
	// printf("Standard Deviation : %f\n", stddeviation);
	return stddeviation;
}

// arguments actualmean -> actual mean of the given inputs
// 			  mean -> the value of mean of the input array

bool test_mean(float mean, float actualmean)
{
	if (mean == actualmean)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// arguments actualsd -> actual sd of the given inputs
// 			  mean -> the value of mean of the input array

bool test_sd(float sd, float actualsd)
{
	if (sd == actualsd)
	{
		return true;
	}
	else
	{
		return false;
	}
}
