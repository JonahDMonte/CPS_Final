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
float yearlyaverages2020(float a[400][10])
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
float yearlyaverages2019(float a[400][10])
{
 return 0; 
}


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

  yearlyaverages2020(intake);
  coldestwarmest(intake);
  daybyday(intake);
  totalwarmest(intake);
  summer(intake);
  winter(intake);
  frozen(intake);
  yearlyaverages2019(intake);
  
}