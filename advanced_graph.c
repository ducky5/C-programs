/* a program that lets you plot the maximum number
 of points on a graph that you determine the size of
 DATE: 14/12/2020
 */

#include <stdio.h>
#include <stdbool.h>

void get_input(void);
void print_graph(void);

int size, points[43*43][2];
const int sizeLimit = 43;//constant limit based on this laptop's screen size and resolution
int main(void)
{
  get_input();//gets graph size and coordinates
  print_graph();//prints the graph using size and points
  return 0;
}

void get_input(void)
{
  //ask user for graph size value
  do
  {
    printf("graph size: ");
    scanf("%i", &size);
  }
  while(size > sizeLimit || size <= 0);
  //ask user for x and y coordinates of each individual point
  for(int i = 0; i < size*size; i++)
  {
    printf("(x, y): ");
    scanf("%i %i", &points[i][0], &points[i][1]);
    if(!points[i][0] && !points[i][1])//if x = y = 0 stop loop
      break;
    //following else if statements cancel bad values but doesn't solve for char data types
    //better not use chars
    else if(points[i][0] > size || points[i][1] > size)
      i--;
    else if(points[i][0] < 0 || points[i][1] < 0)
      i--;
  }
}

void print_graph(void)
{
  int xPosition = 0;//refers to current x coordinate
  int yPosition = size;//refers to current y coordinate
  bool isPlot = false;//1 if point is plotted and 0 if not plotted
  printf("\n\n");//spacing for design purposes
  //prints y axis
  for(; yPosition >= 1; yPosition--)
  {
    xPosition = 0;//resets variable upon jump to next line
    printf("%i", yPosition);
    for(int k = 0; k < size; k++)//detects graph size and sets a limit
    {
      if(isPlot/*meaning isPlot = true*/ || !xPosition)//if a point was plotted
      {
        if(yPosition >= 10 && !xPosition/*meaning xPosition = 0*/)//for 2 digit numbers on y axis
          printf(" ");
        else//for 1 digit numbers on y axis
          printf("  ");
        if(xPosition >= 10)//for 2 digit numbers on x axis
          printf("   ");
      }
      else//if no point was plotted
        {
          if(xPosition >= 10)//for 2 digit numbers on x axis
            printf("    ");
          else//for 1 digit numbers on x axis
            printf("   ");
        }
      if(isPlot)//if isPlot = true then set it to false
        isPlot = false;
      xPosition++;//adds 1 to xPosition
      for(int i = 0; i < size*size; i++)//searches 2d array points[][]
      {
        if(xPosition == points[i][0] && yPosition == points[i][1])//looks for match
        {
          printf("*");//plots point
          isPlot = true;
          break;//prevents duplication
        }
      }
    }

    printf("\n");//end of iteration
  }
  //prints x axis
  for(int j = 0; j <= size; j++)
    printf("%i  ", j);//the spacing equals 2, and SHOULD STAY THIS WAY
  printf("\n\n");//same deal here just spacing for good design
}
