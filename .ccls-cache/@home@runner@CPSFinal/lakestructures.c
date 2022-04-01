#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
//DECLARATION AND INITIALIZATION STARTS HERE
struct Lake{
char name[50];
float d2020[400];
float d2019[400];
float avg2020;
float avg2019;
int warmest;
int coldest;
float summeravg;
float winteravg;
int swimmable;
int frozen;


};


int lakestructures(void)
{

  struct Lake superior, michigan, huron, erie, ontario, stclair;
  struct Lake lakes[6] = {superior, michigan, huron, erie, ontario, stclair};
  strcpy(lakes[0].name, "Lake Superior");
  strcpy(lakes[1].name, "Lake Michigan");
  strcpy(lakes[2].name, "Lake Huron");
  strcpy(lakes[3].name, "Lake Erie");
  strcpy(lakes[4].name, "Lake Ontario");
  strcpy(lakes[5].name, "Lake St. Clair");

  for (int y = 0; y < 6; y++)
    {
      lakes[y].warmest = 0;
      lakes[y].coldest = 0;
    }
  float intake2020[400][10];
  float intake2019[400][10];
  //DECLARATION AND INITIALIZATION ENDS HERE

  //DATA ENTRY STARTS HERE
  FILE *data2020 = fopen("2020data.txt", "r");
      char *nums2020 = NULL;
      size_t len2020 = 0;
      
      for(int i = 0; getline(&nums2020, &len2020, data2020) != -1; i++) //move   vertically in the array
      {
        char *line2020 = nums2020;
        char *linetok2020 = strtok(line2020, "   ");

          for(int j = 0; linetok2020 != NULL;j++) //assign data to element in array and then move horizontally through the array
          {
            intake2020[i][j] = atof(linetok2020);
            linetok2020 = strtok(NULL, " ");
          }
        }
        fclose(data2020);

   FILE *data2019 = fopen("2019data.txt", "r");

      char *nums2019 = NULL;
      size_t len2019 = 0;
      
      for(int i = 0; getline(&nums2019, &len2019, data2019) != -1; i++) //move   vertically in the array
      {
        char *line2019 = nums2019;
        char *linetok2019 = strtok(line2019, "   ");

          for(int j = 0; linetok2019 != NULL;j++) //assign data to element in array and then move horizontally through the array
          {
            intake2019[i][j] = atof(linetok2019);
            linetok2019 = strtok(NULL, " ");
          }
        }
        fclose(data2019);
  //Assigning temps to associated lakes
  for (int y = 2; y < 8; y++)
      {
        for (int x = 0; x < 366; x++)
          {
            lakes[y-2].d2020[x] = intake2020[x][y];
          }
      }
  for (int y = 2; y < 8; y++)
      {
        for (int x = 0; x < 365; x++)
          {
            lakes[y-2].d2019[x] = intake2019[x][y];
          }
      }
  //DATA ENTRY ENDS HERE
  
  //CALCULATIONS BEGIN HERE
  // Averages in 2020
  for (int y = 0; y < 6; y++)
    {
      float count = 0;
      for (int x = 0; x < 366; x++)
        {
          count += lakes[y].d2020[x];
        }
      lakes[y].avg2020 = count/366;
    }
//Averages in 2019
  for (int y = 0; y < 6; y++)
    {
      float count = 0;
      for (int x = 0; x < 365; x++)
        {
          count += lakes[y].d2019[x]; //Add up all temps
        }
      lakes[y].avg2019 = count/365; //Divide to average and assign to avg val in struct
    }
//Warmest and coldest day
  for (int y = 0; y < 6; y++)
    {
      for (int x = 0; x < 366; x++)
        {
         if (lakes[y].d2020[lakes[y].warmest] < lakes[y].d2020[x])
         {
           lakes[y].warmest = x;
         }
          else if (lakes[y].d2020[lakes[y].coldest] > lakes[y].d2020[x])
          {
            lakes[y].coldest = x;
          }
        }

    }

for (int y = 0; y < 6; y++)//summer and winter average
    {
      float count = 0;
      for (int x = 171; x < 265; x++) //summer average
        {
          count += lakes[y].d2020[x];
        }
      lakes[y].summeravg = count/(265-171);
    }  
for (int y = 0; y < 6; y++)//winter average
    {
      float count = 0;
      for (int x = 0; x < 79; x++)
        {
          count += lakes[y].d2020[x];
        }
      for (int x = 354; x < 366; x++)
        {
          count += lakes[y].d2020[x];
        }
      lakes[y].winteravg = count/((79)+(366-354));
    }  

  //swimmable and frozen
  for(int y = 0; y < 6; y++)
    {
      int count[2] = {0};
      for (int x = 0; x < 366; x++)
        {
          if (lakes[y].d2020[x] > 20) //test if swimmable
          {
            count[0] += lakes[y].d2020[x];
          }
          else if (lakes[y].d2020[x] < 0) //teset if frozen
          {
            count[1] += lakes[y].d2020[x];
          }
          lakes[y].swimmable = count[0];
          lakes[y].frozen = count[1];
        }
    }
  //CALCULATIONS END HERE
  //PRINTING ANSWERS STARTS HERE
  //q1
  printf("Average Temperatures Per Lake(2020)\n");
  for (int y = 0; y < 6; y++)
    {
      printf("%s: %0.2f °C\n", lakes[y].name, lakes[y].avg2020);
    }

  //q2
  printf("\nWarmest and Coldest Lakes\n");
  int cold = 0;
  int warm = 0;
  float allavg = 0;
  for(int y = 0; y < 6; y++)
    {
      allavg += lakes[y].avg2020;
      if (lakes[y].avg2020 < lakes[cold].avg2020)
      {
        cold = y;
      }
      else if (lakes[y].avg2020 > lakes[warm].avg2020)
      {
        warm = y;
      }
    }
  allavg = allavg / 6;
  
  printf("Coldest lake: %s\n", lakes[cold].name);
  printf("Warmest lake: %s\n", lakes[warm].name);
  printf("The following lakes are colder than average:\n");
  for (int y = 0; y < 6; y++)
    {
      if (lakes[y].avg2020 < allavg)
      {
        printf("%s\n", lakes[y].name);
      }
    
    }
  printf("The following lakes are warmer than average:\n");
  for (int y = 0; y < 6; y++)
    {
      if (lakes[y].avg2020 > allavg)
      {
        printf("%s\n", lakes[y].name);
      }
    }

  //q3
  printf("\nColdest and Warmest Day on Each Lake\n"); //TODO: Account for ties
  int coldarr[6] = {0};
  int warmarr[6] = {0};
  for (int y = 0; y < 6; y++)
  {
    for(int x = 0; x < 366; x++)
      {
        if (lakes[y].d2020[x] < lakes[y].d2020[coldarr[y]])
        {
          coldarr[y] = x;
        }
        else if (lakes[y].d2020[x] > lakes[y].d2020[warmarr[y]])
        {
          warmarr[y] = x;
        }
      
      }
        printf("%s:\n", lakes[y].name);
        printf("Coldest day: %d\n", coldarr[y] + 1);
        printf("Warmest day: %d\n", warmarr[y] + 1);
    }
  //q4
  printf("\nWarmest Day Across All Lakes\n");
  int warmall = 0; //warmall is a lakes[] number
  for (int y = 0; y < 6; y++)
    {
      if (lakes[warmall].d2020[lakes[warmall].warmest] < lakes[y].d2020[lakes[y].warmest]) 
        //if the temperature on the warmest day on the warmest lake thus far is less than the temperature on the warmest day on lake "y"
      {
          warmall = y;  //the warmest lake bcomes lake "y".
      }
    }
  printf("The warmest lake is %s\n", lakes[warmall].name);
  printf("Day: %d\n", lakes[warmall].warmest + 1);
  printf("Temperature; %0.2f\n", lakes[warmall].d2020[lakes[warmall].warmest]);
  

  
  
  
  return 0;
}

