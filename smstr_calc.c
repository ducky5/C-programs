#include <stdio.h>

int arraySize(void);

float data[12][4], factors[12/*data[][] size*/], numOfTests, multiplied = 0, numOfSubjects, sumOfFactors = 0;
int main(void)
{
  printf("Number of subjects: ");
  scanf("%f", &numOfSubjects);
  for(int i = 0; i < arraySize() && i < numOfSubjects; i++)
  {
    printf("coefficient of subject%i: ", i+1);//+1 for user-friendliness
    scanf("%f", &factors[i]);
    printf("Number of tests for subject%i ", i+1);
    scanf("%f", &numOfTests);
    for(int j = 0; j < sizeof(int) && j < numOfTests; j++)
    {
      printf("Subject%i -> Test%i ", i+1, j+1);
      scanf("%f", &data[i][j]);
    }
    multiplied += ((data[i][0] + data[i][1] + data[i][2] + data[i][3]) / numOfTests) * factors[i];
  }
  for(int k = 0; k < arraySize(); k++)
  {
    sumOfFactors += factors[k];
  }
  printf("result: %.2f\n"/*print 2 digits past decimal point*/, (float)multiplied / sumOfFactors);
  return 0;
}

int arraySize(void)//calculates size of data[][] only
{
  int size;
  size = (sizeof(data) / sizeof(int)) / sizeof(int);
  return size;
}
