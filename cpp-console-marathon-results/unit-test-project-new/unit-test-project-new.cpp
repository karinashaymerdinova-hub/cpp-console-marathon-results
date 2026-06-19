#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/marathon.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:

        // Тест 1: один участник — его время и есть минимальное
        // Старт 8:00:00, финиш 10:30:00 → время забега = 2ч 30мин = 9000 сек
        TEST_METHOD(TestOneRecord)
        {
            MarathonRecord records[1];
            records[0].start = { 8, 0, 0 };
            records[0].finish = { 10, 30, 0 };

            int result = process(records, 1);
            Assert::AreEqual(9000, result);
        }

        // Тест 2: несколько участников, минимальное время у третьего
        // 1й: 8:00:00 -> 11:00:00 = 10800 сек (3ч)
        // 2й: 8:00:00 -> 10:50:00 = 10200 сек (2ч 50мин)
        // 3й: 8:00:00 -> 10:20:00 = 8400 сек  (2ч 20мин) ← минимум
        TEST_METHOD(TestMinIsThird)
        {
            MarathonRecord records[3];
            records[0].start = { 8,0,0 }; records[0].finish = { 11,0,0 };
            records[1].start = { 8,0,0 }; records[1].finish = { 10,50,0 };
            records[2].start = { 8,0,0 }; records[2].finish = { 10,20,0 };

            int result = process(records, 3);
            Assert::AreEqual(8400, result);
        }

        // Тест 3: участники стартуют в разное время
        // 1й: 8:05:00 -> 10:55:00 = 9000 сек (2ч 50мин)
        // 2й: 8:15:00 -> 11:20:00 = 11100 сек (3ч 5мин)
        // 3й: 8:00:00 -> 10:10:00 = 7800 сек  (2ч 10мин) ← минимум
        TEST_METHOD(TestDifferentStartTimes)
        {
            MarathonRecord records[3];
            records[0].start = { 8,5,0 };  records[0].finish = { 10,55,0 };
            records[1].start = { 8,15,0 }; records[1].finish = { 11,20,0 };
            records[2].start = { 8,0,0 };  records[2].finish = { 10,10,0 };

            int result = process(records, 3);
            Assert::AreEqual(7800, result);
        }

        // Тест 4: пустой массив — ожидаем -1
        TEST_METHOD(TestEmptyArray)
        {
            MarathonRecord records[1]; // формально нужен массив, но count = 0
            int result = process(records, 0);
            Assert::AreEqual(-1, result);
        }
    };
}