#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"

namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };

    //----------------------------------------------------------------------------------testy two lists

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };
    /// <summary>
    /// Test spravneho vytvorenia Two Lists
    /// </summary>
    class TestConstructPriorityQueueTwoLists 
        : public SimpleTest
    {
    public:
        TestConstructPriorityQueueTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test kopirovacieho konstruktora Two Lists
    /// </summary>
    class TestCopyConstructorPriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestCopyConstructorPriorityQueueTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test spravneho priradenia Two Lists
    /// </summary>
    class TestAssignPriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestAssignPriorityQueueTwoLists();
        void test();
    };

    /// <summary>
    /// Test spravnej velkosti Two Lists
    /// </summary>
    class TestSizePriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestSizePriorityQueueTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test push Two Lists (pridanie prvku)
    /// </summary>
    class TestPushPriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestPushPriorityQueueTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test pop Two Lists (odobranie prvku)
    /// </summary>
    class TestPopPriorityQueeuTwoLists
        : public SimpleTest
    {
    public:
        TestPopPriorityQueeuTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test spravnej hodnoty prvku s najlepsou prioritou
    /// </summary>
    class TestPeekPriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestPeekPriorityQueueTwoLists();
        void test() override;
    };

    /// <summary>
    /// Test najlepsej priority
    /// </summary>
    class TestPeekPriorityPriorityQueueTwoLists
        : public SimpleTest
    {
    public:
        TestPeekPriorityPriorityQueueTwoLists();
        void test() override;
    };

    //..............................................................................koniec testov two lists
 
    //------------------------------------------------------------------------------zaciatok heap

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Test spravneho vytvorenia Heap
    /// </summary>
    class TestConstructHeap
        : public SimpleTest
    {
    public:
        TestConstructHeap();
        void test() override;
    };

    /// <summary>
    /// Test kopirovacieho konstruktoru Heap
    /// </summary>
    class TestCopyConstructHeap
        : public SimpleTest
    {
    public:
        TestCopyConstructHeap();
        void test() override;
    };

    /// <summary>
    /// Test spravneho priradenia Heap
    /// </summary>
    class TestAssingHeap
        : public SimpleTest
    {
    public:
        TestAssingHeap();
        void test() override;
    };

    /// <summary>
    /// Test pop Heap (pridanie prvku)
    /// </summary>
    class TestPopHeap
        : public SimpleTest
    {
    public:
        TestPopHeap();
        void test() override;
    };

    /// <summary>
    /// Test push Heap (odobratie prvku)
    /// </summary>
    class TestPushHeap
        : public SimpleTest
    {
    public:
        TestPushHeap();
        void test() override;
    };

    //...............................................................................koniec heap

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };
}