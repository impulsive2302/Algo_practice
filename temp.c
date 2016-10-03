#include<stdlib.h>
int main()
{
    int a = 4;
    float b = 5.5;
    int *intptr = &a;
    float *fltptr = &b;
    printf("int %d\n",*intptr);
    printf("float %f\n",*fltptr);
    fltptr = (float*)intptr;
    printf("float %f\n",*fltptr);
    intptr = &b;
    printf("int %d\n",*intptr);
}
