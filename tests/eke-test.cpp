
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

TEST(eke, can_be_called)
{
    char test_dummy[] = "DUMMY";
    
    CHECK_EQUAL(0, eke_sort(test_dummy));
}


TEST(eke, sorts_according_to_spec)
{

    char string_to_sort[] = "eke-elektroniikka";
    const char expected[] = "eeeertiioakkkln";

    eke_sort(string_to_sort);
    STRCMP_EQUAL(expected, string_to_sort);
}
