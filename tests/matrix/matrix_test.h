#pragma once

#include "../test.h"
#include "../../structures/matrix/matrix.h"
#include "../../structures/_logger/logger.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania matice avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class MatrixTestInterface
		: public SimpleTest
	{
	public:
		MatrixTestInterface();
		void test() override;

	protected:
		virtual structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const = 0;
	};

	/// <summary>
	/// Zavola vsetky metody koherentnej matice.
	/// </summary>
	class CoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zavola vsetky metody nekoherentnej matice.
	/// </summary>
	class IncoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherentMatrix.
	/// </summary>
	class CoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		CoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherrentMatrix a IncoherrentMatrix.
	/// </summary>
	class MatrixTestOverall
		: public ComplexTest
	{
	public:
		MatrixTestOverall();
	};

	/// <summary>
	/// Kontrola kopirovacieho konstruktoru CoherrentMatrix
	/// </summary>
	class CoherentMatrixTestCopyConsturctor : public SimpleTest {

	public:
		CoherentMatrixTestCopyConsturctor();
		void test() override;
	};

	/// <summary>
	/// Kontrola spravneho prvku na danej pozicii
	/// </summary>
	class CoherentMatrixTestAt : public SimpleTest {

	public:
		CoherentMatrixTestAt();
		void test() override;
	};

	/// <summary>
	/// Kontrola zhodnosti
	/// </summary>
	class CoherentMatrixTestEquals : public SimpleTest {

	public:
		CoherentMatrixTestEquals();
		void test() override;
	};

	/// <summary>
	/// Kontrola priradenia matic
	/// </summary>
	class CoherentMatrixTestAssign : public SimpleTest {
	public:
		CoherentMatrixTestAssign();
		void test() override;
	};

	/// <summary>
	/// Kontrola kopirovacieho konstruktoru CoherrentMatrix
	/// </summary>
	class IncoherentMatrixTestCopyConsturctor : public SimpleTest {

	public:
		IncoherentMatrixTestCopyConsturctor();
		void test() override;
	};

	/// <summary>
	/// Kontrola spravneho prvku na danej pozicii
	/// </summary>
	class IncoherentMatrixTestAt : public SimpleTest {

	public:
		IncoherentMatrixTestAt();
		void test() override;
	};

	/// <summary>
	/// Kontrola zhodnosti
	/// </summary>
	class IncoherentMatrixTestEquals : public SimpleTest {

	public:
		IncoherentMatrixTestEquals();
		void test() override;
	};

	/// <summary>
	/// Kontrola priradenia matic
	/// </summary>
	class IncoherentMatrixTestAssign : public SimpleTest {
	public:
		IncoherentMatrixTestAssign();
		void test() override;
	};

	class ScenarioACoherent : public SimpleTest
	{
	public:
		ScenarioACoherent();
		void test() override;
	};

	class ScenarioAIncoherent : public SimpleTest 
	{
	public:
		ScenarioAIncoherent();
		void test() override;
	};

	class TimeAt : public SimpleTest
	{
	public:
		TimeAt();
		void AtCoherent();
		void AtIncoherent();
		void test() override;
	};

	class TimeAssign : public SimpleTest
	{
	public:
		TimeAssign();
		void AssignIncoherent();
		void AssignCoherent();
		void test() override;
	};
}