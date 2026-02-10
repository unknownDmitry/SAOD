#include "pch.h"
#include "/SAOD-IV/Task5/Task5/functions.h"

TEST(CompPascal, Row0) {
   int arr[MAX_SIZE][MAX_SIZE] = { 0 };
   comp_pascal(arr, 1);
   //Row 0: 1
   EXPECT_EQ(arr[0][0], 1);
}

TEST(CompPascal, Row1) {
   int arr[MAX_SIZE][MAX_SIZE] = {};
   comp_pascal(arr, 2);
   //Row 1: 1 1
   EXPECT_EQ(arr[1][0], 1);
   EXPECT_EQ(arr[1][1], 1);
}

TEST(CompPascal, Row4) {
   int arr[MAX_SIZE][MAX_SIZE] = {};
   comp_pascal(arr, 5);
   //Row 4: 1 4 6 4 1
   EXPECT_EQ(arr[4][0], 1);
   EXPECT_EQ(arr[4][1], 4);
   EXPECT_EQ(arr[4][2], 6);
   EXPECT_EQ(arr[4][3], 4);
   EXPECT_EQ(arr[4][4], 1);
}

TEST(CompPascal, Edges) {
   int arr[MAX_SIZE][MAX_SIZE] = {};
   comp_pascal(arr, 10);
   for (int i = 0; i < 10; i++) {
      EXPECT_EQ(arr[i][0], 1); // левый край
      EXPECT_EQ(arr[i][i], 1); // правый край
   }
}

TEST(CompPascal, Symmetry) {
   int arr[MAX_SIZE][MAX_SIZE] = {};
   comp_pascal(arr, 10);
   //Row 7: 1 7 21 35 35 21 7 1
   EXPECT_EQ(arr[7][2], arr[7][5]);
   //Row 9: 1 9 36 84 126 126 84 36 9 1
   EXPECT_EQ(arr[9][3], arr[9][6]);
}