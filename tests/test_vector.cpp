#include <gtest/gtest.h>
#include "../lib_vector/vector.h"


TEST(TVectorTest, DefaultConstructorInt) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, DefaultConstructorString) {
    TVector<std::string> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, DefaultConstructorChar) {
    TVector<char> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, DefaultConstructorStruct) {
    struct Point { int x, y; };
    TVector<Point> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, SizedConstructorInt) {
    TVector<int> vec(5);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, SizedConstructorNull) {
    TVector<int> vec(0);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, SizedConstructorString) {
    TVector<std::string> vec(0);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, SizedConstructorChar) {
    TVector<char> vec(0);
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, SizedConstructorStruct) {
    struct Point { int x, y; };
    TVector<Point> vec(5);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, ArrayConstructor) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    for (int i = 0; i < vec.size(); i++) {
        EXPECT_EQ(vec[i], i + 1);
    }
    EXPECT_EQ(vec.size(), 10);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, ArrayConstructorNull) {
    TVector<int> vec({});
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, ArrayConstructorV2) {
    int mass[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    size_t n = 10;
    TVector<int> vec(mass, n);
    for (int i = 0; i < vec.size(); i++) {
        EXPECT_EQ(vec[i], i + 1);
    }
    EXPECT_EQ(vec.size(), 10);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, CopyConstructorInt) {
    TVector<int> original(10);
    TVector<int> copy(original);
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_EQ(original.capacity(), copy.capacity());
}

TEST(TVectorTest, CopyConstructorArray) {
    TVector<int> original({ 1, 2, 3, 4, 5 }, 5);
    TVector<int> copy(original);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(original[i], copy[i]);
    }
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_EQ(original.capacity(), copy.capacity());
}

TEST(TVectorTest, CopyNullConstructorArrayV2) {
    TVector<int> original({});
    TVector<int> copy(original);
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_EQ(original.capacity(), copy.capacity());
}

TEST(TVectorTest, Reserve) {
    TVector<int> vec;
    vec.reserve(75);
    EXPECT_EQ(vec.capacity(), 75);
}

TEST(TVectorTest, ReserveNewLessOld) {
    TVector<int> vec;
    vec.reserve(10);
    EXPECT_EQ(vec.capacity(), 15);
}

TEST(TVectorTest, ReserveInt) {
    TVector<int> vec(16);
    vec.reserve(50);
    EXPECT_EQ(vec.capacity(), 60);
}

TEST(TVectorTest, ReserveNewLessOldInt) {
    TVector<int> vec(16);
    vec.reserve(20);
    EXPECT_EQ(vec.capacity(), 30);
}

TEST(TVectorTest, ReserveMass) {
    TVector<int> vec({ 1, 2, 3 }, 3);
    vec.reserve(50);
    EXPECT_EQ(vec.capacity(), 60);
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, ReserveMassV2) {
    int mass[3] = { 1, 2, 3 };
    TVector<int> vec(mass, 3);
    vec.reserve(50);
    EXPECT_EQ(vec.capacity(), 60);
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, ReserveString) {
    TVector<std::string> vec;
    vec.reserve(50);
    EXPECT_EQ(vec.capacity(), 60);
}

TEST(TVectorTest, ResizeIntUpper) {
    TVector<int> vec(5);
    vec.resize(50, 1);
    EXPECT_EQ(vec.capacity(), 60);
    EXPECT_EQ(vec.size(), 50);
}

TEST(TVectorTest, ResizeIntLower) {
    TVector<int> vec(50);
    vec.resize(5);
    EXPECT_EQ(vec.capacity(), 60);
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, ResizeMassUpper) {
    TVector<int> vec({ 1, 2, 3 }, 3);
    vec.resize(16, 9);
    for (int i = 3; i < 16; ++i) {
        EXPECT_EQ(vec[i], 9);
    }
    EXPECT_EQ(vec.capacity(), 30);
    EXPECT_EQ(vec.size(), 16);
}

