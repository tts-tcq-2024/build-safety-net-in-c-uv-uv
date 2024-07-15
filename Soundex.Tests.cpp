#include <gtest/gtest.h>
#include "Soundex.h"

void generateSoundex(const char *name, char *soundex);
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits)
{
 //AAA
 // to check positive case
  char soundex[5] = {};
  const char* name = "AXDL";
  generateSoundex(name, soundex);
  EXPECT_EQ('A', soundex[0]);
  EXPECT_EQ('2', soundex[1]);
  EXPECT_EQ('3', soundex[2]);
  EXPECT_EQ('4', soundex[3]);

}

TEST(SoudexTestsuite, case2)
{
 // to check positive case
  char soundex[5] = {};
  const char* name = "Robert";
  generateSoundex(name, soundex);
  EXPECT_EQ('R', soundex[0]);
  EXPECT_EQ('1', soundex[1]);
  EXPECT_EQ('6', soundex[2]);
  EXPECT_EQ('3', soundex[3]);
}

TEST(SoudexTestsuite, checktwovowel)
{
 // to check two vowel
  char soundex[5] = {};
  const char* name = "Tymczak";
  generateSoundex(name, soundex);
  EXPECT_EQ('T', soundex[0]);
  EXPECT_EQ('5', soundex[1]);
  EXPECT_EQ('2', soundex[2]);
  EXPECT_EQ('2', soundex[3]);
}

TEST(SoudexTestsuite, checkzeropadding)
{
 // to check zeropadding
  char soundex[5] = {};
  const char* name = "B";
  generateSoundex(name, soundex);
  EXPECT_EQ('B', soundex[0]);
  EXPECT_EQ('0', soundex[1]);
  EXPECT_EQ('0', soundex[2]);
  EXPECT_EQ('0', soundex[3]);
}

TEST(SoudexTestsuite, Secondsameasfirst)
{
 // to check padding if second letter same as first
  char soundex[5] = {};
  const char* name = "Pfister";
  generateSoundex(name, soundex);
  EXPECT_EQ('P', soundex[0]);
  EXPECT_EQ('2', soundex[1]);
  EXPECT_EQ('3', soundex[2]);
  EXPECT_EQ('6', soundex[3]);
}