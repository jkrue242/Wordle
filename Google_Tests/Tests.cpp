//
// Created by Joseph Krueger on 9/26/22.
//

#include <gtest/gtest.h>
#include "Wordle.cpp"
#include <fstream>

//===============================================================
TEST(ConstructorTest, TestPath)
{
    Wordle TestWordle("test");
    ASSERT_EQ(TestWordle.getWordListFilename(), "test");
}

//===============================================================
TEST(ConstructorTest, TestNoPath)
{
    Wordle TestWordle("");
    ASSERT_EQ(TestWordle.getWordListFilename(), "");
}

//===============================================================
TEST(SetterTest, TestPath)
{
    Wordle TestWordle("");
    TestWordle.setWordListFilename("test");
    ASSERT_EQ(TestWordle.getWordListFilename(), "test");
}

//===============================================================
TEST(LoadWordListTest, LoadTestList)
{
    std::vector<std::string> testVector(20);
    std::ifstream fin("testWords.txt");
    int count = 0;
    while(!fin.eof()){
        getline(fin, testVector[count]);
        count++;
    }
    Wordle TestWordle("testWords.txt");
    TestWordle.loadWordList();
    ASSERT_EQ(TestWordle.wordList, testVector);
}

//===============================================================
TEST(LoadWordListTest, LoadEmptyWordList)
{
    std::vector<std::string> testVector(20);
    std::ifstream fin("testWords.txt");
    int count = 0;
    while(!fin.eof()){
        getline(fin, testVector[count]);
        count++;
    }
    Wordle TestWordle("testWords.txt");
    TestWordle.loadWordList();
    ASSERT_EQ(TestWordle.wordList, testVector);
}

//===============================================================
TEST(SecretWordTest, SetValidWord)
{
    Wordle TestWordle("testWords.txt");
    TestWordle.loadWordList();
    TestWordle.setSecretWord("karma");
    ASSERT_EQ(TestWordle.getSecretWord(), "karma");
}

//===============================================================
TEST(SecretWordTest, SetEmptyStringAsSecret)
{
    Wordle TestWordle("testWords.txt");
    TestWordle.loadWordList();
    TestWordle.setSecretWord("");
    ASSERT_EQ(TestWordle.getSecretWord(), "");
}
//===============================================================
int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}