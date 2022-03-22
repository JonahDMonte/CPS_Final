//Jonah D'Monte and Vincent Tat


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

  //j = 0: Year column.
  //j = 1: Day column.
  //j = 2: Lake Superior datapoints column.
  //j = 3: Lake Michigan datapoints column.
  //j = 4: Lake Huron datapoints column.
  //j = 5: Lake Erie datapoints column.
  //j = 6: Lake Ontario datapoints column.
  //j = 7: Late St. Clair datapoints column.

//question 1
float yearlyaverages(float a[400][10])
{
 return 0; 
}
//question 2
float coldestwarmest(float a[400][10])
{
  return 0;
}
//question 3
float daybyday(float a[400][10])
{
  return 0;
}
//question 4
float totalwarmest(float a[400][10])
{
  return 0;
}
//question 5
float summer(float a[400][10])
{
  return 0;
}
//question 6
float winter(float a[400][10])
{
  return 0;
}
//question 7
float swimmable(float a[400][10])
{
  return 0;
}
//question 8
float frozen(float a[400][10])
{
  return 0;
}
//question 9



int main(void) {
  float intake[400][10];
  float dpoints[400][10]; //All datapoints are stored in this array.
  //The first element (referenced as "i" throughout) is the current row of data being operated on.
  //The second element (referenced as "j" throughout) is the current column of data being operated on.
  //When applied together, any point in the data can be accessed by calling dpoints[i][j]. 
  //j = 0: Year column.
  //j = 1: Day column.
  //j = 2: Lake Superior datapoints column.
  //j = 3: Lake Michigan datapoints column.
  //j = 4: Lake Huron datapoints column.
  //j = 5: Lake Erie datapoints column.
  //j = 6: Lake Ontario datapoints column.
  //j = 7: Late St. Clair datapoints column.

  //START: putting .txt file data in array
  int n = 1;
  FILE *data;
  while(n != 0)
  {
    printf("Would you like to use the 2020 or 2019 dataset?\nEnter 2020 or 2019. Enter 0 to exit\n");
    scanf("%d", &n);

    
    if (n == 2020)
    {
      FILE *data = fopen("2020data.txt", "r");
      char *nums = NULL;
      size_t len = 0;
      
      for(int i = 0; getline(&nums, &len, data) != -1; i++) //move   vertically in the array
      {
        char *line = nums;
        char *linetok = strtok(line, "   ");

          for(int j = 0; linetok != NULL;j++) //assign data to element in array and then move horizontally through the array
          {
            intake[i][j] = atof(linetok);
            linetok = strtok(NULL, " ");
          }
        }
        fclose(data);
      //END: putting .txt file data in array
    }
    else if (n == 2019)
    {
      FILE *data = fopen("2019data.txt", "r");
      char *nums = NULL;
      size_t len = 0;
      
      for(int i = 0; getline(&nums, &len, data) != -1; i++) //move   vertically in the array
      {
        char *line = nums;
        char *linetok = strtok(line, "   ");
          for(int j = 0; linetok != NULL;j++) //assign data to element in array and then move horizontally through the array
          {
          
            intake[i][j] = atof(linetok);
            linetok = strtok(NULL, " ");
          }

        }
        fclose(data);
      //END: putting .txt file data in array
    }
    else if(n == 0)
    {
      //Catch n = 0 without printing "Please enter a valid option."
    }
    else
    {
      printf("Please enter a valid option.\n");
    }


  }
printf("Program closed.");
}