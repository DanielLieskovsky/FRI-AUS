#include "table_test.h"
#include "../../structures/table/binary_search_tree.h"
#include "../../structures/table/hash_table.h"
#include "../../structures/table/linked_table.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/table.h"
#include "../../structures/table/treap.h"
#include "../../structures/table/unsorted_sequence_table.h"

namespace tests
{
	TableTestInterface::TableTestInterface() :
		SimpleTest("Interface")
	{
	}

	void TableTestInterface::test()
	{
		int x = 0;
		structures::Table<int, int>* table = this->makeTable();
		table->equals(*table);
		table->assign(*table);
		table->insert(0, 0);
		table->find(0);
		table->remove(0);
		table->tryFind(0, x);
		table->containsKey(0);
		delete table;
		this->logPass("Compiled.");
	}

	structures::Table<int, int>* BinarySearchTreeTestInterface::makeTable()
	{
		return new structures::BinarySearchTree<int, int>();
	}

	structures::Table<int, int>* HashTableTestInterface::makeTable()
	{
		return new structures::HashTable<int, int>();
	}

	structures::Table<int, int>* LinkedTableTestInterface::makeTable()
	{
		return new structures::LinkedTable<int, int>();
	}

	structures::Table<int, int>* SortedSequenceTableTestInterface::makeTable()
	{
		return new structures::SortedSequenceTable<int, int>();
	}

	structures::Table<int, int>* TreapTestInterface::makeTable()
	{
		return new structures::Treap<int, int>();
	}

	structures::Table<int, int>* UnsortedSequenceTableTestInterface::makeTable()
	{
		return new structures::UnsortedSequenceTable<int, int>();
	}

	BinarySearchTreeTestOverall::BinarySearchTreeTestOverall() :
		ComplexTest("BinarySearchTree")
	{
		addTest(new BinarySearchTreeTestInterface());
		addTest(new BSTTestRemove());
		addTest(new BSTConstructorTest());
		addTest(new BSTCopyConstrucTest());
		addTest(new BSTSizeTest());
		addTest(new BSTAssignTest());
		addTest(new BSTEqualsTest());
		addTest(new BSTFindTest());
		addTest(new BSTInsertTest());
		addTest(new BSTTryFindTest());
		addTest(new BSTContainsKeyTest());
	}

	BSTConstructorTest::BSTConstructorTest()
		: SimpleTest("BST Constructor test")
	{
	}

	void BSTConstructorTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST = new structures::BinarySearchTree<int, int>();

		SimpleTest::assertTrue(myBST->size() == 0, "Velkost hned po vytvoreni je 0");

		myBST->insert(128, 'A');
		SimpleTest::assertFalse(myBST->size() == 0, "Velkost nie je 0");
		SimpleTest::assertTrue(myBST->size() == 1, "Velkost sa zvacsila po pridani 128/A");
		myBST->insert(213, 'C');
		myBST->insert(125, 'B');
		myBST->insert(122, 'E');
		myBST->insert(178, 'D');
		myBST->insert(241, 'G');
		myBST->insert(143, 'F');
		myBST->insert(222, 'I');
		myBST->insert(259, 'H');
		myBST->insert(237, 'J');
		SimpleTest::assertTrue(myBST->size() == 10, "Velkost sa zvacsila po pridani 9 dalsich prvkov");