TEST(TVectorTest, ResizeMassLower) {
    int mass[50];
    TVector<int> vec(mass, 50);
    vec.resize(14);
    EXPECT_EQ(vec.capacity(), 60);
    EXPECT_EQ(vec.size(), 14);
}

TEST(TVectorTest, ShrinkToFitInt) {
    TVector<int> vec(14);
    vec.reserve(100);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 15);
    EXPECT_EQ(vec.size(), 14);
}

TEST(TVectorTest, ShrinkToFitMass) {
    int mass[16];
    TVector<int> vec(mass, 16);
    vec.reserve(100);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 30);
    EXPECT_EQ(vec.size(), 16);
}

TEST(TVectorTest, Emplace) {
    TVector<int> vec({ 1, 5, 9, 4, 6, 8 }, 6);
    vec.emplace(4, 2);
    EXPECT_EQ(vec[4], 2);
}

TEST(TVectorTest, ThrowWhenEmplaceInvalidPos) {
    TVector<int> vec({ 1, 5, 9, 4, 6, 8 }, 6);
    EXPECT_THROW(vec.emplace(10, 2), std::exception);
}

TEST(TVectorTest, Assign) {
    int mass[5] = { 4, 9, 1, 7, 5 };
    TVector<int> vec;
    vec.assign(mass, 3);
    EXPECT_EQ(vec[0], 4);
    EXPECT_EQ(vec[1], 9);
    EXPECT_EQ(vec[2], 1);
}

TEST(TVectorTest, ClearMass) {
    int mass[5] = { 4, 9, 1, 7, 5 };
    TVector<int> vec(mass, 5);
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVectorTest, PushBackInt) {
    TVector<int> vec(5);
    vec.push_back(111);
    vec.push_back(99);
    vec.push_back(1);
    EXPECT_EQ(vec[5], 111);
    EXPECT_EQ(vec[6], 99);
    EXPECT_EQ(vec[7], 1);
}

TEST(TVectorTest, PushBackChar) {
    TVector<char> vec;
    vec.push_back('5');
    vec.push_back('h');
    vec.push_back('#');
    EXPECT_EQ(vec[0], '5');
    EXPECT_EQ(vec[1], 'h');
    EXPECT_EQ(vec[2], '#');
}

TEST(TVectorTest, PushBackString) {
    TVector<std::string> vec;
    vec.push_back("Hello");
    vec.push_back("there");
    vec.push_back("guys");
    EXPECT_EQ(vec[0], "Hello");
    EXPECT_EQ(vec[1], "there");
    EXPECT_EQ(vec[2], "guys");
}

TEST(TVectorTest, PushBackMass) {
    TVector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    EXPECT_EQ(vec.size(), 10);
    EXPECT_EQ(vec[7], 7);
}

TEST(TVectorTest, PushFrontInt) {
    TVector<int> vec(5);
    vec.push_front(111);
    vec.push_front(99);
    vec.push_front(1);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 99);
    EXPECT_EQ(vec[2], 111);
}

TEST(TVectorTest, PushFrontChar) {
    TVector<char> vec;
    vec.push_front('5');
    vec.push_front('h');
    vec.push_front('#');
    EXPECT_EQ(vec[0], '#');
    EXPECT_EQ(vec[1], 'h');
    EXPECT_EQ(vec[2], '5');
}

TEST(TVectorTest, PushFrontString) {
    TVector<std::string> vec;
    vec.push_front("yo");
    vec.push_front("hi");
    vec.push_front("wassup");
    EXPECT_EQ(vec[0], "wassup");
    EXPECT_EQ(vec[1], "hi");
    EXPECT_EQ(vec[2], "yo");
}

TEST(TVectorTest, PushFrontMass) {
    TVector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_front(i);
    }
    EXPECT_EQ(vec.size(), 10);
    EXPECT_EQ(vec[9], 0);
    EXPECT_EQ(vec[4], 5);
}

