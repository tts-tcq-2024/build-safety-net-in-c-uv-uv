#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  // to check positive case
  ASSERT_EQ("A234",(generateSoundex("AXDL", soundex)));
}
