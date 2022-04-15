#pragma once

#include "../test.h"
#include "../../structures/list/array_list.h"
#include "../../structures/list/linked_list.h"
#include "../../structures/list/double_linked_list.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania listu avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class ListTestInterface
		: public SimpleTest
	{
	public:
		ListTestInterface(std::string name);
		void test() override;

	protected:
		virtual structures::List<int>* makeList() const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody ArrayListu.
	/// </summary>
	class ArrayListTestInterface
		: public ListTestInterface
	{
	public:
		ArrayListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zavola vsetky metody LinkedListu.
	/// </summary>
	class LinkedListTestInterface
		: public ListTestInterface
	{
	public:
		LinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList.
	/// </summary>
	class ArrayListTestOverall
		: public ComplexTest
	{
	public:
		ArrayListTestOverall();
	};

	/// <summary>
	/// testovanie konstruktora (vytvorenie a spravne priradenie hodnot do struktury)
	/// </summary>
	class ALConstructorTest :
		public SimpleTest 
	{
	public:
		ALConstructorTest();
		void test() override;
	};

	/// <summary>
	/// testovanie kopirovacieho konstruktora (vytvorenie spravnej kopie podla uz vytvorenej matice)
	/// </summary>
	class ALCopyConstrucotr :
		public SimpleTest
	{
	public :
		ALCopyConstrucotr();
		void test() override;
	};

	/// <summary>
	/// testovanie priradenia jedneho ArrayListu do druheho
	/// </summary>
	class ALAssign :
		public SimpleTest
	{
	public:
		ALAssign();
		void test() override;
	};

	/// <summary>
	/// testovanie zhodnosti ArrayListov
	/// </summary>
	class ALEquals :
		public SimpleTest
	{
	public:
		ALEquals();
		void test() override;
	};

	/// <summary>
	/// testovanie hodnoty na danom indexe
	/// </summary>
	class ALAt :
		public SimpleTest
	{
	public:
		ALAt();
		void test() override;
	};

	/// <summary>
	/// testovanie priradenia hodnoty na koniec struktury
	/// </summary>
	class ALAdd :
		public SimpleTest
	{
	public:
		ALAdd();
		void test() override;
	};

	/// <summary>
	/// testovanie pridania hodnoty na danu poziciu
	/// </summary>
	class ALInsert :
		public SimpleTest
	{
	public:
		ALInsert();
		void test() override;
	};

	/// <summary>
	/// testovanie vymazania daneho prvku
	/// </summary>
	class ALTryRemove :
		public SimpleTest
	{
	public:
		ALTryRemove();
		void test() override;
	};

	/// <summary>
	/// testovanie vymazania z danej pozicie
	/// </summary>
	class ALRemoveAt :
		public SimpleTest
	{
	public:
		ALRemoveAt();
		void test() override;
	};

	/// <summary>
	/// testovanie vratenia indexu daneho prvku
	/// </summary>
	class ALGetIndexOf :
		public SimpleTest
	{
	public:
		ALGetIndexOf();
		void test() override;
	};

	/// <summary>
	/// testovanie vycistenia celeho ArrayListu
	/// </summary>
	class ALClear :
		public SimpleTest
	{
	public:
		ALClear();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class LinkedListTestOverall
		: public ComplexTest
	{
	public:
		LinkedListTestOverall();
	};

	/// <summary>
	/// Testovanie konstruktora DLL (vytvorenie a spravne priradenie hodnot do struktury)
	/// </summary>
	class DLLCosntructorTest :
		public SimpleTest
	{
	public:
		DLLCosntructorTest();
		void test() override;
	};

	/// <summary>
	/// testovanie kopirovacieho konstruktora (vytvorenie spravnej kopie)
	/// </summary>
	class DLLCopyConsturctor :
		public SimpleTest
	{
	public:
		DLLCopyConsturctor();
		void test() override;
	};

	/// <summary>
	/// Testovanie priradenia jedneho DLL do druheho
	/// </summary>
	class DLLAssign :
		public SimpleTest
	{
	public:
		DLLAssign();
		void test() override;
	};

	/// <summary>
	/// testovanie zhodnosti DoubleLinkedListov
	/// </summary>
	class DLLEquals :
		public SimpleTest
	{
	public:
		DLLEquals();
		void test() override;
	};

	/// <summary>
	/// Testovanie vyberu na urcitom indexe 
	/// </summary>
	class DLLAt :
		public SimpleTest
	{
	public:
		DLLAt();
		void test() override;
	};

	class DLLAdd :
		public SimpleTest
	{
	public:
		DLLAdd();
		void test() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju DoubleLinkedList.
	/// </summary>
	class DoubleLinkedListOverall
		: public ComplexTest
	{
	public:
		DoubleLinkedListOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList a LinkedList.
	/// </summary>
	class ListTestOverall :
		public ComplexTest
	{
	public:
		ListTestOverall();
	};
}