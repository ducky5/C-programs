#include <stdio.h>

int main(void)
{
  unsigned int xd, yd, xv, yv;

  // get input
  printf("x length only positive integers: ");
  scanf("%i", &xd);
  printf("y length only positive integers: ");
  scanf("%i", &yd);
  printf("x value only positive integers: ");
  scanf("%i", &xv);
  printf("y value only positive integers: ");
  scanf("%i", &yv);
  // prints three blank lines at top of graph
  printf("\n\n\n");
  // prints the y axis
  for(unsigned int i = yd; i <= yd && i != 0; i--)
  {
    // checks if i is equal to user input for y coordinate
    if(i == yv)
    {
      // search for the x coordinate
      for(int ic = 1; ic <= xv; ic++)
      {
        // this line makes sure the coordinate number is printed before searching for the x coordinate
        if(ic == 1)
        {
          printf("%i", i);
        }
        // if x coordinate is not found add 3 spaces
        if(ic != xv)
        {
          printf("   ");
        }
        // if x coordinate is found then add 2 spaces and graph the point
        if(ic == xv)
        {
          if(i >= 10)
          {
            printf(" *\n");
          }
          else
          {
            printf("  *\n");
          }
          //printf("  *\n");
        }
      }
    }
    // if i is not equal to user input for the y coordinate the following line just prints the y coordinate new line
    else
    {
      printf("%i\n", i);
    }
  }
  // print the 0 point on graph
  printf("0");
  // print the x axis
  for(unsigned int j = 1; j <= xd; j++)
  {
    if(j >= 10)
    {
      printf(" %i", j);
    }
    else
    {
      printf("  %i", j);
    }
  }
  // prints three blank lines at bottom of graph
  printf("\n\n\n");
  return 0;
}
