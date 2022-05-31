//
// Created by mulh8377 on 5/31/22.
//

#include "../src/linkedlist.h"

#include <gtest/gtest.h>

namespace test {
class LinkedListTest : public ::testing::Test {

};

TEST_F(LinkedListTest, LinkedListTesting) {
    EXPECT_EQ(1, 1);
}

int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
}