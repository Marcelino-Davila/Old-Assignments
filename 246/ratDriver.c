#include <stdio.h>
#include "rat.h"
int main(void) {
rat r1 = createRat(-1,-1), r2 = createRat(6,3);
printf("neg / neg %s  reduce whole number %s\n", toString(norm(r1)), toString(reduce(r2))); 
printf("%s\n%d\n",toString(r1),cmp(r1,r2));
printf("num %d\n",r1->n);
printf("\n %s \n",toString(norm(r2)));
printf("add(r1,r2) = %s\n",toString(add(r1,r2)));
printf("is r1 well formed? %s\n",wellFormed(r1)?"yes":"no");
printf("\nSUBTRACT             %s\n",toString(sub(r1,r2)));
printf("\nMULTIPLY           %s\n",toString(mul(r1,r2)));
printf("\nDIVIDE             %s\n",toString(divide(r1,r2)));
}
