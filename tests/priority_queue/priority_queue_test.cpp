#include "priority_queue_test.h"
#include <ctime>
#include <cstdlib>
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

    //.............................................................................................PQUAL zaciatok
    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
        addTest(new PriorityQueueUnsortedArrayListConstructorTest());
        addTest(new PriorityQueueUnsortedArrayListCopyConstructorTest());
    }


    PriorityQueueUnsortedArrayListConstructorTest::PriorityQueueUnsortedArrayListConstructorTest()
        : SimpleTest("Test konstruktora PQUAL")
    {
    }

    void PriorityQueueUnsortedArrayListConstructorTest::test()
    {
        //srand(time(NULL));
        int priorita = 0;

        structures::PriorityQueueUnsortedArrayList<int>* PQUALtest = new structures::PriorityQueueUnsortedArrayList<int>();

        for (int i = 0; i < 8; i++)
        {
            priorita = rand() % 10;
            PQUALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        SimpleTest::assertTrue(PQUALtest->size() == 8, "Velkost je skutocne 8");

        while (PQUALtest->size() != 0)
        {
            int popnuty = PQUALtest->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQUALtest;
    }

    PriorityQueueUnsortedArrayListCopyConstructorTest::PriorityQueueUnsortedArrayListCopyConstructorTest()
        : SimpleTest("Test copy constructor")
    {
    }

    void PriorityQueueUnsortedArrayListCopyConstructorTest::test()
    {
        structures::PriorityQueueUnsortedArrayList<int>* PQUALtest = new structures::PriorityQueueUnsortedArrayList<int>();

        int priorita = 0;

        for (int i = 0; i < 8; i++)
        {
            priorita = rand() % 10;
            PQUALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        SimpleTest::assertTrue(PQUALtest->size() == 8, "Velkost je skutocne 8");

        structures::PriorityQueueUnsortedArrayList<int>* PQUALtest2 = new structures::PriorityQueueUnsortedArrayList<int>(*PQUALtest);

        SimpleTest::assertTrue(true, "Prebehlo priradenie 1->2");

        delete PQUALtest;

        SimpleTest::assertTrue(true, "Prebehlo odstranenie 1.");

        SimpleTest::assertTrue(PQUALtest2->size() == 8, "Velkost je skutocne 8");

        while (PQUALtest2->size() != 0)
        {
            int popnuty = PQUALtest2->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQUALtest2;
    }
    //---------------------------------------------------------------------------------------------PQUAL koniec

    //.............................................................................................PQSAL zaciatok
    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
        addTest(new PriorityQueueSortedArrayListConstructorTest());
        addTest(new PriorityQueueSortedArrayListCopyConstructorTest());
    }

    PriorityQueueSortedArrayListConstructorTest::PriorityQueueSortedArrayListConstructorTest()
        : SimpleTest("Test Constructor")
    {
    }

    void PriorityQueueSortedArrayListConstructorTest::test()
    {
        structures::PriorityQueueSortedArrayList<int>* PQSALtest = new structures::PriorityQueueSortedArrayList<int>();

        int priorita = 0;

        for (int i = 0; i < 8; i++)
        {
            priorita = rand() % 10;
            PQSALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        PQSALtest->push(-1, 10);
        PQSALtest->push(2, 11);
        PQSALtest->push(10, 12);

        int popnuty = 0;

        while (PQSALtest->size() != 0)
        {
            popnuty = PQSALtest->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQSALtest;
    }

    PriorityQueueSortedArrayListCopyConstructorTest::PriorityQueueSortedArrayListCopyConstructorTest()
        : SimpleTest("Test Copy Constructor")
    {
    }

    void PriorityQueueSortedArrayListCopyConstructorTest::test()
    {
        structures::PriorityQueueSortedArrayList<int>* PQSALtest = new structures::PriorityQueueSortedArrayList<int>();

        int priorita = 0;

        for (int i = 0; i < 8; i++)
        {
            priorita = rand() % 10;
            PQSALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        SimpleTest::assertTrue(PQSALtest->size() == 8, "Velkost je skutocne 8");

        structures::PriorityQueueSortedArrayList<int>* PQSALtest2 = new structures::PriorityQueueSortedArrayList<int>(*PQSALtest);

        SimpleTest::assertTrue(true, "Prebehlo priradenie 1->2");

        delete PQSALtest;

        SimpleTest::assertTrue(true, "Prebehlo odstranenie 1.");

        SimpleTest::assertTrue(PQSALtest2->size() == 8, "Velkost je skutocne 8");

        while (PQSALtest2->size() != 0)
        {
            int popnuty = PQSALtest2->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQSALtest2;
    }

    //---------------------------------------------------------------------------------------------PQSAL koniec

    //.............................................................................................PQLSAL zaciatok

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
        addTest(new PriorityQueueLimitedSortedArrayListConstructorTest());
        addTest(new PriorityQueueLimitedSortedArrayListCopyConstructorTest());
    }


    PriorityQueueLimitedSortedArrayListConstructorTest::PriorityQueueLimitedSortedArrayListConstructorTest()
        : SimpleTest("Test constructor")
    {
    }

    void PriorityQueueLimitedSortedArrayListConstructorTest::test()
    {
        structures::PriorityQueueLimitedSortedArrayList<int>* PQLSALtest = new structures::PriorityQueueLimitedSortedArrayList<int>();
        structures::PriorityQueueLimitedSortedArrayList<int>* PQLSALtest2 = new structures::PriorityQueueLimitedSortedArrayList<int>(7);

        int priorita = 0;

        for (int i = 0; i < 4; i++)
        {
            priorita = rand() % 10;
            PQLSALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        for (int i = 0; i < 7; i++)
        {
            priorita = rand() % 10;
            PQLSALtest2->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        int popnuty = 0;

        while (PQLSALtest->size() != 0)
        {
            popnuty = PQLSALtest->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        while (PQLSALtest2->size() != 0)
        {
            popnuty = PQLSALtest2->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQLSALtest2;
        delete PQLSALtest;
    }

    PriorityQueueLimitedSortedArrayListCopyConstructorTest::PriorityQueueLimitedSortedArrayListCopyConstructorTest()
        : SimpleTest("Test Copy constructor")
    {
    }

    void PriorityQueueLimitedSortedArrayListCopyConstructorTest::test()
    {
        structures::PriorityQueueLimitedSortedArrayList<int>* PQLSALtest = new structures::PriorityQueueLimitedSortedArrayList<int>();

        int priorita = 0;

        for (int i = 0; i < 4; i++)
        {
            priorita = rand() % 10;
            PQLSALtest->push(priorita, i);
            SimpleTest::assertTrue(true, "Push prvku: " + std::to_string(i) + " s prioritou: " + std::to_string(priorita));
        }

        SimpleTest::assertTrue(PQLSALtest->size() == 4, "Velkost je skutocne 4");

        structures::PriorityQueueLimitedSortedArrayList<int>* PQLSALtest2 = new structures::PriorityQueueLimitedSortedArrayList<int>(*PQLSALtest);

        SimpleTest::assertTrue(true, "Prebehlo priradenie 1->2");

        delete PQLSALtest;

        SimpleTest::assertTrue(true, "Prebehlo odstranenie 1.");

        SimpleTest::assertTrue(PQLSALtest2->size() == 4, "Velkost je skutocne 4");

        while (PQLSALtest2->size() != 0)
        {
            int popnuty = PQLSALtest2->pop();
            SimpleTest::assertTrue(true, "pop prvku " + std::to_string(popnuty));
        }

        delete PQLSALtest2;
    }

    //---------------------------------------------------------------------------------------------PQLSAL koniec

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
        addTest(new ScenarTestTwoLists());
        addTest(new TimePQTLPush());
        addTest(new TimePQTLPop());
        addTest(new TimePQTLPeek());
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
        //SimpleTest::assertTrue(twoList1->size() == 0, "Velkost je 0");

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

    ScenarTestTwoLists::ScenarTestTwoLists()
        : SimpleTest("Scenarove testy pre Two Lists")
    {
    }

    void ScenarTestTwoLists::test()
    {
        structures::PriorityQueueTwoLists<int>* twoListsTest = new structures::PriorityQueueTwoLists<int>();

        srand(time(NULL));

        int pocitadloPush = 0;
        int pocitadloPop = 0;
        int pocitadloPeek = 0;
       
        /*int maxPush = 35000;
        int maxPop = 35000;
        int maxPeek = 30000;*/

        //int maxPush = 50000;
        //int maxPop = 30000;
        //int maxPeek = 20000;

        int maxPush = 70000;
        int maxPop = 25000;
        int maxPeek = 5000;

        int operacia = 0;
        int priorita = 0;
        int hodnota = 0;

        for (int i = 0; i < 100000; i++)
        {
            if (pocitadloPush < maxPush && pocitadloPop < maxPop && pocitadloPeek < maxPeek)
            {
                operacia = rand() % 3;
            } 
            else if (pocitadloPush == maxPush && pocitadloPop < maxPop && pocitadloPeek < maxPeek)
            {
                operacia = (rand() % 2) + 1;
            }
            else if (pocitadloPush < maxPush && pocitadloPop == maxPop && pocitadloPeek < maxPeek)
            {
                operacia = rand() % 2;
                if (operacia == 1)
                {
                    operacia = 2;
                }
            }
            else if (pocitadloPush < maxPush && pocitadloPop < maxPop && pocitadloPeek == maxPeek)
            {
                operacia = rand() % 2;
            }
            else if (pocitadloPush == maxPush && pocitadloPop == maxPop && pocitadloPeek < maxPeek)
            {
                operacia = 2;
            }
            else if (pocitadloPush == maxPush && pocitadloPop < maxPop && pocitadloPeek == maxPeek)
            {
                operacia = 1;
            } 
            else
            {
                operacia = 0;
            }

            priorita = rand() % 100000;
            hodnota = rand() % 100000;

            if (twoListsTest->size() == 0)
            {
                twoListsTest->push(priorita, hodnota);
            }

            switch (operacia)
            {
            case 0 :
                SimpleTest::startStopwatch();
                twoListsTest->push(priorita, hodnota);
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPush, SimpleTest::getElapsedTime(), "Push");
                pocitadloPush++;
                break;
            case 1:
                SimpleTest::startStopwatch();
                twoListsTest->pop();
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPop, SimpleTest::getElapsedTime(), "Pop");
                pocitadloPop++;
                break;
            case 2 :
                SimpleTest::startStopwatch();
                twoListsTest->peek();
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPeek, SimpleTest::getElapsedTime(), "Peek");
                pocitadloPeek++;
                break;
            default:
                break;
            }
        }
        delete twoListsTest;
    }

    TimePQTLPush::TimePQTLPush()
        : SimpleTest("Casova zlozitost Push pre PQTL")
    {
    }

    void TimePQTLPush::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;
        DurationTime cas;

        for (int i = 1; i < 10000; i += 10)
        {
            structures::PriorityQueueTwoLists<int>* pqtlTest = new structures::PriorityQueueTwoLists<int>((int)sqrt(i));

            for (int j = 0; j < i; j++)
            {
                data = rand() % 100;
                priorita = rand() % i;
                pqtlTest->push(priorita, data);
            }

            for (int k = 0; k < 100; k++)
            {
                data = rand() % 100;
                priorita = i + k;
                SimpleTest::startStopwatch();
                pqtlTest->push(priorita, data);
                SimpleTest::stopStopwatch();
                cas += SimpleTest::getElapsedTime();
            }
            cas = cas / 100;
            structures::Logger::getInstance().logDuration(i, cas, "Push");
            delete pqtlTest;
            cas = (DurationTime)0;
        }
    }


    TimePQTLPop::TimePQTLPop()
        : SimpleTest("Casova zlozitost Pop pre PQTL")
    {
    }

    void TimePQTLPop::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;

        structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>((int)sqrt(10000));

        for (int j = 0; j < 10000; j++)
        {
            priorita = rand() % 10000;
            data = rand() % 10000;

            twoList1->push(priorita, data);
        }

        for (int k = 0; k < 1000; k++)
        {
            SimpleTest::startStopwatch();
            twoList1->pop();
            SimpleTest::stopStopwatch(); 
            structures::Logger::getInstance().logDuration(k, SimpleTest::getElapsedTime(), "Pop");
        }

        delete twoList1;
    }

    TimePQTLPeek::TimePQTLPeek()
        : SimpleTest("Casova zlozitost Peek pre PQTL")
    {
    }

    void TimePQTLPeek::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;

        for (int i = 1; i < 10000; i = i + 100)
        {
            structures::PriorityQueueTwoLists<int>* twoList1 = new structures::PriorityQueueTwoLists<int>((int)sqrt(i));

            for (int j = 0; j < i; j++)
            {
                priorita = rand() % 1000;
                data = rand() % 1000;

                twoList1->push(priorita, data);
            }

            SimpleTest::startStopwatch();
            twoList1->peek();
            SimpleTest::stopStopwatch(); 
            structures::Logger::getInstance().logDuration(i, SimpleTest::getElapsedTime(), "Peek");
            delete twoList1;
        }
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
        addTest(new ScenarTestHeap());
        addTest(new TimeHeapPush());
        addTest(new TimeHeapPop());
        addTest(new TimeHeapPeek());
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

    ScenarTestHeap::ScenarTestHeap()
        : SimpleTest("Scenarove testy pre Heap")
    {
    }

    void ScenarTestHeap::test()
    {
        structures::Heap<int>* heapTest = new structures::Heap<int>();

        srand(time(NULL));

        int pocitadloPush = 0;
        int pocitadloPop = 0;
        int pocitadloPeek = 0;


        /*int maxPush = 35000;
        int maxPop = 35000;
        int maxPeek = 30000;*/

        /*int maxPush = 50000;
        int maxPop = 30000;
        int maxPeek = 20000;*/

        int maxPush = 70000;
        int maxPop = 25000;
        int maxPeek = 5000;

        int operacia = 0;
        int priorita = 0;
        int hodnota = 0;

        for (int i = 0; i < 100000; i++)
        {
            if (pocitadloPush < maxPush && pocitadloPop < maxPop && pocitadloPeek < maxPeek)
            {
                operacia = rand() % 3;
            }
            else if (pocitadloPush == maxPush && pocitadloPop < maxPop && pocitadloPeek < maxPeek)
            {
                operacia = (rand() % 2) + 1;
            }
            else if (pocitadloPush < maxPush && pocitadloPop == maxPop && pocitadloPeek < maxPeek)
            {
                operacia = rand() % 2;
                if (operacia == 1)
                {
                    operacia = 2;
                }
            }
            else if (pocitadloPush < maxPush && pocitadloPop < maxPop && pocitadloPeek == maxPeek)
            {
                operacia = rand() % 2;
            }
            else if (pocitadloPush == maxPush && pocitadloPop == maxPop && pocitadloPeek < maxPeek)
            {
                operacia = 2;
            }
            else if (pocitadloPush == maxPush && pocitadloPop < maxPop && pocitadloPeek == maxPeek)
            {
                operacia = 1;
            }
            else
            {
                operacia = 0;
            }

            priorita = rand() % 100000;
            hodnota = rand() % 100000;

            if (heapTest->size() == 0)
            {
                heapTest->push(priorita, hodnota);
            }

            switch (operacia)
            {
            case 0:
                SimpleTest::startStopwatch();
                heapTest->push(priorita, hodnota);
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPush, SimpleTest::getElapsedTime(), "Push");
                pocitadloPush++;
                break;
            case 1:
                SimpleTest::startStopwatch();
                heapTest->pop();
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPop, SimpleTest::getElapsedTime(), "Pop");
                pocitadloPop++;
                break;
            case 2:
                SimpleTest::startStopwatch();
                heapTest->peek();
                SimpleTest::stopStopwatch();
                structures::Logger::getInstance().logDuration(pocitadloPeek, SimpleTest::getElapsedTime(), "Peek");
                pocitadloPeek++;
                break;
            default:
                break;
            }
        }
        delete heapTest;
    }

    TimeHeapPush::TimeHeapPush()
        : SimpleTest("Casova zlozitost Push pre Heap")
    {
    }

    void TimeHeapPush::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;
        DurationTime cas;

        for (int i = 1; i < 10000; i += 10)
        {
            structures::Heap<int>* heapTest = new structures::Heap<int>();

            for (int j = 0; j < i; j++)
            {
                data = rand() % 100;
                priorita = rand() % i;
                heapTest->push(priorita, data);
            }

            for (int k = 0; k < 100; k++)
            {
                data = rand() % 100;
                priorita = 0 - k;
                SimpleTest::startStopwatch();
                heapTest->push(priorita, data);
                SimpleTest::stopStopwatch();
                cas += SimpleTest::getElapsedTime();
            }
            cas = cas / 100;
            structures::Logger::getInstance().logDuration(i, cas, "Push");
            delete heapTest;
            cas = (DurationTime)0;
        }
    }


    TimeHeapPop::TimeHeapPop()
        : SimpleTest("Casova zlozitost Pop pre Heap")
    {
    }

    void TimeHeapPop::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;
        DurationTime cas;

        for (int i = 101; i < 10000; i += 10)
        {
            structures::Heap<int>* heapTest = new structures::Heap<int>();

            for (int j = 0; j < i; j++)
            {
                data = rand() % 100;
                priorita = rand() % i;
                heapTest->push(priorita, data);
            }

            for (int k = 0; k < 100; k++)
            {
                SimpleTest::startStopwatch();
                heapTest->pop();
                SimpleTest::stopStopwatch();
                cas += SimpleTest::getElapsedTime();
            }
            cas = cas / 100;
            structures::Logger::getInstance().logDuration(i, cas, "Pop");
            delete heapTest;
            cas = (DurationTime)0;
        }
    }

    TimeHeapPeek::TimeHeapPeek()
        : SimpleTest("Casova zlozitost Peek pre Heap")
    {
    }

    void TimeHeapPeek::test()
    {
        srand(time(NULL));
        int priorita = 0;
        int data = 0;

        structures::Heap<int>* heap3 = new structures::Heap<int>();
        structures::Heap<int>* heap1 = new structures::Heap<int>();
        structures::Heap<int>* heap2 = new structures::Heap<int>();

        for (int j = 0; j < 150; j++)
        {
            priorita = rand() % 100;
            data = rand() % 100;

            heap1->push(priorita, data);
        }

        for (int j = 0; j < 300; j++)
        {
            priorita = rand() % 100;
            data = rand() % 100;

            heap2->push(priorita, data);
        }

        for (int j = 0; j < 450; j++)
        {
            priorita = rand() % 100;
            data = rand() % 100;

            heap3->push(priorita, data);
        }

        for (int k = 0; k < 100; k++)
        {
            SimpleTest::startStopwatch();
            heap1->peek();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(k, SimpleTest::getElapsedTime(), "Pop 1");
        }

        for (int k = 0; k < 100; k++)
        {
            SimpleTest::startStopwatch();
            heap2->peek();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(k, SimpleTest::getElapsedTime(), "Pop 2");
        }

        for (int k = 0; k < 100; k++)
        {
            SimpleTest::startStopwatch();
            heap3->peek();
            SimpleTest::stopStopwatch();
            structures::Logger::getInstance().logDuration(k, SimpleTest::getElapsedTime(), "Pop 3");
        }

        delete heap1;
        delete heap2;
        delete heap3;
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