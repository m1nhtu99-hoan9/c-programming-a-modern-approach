#include <stdio.h>
#include <stdlib.h>

/* Modified version of `07.c` */

int max_score(int arr[5]);
int min_score(int arr[5]);

int main()
{
  int i, j, cur, quiz_score_sums[5] = {}, student_score_sums[5] = {},
                 // scores categorised by quizes
      quiz_scores[5][5] = {};

  printf("Enter five quiz grades for each of five students ");
  printf("(scores separated by a black space)\n");
  for (i = 0; i < 5; i++)
  // traverse rows
  {
    printf("Enter student #%d\'s grades: ", i + 1);
    for (j = 0; j < 5; j++)
    // traverse columns
    {
      scanf("%d", &cur);

      quiz_scores[j][i] = cur;
      // accumulate scanned value to respective running totals
      student_score_sums[i] += cur;
      quiz_score_sums[j] += cur;
    }
  }

  /* print out results */

  printf("\n--STUDENT STATISTICS--\n");
  printf("Total score of each student: \n");
  for (int i = 0; i < 5; i++)
  {
    printf("  Student #%d:", i + 1);
    printf("%3d (avg: %4.2f)", student_score_sums[i], student_score_sums[i] / 5.0);
    printf("\n");
  }
  printf("\n--QUIZ STATISTICS--:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("  Quiz #%d:", i + 1);
    printf(" <avg> %4.2f; <min> %d; <max> %d", quiz_score_sums[i] / 5.0, min_score(quiz_scores[i]), max_score(quiz_scores[i]));
    printf("\n");
  }
  printf("\n");

  return 0;
}

/* implementations */

int max_score(int arr[5])
{
  int res = 0;

  for (int i = 0; i < 5; i++)
  {
    if (arr[i] > res)
      res = arr[i];
  }

  return res;
}

int min_score(int arr[5])
{
  int res = arr[0];

  for (int i = 1; i < 5; i++)
  {
    if (arr[i] < res)
      res = arr[i];
  }

  return res;
}