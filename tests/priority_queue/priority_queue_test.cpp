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
        addTest(new TestPushPriorityQueueTwoLists());
        addTest(new TestPopPriorityQueeuTwoLists());
        addTest(new TestPeekPriorityQueueTwoLists());
        addTest(new TestPeekPriorityPriorityQueueTwoLists());
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

        delete twoList1;
        delete twoList2;
    }


    TestPushPriorityQueueTwoLists::TestPushPriorityQueueTwoLists()
        : SimpleTest("Test Push Two Lists")
    {
    }

    void TestPushPriorityQueueTwoLists::test()
    {

        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();

      
        twoList1->push(22, 1500);
        SimpleTest::assertTrue(twoList1->pop() == 1500, "Vlozila sa hodnota 1500 s prioritou 22");

        for (int i = 0; i < 20; i++)
        {
            twoList1->push(23 + i, i * i);
        }

        SimpleTest::assertTrue(twoList1->size() == 20, "velkost po 20tich pushoch je realne 20");

        delete twoList1;
    }


    TestPopPriorityQueeuTwoLists::TestPopPriorityQueeuTwoLists()
        : SimpleTest("Test Pop Two Lists")
    {
    }

    void TestPopPriorityQueeuTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();

        twoList1->push(22, 1500);
        SimpleTest::assertTrue(twoList1->pop() == 1500, "Vlozila sa hodnota 1500 s prioritou 22");

        for (int i = 0; i < 20; i++)
        {
            twoList1->push(23 - i, i * i);
        }

        int popPocitadlo = 0;
        int velkost = twoList1->size() - 1;

        for (int i = velkost; i >= 0; i--)
        {
            SimpleTest::assertTrue(twoList1->pop() == (i*i), "Hodnota popnuteho sa rovna ocakavanej hodnote");

            popPocitadlo++;
        }

        SimpleTest::assertTrue(popPocitadlo == 20, "Pop prebehol okcakavany pocet krat (20)");

        delete twoList1;
    }


    TestPeekPriorityQueueTwoLists::TestPeekPriorityQueueTwoLists()
        : SimpleTest("Test Peak Two Lists")
    {
    }

    void TestPeekPriorityQueueTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();

        for (int i = 0; i < 20; i++)
        {
            twoList1->push(23 - i, i * i);
        }

        SimpleTest::assertTrue(twoList1->peek() == (19*19), "Hodnota prvku s najvacsiou prioritou je 19^2");

        twoList1->push(1, 12345);

        SimpleTest::assertTrue(twoList1->peek() == 12345, "Hodnota prvku s najvacsiou prioritou je 12345");
        SimpleTest::assertFalse(twoList1->peek() == (19 * 19), "Hodnota prvku s najvacsiou prioritou nie je 19^2 (stara hodnota)");

        delete twoList1;
    }


    TestPeekPriorityPriorityQueueTwoLists::TestPeekPriorityPriorityQueueTwoLists()
        : SimpleTest("Test PeekPriority Two Lists")
    {
    }

    void TestPeekPriorityPriorityQueueTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>();

        for (int i = 0; i < 20; i++)
        {
            twoList1->push(23 - i, i * i);
        }

        SimpleTest::assertTrue(twoList1->peekPriority() == 4, "Najvacsia (najlepsia) priorita je 4");

        twoList1->push(1, 12345);

        SimpleTest::assertTrue(twoList1->peekPriority() == 1, "Najvacsia (najlepsia) priorita je 1");
        SimpleTest::assertFalse(twoList1->peekPriority() == 4, "Najvacsia (najlepsia) priorita nie je (stara hodnota)");

        delete twoList1;
    }

    //................................................................................................koniec two list

    //------------------------------------------------------------------------------------------------zaciatok heap

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
        addTest(new TestConstructHeap());
        addTest(new TestCopyConstructHeap());
        addTest(new TestAssingHeap());
        addTest(new TestPopHeap());
        addTest(new TestPushHeap());
    }


    TestConstructHeap::TestConstructHeap()
        : SimpleTest("Test konstruktoru Heap")
    {
    }

    void TestConstructHeap::test()
    {
        structures::Heap<int>* testHeap1 = new structures::Heap<int>();

        testHeap1->push(0, 'P');
        testHeap1->push(2, 'I');
        testHeap1->push(6, 'D');
        testHeap1->push(7, 'E');
        testHeap1->push(4, 'H');
        testHeap1->push(9, 'O');
        testHeap1->push(7, 'J');
        testHeap1->push(9, 'B');
        testHeap1->push(7, 'K');
        testHeap1->push(6, 'U');
        testHeap1->push(6, 'X');
        testHeap1->push(9, 'A');

        SimpleTest::assertTrue(testHeap1->pop() == 'P', "hodnota bola P");
        SimpleTest::assertTrue(testHeap1->pop() == 'I', "hodnota bola I");
        SimpleTest::assertTrue(testHeap1->pop() == 'H', "hodnota bola H");
        SimpleTest::assertTrue(testHeap1->pop() == 'D', "hodnota bola D (priorita 6 sa nachadza v heape viac krat ale toto bolo vlozene najskor)");

        testHeap1->push(1, 'Z');

        SimpleTest::assertTrue(testHeap1->pop() == 'Z', "hodnota bola Z (po pridani prvku s najnizsou prioritou)");

        delete testHeap1;
    }


    TestCopyConstructHeap::TestCopyConstructHeap()
        : SimpleTest("Test CopyConstructor Heap")
    {
    }

    void TestCopyConstructHeap::test()
    {
        structures::Heap<int>* testHeap1 = new structures::Heap<int>();

        testHeap1->push(0, 'P');
        testHeap1->push(2, 'I');
        testHeap1->push(6, 'D');
        testHeap1->push(7, 'E');
        testHeap1->push(4, 'H');
        testHeap1->push(9, 'O');
        testHeap1->push(7, 'J');
        testHeap1->push(9, 'B');
        testHeap1->push(7, 'K');
        testHeap1->push(6, 'U');
        testHeap1->push(6, 'X');
        testHeap1->push(9, 'A');

        structures::Heap<int>* testHeap2 = new structures::Heap<int>(*testHeap1);

        SimpleTest::assertTrue(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa rovnaju (0,P)");
        SimpleTest::assertTrue(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa rovnaju (2,I)");

        testHeap2->push(1, 'Z');

        SimpleTest::assertFalse(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa nerovnaju (4,H) != (1,Z)");

        delete testHeap1;
        delete testHeap2;
    }

    TestAssingHeap::TestAssingHeap()
        : SimpleTest("Test Assign Heap")
    {
    }

    void TestAssingHeap::test()
    {
        structures::Heap<int>* testHeap1 = new structures::Heap<int>();

        testHeap1->push(0, 'P');
        testHeap1->push(2, 'I');
        testHeap1->push(6, 'D');
        testHeap1->push(7, 'E');
        testHeap1->push(4, 'H');
        testHeap1->push(9, 'O');
        testHeap1->push(7, 'J');
        testHeap1->push(9, 'B');
        testHeap1->push(7, 'K');
        testHeap1->push(6, 'U');
        testHeap1->push(6, 'X');
        testHeap1->push(9, 'A');

        structures::Heap<int>* testHeap2 = new structures::Heap<int>();

        testHeap2->assign(*testHeap1);

        SimpleTest::assertTrue(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa rovnaju (0,P)");
        SimpleTest::assertTrue(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa rovnaju (2,I)");

        testHeap2->push(1, 'Z');

        SimpleTest::assertFalse(testHeap1->pop() == testHeap2->pop(), "Hodnoty sa nerovnaju (4,H) != (1,Z)");

        delete testHeap1;
        delete testHeap2;
    }


    TestPopHeap::TestPopHeap()
        : SimpleTest("Test Pop Heap")
    {
    }

    void TestPopHeap::test()
    {
        structures::Heap<int>* testHeap1 = new structures::Heap<int>();

        testHeap1->push(0, 'P');
        testHeap1->push(2, 'I');
        testHeap1->push(6, 'D');
        testHeap1->push(7, 'E');
        testHeap1->push(4, 'H');
        testHeap1->push(9, 'O');
        testHeap1->push(7, 'J');
        testHeap1->push(9, 'B');
        testHeap1->push(7, 'K');
        testHeap1->push(6, 'U');
        testHeap1->push(6, 'X');
        testHeap1->push(9, 'A');

        SimpleTest::assertTrue(testHeap1->pop() == 'P', "hodnota bola P");
        SimpleTest::assertTrue(testHeap1->pop() == 'I', "hodnota bola I");
        SimpleTest::assertTrue(testHeap1->pop() == 'H', "hodnota bola H");
        SimpleTest::assertTrue(testHeap1->pop() == 'D', "hodnota bola D (priorita 6 sa nachadza v heape viac krat ale toto bolo vlozene najskor)");

        testHeap1->push(1, 'Z');
        testHeap1->push(1, 'X');

        SimpleTest::assertTrue(testHeap1->pop() == 'Z', "hodnota bola Z (po pridani prvku s prioritou 1 ako prveho)");
        SimpleTest::assertTrue(testHeap1->pop() == 'X', "hodnota bola X (po pridani prvku s prioritou 1 ako druheho)");

        delete testHeap1;
    }


    TestPushHeap::TestPushHeap()
        : SimpleTest("Test Push Heap")
    {
    }

    void TestPushHeap::test()
    {
        structures::Heap<int>* testHeap1 = new structures::Heap<int>();

        testHeap1->push(0, 'P');
        testHeap1->push(2, 'I');
        testHeap1->push(6, 'D');
        testHeap1->push(7, 'E');
        testHeap1->push(4, 'H');
        testHeap1->push(9, 'O');
        testHeap1->push(7, 'J');
        testHeap1->push(9, 'B');
        testHeap1->push(7, 'K');
        testHeap1->push(6, 'U');
        testHeap1->push(6, 'X');
        testHeap1->push(9, 'A');

        SimpleTest::assertTrue(testHeap1->pop() == 'P', "hodnota bola P");
        SimpleTest::assertTrue(testHeap1->pop() == 'I', "hodnota bola I");
        SimpleTest::assertTrue(testHeap1->pop() == 'H', "hodnota bola H");

        testHeap1->push(1, 'Z');
        testHeap1->push(2, 'X');
        testHeap1->push(3, 'Y');

        SimpleTest::assertTrue(testHeap1->pop() == 'Z', "hodnota bola Z");
        SimpleTest::assertTrue(testHeap1->pop() == 'X', "hodnota bola X");
        SimpleTest::assertTrue(testHeap1->pop() == 'Y', "hodnota bola Y");

        delete testHeap1;
    }

    //................................................................................................koniec heap

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