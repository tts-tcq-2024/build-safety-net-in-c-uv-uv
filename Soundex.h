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
    else
    {
        return 0;
    }
}


int Fun_set5value(char c)
{
    c = toupper(c);
    if (c == 'M' || c == 'N')
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
    if (c == 'D' || c == 'T')
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
    if (c == 'C' || c == 'G' || c=='J' || c=='k' || c=='Q' || c=='S' || c=='X' || c=='Z')
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
    if (c == 'B' || c == 'F' || c=='P' || c=='V')
    {
        return 1;
    }
    else
    {
        return Fun_set2value(c);
    }
}

char getSoundexCode(char c) {
    return Fun_set1value(c);

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
