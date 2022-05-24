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
		addTest(new BSTConstructorTest());
		addTest(new BSTCopyConstrucTest());
		addTest(new BSTSizeTest());
		addTest(new BSTAssignTest());
		addTest(new BSTEqualsTest());
		addTest(new BSTTestRemove());
		addTest(new BSTFindTest());
		addTest(new BSTInsertTest());
		addTest(new BSTTryFindTest());
		addTest(new BSTContainsKeyTest());
		addTest(new BSTScenarTest());
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
		//odstranovanie korena
		structures::BinarySearchTree<int, int>* myBST = new structures::BinarySearchTree<int, int>();

		myBST->insert(2, 2);

		SimpleTest::assertTrue(myBST->remove(2) == 2, "odstranenie korenu bez ziadnych dalsich prvkov prebehol uspesne");

		myBST->insert(5, 5);
		myBST->insert(9, 9);
		myBST->insert(1, 1);

		SimpleTest::assertTrue(myBST->remove(5) == 5, "odstranenie korenu s 2 dalsimi prvkami prebehlo uspesne");

		delete myBST;

		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		myBST1->insert(7, 7);
		myBST1->insert(4, 4);

		SimpleTest::assertTrue(myBST1->remove(7) == 7, "odstranenie korenu s 1 dalsim (lavym) prvkom prebehlo uspesne");

		delete myBST1;

		structures::BinarySearchTree<int, int>* myBST2 = new structures::BinarySearchTree<int, int>();

		myBST2->insert(7, 7);
		myBST2->insert(9, 9);

		SimpleTest::assertTrue(myBST2->remove(7) == 7, "odstranenie korenu s 1 dalsim (pravym) prvkom prebehlo uspesne");

		delete myBST2;

		//odstranovanie listu hlbsie v strome
		structures::BinarySearchTree<int, int>* myBST3 = new structures::BinarySearchTree<int, int>();

		myBST3->insert(7, 7);
		myBST3->insert(9, 9);
		myBST3->insert(4, 4);
		myBST3->insert(2, 2);
		myBST3->insert(3, 3);
		myBST3->insert(8, 8);
		myBST3->insert(11, 11);
		myBST3->insert(5, 5);

		SimpleTest::assertTrue(myBST3->remove(5) == 5, "odstranenie listu z lavej strany");
		SimpleTest::assertTrue(myBST3->remove(11) == 11, "odstranenie listu z pravej strany");

		delete myBST3;

		//odstranovanie vo vnutri stromu
		structures::BinarySearchTree<int, int>* myBST4 = new structures::BinarySearchTree<int, int>();

		myBST4->insert(7, 7);
		myBST4->insert(9, 9);
		myBST4->insert(4, 4);
		myBST4->insert(2, 2);
		myBST4->insert(3, 3);
		myBST4->insert(8, 8);
		myBST4->insert(11, 11);
		myBST4->insert(5, 5);
		myBST4->insert(13, 13);

		SimpleTest::assertTrue(myBST4->remove(9) == 9, "odstranenie vrcholu s 2 dalsimi prvkami");
		SimpleTest::assertTrue(myBST4->remove(2) == 2, "odstranenie vrcholu s pravym");
		SimpleTest::assertTrue(myBST4->remove(5) == 5, "odstranenie listu aby som mal 4 s lavym synom 3");
		SimpleTest::assertTrue(myBST4->remove(4) == 4, "odstranenie vrcholu s lavym");

		delete myBST4;
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
		addTest(new SSTConstructTest());
		addTest(new SSTCopyConstructTest());
		addTest(new SSTAssignTest());
		addTest(new SSTInsertTest());
		addTest(new SSTEqualsTest());
		addTest(new SSTScenarTest());
		addTest(new InsertCasovaZlozitost());
		addTest(new RemoveCasovaZlozitost());
		addTest(new TryFindCasovaZlozitost());
	}

	SSTConstructTest::SSTConstructTest()
		: SimpleTest("SST Constructor test")
	{
	}

	void SSTConstructTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST = new structures::SortedSequenceTable<int, int>();

		SimpleTest::assertTrue(mySST->size() == 0, "Prazdna tabulka je vytvorena");

		mySST->insert(128, 'A');
		SimpleTest::assertTrue(mySST->size() == 1, "Vlozilo do tabulky prvok 128/A");
		mySST->insert(125, 'B');
		mySST->insert(213, 'C');
		mySST->insert(178, 'D');
		mySST->insert(122, 'E');
		mySST->insert(143, 'F');
		mySST->insert(241, 'G');
		mySST->insert(259, 'H');
		mySST->insert(222, 'I');
		mySST->insert(237, 'J');
		SimpleTest::assertTrue(mySST->size() == 10, "Vlozilo do tabulky dalsich 9 prvkov");

		delete mySST;
	}

	SSTCopyConstructTest::SSTCopyConstructTest()
		: SimpleTest("SST CopyConstructor test")
	{
	}

	void SSTCopyConstructTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST = new structures::SortedSequenceTable<int, int>();

		SimpleTest::assertTrue(mySST->size() == 0, "Prazdna tabulka je vytvorena");

		mySST->insert(128, 'A');
		mySST->insert(125, 'B');
		mySST->insert(213, 'C');
		mySST->insert(178, 'D');
		mySST->insert(122, 'E');
		mySST->insert(143, 'F');
		mySST->insert(241, 'G');
		mySST->insert(259, 'H');
		mySST->insert(222, 'I');
		mySST->insert(237, 'J');

		SimpleTest::assertTrue(mySST->size() == 10, "Tabulka bola naplnena 10 prvkami");

		structures::SortedSequenceTable<int, int>* mySST1 = new structures::SortedSequenceTable<int, int>(*mySST);

		SimpleTest::assertTrue(mySST1->size() == 10, "Do kopie tabulky bol uspesne vlozeny originál");

		mySST->remove(222);

		SimpleTest::assertTrue(mySST->size() == 9, "Odstranil sa jeden prvok z originalu");
		SimpleTest::assertTrue(mySST1->size() == 10, "Neodstranil sa prvok z kopie");

		delete mySST;
		delete mySST1;
	}

	SSTAssignTest::SSTAssignTest()
		: SimpleTest("SST Assign test")
	{
	}

	void SSTAssignTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST = new structures::SortedSequenceTable<int, int>();

		SimpleTest::assertTrue(mySST->size() == 0, "Prazdna tabulka je vytvorena");

		mySST->insert(128, 'A');
		mySST->insert(125, 'B');
		mySST->insert(213, 'C');
		mySST->insert(178, 'D');
		mySST->insert(122, 'E');
		mySST->insert(143, 'F');
		mySST->insert(241, 'G');
		mySST->insert(259, 'H');
		mySST->insert(222, 'I');
		mySST->insert(237, 'J');

		SimpleTest::assertTrue(mySST->size() == 10, "Tabulka (original) bola naplnena 10 prvkami");

		structures::SortedSequenceTable<int, int>* mySST1 = new structures::SortedSequenceTable<int, int>();

		mySST1->insert(128, 'A');
		mySST1->insert(125, 'B');
		mySST1->insert(213, 'C');
		mySST1->insert(178, 'D');
		mySST1->insert(122, 'E');

		SimpleTest::assertTrue(mySST1->size() == 5, "Tabulka (kopia) bola naplnena 5 prvkami");

		mySST1->assign(*mySST);

		SimpleTest::assertTrue(mySST1->size() == 10, "Tabulka (kopia) po priradeni ma velkost originalu");

		delete mySST;
		delete mySST1;
	}

	SSTInsertTest::SSTInsertTest()
		: SimpleTest("SST Insert test")
	{
	}

	void SSTInsertTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST = new structures::SortedSequenceTable<int, int>();

		SimpleTest::assertTrue(mySST->size() == 0, "Prazdna tabulka je vytvorena");

		mySST->insert(128, 'A');
		SimpleTest::assertTrue(mySST->size() == 1, "Tabulka sa naplnila 1 prvkom");
		mySST->insert(125, 'B');
		mySST->insert(213, 'C');
		SimpleTest::assertTrue(mySST->size() == 3, "Tabulka sa naplnila dalsimi 2 prvkami");
		mySST->insert(178, 'D');
		mySST->insert(122, 'E');
		mySST->insert(143, 'F');
		SimpleTest::assertTrue(mySST->size() == 6, "Tabulka sa naplnila dalsimi 3 prvkami");
		mySST->insert(241, 'G');
		mySST->insert(259, 'H');
		mySST->insert(222, 'I');
		mySST->insert(237, 'J');
		SimpleTest::assertTrue(mySST->size() == 10, "Tabulka sa naplnila dalsimi 4 prvkami");

		delete mySST;
	}

	SSTEqualsTest::SSTEqualsTest()
		: SimpleTest("SST Equal test")
	{
	}

	void SSTEqualsTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST = new structures::SortedSequenceTable<int, int>();

		mySST->insert(128, 'A');
		mySST->insert(125, 'B');
		mySST->insert(213, 'C');
		mySST->insert(178, 'D');
		mySST->insert(122, 'E');

		SimpleTest::assertTrue(mySST->size() == 5, "Prva tabulka s velkostou 5");

		structures::SortedSequenceTable<int, int>* mySST1 = new structures::SortedSequenceTable<int, int>();

		mySST1->insert(128, 'A');
		mySST1->insert(125, 'B');
		mySST1->insert(213, 'C');
		mySST1->insert(178, 'D');

		SimpleTest::assertTrue(mySST1->size() == 4, "Druha tabulka s velkostou 4");

		structures::SortedSequenceTable<int, int>* mySST2 = new structures::SortedSequenceTable<int, int>();

		mySST2->insert(128, 'A');
		mySST2->insert(125, 'B');
		mySST2->insert(214, 'C');
		mySST2->insert(178, 'D');
		mySST2->insert(122, 'E');

		SimpleTest::assertTrue(mySST2->size() == 5, "Tretia tabulka s velkostou 4");

		structures::SortedSequenceTable<int, int>* mySST3 = new structures::SortedSequenceTable<int, int>();

		mySST3->insert(128, 'A');
		mySST3->insert(125, 'B');
		mySST3->insert(213, 'C');
		mySST3->insert(178, 'D');
		mySST3->insert(122, 'E');

		SimpleTest::assertTrue(mySST3->size() == 5, "Stvrta tabulka s velkostou 5");

		SimpleTest::assertTrue(mySST3->equals(*mySST), "Prva so stvrtou su rovnake (aj velkost aj prvky)");
		SimpleTest::assertFalse(mySST->equals(*mySST1), "Prva a druha nie su rovnake (rozlicna velkost)");
		SimpleTest::assertFalse(mySST->equals(*mySST2), "Prva a tretia nie su rovnake (ine kluce)");


		delete mySST;
		delete mySST1;
		delete mySST2;
		delete mySST3;
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

	BSTScenarTest::BSTScenarTest()
		: SimpleTest("Scenarove testy pre BST")
	{
	}

	void BSTScenarTest::test()
	{
		structures::BinarySearchTree<int, int>* myBST1 = new structures::BinarySearchTree<int, int>();

		srand(time(NULL));

		int pocitadloInsert = 0;
		int pocitadloRemove = 0;
		int pocitadloTryFind = 0;

		/*int maxInsert = 20000;
		int maxRemove = 20000;
		int maxTryFind = 60000;*/

		int maxInsert = 40000;
		int maxRemove = 40000;
		int maxTryFind = 20000;

		int operacia = 0;
		int kluc = 0;
		int hodnota = 0;

		structures::ArrayList<int>* TabKluce = new structures::ArrayList<int>();

		for (int i = 0; i < 100000; i++)
		{
			TabKluce->add(i + 1);
		}

		for (int i = 0; i < 100000; i++)
		{
			// insert = 0; remove = 1; tryfind = 2;
			if (pocitadloInsert < maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = rand() % 3;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove == maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = rand() % 2;

				if (operacia == 1)
				{
					operacia = 2;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = rand() % 2;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove == maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = 0;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = 1;
			}
			else 
			{
				operacia = 2;
			}

			kluc = TabKluce->removeAt(rand() % TabKluce->size());
			hodnota = rand();

			if (operacia == 1 && !myBST1->containsKey(kluc))
			{
				myBST1->insert(kluc, hodnota);
			}

			switch (operacia)
			{
			case 0: 
				SimpleTest::startStopwatch();
				myBST1->insert(kluc, hodnota);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloInsert, SimpleTest::getElapsedTime(), "Insert");
				pocitadloInsert++;
				break;
			case 1:
				SimpleTest::startStopwatch();
				myBST1->remove(kluc);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloRemove, SimpleTest::getElapsedTime(), "Remove");
				pocitadloRemove++;
				break;
			case 2:
				SimpleTest::startStopwatch();
				myBST1->tryFind(kluc,hodnota);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloTryFind, SimpleTest::getElapsedTime(), "tryFind");
				pocitadloTryFind++;
				break;
			default:
				break;
			}
		}
		delete myBST1;
		delete TabKluce;
	}

	SSTScenarTest::SSTScenarTest()
		: SimpleTest("SST Scenar test")
	{
	}

	void SSTScenarTest::test()
	{
		structures::SortedSequenceTable<int, int>* mySST1 = new structures::SortedSequenceTable<int, int>();

		srand(time(NULL));

		int pocitadloInsert = 0;
		int pocitadloRemove = 0;
		int pocitadloTryFind = 0;

		/*int maxInsert = 20000;
		int maxRemove = 20000;
		int maxTryFind = 60000;*/

		int maxInsert = 40000;
		int maxRemove = 40000;
		int maxTryFind = 20000;

		int operacia = 0;
		int kluc = 0;
		int hodnota = 0;

		structures::ArrayList<int>* TabKluce = new structures::ArrayList<int>();

		for (int i = 0; i < 100000; i++)
		{
			TabKluce->add(i + 1);
		}

		for (int i = 0; i < 100000; i++)
		{
			// insert = 0; remove = 1; tryfind = 2;
			if (pocitadloInsert < maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = rand() % 3;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove == maxRemove && pocitadloTryFind < maxTryFind)
			{
				operacia = rand() % 2;

				if (operacia == 1)
				{
					operacia = 2;
				}
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = rand() % 2;
			}
			else if (pocitadloInsert < maxInsert && pocitadloRemove == maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = 0;
			}
			else if (pocitadloInsert == maxInsert && pocitadloRemove < maxRemove && pocitadloTryFind == maxTryFind)
			{
				operacia = 1;
			}
			else
			{
				operacia = 2;
			}

			kluc = TabKluce->removeAt(rand() % TabKluce->size());
			hodnota = rand();

			if (operacia == 1 && !mySST1->containsKey(kluc))
			{
				mySST1->insert(kluc, hodnota);
			}

			switch (operacia)
			{
			case 0:
				SimpleTest::startStopwatch();
				mySST1->insert(kluc, hodnota);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloInsert, SimpleTest::getElapsedTime(), "Insert");
				pocitadloInsert++;
				break;
			case 1:
				SimpleTest::startStopwatch();
				mySST1->remove(kluc);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloRemove, SimpleTest::getElapsedTime(), "Remove");
				pocitadloRemove++;
				break;
			case 2:
				SimpleTest::startStopwatch();
				mySST1->tryFind(kluc, hodnota);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloTryFind, SimpleTest::getElapsedTime(), "tryFind");
				pocitadloTryFind++;
				break;
			default:
				break;
			}
		}
		delete mySST1;
		delete TabKluce;
	}

	InsertCasovaZlozitost::InsertCasovaZlozitost()
		: SimpleTest("Casova zlozitost operacie Insert")
	{
	}

	void InsertCasovaZlozitost::test()
	{
		srand(time(NULL));

		int kluc = 0;
		int hodnota = 0;
		DurationTime cas;

		for (int i = 100; i < 50101; i += 1000)
		{
			structures::ArrayList<int>* TabKluce = new structures::ArrayList<int>();
			//structures::BinarySearchTree<int, int>* myStruct = new structures::BinarySearchTree<int, int>();

			structures::SortedSequenceTable<int, int>* myStruct = new structures::SortedSequenceTable<int, int>();

			for (int i = 0; i < 100000; i++)
			{
				TabKluce->add(i + 1);
			}

			for (int j = 0; j < i; j++)
			{
				kluc = TabKluce->removeAt(rand() % TabKluce->size());
				hodnota = rand();

				myStruct->insert(kluc, hodnota);
			}

			for (int i = 0; i < 100; i++)
			{
				kluc = TabKluce->removeAt(rand() % TabKluce->size());
				hodnota = rand();

				SimpleTest::startStopwatch();
				myStruct->insert(kluc, hodnota);
				SimpleTest::stopStopwatch();
				cas += SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Insert");

			cas = (DurationTime)0;

			delete myStruct;
			delete TabKluce;
		}
	}

	RemoveCasovaZlozitost::RemoveCasovaZlozitost()
		: SimpleTest("Casova zlozitost operacie Remove")
	{
	}

	void RemoveCasovaZlozitost::test()
	{
		srand(time(NULL));

		int kluc = 0;
		int hodnota = 0;
		DurationTime cas;

		for (int i = 100; i < 50101; i += 1000)
		{
			structures::ArrayList<int>* TabKluce = new structures::ArrayList<int>();
			//structures::BinarySearchTree<int, int>* myStruct = new structures::BinarySearchTree<int, int>();

			structures::SortedSequenceTable<int, int>* myStruct = new structures::SortedSequenceTable<int, int>();

			for (int i = 0; i < 100000; i++)
			{
				TabKluce->add(i + 1);
			}

			for (int j = 0; j < i; j++)
			{
				kluc = TabKluce->removeAt(rand() % TabKluce->size());
				hodnota = rand();

				myStruct->insert(kluc, hodnota);
			}

			for (int i = 0; i < 100; i++)
			{
				kluc = TabKluce->removeAt(rand() % TabKluce->size());
				hodnota = rand();
				myStruct->insert(kluc, hodnota);

				SimpleTest::startStopwatch();
				myStruct->remove(kluc);
				SimpleTest::stopStopwatch();
				cas += SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "Remove");

			cas = (DurationTime)0;

			delete myStruct;
			delete TabKluce;
		}
	}

	TryFindCasovaZlozitost::TryFindCasovaZlozitost()
		: SimpleTest("Casova zlozitost pre TryFind")
	{
	}

	void TryFindCasovaZlozitost::test()
	{
		srand(time(NULL));

		int kluc = 0;
		int hodnota = 0;
		DurationTime cas;

		for (int i = 100; i < 50101; i += 1000)
		{
			structures::ArrayList<int>* TabKluce = new structures::ArrayList<int>();
			//structures::BinarySearchTree<int, int>* myStruct = new structures::BinarySearchTree<int, int>();

			structures::SortedSequenceTable<int, int>* myStruct = new structures::SortedSequenceTable<int, int>();

			for (int i = 0; i < 100000; i++)
			{
				TabKluce->add(i + 1);
			}

			for (int j = 0; j < i; j++)
			{
				kluc = TabKluce->removeAt(rand() % TabKluce->size());
				hodnota = rand();

				myStruct->insert(kluc, hodnota);
			}

			for (int i = 0; i < 100; i++)
			{
				SimpleTest::startStopwatch();
				myStruct->tryFind(500000, hodnota);
				SimpleTest::stopStopwatch();
				cas += SimpleTest::getElapsedTime();
			}
			cas = cas / 100;
			structures::Logger::getInstance().logDuration(i, cas, "tryFind");

			cas = (DurationTime)0;

			delete myStruct;
			delete TabKluce;
		}
	}
}