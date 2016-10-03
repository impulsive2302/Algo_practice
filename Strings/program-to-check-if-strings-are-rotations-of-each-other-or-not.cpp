#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int areRotations(char* str1, char* str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str1);
    if(size1 != size2)
        return false;
    char* temp;
    temp = (char *)malloc((2*size1 +1)*sizeof(char));
    temp[0] = '\0';
    strcat(temp,str1);
    strcat(temp,str2);
    char* d = strstr(temp,str2);
    free(temp);
    if(d)
        return true;
    else return false;

}
int main()
{
    char *str1 = "AACD";
    char *str2 = "ACDA";

    if (areRotations(str1, str2))
       printf("Strings are rotations of each other");
    else
       printf("Strings are not rotations of each other");

    getchar();
    return 0;
}