/*1. Calculate the yearly average temperature for each of the lakes, and the yearly average for all six lakes put together.

2. Indicate which lake is the coldest and which one is the warmest, based on the average yearly temperatures calculated in step #1. Also indicate which lakes have average temperatures above the average of all the lakes and which ones are below that same average.

3. Indicate the day and the temperature for the warmest water temperatures for each of the lakes. Do the same for the coldest temperatures. You must convert the day of the year value into a date/month format (you might want to create a function for that).  In the case of a tie, mention all the dates.

4. Find the overall warmest water temperature (all lakes combined). Print out which lake it was, what day it was and what was the temperature. You must convert the day of the year value into a date/month format. Do the same for the coldest overall temperature.  In the case of a tie, mention all the dates.

5. Calculate the summer average (day 172 to day 265) for all 6 lakes (one average per lake).  Display the names of the lakes in order from warmest to coldest.  Is the order from warmest to coldest the same as with the yearly average calculated in step #2?

6. Calculate the winter average (days 1 to 79 and days 355 to 365) for all 6 lakes (one average per lake).  Display the names of the lakes in order from warmest to coldest.  Is the order from warmest to coldest the same as with the yearly average calculated in step #2?

7. Assuming that you can swim comfortably in the lake if the temperature is above 20 degrees. Calculate the number of days in the year you can swim for each of the 6 lakes.

8. Assuming that lakes freeze when the water falls below 0 degrees.  Calculate the number of days in the year that the lake is frozen.

9. Re-do question 1 (the 7 yearly averages) but with data from 2019 instead. Make a table of the averages side by side to illustrate the two yearly results. Any notable changes between 2019 and 2020? Can you advance a conclusion why there is a difference (or not)? The data file for 2019 is here (365 days in 2019): 

https://coastwatch.glerl.noaa.gov/ftp/glsea/avgtemps/2019/glsea-temps2019_1024.dat */