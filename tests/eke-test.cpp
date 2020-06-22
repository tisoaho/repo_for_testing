
extern "C" {
#include "eke.h"
}


#include "CppUTest/TestHarness.h"



TEST_GROUP(eke)
{
    void setup()
    { 
        
    }

    void teardown() {
        
    }
};



TEST(eke, sorts_according_to_spec)
{

    char string_to_sort[] = "eke-elektroniikka";
    const char expected[] = "eeeertiioakkkkln"; // REALLY! There is 4 k's!

    eke_sort(string_to_sort);
    STRCMP_EQUAL(expected, string_to_sort);
}

TEST(eke, consumes_non_alpha_characters)
{
    char string_to_sort[] = "4732568462-.'*eke-elektroniikka67146719647165-,.,.'";
    const char expected[] = "eeeertiioakkkkln";

    eke_sort(string_to_sort);
    STRCMP_EQUAL(expected, string_to_sort);
}

TEST(eke, operates_on_longer_input)
{
    char string_to_sort[] = "eke-elektroniikka3463274856754q761876547164752784567823465";

    CHECK_EQUAL(0, eke_sort(string_to_sort));
}

TEST(eke, copes_with_an_empty_string)
{
    char string_to_sort[] = "";

    CHECK_EQUAL(0, eke_sort(string_to_sort));
    
}

TEST(eke, returns_fail_with_null_string)
{
    CHECK_EQUAL(-1, eke_sort(NULL)); 
}
