#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"

namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
        this->logPass("Compiled.");
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
    }

    PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }
    //--------------------------------------------------------------------------------------------------two list
    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());
        addTest(new TestConstructPriorityQueueTwoLists());
        addTest(new TestCopyConstructorPriorityQueueTwoLists());
        addTest(new TestAssignPriorityQueueTwoLists());
        addTest(new TestSizePriorityQueueTwoLists());
    }

    TestConstructPriorityQueueTwoLists::TestConstructPriorityQueueTwoLists() 
        : SimpleTest("Test konstruktoru Two Lists")
    {
    }

    void TestConstructPriorityQueueTwoLists::test()
    {
        //push 10 prvkov, pridam este 2 (jeden na zaciatok a druhy na koniec)
        //pop prveho (100) pop do polovice velkosti (9,8,7,6)
        //pridanie prvu medzi 5 a 4 (150) 
        //pop 5 a 150
        //dopopovanie do konca

        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();

        for (int i = 0; i < 10; i++)
        {
            twoList1->push(22 - i * 2, i);
        }

        twoList1->push(1, 100);
        twoList1->push(24, 200);

        int popCislo = twoList1->pop();
        SimpleTest::assertTrue(popCislo == 100, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne 100");
        //SimpleTest::assertTrue(twoList1->size() == 11, "Size je 11");

        int velkostPredPop = twoList1->size();

        for (int i =  velkostPredPop - 2; i > velkostPredPop / 2; i--)
        {
            int popCislo = twoList1->pop();
            SimpleTest::assertTrue(popCislo == i, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne " + std::to_string(i));
        }

        twoList1->push(13, 150);

        popCislo = twoList1->pop();
        SimpleTest::assertTrue(popCislo == 5, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne 5");

        popCislo = twoList1->pop();
        SimpleTest::assertTrue(popCislo == 150, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne 150");

        velkostPredPop = twoList1->size();
        //SimpleTest::assertTrue(twoList1->size() == 6, "Size je 6");

        for (int i = velkostPredPop - 2; i >= 0; i--)
        {
            popCislo = twoList1->pop();
            SimpleTest::assertTrue(popCislo == i, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne " + std::to_string(i));
        }

        popCislo = twoList1->pop();
        SimpleTest::assertTrue(popCislo == 200, "Cislo popnute z listu je: " + std::to_string(popCislo) + " a je rovne 200");
        
        delete twoList1;
    }


    TestCopyConstructorPriorityQueueTwoLists::TestCopyConstructorPriorityQueueTwoLists()
        : SimpleTest("Test CopyKonstruktoru Two Lists")
    {

    }

    void TestCopyConstructorPriorityQueueTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();
        for (int i = 0; i < 10; i++)
        {
            twoList1->push(22 - i * 2, i);
        }

        structures::PriorityQueueTwoLists<int>* copyTwoList = new structures::PriorityQueueTwoLists<int>(*twoList1);

        int popCislo = 0;
        int popCisloCopy = 0;
        for (int i = 9; i >= 0; i--)
        {
            popCislo = twoList1->pop();
            popCisloCopy = copyTwoList->pop();

            SimpleTest::assertTrue(popCislo == popCisloCopy, "Cislo z povodneho " 
                + std::to_string(popCislo) + " sa rovna cislu z skopirovaneho " + std::to_string(popCisloCopy));
        }

        delete twoList1;
        delete copyTwoList;

    }

    TestAssignPriorityQueueTwoLists::TestAssignPriorityQueueTwoLists() :
        SimpleTest("Test assign Two Lists")
    {
    }

    void TestAssignPriorityQueueTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();
        structures::PriorityQueueTwoLists<int>* twoList2 = new structures::PriorityQueueTwoLists<int>(*twoList1);
        for (int i = 0; i < 7; i++) {
            twoList1->push(22 - i * 2, i);
            twoList2->push(22 - i, i + 10);
        }

        int velkost = twoList1->size();
        int popCislo1 = 0;
        int popCislo2 = 0;

        for (int i = 0; i < velkost - 1; i++)
        {
            popCislo1 = twoList1->pop();
            popCislo2 = twoList2->pop();

            SimpleTest::assertFalse(popCislo1 == popCislo2, "Cisla sa nerovnaju: " + std::to_string(popCislo1) + " != " + std::to_string(popCislo2));
        }

        for (int i = 0; i < 7; i++) {
            twoList1->push(22 - i * 2, i);
            twoList2->push(22 - i, i + 10);
        }

        twoList1->assign(*twoList2);

        for (int i = 0; i < 7; i++) {
            popCislo1 = twoList1->pop();
            popCislo2 = twoList2->pop();
            SimpleTest::assertTrue(popCislo1 == popCislo2, std::to_string(popCislo1) + " == " + std::to_string(popCislo2));
        }

        delete twoList1;
        delete twoList2;
    }

    TestSizePriorityQueueTwoLists::TestSizePriorityQueueTwoLists()
        : SimpleTest("Test size Two Lists")
    {
    }

    void TestSizePriorityQueueTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();
        structures::PriorityQueueTwoLists<int>* twoList2 = new structures::PriorityQueueTwoLists<int>(*twoList1);
        for (int i = 0; i < 7; i++) {
            twoList1->push(22 - i * 2, i);
        }

        for (int i = 0; i < 10; i++)
        {
            twoList2->push(22 - i, i + 10);
        }

        SimpleTest::assertTrue(twoList1->size() == 7, "Velkost je 7 (po vytvoreni a naplneni 7 prvkami)");
        SimpleTest::assertTrue(twoList2->size() == 10, "Velkost je 7 (po vytvoreni a naplneni 10 prvkami)");

        for (int i = 0; i < 3; i++)
        {
            twoList1->pop();
            twoList2->pop();
        }

        SimpleTest::assertTrue(twoList1->size() == (7 - 3), "Velkost je 4 (po odstraneni 3 prvkov)");
        SimpleTest::assertTrue(twoList2->size() == (10 - 3), "Velkost je 7 (po odstraneni 3 prvkov)");

        for (int i = 0; i < 10; i++)
        {
            twoList1->push(i + 10, i + 100);
            twoList2->push(i + 10, i + 100);
        }

        SimpleTest::assertTrue(twoList1->size() == (7 - 3 + 10), "Velkost je 14 (po pridani 10 prvkov)");
        SimpleTest::assertTrue(twoList2->size() == (10 - 3 + 10), "Velkost je 17 (po pridani 10 prvkov)");
    }

    //................................................................................................koniec two list

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
    }

    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        addTest(new PriorityQueueUnsortedArrayListTestOverall());
        addTest(new PriorityQueueSortedArrayListTestOverall());
        addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }
}