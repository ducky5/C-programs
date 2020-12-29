#include <stdio.h>

int arraySize(void);
//can't not hardcode 14 in the line below cuz compiler throws error
float data[14][4], factors[14/*data[][] size*/], numOfTests = 0, multiplied = 0, numOfSubjects = 0, sumOfFactors = 0;
int main(void)
{
  printf("Number of subjects: ");
  scanf("%f", &numOfSubjects);
  for(int i = 0; i < arraySize() && i < numOfSubjects; i++)
  {
    printf("coefficient of subject%i: ", i+1);//+1 for user-friendliness
    scanf("%f", &factors[i]);
    printf("Number of tests for subject%i: ", i+1);
    scanf("%f", &numOfTests);
    for(int j = 0; j < sizeof(float) && j < numOfTests; j++)
    {
      printf("Subject%i -> Test%i: ", i+1, j+1);
      scanf("%f", &data[i][j]);
    }
    multiplied += ((data[i][0] + data[i][1] + data[i][2] + data[i][3]) / numOfTests) * factors[i];
  }
  for(int k = 0; k < arraySize(); k++)
    sumOfFactors += factors[k];
  printf("result: %.2f\n"/*print 2 digits past decimal point*/, multiplied / sumOfFactors);
  return 0;
}

int arraySize(void)//calculates size of data[][] only
{
  return ((sizeof(data) / sizeof(float)) / sizeof(float));
}
