#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits)
{
 //AAA
 // to check positive case
  char soundex[5] = {};
  const char* name = "AXDL";
  generateSoundex(name, soundex);
  EXPECT_EQ('A', soundex[0]);
  EXPECT_EQ(2, soundex[1]);
  EXPECT_EQ(3, soundex[2]);
  EXPECT_EQ(4, soundex[3]);

}

TEST(SoudexTestsuite, Checktwovowels)
{
// to check two vowels case
  soundex[5] = {};
  const char* name = "Tymczak";
  generateSoundex(name, soundex);
  EXPECT_EQ('T', soundex[0]);
  EXPECT_EQ(5, soundex[1]);
  EXPECT_EQ(2, soundex[2]);
  EXPECT_EQ(2, soundex[3]);

}