TEST(TVectorTest, InsertInt) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.insert(2, 499);
    EXPECT_EQ(vec[2], 499);
    EXPECT_EQ(vec[3], 9);
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertIntIt) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.insert(vec.begin() + 2, 499);
    EXPECT_EQ(vec[2], 499);
    EXPECT_EQ(vec[3], 9);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertChar) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.insert(2, '4');
    EXPECT_EQ(vec[2], '4');
    EXPECT_EQ(vec[3], '9');
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertCharIt) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.insert(vec.begin(), '4');
    EXPECT_EQ(vec[0], '4');
    EXPECT_EQ(vec[3], '9');
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertString) {
    TVector<std::string> vec({ "yo", "gg", "hi", "qwerty" }, 4);
    vec.insert(2, "boo");
    EXPECT_EQ(vec[2], "boo");
    EXPECT_EQ(vec[3], "hi");
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertStringIt) {
    TVector<std::string> vec({ "yo", "gg", "hi", "qwerty" }, 4);
    vec.insert(vec.begin(), "boo");
    EXPECT_EQ(vec[0], "boo");
    EXPECT_EQ(vec[3], "hi");
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertIntItCount) {
    TVector<int> vec({ 1, 5, 9, 3, 8, 2, 7, 25, 900, 33, 0 }, 11);
    vec.insert(vec.begin() + 2, 3, 499);
    EXPECT_EQ(vec[2], 499);
    EXPECT_EQ(vec[3], 499);
    EXPECT_EQ(vec[4], 499);
    EXPECT_EQ(vec.size(), 14);
    EXPECT_EQ(vec[5], 9);
    EXPECT_EQ(vec[1], 5);
}

TEST(TVectorTest, InsertCharItCount) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.insert(vec.begin(), 3, '4');
    EXPECT_EQ(vec[0], '4');
    EXPECT_EQ(vec[1], '4');
    EXPECT_EQ(vec[2], '4');
    EXPECT_EQ(vec.size(), 7);
}

TEST(TVectorTest, InsertStringItCount) {
    TVector<std::string> vec({ "yo", "gg", "hi", "qwerty" }, 4);
    vec.insert(vec.begin() + 1, 3, "boo");
    EXPECT_EQ(vec[1], "boo");
    EXPECT_EQ(vec[2], "boo");
    EXPECT_EQ(vec[3], "boo");
    EXPECT_EQ(vec[5], "hi");
    EXPECT_EQ(vec.size(), 7);
}

TEST(TVectorTest, EraseInt) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.erase(2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseIntIt) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.erase(vec.begin());
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec[1], 9);
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseChar) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.erase(2);
    EXPECT_EQ(vec[2], '3');
    EXPECT_EQ(vec[1], '5');
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseCharIt) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.erase(vec.begin());
    EXPECT_EQ(vec[0], '5');
    EXPECT_EQ(vec[1], '9');
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseString) {
    TVector<std::string> vec({ "yo", "gg", "hi", "qwerty" }, 4);
    vec.erase(2);
    EXPECT_EQ(vec[2], "qwerty");
    EXPECT_EQ(vec[1], "gg");
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseStringIt) {
    TVector<std::string> vec({ "yo", "gg", "hi", "qwerty" }, 4);
    vec.erase(vec.begin());
    EXPECT_EQ(vec[0], "gg");
    EXPECT_EQ(vec[2], "qwerty");
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, EraseIntItCount) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.erase(vec.begin(), 3);
    EXPECT_EQ(vec[0], 3);
    EXPECT_EQ(vec.size(), 1);
}

TEST(TVectorTest, EraseCharItCount) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.erase(vec.begin(), 3);
    EXPECT_EQ(vec[0], '3');
    EXPECT_EQ(vec.size(), 1);
}

TEST(TVectorTest, EraseIntItRange) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.erase(vec.begin(), vec.end());
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVectorTest, EraseCharItRange) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.erase(vec.begin(), vec.end());
    EXPECT_EQ(vec.size(), 0);
}

