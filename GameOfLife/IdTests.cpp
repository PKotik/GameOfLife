#include "gtest/gtest.h"
#include "ObjectWithId.h"

TEST(ObjectWithIdTests, IdShouldBeSameForCloseCoordinates)
{
    ObjectWithId obj1(0.625f, 0.125f);
    ObjectWithId obj2(0.637f, 0.139f);
    ASSERT_EQ(obj1.Id(), obj2.Id());
}
