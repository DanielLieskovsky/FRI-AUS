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

	class ALConstructorTest :
		public SimpleTest 
	{
	public:
		ALConstructorTest();
		void test() override;
	};

	class ALCopyConstrucotr :
		public SimpleTest
	{
	public :
		ALCopyConstrucotr();
		void test() override;
	};

	class ALAssign :
		public SimpleTest
	{
	public:
		ALAssign();
		void test() override;
	};

	class ALEquals :
		public SimpleTest
	{
	public:
		ALEquals();
		void test() override;
	};

	class ALAt :
		public SimpleTest
	{
	public:
		ALAt();
		void test() override;
	};

	class ALAdd :
		public SimpleTest
	{
	public:
		ALAdd();
		void test() override;
	};

	class ALInsert :
		public SimpleTest
	{
	public:
		ALInsert();
		void test() override;
	};

	class ALTryRemove :
		public SimpleTest
	{
	public:
		ALTryRemove();
		void test() override;
	};

	class ALRemoveAt :
		public SimpleTest
	{
	public:
		ALRemoveAt();
		void test() override;
	};

	class ALGetIndexOf :
		public SimpleTest
	{
	public:
		ALGetIndexOf();
		void test() override;
	};

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