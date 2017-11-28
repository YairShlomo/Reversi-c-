/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#ifndef UNTITLED_TEST_POINT_H
#define UNTITLED_TEST_POINT_H
#include <gtest/gtest.h>
#include "../include/Point.h"
#include <iostream>
using namespace std;
class test_Point: public testing::Test {
public:
    test_Point(): p1(1,2), p2(3,4) {}

protected:
    Point p1, p2;
};
#endif //UNTITLED_TEST_POINT_H
