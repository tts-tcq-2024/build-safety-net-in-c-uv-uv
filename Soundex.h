#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

int Fun_set6value(char c)
{
    c = toupper(c);
    if (c == 'R')
    {
        return 6;
    }
}


int Fun_set5value(char c)
{
    c = toupper(c);
    char Set5Array[2] = {'M','N'};
    int count =0;
    for (int i = 0; i < 2; i++)
    {
        if (c == Set5Array[i])
        {
            count = count + 1;
            break;
        }
    }
    if (count == 1)
    {
        return 5;
    }
    else
    {
        return Fun_set6value(c);
    }
}


int Fun_set4value(char c)
{
    c = toupper(c);
    if (c == 'L')
    {
        return 4;
    }
    else
    {
        return Fun_set5value(c);
    }
}


int Fun_set3value(char c)
{
    c = toupper(c);
    char Set3Array[2] = {'D','T'};
    int count =0;
    for (int i = 0; i < 2; i++)
    {
        if (c == Set3Array[i])
        {
            count = count + 1;
            break;
        }
    }
    if (count == 1)
    {
        return 3;
    }
    else
    {
        return Fun_set4value(c);
    }
}

int Fun_set2value(char c)
{
    c = toupper(c);
    char Set2Array[8] = {'C','G','J','K','Q','S','X','Z'};
    int count =0;
    for (int i = 0; i < 8; i++)
    {
        if (c == Set2Array[i])
        {
            count = count + 1;
            break;
        }
    }
    if (count == 1)
    {
        return 2;
    }
    else
    {
        return Fun_set3value(c);
    }
}

int Fun_set1value(char c)
{
    c = toupper(c);
    char Set1Array[4] = {'B','F','P','V'};
    int count =0;
    for (int i = 0; i < 4; i++)
    {
        if (c == Set1Array[i])
        {
            count = count + 1;
            break;
        }
    }
    if (count == 1)
    {
        return 1;
    }
    else
    {
        return Fun_set2value(c);
    }
}

int Fun_set0value(char c)
{
    c = toupper(c);
    char Set0Array[8] = {'A','E','I','O','U','H','W','Y'};
    int count =0;
    for (int i = 0; i < 8; i++)
    {
        if (c == Set0Array[i])
        {
            count = count + 1;
            break;
        }
    }
    if (count == 1)
    {
        return 0;
    }
    else
    {
        return Fun_set1value(c);
    }
}




char getSoundexCode(char c) {
    return Fun_set0value(c);

}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
