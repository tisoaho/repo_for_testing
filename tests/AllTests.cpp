// Top level file for unit testing: runs all the test files using CppUTest test runner.
// Copyright (C) Tero Isoaho 22.6.2020 

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestPlugin.h"
#include "CppUTest/TestRegistry.h"


int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
