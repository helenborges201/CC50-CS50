#include <stdio.h>
#include <cs50.h>

float average();

const int TOTAL = 3;

int main(void)
{
    int score[TOTAL];
    for(int i = 0; i < TOTAL; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(TOTAL, score));
}

float average(int length, int array[])
{
  int sum = 0;

  for(let i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / (float) length;

}