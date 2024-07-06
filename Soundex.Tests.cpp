#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
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
