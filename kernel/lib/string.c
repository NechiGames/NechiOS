#include "include/lib/string.h"

char tolower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int strlen(const char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return len;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];

        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
    }
    return 0;
}

int strcasecmp(const char *str1,const char *str2){
    while(*str1 && *str2){
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);

        if(c1 != c2){
            return c1 - c2;
        }

        str1++;
        str2++;
    }

    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}