		delete myBST;
	}

	BSTCopyConstrucTest::BSTCopyConstrucTest()
		: SimpleTest("BST CopyConstructor test")
	{
	}

	void BSTCopyConstrucTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		SimpleTest::assertTrue(myBST1->size() == 0, "Vytvorenie prazdneho orgiginalu prebehlo v pohode");

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		SimpleTest::assertTrue(myBST1->size() == 4, "Naplnenie originalu 4 prvkami prebehlo fajn");

		structures::BinarySearchTree<int, int>* myBST2 = new structures::BinarySearchTree<int, int>(*myBST1);

		SimpleTest::assertTrue(myBST2->size() == 4, "Vytvorila sa kopia so 4 prvkami");

		SimpleTest::assertTrue(myBST1->remove(128) == 'A', "Odstranenie korena originalu");
		SimpleTest::assertFalse(myBST1->size() == 4, "Velkost uz nie je 4");
		SimpleTest::assertTrue(myBST2->size() == 4, "Velkost kopie je aj napreik tomu 4");

		delete myBST1;
		delete myBST2;
	}

	BSTSizeTest::BSTSizeTest()
		: SimpleTest("BST Size test")
	{
	}

	void BSTSizeTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST = new structures::BinarySearchTree<int, int>();

		myBST->insert(128, 'A');
		SimpleTest::assertFalse(myBST->size() == 0, "Velkost nie je 0");
		SimpleTest::assertTrue(myBST->size() == 1, "Velkost sa zvacsila po pridani 128/A");
		myBST->insert(213, 'C');
		myBST->insert(125, 'B');
		SimpleTest::assertFalse(myBST->size() == 1, "Velkost nie je 1");
		SimpleTest::assertTrue(myBST->size() == 3, "Velkost sa zvacsila po pridani 2 dalsich");
		myBST->insert(122, 'E');
		myBST->insert(178, 'D');
		myBST->insert(241, 'G');
		SimpleTest::assertFalse(myBST->size() == 3, "Velkost nie je 3");
		SimpleTest::assertTrue(myBST->size() == 6, "Velkost sa zvacsila po pridani 3 dalsich");
		myBST->insert(143, 'F');
		myBST->insert(222, 'I');
		myBST->insert(259, 'H');
		myBST->insert(237, 'J');
		SimpleTest::assertFalse(myBST->size() == 6, "Velkost nie je 6");
		SimpleTest::assertTrue(myBST->size() == 10, "Velkost sa zvacsila po pridani 4 dalsich");

		myBST->remove(213);
		SimpleTest::assertFalse(myBST->size() == 10, "Velkost nie je 10");
		SimpleTest::assertTrue(myBST->size() == 9, "Velkost sa zmensila po odbrati 1 prvku");
		myBST->remove(178);
		myBST->remove(222);
		SimpleTest::assertFalse(myBST->size() == 8, "Velkost nie je 9");
		SimpleTest::assertTrue(myBST->size() == 7, "Velkost sa zmensila po odbrati 2 dalsich");

		delete myBST;
	}

	BSTAssignTest::BSTAssignTest()
		: SimpleTest("BST Assign test")
	{
	}

	void BSTAssignTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		SimpleTest::assertTrue(myBST1->size() == 0, "Vytvorenie prazdneho orgiginalu prebehlo v pohode");

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		SimpleTest::assertTrue(myBST1->size() == 4, "Naplnenie originalu 4 prvkami prebehlo fajn");

		structures::BinarySearchTree<int, int>* myBST2 = new structures::BinarySearchTree<int, int>();

		SimpleTest::assertTrue(myBST2->size() == 0, "Vytvorenie prazdnej kopie prebehlo v pohode");

		myBST2->insert(125, 'B');
		myBST2->insert(122, 'E');
		myBST2->insert(178, 'D');
		myBST2->insert(241, 'G');
		myBST2->insert(143, 'F');

		SimpleTest::assertTrue(myBST2->size() == 5, "Naplnenie kopie 5 prvkami prebehlo fajn");

		myBST2->assign(*myBST1);

		SimpleTest::assertTrue(myBST2->size() != 5, "Nema velkost 5");
		SimpleTest::assertTrue(myBST2->size() == myBST1->size(), "Ma velkost 4 tak ako original");

		delete myBST1;
		delete myBST2;
	}

	BSTEqualsTest::BSTEqualsTest()
		: SimpleTest("BST Equals test")
	{
	}

	void BSTEqualsTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		SimpleTest::assertTrue(myBST1->size() == 4, "Naplnenie prvej 4 prvkami prebehlo fajn -> size je 4");

		structures::BinarySearchTree<int, int>* myBST2 = new structures::BinarySearchTree<int, int>();

		myBST2->insert(125, 'B');
		myBST2->insert(122, 'E');
		myBST2->insert(178, 'D');
		myBST2->insert(241, 'G');
		myBST2->insert(143, 'F');

		SimpleTest::assertTrue(myBST2->size() == 5, "Naplnenie prvej 5 prvkami prebehlo fajn -> size je 5");

		structures::BinarySearchTree<int, int>* myBST3 = new structures::BinarySearchTree<int, int>();

		myBST3->insert(128, 'A');
		myBST3->insert(213, 'C');
		myBST3->insert(125, 'B');
		myBST3->insert(122, 'E');

		SimpleTest::assertTrue(myBST3->size() == 4, "Naplnenie tretej 4 rovnakymi prvkami ako 1 prebehlo fajn -> size je 4");

		structures::BinarySearchTree<int, int>* myBST4 = new structures::BinarySearchTree<int, int>();

		myBST4->insert(128, 'A');
		myBST4->insert(213, 'C');
		myBST4->insert(125, 'B');
		myBST4->insert(123, 'E');

		SimpleTest::assertTrue(myBST4->size() == 4, "Naplnenie prvej 4 prvkami inymi ako 1 prebehlo fajn -> size je 4");

		SimpleTest::assertFalse(myBST1->equals(*myBST2), "BST1 a BST2 sa nerovnaju");
		SimpleTest::assertTrue(myBST1->equals(*myBST3), "BST1 a BST3 sa rovnaju");
		SimpleTest::assertFalse(myBST1->equals(*myBST4), "BST1 a BST4 sa nerovnaju");

		delete myBST1;
		delete myBST2;
		delete myBST3;
		delete myBST4;
	}

	BSTFindTest::BSTFindTest()
		: SimpleTest("BST Find test")
	{
	}

	void BSTFindTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		SimpleTest::assertTrue(myBST1->find(128) == 'A', "Kluc 128 obsahuje data A");
		SimpleTest::assertTrue(myBST1->find(122) == 'E', "Kluc 122 obsahuje data E");

		delete myBST1;
	}

	BSTInsertTest::BSTInsertTest()
		: SimpleTest("BST Insert test")
	{
	}

	void BSTInsertTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(128, 'A');
		SimpleTest::assertTrue(myBST1->remove(128) == 'A', "Prebehlo vlozeneie 128/A");
		myBST1->insert(213, 'C');
		SimpleTest::assertTrue(myBST1->remove(213) == 'C', "Prebehlo vlozeneie 213/C");
		myBST1->insert(125, 'B');
		SimpleTest::assertTrue(myBST1->remove(125) == 'B', "Prebehlo vlozeneie 125/B");
		myBST1->insert(122, 'E');
		SimpleTest::assertTrue(myBST1->remove(122) == 'E', "Prebehlo vlozeneie 122/E");

		delete myBST1;
	}

	BSTTestRemove::BSTTestRemove()
		: SimpleTest("BST Remove test")
	{
	}

	void BSTTestRemove::test()
	{
		structures::BinarySearchTree<int, int>* myBST = new structures::BinarySearchTree<int, int>();

		myBST->insert(2, 2);
		myBST->insert(5, 5);
		myBST->insert(9, 9);
		myBST->insert(1, 1);
		myBST->insert(7, 7);
		myBST->insert(4, 4);
		myBST->insert(3, 3);
		myBST->insert(6, 6);

		SimpleTest::assertTrue(myBST->remove(4) == 4, "removed 4");
		SimpleTest::assertTrue(myBST->remove(2) == 2, "removed 2");
		SimpleTest::assertTrue(myBST->remove(1) == 1, "removed 1");
		SimpleTest::assertTrue(myBST->remove(5) == 5, "removed 5");
		SimpleTest::assertTrue(myBST->remove(7) == 7, "removed 7");

		delete myBST;
	}

	BSTTryFindTest::BSTTryFindTest()
		: SimpleTest("BST TryFind test")
	{
	}

	void BSTTryFindTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		int data;

		SimpleTest::assertTrue(myBST1->tryFind(128, data), "Nasiel data s danym klucom");
		SimpleTest::assertTrue(data == 'A', "data A");
		SimpleTest::assertFalse(myBST1->tryFind(1233, data), "Nenasiel data s danym klucom");
		SimpleTest::assertTrue(data == 'A', "Nezmenil data lebo nic nezasiel");

		delete myBST1;
	}

	BSTContainsKeyTest::BSTContainsKeyTest()
		: SimpleTest("BST ContainsKey test")
	{
	}

	void BSTContainsKeyTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(128, 'A');
		myBST1->insert(213, 'C');
		myBST1->insert(125, 'B');
		myBST1->insert(122, 'E');

		SimpleTest::assertTrue(myBST1->containsKey(128), "Obsahuje dany kluc");
		SimpleTest::assertFalse(myBST1->containsKey(1232), "Neobsahuje dany kluc");

		delete myBST1;
	}

	HashTableTestOverall::HashTableTestOverall() :
		ComplexTest("HashTable")
	{
		addTest(new HashTableTestInterface());
	}

	LinkedTableTestOverall::LinkedTableTestOverall() :
		ComplexTest("LinkedTable")
	{
		addTest(new LinkedTableTestInterface());
	}

	SortedSequenceTableTestOverall::SortedSequenceTableTestOverall() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SortedSequenceTableTestInterface());
	}

	TreapTestOverall::TreapTestOverall() :
		ComplexTest("Treap")
	{
		addTest(new TreapTestInterface());
	}

	UnsortedSequenceTableTestOverall::UnsortedSequenceTableTestOverall() :
		ComplexTest("UnsortedSequenceTable")
	{
		addTest(new UnsortedSequenceTableTestInterface());
	}

	TableTestOverall::TableTestOverall() :
		ComplexTest("Table")
	{
		addTest(new BinarySearchTreeTestOverall());
		addTest(new HashTableTestOverall());
		addTest(new LinkedTableTestOverall());
		addTest(new SortedSequenceTableTestOverall());
		addTest(new TreapTestOverall());
		addTest(new UnsortedSequenceTableTestOverall());
	}
}