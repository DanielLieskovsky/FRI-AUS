#include "list_test.h"
#include <time.h>
#include <stdlib.h>

namespace tests
{
// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}

// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}


	ALConstructorTest::ALConstructorTest() : 
		SimpleTest("Konstruktor test")
	{
	}

	void ALConstructorTest::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		SimpleTest::assertTrue(testAL->size() == 10, "Velkost 10 je spravna");
		SimpleTest::assertTrue(testAL->at(0) == 0, "Prvok 0 je 0 ");
		SimpleTest::assertTrue(testAL->at(testAL->size() - 1) == 9, "Prvok 9 je 9 ");

		delete testAL;
	}


	ALCopyConstrucotr::ALCopyConstrucotr() : SimpleTest("Copy konstruktor test")
	{
	}

	void ALCopyConstrucotr::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		structures::ArrayList<int>* copyTestAL = new structures::ArrayList<int>(*testAL);

		SimpleTest::assertTrue(copyTestAL->at(4) == testAL->at(4), "Rovnaka hodnota na pozici 4");
		SimpleTest::assertTrue(copyTestAL->at(0) == testAL->at(0), "Rovnaka hodnota na pozici 0");
		SimpleTest::assertTrue(copyTestAL->at(copyTestAL->size()-1) == testAL->at(testAL->size()-1), "Rovnaka hodnota na poslednej pozici");
		SimpleTest::assertFalse(copyTestAL->at(1) == testAL->at(2), "nerovnake hodnoty na pozcii 1 a 2");

		delete testAL;
		delete copyTestAL;
	}


	ALAssign::ALAssign() :
		SimpleTest("Assign test")
	{
	}

	void ALAssign::test()
	{
		structures::ArrayList<int>* testAL1 = new structures::ArrayList<int>();
		structures::ArrayList<int>* testAL2 = new structures::ArrayList<int>();
		structures::ArrayList<int>* testAL3 = new structures::ArrayList<int>();
		 
		for (int i = 0; i < 10; i++)
		{
			testAL1->add(i);
			testAL2->add(i + 2);
		}

		for (int i = 0; i < 15; i++)
		{
			testAL3->add(i);
		}

		testAL1->assign(*testAL2);

		SimpleTest::assertTrue(testAL2->equals(*testAL1), "ArrayListy rovnakej velkosti sa po priradení rovnajú");

		testAL1->assign(*testAL3);

		SimpleTest::assertTrue(testAL3->equals(*testAL1), "ArrayListy roznej velkosti sa po priradeni rovnaju");

		delete testAL1;
		delete testAL2;
		delete testAL3;
	}

	ALEquals::ALEquals() : 
		SimpleTest("Equals test")
	{
	}

	void ALEquals::test()
	{
		structures::ArrayList<int>* testAL1 = new structures::ArrayList<int>();
		structures::ArrayList<int>* testAL2 = new structures::ArrayList<int>();
		structures::ArrayList<int>* testAL3 = new structures::ArrayList<int>();
		structures::ArrayList<int>* testAL4 = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL1->add(i);
			testAL2->add(i);
			testAL4->add(i + 1);
		}

		for (int i = 0; i < 15; i++)
		{
			testAL3->add(i);
		}

		SimpleTest::assertTrue(testAL1->equals(*testAL2), "Matice rovnakej velkosti a rovnako naplnene sa rovnaju");
		SimpleTest::assertFalse(testAL2->equals(*testAL3), "Matice roznej velkosti sa nerovnaju");
		SimpleTest::assertFalse(testAL1->equals(*testAL4), "Matice rovnakej velkosti a rozne naplnene sa nerovnaju");

		delete testAL1;
		delete testAL2;
		delete testAL3;
		delete testAL4;
	}

	ALAt::ALAt() :
		SimpleTest("At test")
	{
	}

	void ALAt::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i+1);
		}

		SimpleTest::assertTrue(testAL->at(0) == 1, "Na nultej poziici je prvok 1");
		SimpleTest::assertTrue(testAL->at(testAL->size() - 1) == 10, "Na poslednej poziici je prvok 9");
		SimpleTest::assertFalse(testAL->at(1)  == 1, "Na prvej pozicii nie je prvok 1");
		SimpleTest::assertFalse(testAL->at(testAL->size() - 1) == 1, "Na poslednej pozici nie je prvok 1");

		delete testAL;
	}


	ALAdd::ALAdd() :
		SimpleTest("Add test")
	{
	}

	void ALAdd::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		testAL->add(2);

		SimpleTest::assertTrue(testAL->at(testAL->size() - 1) == 2, "Na poslednej pozicii je pridany prvok");
		SimpleTest::assertFalse(testAL->at(testAL->size() - 1) == 9, "Na poslednej pozicii sa nenachadza posledny prvok pred pridanim noveho");

		delete testAL;
	}


	ALInsert::ALInsert() :
		SimpleTest("Insert test")
	{
	}

	void ALInsert::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		testAL->insert(100,0);

		SimpleTest::assertTrue(testAL->at(0) == 100, "Na nultu poziciu sa uspesne vlozila 100");
		SimpleTest::assertFalse(testAL->at(0) == 0, "Na nultej pozicii nie je stara hodnota (0)");

		testAL->insert(200, 5);

		SimpleTest::assertTrue(testAL->at(5) == 200, "Na piatu poziciu sa uspesne vlozila 200");
		SimpleTest::assertFalse(testAL->at(5) == 5, "Na piatej pozicii nie je stara hodnota (5)");

		int indexAktualnePoslednejPozicie = testAL->size() - 1;
		testAL->insert(300, indexAktualnePoslednejPozicie);
		SimpleTest::assertTrue(testAL->at(indexAktualnePoslednejPozicie) == 300, "Na poslednu poziciu sa uspesne vlozila 300");
		SimpleTest::assertFalse(testAL->at(indexAktualnePoslednejPozicie) == 9, "Na poslednej pozicii nie je stara hodnota (9)");

		delete testAL;
	}

	ALTryRemove::ALTryRemove() :
		SimpleTest("TryRemove test")
	{
	}

	void ALTryRemove::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		SimpleTest::assertTrue(testAL->tryRemove(5), "Hodnota 5 sa nachadza v tabulke cize ju mozno odstranit");
		SimpleTest::assertFalse(testAL->tryRemove(200), "Hodnota 200 sa nenachadza v tabulke takze ju nemozno odstranit");

		delete testAL;
	}

	ALRemoveAt::ALRemoveAt() :
		SimpleTest("Remove test")
	{
	}

	void ALRemoveAt::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i);
		}

		SimpleTest::assertTrue(testAL->removeAt(0) == 0, "Odstranila sa 0 z nultej pozicie");
		SimpleTest::assertFalse(testAL->removeAt(0) == 0, "Odstranilo sa nieco z nultej pozicie co nebolo 0");
		SimpleTest::assertTrue(testAL->removeAt(testAL->size() - 1) == 9, "Odstranila sa 9 z poslednej pozicie");
		SimpleTest::assertFalse(testAL->removeAt(testAL->size() - 1) == 9, "Odstranilo sa nieco z poslednej pozicie co nebolo 9");

		delete testAL;
	}


	ALGetIndexOf::ALGetIndexOf() :
		SimpleTest("GetIndexOf test")
	{
	}

	void ALGetIndexOf::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i+1);
		}

		SimpleTest::assertTrue(testAL->getIndexOf(1) == 0, "Hodnota 1 sa nachadza na 0 pozicii");
		SimpleTest::assertFalse(testAL->getIndexOf(1) == 1, "Hodnota 1 sa nenachadaza na 1 pozicii");
		SimpleTest::assertTrue(testAL->getIndexOf(10) == (testAL->size() - 1), "Hodnota 9 sa nachadza na poslednej pozicii");
		SimpleTest::assertFalse(testAL->getIndexOf(10) == (testAL->size() - 2), " Hodnota 9 sa nenachadza na predposlednej pozicii");

		delete testAL;
	}

	ALClear::ALClear() :
		SimpleTest("Clear test")
	{
	}

	void ALClear::test()
	{
		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

		for (int i = 0; i < 10; i++)
		{
			testAL->add(i + 1);
		}

		testAL->clear();

		SimpleTest::assertTrue(testAL->size() == 0, "Po Clear je velkost ArrayListu 0");
		SimpleTest::assertFalse(testAL->size() == 1, "Po Clear nie je velkost ArrayListu 1");

		delete testAL;
	}

	//koniec testov AL ......................................................................................................

// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}

// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());
		addTest(new ALConstructorTest());
		addTest(new ALCopyConstrucotr());
		addTest(new ALAssign());
		addTest(new ALEquals());
		addTest(new ALAt());
		addTest(new ALAdd());
		addTest(new ALInsert());
		addTest(new ALTryRemove());
		addTest(new ALRemoveAt());
		addTest(new ALGetIndexOf());
		addTest(new ALClear());
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
	}

// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		addTest(new LinkedListTestOverall());
		addTest(new DoubleLinkedListOverall());
		addTest(new ALScenarTest());
		addTest(new DLLScenarTest());
		addTest(new TimeInsertAL());
		addTest(new TimeInsertDLL());
		addTest(new TimeAtAL());
		addTest(new TimeAtDLL());
		addTest(new TimeRemoveAtAL());
	}

// DoubleLinkedListOverall:
	// registracia testov DLL ........................................................................................................
	DoubleLinkedListOverall::DoubleLinkedListOverall() :
		ComplexTest("DoubleLinkedList")
	{
		addTest(new DLLCosntructorTest());
		addTest(new DLLCopyConsturctor());
		addTest(new DLLAssign());
		addTest(new DLLEquals());
		addTest(new DLLAt());
		addTest(new DLLAdd());
		addTest(new DLLInsert());
		addTest(new DLLTryRemove());
		addTest(new DLLRemoveAt());
		addTest(new DLLGetIndexOf());
		addTest(new DLLClear());
	}

	DLLCosntructorTest::DLLCosntructorTest() :
		SimpleTest("Konsturktor test")
	{
	}

	void DLLCosntructorTest::test()
	{
		structures::DoubleLinkedList<int>* testDDL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDDL->add(i);
		}

		SimpleTest::assertTrue(testDDL->size() == 10, "Velkost 10 je spravna");
		SimpleTest::assertTrue(testDDL->at(0) == 0, "Prvok 0 je 0 ");
		SimpleTest::assertTrue(testDDL->at(testDDL->size() - 1) == 9, "Prvok 9 je 9 ");

		delete testDDL;

	}

	DLLCopyConsturctor::DLLCopyConsturctor() :
		SimpleTest("CopyKonstruktor test")
	{
	}

	void DLLCopyConsturctor::test()
	{
		structures::DoubleLinkedList<int>* testDDL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDDL->add(i);
		}

		structures::DoubleLinkedList<int>* copyTestDDL = new structures::DoubleLinkedList<int>(*testDDL);

		SimpleTest::assertTrue(copyTestDDL->at(4) == testDDL->at(4), "Rovnaka hodnota na pozici 4");
		SimpleTest::assertTrue(copyTestDDL->at(0) == testDDL->at(0), "Rovnaka hodnota na pozici 0");
		SimpleTest::assertTrue(copyTestDDL->at(copyTestDDL->size() - 1) == testDDL->at(testDDL->size() - 1), "Rovnaka hodnota na poslednej pozici");
		SimpleTest::assertFalse(copyTestDDL->at(1) == testDDL->at(2), "nerovnake hodnoty na pozcii 1 a 2");

		delete copyTestDDL;
		delete testDDL;
	}

	DLLAssign::DLLAssign() :
		SimpleTest("Assign test")
	{
	}

	void DLLAssign::test()
	{
		structures::DoubleLinkedList<int>* testDLL1 = new structures::DoubleLinkedList<int>();
		structures::DoubleLinkedList<int>* testDLL2 = new structures::DoubleLinkedList<int>();
		structures::DoubleLinkedList<int>* testDLL3 = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL1->add(i);
			testDLL2->add(i + 2);
		}

		for (int i = 0; i < 15; i++)
		{
			testDLL3->add(i);
		}

		testDLL1->assign(*testDLL2);

		SimpleTest::assertTrue(testDLL2->equals(*testDLL1), "DoubleLinkedListy rovnakej velkosti sa po priradení rovnajú");

		testDLL1->assign(*testDLL3);

		SimpleTest::assertTrue(testDLL3->equals(*testDLL1), "DoubleLinkedListy roznej velkosti sa po priradeni rovnaju");

		delete testDLL1;
		delete testDLL2;
		delete testDLL3;
	}

	DLLEquals::DLLEquals() :
		SimpleTest("Equals test")
	{
	}

	void DLLEquals::test()
	{
		structures::DoubleLinkedList<int>* testDLL1 = new structures::DoubleLinkedList<int>();
		structures::DoubleLinkedList<int>* testDLL2 = new structures::DoubleLinkedList<int>();
		structures::DoubleLinkedList<int>* testDLL3 = new structures::DoubleLinkedList<int>();
		structures::DoubleLinkedList<int>* testDLL4 = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL1->add(i);
			testDLL2->add(i);
			testDLL4->add(i + 1);
		}

		for (int i = 0; i < 15; i++)
		{
			testDLL3->add(i);
		}

		SimpleTest::assertTrue(testDLL1->equals(*testDLL2), "Matice rovnakej velkosti a rovnako naplnene sa rovnaju");
		SimpleTest::assertFalse(testDLL2->equals(*testDLL3), "Matice roznej velkosti sa nerovnaju");
		SimpleTest::assertFalse(testDLL1->equals(*testDLL4), "Matice rovnakej velkosti a rozne naplnene sa nerovnaju");

		delete testDLL1;
		delete testDLL2;
		delete testDLL3;
		delete testDLL4;
	}

	DLLAt::DLLAt() :
		SimpleTest("At test")
	{
	}

	void DLLAt::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i + 1);
		}

		SimpleTest::assertTrue(testDLL->at(0) == 1, "Na nultej poziici je prvok 1");
		SimpleTest::assertTrue(testDLL->at(testDLL->size() - 1) == 10, "Na poslednej poziici je prvok 9");
		SimpleTest::assertFalse(testDLL->at(1) == 1, "Na prvej pozicii nie je prvok 1");
		SimpleTest::assertFalse(testDLL->at(testDLL->size() - 1) == 1, "Na poslednej pozici nie je prvok 1");

		delete testDLL;
	}

	DLLAdd::DLLAdd() :
		SimpleTest("Add test")
	{
	}

	void DLLAdd::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i);
		}

		testDLL->add(2);

		SimpleTest::assertTrue(testDLL->at(testDLL->size() - 1) == 2, "Na poslednej pozicii je pridany prvok");
		SimpleTest::assertFalse(testDLL->at(testDLL->size() - 1) == 9, "Na poslednej pozicii sa nenachadza posledny prvok pred pridanim noveho");

		delete testDLL;
	}

	DLLInsert::DLLInsert() :
		SimpleTest("Insert test")
	{
	}

	void DLLInsert::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i);
		}

		testDLL->insert(100, 0);

		SimpleTest::assertTrue(testDLL->at(0) == 100, "Na nultu poziciu sa uspesne vlozila 100");
		SimpleTest::assertFalse(testDLL->at(0) == 0, "Na nultej pozicii nie je stara hodnota (0)");

		testDLL->insert(200, 5);

		SimpleTest::assertTrue(testDLL->at(5) == 200, "Na piatu poziciu sa uspesne vlozila 200");
		SimpleTest::assertFalse(testDLL->at(5) == 5, "Na piatej pozicii nie je stara hodnota (5)");

		int indexAktualnePoslednejPozicie = testDLL->size() - 1;
		testDLL->insert(300, indexAktualnePoslednejPozicie);
		SimpleTest::assertTrue(testDLL->at(indexAktualnePoslednejPozicie) == 300, "Na poslednu poziciu sa uspesne vlozila 300");
		SimpleTest::assertFalse(testDLL->at(indexAktualnePoslednejPozicie) == 9, "Na poslednej pozicii nie je stara hodnota (9)");

		delete testDLL;
	}

	DLLTryRemove::DLLTryRemove() :
		SimpleTest("TryRemove test")
	{
	}

	void DLLTryRemove::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i);
		}

		SimpleTest::assertTrue(testDLL->tryRemove(5), "Hodnota 5 sa nachadza v tabulke cize ju mozno odstranit");
		SimpleTest::assertFalse(testDLL->tryRemove(200), "Hodnota 200 sa nenachadza v tabulke takze ju nemozno odstranit");

		delete testDLL;
	}

	DLLRemoveAt::DLLRemoveAt() :
		SimpleTest("RemoveAt test")
	{
	}

	void DLLRemoveAt::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i);
		}

		SimpleTest::assertTrue(testDLL->removeAt(0) == 0, "Odstranila sa 0 z nultej pozicie");
		SimpleTest::assertFalse(testDLL->removeAt(0) == 0, "Odstranilo sa nieco z nultej pozicie co nebolo 0");
		SimpleTest::assertTrue(testDLL->removeAt(testDLL->size() - 1) == 9, "Odstranila sa 9 z poslednej pozicie");
		SimpleTest::assertFalse(testDLL->removeAt(testDLL->size() - 1) == 9, "Odstranilo sa nieco z poslednej pozicie co nebolo 9");

		delete testDLL;
	}

	DLLGetIndexOf::DLLGetIndexOf() :
		SimpleTest("GetIndexOf test")
	{
	}

	void DLLGetIndexOf::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i + 1);
		}

		SimpleTest::assertTrue(testDLL->getIndexOf(1) == 0, "Hodnota 1 sa nachadza na 0 pozicii");
		SimpleTest::assertFalse(testDLL->getIndexOf(1) == 1, "Hodnota 1 sa nenachadaza na 1 pozicii");
		SimpleTest::assertTrue(testDLL->getIndexOf(10) == (testDLL->size() - 1), "Hodnota 9 sa nachadza na poslednej pozicii");
		SimpleTest::assertFalse(testDLL->getIndexOf(10) == (testDLL->size() - 2), " Hodnota 9 sa nenachadza na predposlednej pozicii");

		delete testDLL;
	}

	DLLClear::DLLClear() :
		SimpleTest("Clear test")
	{
	}

	void DLLClear::test()
	{
		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		for (int i = 0; i < 10; i++)
		{
			testDLL->add(i + 1);
		}

		testDLL->clear();

		SimpleTest::assertTrue(testDLL->size() == 0, "Po Clear je velkost ArrayListu 0");
		SimpleTest::assertFalse(testDLL->size() == 1, "Po Clear nie je velkost ArrayListu 1");

		delete testDLL;
	}

	ALScenarTest::ALScenarTest() :
		SimpleTest("Scenar ArrayList test")
	{
	}

	void ALScenarTest::test()
	{
		srand(time(NULL));

		structures::ArrayList<int>* testAL = new structures::ArrayList<int>();
		//structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		int maxInsert = 45000;
		int pocitadloInsert = 0;

		int maxRemoveAt = 45000;
		int pocitadloRemoveAt = 0;

		int maxAt = 5000;
		int pocitadloAt = 0;

		int maxGetIndexOf = 5000;
		int pocitadloGetIndexOf = 0;

		int operacia = 0;

		for (int i = 0; i < 100000; i++)
		{
			if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf) 
			{
				//0,1,2,3
				operacia = rand() % 4;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf) 
			{
				//0,1,2
				operacia = rand() % 3;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,1,3
				operacia = rand() % 3;
				if (operacia == 2) 
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,2,3
				operacia = (rand() % 3) + 1;
				if (operacia == 1) 
				{
					operacia = 0;
				}
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf) 
			{
				//1,2,3
				operacia = (rand() % 3) + 1;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//2,3
				operacia = (rand() % 2) + 2;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,3
				operacia = rand() % 2;
				if (operacia == 1) 
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0,1
				operacia = rand() % 2;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//1,3
				operacia = (rand() % 2) + 1;
				if (operacia == 2) 
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0,2
				operacia = rand() % 2;
				if (operacia == 1) 
				{
					operacia = 2;
				}
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//1,2
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0
				operacia = 0;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//1
				operacia = 1;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//2
				operacia = 2;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//3
				operacia = 3;
			}

			if (testAL->size() == 0) {
				testAL->add(rand() % 100);
			}

			int index = rand() % testAL->size();
			int data = rand() % 100;

			switch (operacia)
			{
			case 0 :
				SimpleTest::startStopwatch();
				testAL->insert(data, index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloInsert, SimpleTest::getElapsedTime(), "Insert");
				pocitadloInsert++;
				break;
			case 1:
				
				SimpleTest::startStopwatch();
				testAL->removeAt(index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloRemoveAt, SimpleTest::getElapsedTime(), "removeAt");
				pocitadloRemoveAt++;
				break;
			case 2:
				SimpleTest::startStopwatch();
				testAL->at(index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "At");
				pocitadloAt++;
				break;
			case 3:
				SimpleTest::startStopwatch();
				testAL->getIndexOf(data);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloGetIndexOf, SimpleTest::getElapsedTime(), "getIndexOf");
				pocitadloGetIndexOf++;
				break;
			default:
				break;
			}
		}
		delete testAL;
	}

	DLLScenarTest::DLLScenarTest() :
		SimpleTest("Scenar DoubleLinkedList test")
	{
	}

	void DLLScenarTest::test()
	{
		srand(time(NULL));

		structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

		int maxInsert = 45000;
		int pocitadloInsert = 0;

		int maxRemoveAt = 45000;
		int pocitadloRemoveAt = 0;

		int maxAt = 5000;
		int pocitadloAt = 0;

		int maxGetIndexOf = 5000;
		int pocitadloGetIndexOf = 0;

		int operacia = 0;

		for (int i = 0; i < 100000; i++)
		{
			if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,1,2,3
				operacia = rand() % 4;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0,1,2
				operacia = rand() % 3;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,1,3
				operacia = rand() % 3;
				if (operacia == 2)
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,2,3
				operacia = (rand() % 3) + 1;
				if (operacia == 1)
				{
					operacia = 0;
				}
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//1,2,3
				operacia = (rand() % 3) + 1;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//2,3
				operacia = (rand() % 2) + 2;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//0,3
				operacia = rand() % 2;
				if (operacia == 1)
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0,1
				operacia = rand() % 2;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//1,3
				operacia = (rand() % 2) + 1;
				if (operacia == 2)
				{
					operacia = 3;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0,2
				operacia = rand() % 2;
				if (operacia == 1)
				{
					operacia = 2;
				}
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//1,2
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//0
				operacia = 0;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt < maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//1
				operacia = 1;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt < maxAt && pocitadloGetIndexOf == maxGetIndexOf)
			{
				//2
				operacia = 2;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemoveAt == maxRemoveAt && pocitadloRemoveAt && pocitadloAt == maxAt && pocitadloGetIndexOf < maxGetIndexOf)
			{
				//3
				operacia = 3;
			}

			if (testDLL->size() == 0) {
				testDLL->add(rand() % 100);
			}

			int index = rand() % testDLL->size();
			int data = rand() % 100;

			switch (operacia)
			{
			case 0:
				SimpleTest::startStopwatch();
				testDLL->insert(data, index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "Insert");
				pocitadloInsert++;
				break;
			case 1:

				SimpleTest::startStopwatch();
				testDLL->removeAt(index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "removeAt");
				pocitadloRemoveAt++;
				break;
			case 2:
				SimpleTest::startStopwatch();
				testDLL->at(index);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "At");
				pocitadloAt++;
				break;
			case 3:
				SimpleTest::startStopwatch();
				testDLL->getIndexOf(data);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "getIndexOf");
				pocitadloGetIndexOf++;
				break;
			default:
				break;
			}
		}
		delete testDLL;
	}

	TimeInsertAL::TimeInsertAL() :
		SimpleTest("Casova zlozitost insert AL")
	{
	}

	void TimeInsertAL::test()
	{
		srand(time(NULL));
		int index = 0;
		int data = 0;
		DurationTime cas;


		for (int i = 1; i < 10001; i = i + 100)
		{
			structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

			for (int j = 0; j < i; j++)
			{
				testAL->add(rand() % 100);
			}

			for (int k = 0; k < 100; k++)
			{
				index = rand() % testAL->size();
				data = rand() % 100;

				SimpleTest::startStopwatch();
				testAL->insert(data, index);
				SimpleTest::stopStopwatch();
				cas = cas + SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");
			delete testAL;
			cas = (DurationTime)0;
		}
	}

	TimeInsertDLL::TimeInsertDLL() :
		SimpleTest("Casova zlozitost Insert pre DLL")
	{
	}

	void TimeInsertDLL::test()
	{
		srand(time(NULL));
		int index = 0;
		int data = 0;
		DurationTime cas;


		for (int i = 1; i < 10001; i = i + 100)
		{
			structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

			for (int j = 0; j < i; j++)
			{
				testDLL->add(rand() % 100);
			}

			for (int k = 0; k < 100; k++)
			{
				index = rand() % testDLL->size();
				data = rand() % 100;

				SimpleTest::startStopwatch();
				testDLL->insert(data, index);
				SimpleTest::stopStopwatch();
				cas = cas + SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");
			delete testDLL;
			cas = (DurationTime)0;
		}
	}

	TimeAtAL::TimeAtAL() :
		SimpleTest("Casova zlozitost At pre ArrayList")
	{
	}

	void TimeAtAL::test()
	{
		srand(time(NULL));
		int index = 0;
		int data = 0;
		DurationTime cas;


		for (int i = 1; i < 10002; i = i + 100)
		{
			structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

			for (int j = 0; j < i; j++)
			{
				testAL->add(rand() % 100);
			}

			for (int k = 0; k < 100; k++)
			{
				index = rand() % testAL->size();

				SimpleTest::startStopwatch();
				testAL->at(index);
				SimpleTest::stopStopwatch();
				cas = cas + SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");
			delete testAL;
			cas = (DurationTime)0;
		}
	}

	TimeAtDLL::TimeAtDLL() :
		SimpleTest("Casova zlozitost At pre DLL")
	{
	}

	void TimeAtDLL::test()
	{
		srand(time(NULL));
		int index = 0;
		int data = 0;
		DurationTime cas;


		for (int i = 1; i < 10002; i = i + 100)
		{
			structures::DoubleLinkedList<int>* testDLL = new structures::DoubleLinkedList<int>();

			for (int j = 0; j < i; j++)
			{
				testDLL->add(rand() % 100);
			}

			for (int k = 0; k < 100; k++)
			{
				index = rand() % testDLL->size();

				SimpleTest::startStopwatch();
				testDLL->at(index);
				SimpleTest::stopStopwatch();
				cas = cas + SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");
			delete testDLL;
			cas = (DurationTime)0;
		}
	}

	TimeRemoveAtAL::TimeRemoveAtAL() :
		SimpleTest("Casova zlozitost RemoveAt pre AL")
	{
	}

	void TimeRemoveAtAL::test()
	{
		srand(time(NULL));
		int index = 0;
		int data = 0;
		DurationTime cas;


		for (int i = 101; i < 100002; i = i + 1000)
		{
			structures::ArrayList<int>* testAL = new structures::ArrayList<int>();

			for (int j = 0; j < i; j++)
			{
				testAL->add(rand() % 100);
			}

			for (int k = 0; k < 100; k++)
			{
				index = rand() % testAL->size();

				SimpleTest::startStopwatch();
				testAL->removeAt(index);
				SimpleTest::stopStopwatch();
				cas = cas + SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");
			delete testAL;
			cas = (DurationTime)0;
		}
	}
}