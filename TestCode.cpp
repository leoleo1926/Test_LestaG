#include <gtest/gtest.h>
#include "FIFO.cpp"
#include "Functions.cpp"


// Тесты для CBVector
TEST(CBVectorTest, PushAndPop) {
    CBVector cb(5); 
    cb.push(1);
    cb.push(2);
    cb.push(3);

    ASSERT_FALSE(cb.isEmpty());
    ASSERT_TRUE(cb.isFull());

    EXPECT_EQ(cb.pop(), 1);
    EXPECT_EQ(cb.pop(), 2);
    EXPECT_EQ(cb.pop(), 3);

    ASSERT_TRUE(cb.isEmpty());
    ASSERT_FALSE(cb.isFull());
}

TEST(CBVectorTest, OverflowException) {
    CBVector cb(3); 

    cb.push(1);
    cb.push(2);
    cb.push(3);

    ASSERT_THROW(cb.push(4), std::overflow_error);
}

TEST(CBVectorTest, UnderflowException) {
    CBVector cb(3); 

    ASSERT_THROW(cb.pop(), std::underflow_error);
}

// Тесты для CBArray
TEST(CBArrayTest, PushAndPop) {
    CBArray cb(5); 

    cb.push(1);
    cb.push(2);
    cb.push(3);

    ASSERT_FALSE(cb.isEmpty());
    ASSERT_TRUE(cb.isFull());

    EXPECT_EQ(cb.pop(), 1);
    EXPECT_EQ(cb.pop(), 2);
    EXPECT_EQ(cb.pop(), 3);

    ASSERT_TRUE(cb.isEmpty());
    ASSERT_FALSE(cb.isFull());
}

TEST(CBArrayTest, OverflowException) {
    CBArray cb(3); 

    cb.push(1);
    cb.push(2);
    cb.push(3);

    ASSERT_THROW(cb.push(4), std::overflow_error);
}

TEST(CBArrayTest, UnderflowException) {
    CBArray cb(3);

    ASSERT_THROW(cb.pop(), std::underflow_error);
}
// Тестирование функции isEven
TEST(isEvenTest, HandlesEvenNumbers) {
    EXPECT_TRUE(isEven(2));
    EXPECT_TRUE(isEven(0));
    EXPECT_TRUE(isEven(-4));
}

TEST(isEvenTest, HandlesOddNumbers) {
    EXPECT_FALSE(isEven(1));
    EXPECT_FALSE(isEven(-3));
    EXPECT_FALSE(isEven(5));
}

// Тестирование функции Divide
TEST(DivideTest, HandlesBasicCases) {
    std::vector<int> arr = {4, 1, 8, 3, 2, 9};
    int result = Divide(arr, 0, arr.size() - 1);

    EXPECT_EQ(result, 3); // Ожидаем, что индекс опорного элемента равен 3

    // Проверяем, что элементы слева от опорного меньше него
    for (int i = 0; i < result; ++i) {
        EXPECT_LE(arr[i], arr[result]);
    }

    // Проверяем, что элементы справа от опорного больше него
    for (int i = result + 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[result]);
    }
}

// Тестирование функции QuickSort
TEST(QuickSortTest, HandlesBasicCases) {
    std::vector<int> arr = {4, 1, 8, 3, 2, 9};
    QuickSort(arr, 0, arr.size() - 1);

    // После сортировки элементы должны быть в порядке возрастания
    for (size_t i = 1; i < arr.size(); ++i) {
        EXPECT_LE(arr[i - 1], arr[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