TEST(TVectorTest, PopBackInt) {
    TVector<int> vec({ 1, 5, 9, 3 }, 4);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, PopBackChar) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, PopBackString) {
    TVector<std::string> vec({ "1", "5", "9", "3" }, 4);
    vec.pop_back();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, PopFrontChar) {
    TVector<char> vec({ '1', '5', '9', '3' }, 4);
    vec.pop_front();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, PopFrontInt) {
    int mass[4] = { 1, 5, 9, 3 };
    TVector<int> vec(mass, 4);
    vec.pop_front();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, PopFrontString) {
    TVector<std::string> vec({ "1", "5", "9", "3" }, 4);
    vec.pop_front();
    EXPECT_EQ(vec.size(), 3);
}

TEST(TVectorTest, DataForVectorWithElem1) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    const int* a = vec.data();
    EXPECT_NE(a, nullptr);
}

TEST(TVectorTest, DataForVectorWithElem2) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    const int* a = vec.data();
    EXPECT_EQ(1, *a);
    EXPECT_EQ(2, a[1]);
    EXPECT_EQ(10, a[9]);
}

TEST(TVectorTest, DataForVectorWithElem3) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    const int* a = vec.data();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    const int* b = vec.data();
    EXPECT_NE(b, nullptr);
    EXPECT_EQ(b[10], 1);
}


TEST(TVectorTest, BackForVectorWithElemV1) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    int a = vec.back();
    EXPECT_EQ(a, 10);
}

TEST(TVectorTest, BackForVectorWithElem) {
    TVector<int> vec({ 333 });
    int last_value = vec.back();
    EXPECT_EQ(last_value, 333);
}

TEST(TVectorTest, BackForVectorWithElemV2) {
    TVector<int> vec({ 1 });
    vec.back() = 4;
    EXPECT_EQ(vec.back(), 4);
}

TEST(TVectorTest, BackForVectorWithElemV3) {
    TVector<int> vec({ 1 });
    vec.push_back(5);
    EXPECT_EQ(vec.back(), 5);
}

TEST(TVectorTest, BackForVectorWithElemV4) {
    TVector<int> vec({ 1, 2, 3 }, 3);
    vec.pop_back();
    EXPECT_EQ(vec.back(), 2);
}

TEST(TVectorTest, FrontForEmptyVector) {
    TVector<int> vec;
    EXPECT_THROW(auto a = vec.front(), std::exception);
}

TEST(TVectorTest, FrontForVectorWithElemV1) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10);
    int a = vec.front();
    EXPECT_EQ(a, 1);
}

TEST(TVectorTest, FrontForVectorWithElem) {
    TVector<int> vec({ 333 });
    int first_value = vec.front();
    EXPECT_EQ(first_value, 333);
}

TEST(TVectorTest, FrontForVectorWithElemV2) {
    TVector<int> vec({ 1 });
    vec.front() = 4;
    EXPECT_EQ(vec.back(), 4);
}

TEST(TVectorTest, FrontForVectorWithElemV3) {
    TVector<int> vec({ 1 });
    vec.push_back(5);
    EXPECT_EQ(vec.back(), 5);
}

TEST(TVectorTest, FrontForVectorWithElemV4) {
    TVector<int> vec({ 1, 2, 3 }, 3);
    vec.pop_front();
    EXPECT_EQ(vec.front(), 2);
}

TEST(TVectorTest, At) {
    TVector<int> vec({ 10, 20, 30, 40, 50 }, 5);
    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.at(2), 30);
    EXPECT_EQ(vec.at(4), 50);
    vec.at(1) = 25;
    EXPECT_EQ(vec.at(1), 25);
}

TEST(TVectorTest, AtThrowWhenOutOfRange) {
    TVector<std::string> vec({ "a", "b", "c" }, 3);
    EXPECT_THROW(vec.at(3), std::out_of_range);
}

TEST(TVectorTest, AtThrowWhenMinusOne) {
    TVector<std::string> vec({ "a", "b", "c" }, 3);
    EXPECT_THROW(vec.at(-1), std::out_of_range);
}

