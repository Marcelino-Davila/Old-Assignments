#include <stdio.h>

void UpdateScoreVals(int scoreVals[], int numVals, int updateVal) {
   int i;

   for (i = 0; i < numVals; ++i) {
      scoreVals[i] = scoreVals[i] * updateVal;
   }
}

void PrintScoreVals(const int scoreVals[], int numVals) {
   int i;

   for (i = 0; i < numVals; ++i)  {
      printf("%d\n", scoreVals[i]);
   }
}

int main() {
   const int NUM_SCORES = 4;
   int quizScores[NUM_SCORES];
   int scoreUpdate = 10;
   int i;

   for (i = 0; i < NUM_SCORES; ++i) {
      scanf("%d", &(quizScores[i]));
   }

   UpdateScoreVals(quizScores, NUM_SCORES, scoreUpdate);
   PrintScoreVals(quizScores, NUM_SCORES);

   return 0;
}