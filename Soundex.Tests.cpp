#include <gtest/gtest.h>
#include "Soundex.h"

void generateSoundex(const char *name, char *soundex);
TEST(SoudexTestsuite, Checktwovowels)
{
// to check two vowels case
    const char* expectedSoundex = "T522";
    char soundex[5] = {};
    const char* name = "Tymczak";
    generateSoundex(name, soundex);
    EXPECT_EQ(expectedSoundex[0], soundex[0]);
    EXPECT_EQ(expectedSoundex[1], soundex[1]);
    EXPECT_EQ(expectedSoundex[2], soundex[2]);
    EXPECT_EQ(expectedSoundex[3], soundex[3]);
    EXPECT_EQ(expectedSoundex[4], soundex[4]);

}