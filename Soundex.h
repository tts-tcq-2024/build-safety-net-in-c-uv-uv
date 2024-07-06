#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>



int Arraycheck(char c, int row_value ,int column_value)
{
    char SetArray[6][8] = {
    {'B','F','P','V'},
    {'C','G','J','K','Q','S','X','Z'},
    {'D','T'},
    {'L'},
    {'M','N'},
    {'R'}
    };

     for (int i = 0; i < column_value; i++)
    {
        if (c == SetArray[row_value][i])
        {
            return 1;
            break;
        }
    }
    return 0;
}


char Fun_set6value(char c)
{
    c = toupper(c);
    int row_value = 5;
    int column_value = 1;
    if (Arraycheck(c,row_value,column_value) == 1)
    {
        return 6;
    }
    else
    {
        return 0;
    }
}


char Fun_set5value(char c)
{
    c = toupper(c);
    int row_value = 4;
    int column_value = 2;
    if (Arraycheck(c,row_value,column_value) == 1)
    {
        return 5;
    }
    else
    {
        return Fun_set6value(c);
    }
}


char Fun_set4value(char c)
{
    c = toupper(c);
    int row_value = 3;
    int column_value = 1;
    if (Arraycheck(c,row_value,column_value) == 1)
    {
        return 4;
    }
    else
    {
        return Fun_set5value(c);
    }
}


char Fun_set3value(char c)
{
    c = toupper(c);
    int row_value = 2;
    int column_value = 2;
    if (Arraycheck(c,row_value,column_value) == 1)
    {
        return 3;
    }
    else
    {
        return Fun_set4value(c);
    }
}
char Fun_set2value(char c)
{
    c = toupper(c);
    int row_value = 1;
    int column_value = 8;
    if (Arraycheck(c,row_value,column_value) == 1)
    {
        return 2;
    }
    else
    {
        return Fun_set3value(c);
    }
}


char Fun_set1value(char c)
{
    c = toupper(c);
    int row_value = 0;
    int column_value = 4;
    if (Arraycheck(c,row_value,column_value) == 1)
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
/*
void updatesoundex(char code, char* soundex, int* sIndex)
 {
    if (code != '0' && code != soundex[(*sIndex) - 1])
    {
        soundex[(*sIndex)++] = code;
    }
}
*/
void padzeros(char* soundex, int sIndex)
{
    while (sIndex < 4)
    {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        //updatesoundex(code, soundex, &sIndex);
        if (code != '0' && code != soundex[sIndex - 1])
        {
            soundex[sIndex++] = code;
        }
        
    }
    padzeros(soundex,sIndex);
    
}

#endif // SOUNDEX_H
