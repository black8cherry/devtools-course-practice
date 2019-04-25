// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>

#include "include/bit_array.h"

TEST(BitArrayTest, Default_Constructor_Test) {
    // Arrange
    BitArray bit;

    // Act
    
    // Assert
    EXPECT_GT(bit.size(), 0);
}

TEST(BitArrayTest, Int_Constructor_Test) {
    // Arrange
    int bit_count = 256;

    // Act
    BitArray bit(bit_count);

    // Assert
    EXPECT_EQ(bit.size(), 256);
}

TEST(BitArrayTest, Cant_Create_Negative_Size_Array) {
    // Arrange
    int bit_count = -256;

    // Act

    // Assert
    EXPECT_ANY_THROW(BitArray bit(bit_count));
}

TEST(BitArrayTest, Copy_Constructor_Test) {
    // Arrange
    int bit_count = 512;
    BitArray bit(bit_count);
    int size_1 = 0;
    int size_2 = 0;

    // Act
    BitArray copy_bit(bit);
    size_1 = bit.size();
    size_2 = copy_bit.size();

    // Assert
    EXPECT_EQ(size_1, size_2);
}

TEST(BitArrayTest, Can_Print) {
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);
    std::string to_exp = "";
    int length;

    // Act
    to_exp = bit.print_string();
    length = to_exp.length();

    // Assert
    EXPECT_EQ(length, 8);
    EXPECT_EQ(to_exp, "00000000");
}

TEST(BitArrayTest, Can_Set_Value_True) {
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);
    std::string to_exp = "";
    int length;

    // Act
    bit.SetBit(0, true);
    bit.SetBit(2, true);
    to_exp = bit.print_string();
    length = to_exp.length();

    // Assert
    EXPECT_EQ(length, 8);
    EXPECT_EQ(to_exp, "10100000");
}




