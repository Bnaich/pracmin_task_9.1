#include "gtest/gtest.h"
#include <set>

TEST(SetTets, size_test) {
    std::set<int> set {1,2,3,2};
    ASSERT_EQ(3, set.size());
    set.erase(2);
    ASSERT_EQ(2, set.size());
    set.erase(1);
    ASSERT_EQ(1, set.size());
    set.erase(3);
    ASSERT_TRUE(set.empty());
}

TEST(SetTets, contains_test) {
    std::set<int> set {1,2,3};
    ASSERT_FALSE(set.find(4) != set.end());
    set.erase(2);
    ASSERT_TRUE(set.find(1) != set.end());
    set.erase(1);
}

TEST(SetTets, mix_test) {
    std::set<int> set {};
    ASSERT_FALSE(!set.empty());
    ASSERT_TRUE(set.count(3) == 0);
    set.insert(3);
    ASSERT_TRUE(set.count(3) == 1);
    set.insert(3);
    set.insert(3);
    set.insert(3);
    ASSERT_TRUE(set.count(3) == 1);
    set.erase(3);
    ASSERT_TRUE(set.count(3) == 0);

    for (auto i = 0; i < 10; ++i)
        set.insert(i);
    ASSERT_TRUE(set.size() == 10);
    for (auto i = 0; i < 10; ++i)
        ASSERT_TRUE(set.count(i) == 1);
    set.clear();
    ASSERT_TRUE(set.empty());
}
