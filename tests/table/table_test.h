#pragma once

#include "../test.h"
#include "../../structures/table/table.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania tabulky avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class TableTestInterface
		: public SimpleTest
	{
	public:
		TableTestInterface();
		void test() override;

	protected:
		virtual structures::Table<int, int>* makeTable() = 0;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class BinarySearchTreeTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class HashTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class LinkedTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class SortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class TreapTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class UnsortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class BinarySearchTreeTestOverall
		: public ComplexTest
	{
	public:
		BinarySearchTreeTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class HashTableTestOverall
		: public ComplexTest
	{
	public:
		HashTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class LinkedTableTestOverall
		: public ComplexTest
	{
	public:
		LinkedTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class SortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		SortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class TreapTestOverall
		: public ComplexTest
	{
	public:
		TreapTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class UnsortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		UnsortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju tabulku.
	/// </summary>
	class TableTestOverall
		: public ComplexTest
	{
	public:
		TableTestOverall();
	};

	class BSTConstructorTest
		: public SimpleTest
	{
	public:
		BSTConstructorTest();
		void test() override;
	};

	class BSTCopyConstrucTest
		: public SimpleTest
	{
	public:
		BSTCopyConstrucTest();
		void test() override;
	};


	class BSTSizeTest
		: public SimpleTest
	{
	public:
		BSTSizeTest();
		void test() override;
	};

	class BSTAssignTest
		: public SimpleTest
	{
	public:
		BSTAssignTest();
		void test() override;
	};

	class BSTEqualsTest
		: public SimpleTest
	{
	public:
		BSTEqualsTest();
		void test() override;
	};

	class BSTFindTest
		: public SimpleTest
	{
	public:
		BSTFindTest();
		void test() override;
	};

	class BSTInsertTest
		: public SimpleTest
	{
	public:
		BSTInsertTest();
		void test() override;
	};

	class BSTTestRemove
		: public SimpleTest
	{
	public:
		BSTTestRemove();
		void test() override;
	};

	class BSTTryFindTest
		: public SimpleTest
	{
	public:
		BSTTryFindTest();
		void test() override;
	};

	class BSTContainsKeyTest
		: public SimpleTest
	{
	public:
		BSTContainsKeyTest();
		void test() override;
	};

	class SSTConstructTest
		: public SimpleTest
	{
	public:
		SSTConstructTest();
		void test() override;
	};

	class SSTCopyConstructTest
		: public SimpleTest
	{
	public:
		SSTCopyConstructTest();
		void test() override;
	};

	class SSTAssignTest
		: public SimpleTest
	{
	public:
		SSTAssignTest();
		void test() override;
	};

	class SSTEqualsTest
		: public SimpleTest
	{
	public:
		SSTEqualsTest();
		void test() override;
	};

	class SSTInsertTest
		: public SimpleTest
	{
	public:
		SSTInsertTest();
		void test() override;
	};

	class BSTScenarTest
		: public SimpleTest
	{
	public:
		BSTScenarTest();
		void test() override;
	};

	class SSTScenarTest
		: public SimpleTest
	{
	public:
		SSTScenarTest();
		void test() override;
	};

	class InsertCasovaZlozitost
		: public SimpleTest
	{
	public:
		InsertCasovaZlozitost();
		void test() override;
	};

	class RemoveCasovaZlozitost
		: public SimpleTest
	{
	public:
		RemoveCasovaZlozitost();
		void test() override;
	};

	class TryFindCasovaZlozitost
		: public SimpleTest
	{
	public:
		TryFindCasovaZlozitost();
		void test() override;
	};
}