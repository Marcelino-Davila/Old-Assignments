#include <stdio.h>
#include "intSet.h"

int main() {
// test each function and print it on console
printf("Expected : Actual\n");
intSet s1 = createSet();
// create empty set
printf("{} : %s\n", toString(s1));
// add element to set
add(s1, 9);
add(s1, -15);
add(s1, 14);
printf("{-15,9,14} : %s\n", toString(s1));
// check smallest and largest

printf("-15 : %d\n", smallest(s1));
printf("14 : %d\n", largest(s1));
// create new set
intSet s2 = createSet();
add(s2, 9);
printf("\n------------------------------\n");
add(s2, 0);
printf("\n------------------------------\n");
add(s2, 9);
add(s2, 27);
add(s2, -6);
printf("{-6,0,9,27} : %s\n", toString(s2));
// check union
intSet s3 = union_(s1, s2);
printf("{-15,-6,0,9,14,27} : %s\n", toString(s3));
// check intersection
intSet s4 = intersect(s1, s2);
printf("{9} : %s\n", toString(s4));
printf(" check difference \n");
intSet s5 = diff(s1, s2);
printf("{-15,14} : %s\n", toString(s5));
printf(" check remove\n");
remove_(s3, 0);
remove_(s3, -6);
remove_(s3, 9);
printf("{-15,14,27} : %s\n", toString(s3));

// free memory
destroySet(s1);
destroySet(s2);

return 0;
}