//
// Created by angelos on 14/12/2019.
//
#include "mode.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(mode_tests, one_mode) {
  int t[] = {1, 1, 2};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 1);
}

TEST(mode_tests, one_mode_noncontinuous) {
  int t[] = {1, 2, 1};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 1);
}

TEST(mode_tests, same_element) {
  int t[] = {1, 1, 1};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 1);
}

TEST(mode_tests, multiple_modes_continuous) {
  int t[] = {1, 1, 2, 2};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 0);
}

TEST(mode_tests, multiple_modes_noncontinuous) {
  int t[] = {1, 2, 1, 2};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 0);
}

TEST(mode_tests, all_different_elements) {
  int t[] = {1, 2, 3, 4};

  size_t length{sizeof(t) / sizeof(*t)};
  int res{mode(t, length)};

  EXPECT_EQ(res, 0);
}

TEST(mode_tests, zero_length) {
  int t[] = {1, 2, 3, 4};

  int res{mode(t, 0)};

  EXPECT_EQ(res, 0);
}

TEST(mode_tests, invalid_argument) {
  int t[]{};

  try {
    int res{mode(t, 10)};
  } catch (const std::invalid_argument &e) {
    EXPECT_EQ(std::string(e.what()), "Invalid input array");
  }
}