TEST(TVectorTest, IsFull) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, 15);
    EXPECT_TRUE(vec.is_full());
}

TEST(TVectorTest, IsNotFull) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    vec.pop_back();
    EXPECT_FALSE(vec.is_full());
}

TEST(TVectorTest, IsEmpty) {
    TVector<int> vec;
    EXPECT_TRUE(vec.is_empty());
}

TEST(TVectorTest, IsNotEmpty) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    vec.pop_back();
    EXPECT_FALSE(vec.is_empty());
}

TEST(TVectorTest, BeginOneElem) {
    TVector<int> vec({ 7 });
    EXPECT_EQ(*vec.begin(), 7);
    EXPECT_EQ(vec.begin() + 1, vec.end());
}

TEST(TVectorTest, BeginErase) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    vec.erase(vec.begin(), 2);
    EXPECT_EQ(*vec.begin(), 3);
}

TEST(TVectorTest, BeginMass) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    for (int i = 0; i < vec.size(); i++) {
        EXPECT_EQ(*(vec.begin() + i), vec[i]);
    }
}

TEST(TVectorTest, End) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(vec.begin() + 2);

    auto end_it = vec.end();
    int count = 0;
    for (auto it = vec.begin(); it != end_it; ++it) {
        ++count;
    }
    EXPECT_EQ(count, 2);
}

TEST(TVectorTest, End2) {
    TVector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i * 10);
    }

    int sum = 0;
    auto end_it = vec.end();
    for (auto it = vec.begin(); it != end_it; ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 100);
}

TEST(TVectorTest, Shuffle) {
    TVector<int> vec({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    fisher_yates_shuffle(vec);
    bool all_same = true;
    int original[] = { 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < 7; i++) {
        if (vec[i] != original[i]) {
            all_same = false;
            break;
        }
    }
    EXPECT_FALSE(all_same);
}

TEST(TVectorTest, FindFirst) {
    TVector<int> vec({ 1, 2, 3, 3, 5, 6, 7 }, 7);
    int a = find_first(vec, 3);
    EXPECT_EQ(a, 2);
}

TEST(TVectorTest, FindLast) {
    TVector<int> vec({ 1, 2, 3, 3, 5, 6, 7 }, 7);
    int a = find_last(vec, 3);
    EXPECT_EQ(a, 3);
}

TEST(TVectorTest, FindAll) {
    TVector<int> vec({ 1, 2, 2, 4, 5, 6, 7 }, 7);
    int* a = find_all(vec, 2);
    EXPECT_NE(a, nullptr);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
}

TEST(TVectorTest, ThrowWhenPopBackNullArray) {
    TVector<int> vec;
    EXPECT_THROW(vec.pop_back(), std::exception);
}

TEST(TVectorTest, ThrowWhenPopFrontNullArray) {
    TVector<int> vec;
    EXPECT_THROW(vec.pop_front(), std::exception);
}

TEST(TVectorTest, ThrowWhenEraseNullArray) {
    TVector<int> vec;
    EXPECT_THROW(vec.erase(2), std::exception);
}

TEST(TVectorTest, PushFrontAfterPopFront) {
    TVector<int> vec(5);
    vec.pop_front();
    vec.push_front(99);
    EXPECT_EQ(vec[0], 99);
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, InsertDeleted) {
    int mass[5] = { 9, 777, 15, 38, 4 };
    TVector<int> vec(mass, 5);
    vec.erase(1);
    vec.insert(1, 99);
    EXPECT_EQ(vec[1], 99);
    EXPECT_EQ(vec.size(), 5);
}

TEST(TVectorTest, ResizeDeleted) {
    TVector<int> vec;
    vec.resize(50, 0);
    vec.erase(1);
    vec.erase(3);
    vec.resize(3);
    EXPECT_EQ(vec[0], 0);
    EXPECT_EQ(vec[1], 0);
    EXPECT_EQ(vec[2], 0);
    EXPECT_EQ(vec.size(), 3);
}
