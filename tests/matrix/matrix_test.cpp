#include "matrix_test.h"
#include <time.h>
#include <stdlib.h>
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/matrix/incoherent_matrix.h"
#include "../../csv_log_consumer.h"

namespace tests
{
	tests::MatrixTestInterface::MatrixTestInterface() :
		SimpleTest("Interface")
	{
	}

	void tests::MatrixTestInterface::test()
	{
		structures::Matrix<int>* matrix = this->makeMatrix(20, 20);
		matrix->assign(*matrix);
		matrix->equals(*matrix);
		matrix->size();
		matrix->isEmpty();
		matrix->getRowCount();
		matrix->getColumnCount();
		matrix->at(10, 10);
		delete matrix;
	}

	structures::Matrix<int>* CoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::CoherentMatrix<int>(rows, cols);
	}

	structures::Matrix<int>* IncoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::IncoherentMatrix<int>(rows, cols);
	}

	CoherentMatrixTestOverall::CoherentMatrixTestOverall() :
		ComplexTest("CoherentMatrix")
	{
		addTest(new CoherentMatrixTestInterface());
		addTest(new CoherentMatrixTestCopyConsturctor());
		addTest(new CoherentMatrixTestAt());
		addTest(new CoherentMatrixTestEquals());
		addTest(new CoherentMatrixTestAssign());
		addTest(new ScenarioACoherent());
	}

	IncoherentMatrixTestOverall::IncoherentMatrixTestOverall() :
		ComplexTest("IncoherentMatrix")
	{
		addTest(new IncoherentMatrixTestInterface());
		addTest(new IncoherentMatrixTestCopyConsturctor());
		addTest(new IncoherentMatrixTestAt());
		addTest(new IncoherentMatrixTestEquals());
		addTest(new IncoherentMatrixTestAssign());
		addTest(new ScenarioAIncoherent());
	}

	MatrixTestOverall::MatrixTestOverall() :
		ComplexTest("Matrix")
	{
		addTest(new CoherentMatrixTestOverall());
		addTest(new IncoherentMatrixTestOverall());
		addTest(new TimeAt());
		addTest(new TimeAssign());
	}

	CoherentMatrixTestCopyConsturctor::CoherentMatrixTestCopyConsturctor() : 
		SimpleTest("CoherentMatrix::CopyConstructor()")
	{
	}
	void CoherentMatrixTestCopyConsturctor::test()
	{
		structures::CoherentMatrix<int>* testCoherentMatrix = new structures::CoherentMatrix<int>(4, 5);
		
		for (size_t i = 0; i < testCoherentMatrix->getRowCount(); i++)
		{
			for (size_t j = 0; j < testCoherentMatrix->getColumnCount(); j++)
			{
				testCoherentMatrix->at(i, j) = i * j;
			}
		}

		structures::CoherentMatrix<int>* testCopyCoherentMatrix = new structures::CoherentMatrix<int>(*testCoherentMatrix);

		SimpleTest::assertTrue(testCopyCoherentMatrix->equals(*testCoherentMatrix));

		delete testCopyCoherentMatrix;
		delete testCoherentMatrix;
	}

	CoherentMatrixTestAt::CoherentMatrixTestAt()
		: SimpleTest("CoherentMatrix::At()")
	{
	}

	void CoherentMatrixTestAt::test()
	{
		structures::CoherentMatrix<int>* testCoherentMatrix = new structures::CoherentMatrix<int>(4, 5);

		for (size_t i = 0; i < testCoherentMatrix->getRowCount(); i++) {
			for (size_t j = 0; j < testCoherentMatrix->getColumnCount(); j++) {
				testCoherentMatrix->at(i, j) = i * j;
			}
		}

		for (size_t i = 0; i < testCoherentMatrix->getRowCount(); i++) {
			for (size_t j = 0; j < testCoherentMatrix->getColumnCount(); j++) {
				SimpleTest::assertTrue(testCoherentMatrix->at(i, j) == i * j, "Coherent Matrix at: " + std::to_string(j * i));
			}
		}

		delete testCoherentMatrix;
	}

	CoherentMatrixTestEquals::CoherentMatrixTestEquals() :
		SimpleTest("CoherentMatrix::equals()")
	{
	}

	void CoherentMatrixTestEquals::test()
	{
		structures::CoherentMatrix<int>* testCoherentMatrix1 = new structures::CoherentMatrix<int>(4, 4);
		structures::CoherentMatrix<int>* testCoherentMatrix2 = new structures::CoherentMatrix<int>(4, 4);
		for (size_t i = 0; i < testCoherentMatrix1->getRowCount(); i++) {
			for (size_t j = 0; j < testCoherentMatrix1->getColumnCount(); j++) {
				testCoherentMatrix1->at(i, j) = i * j;
				testCoherentMatrix2->at(i, j) = i * j;
			}
		}

		SimpleTest::assertTrue(testCoherentMatrix1->equals(*testCoherentMatrix2), "Rovnaju sa");

		delete testCoherentMatrix1;
		delete testCoherentMatrix2;
	}


	CoherentMatrixTestAssign::CoherentMatrixTestAssign() : 
		SimpleTest("CoherentMatrix::Assign()")
	{
	}

	void CoherentMatrixTestAssign::test()
	{
		structures::CoherentMatrix<int>* testCoherentMatrix1 = new structures::CoherentMatrix<int>(4, 4);
		structures::CoherentMatrix<int>* testCoherentMatrix2 = new structures::CoherentMatrix<int>(4, 4);
		for (size_t i = 0; i < testCoherentMatrix1->getRowCount(); i++) {
			for (size_t j = 0; j < testCoherentMatrix1->getColumnCount(); j++) {
				testCoherentMatrix1->at(i, j) = i * j;
				testCoherentMatrix2->at(i, j) = i;
			}
		}

		SimpleTest::assertFalse(testCoherentMatrix1->equals(*testCoherentMatrix2), "Povodne matice sa nerovnaju");

		testCoherentMatrix2->assign(*testCoherentMatrix1);

		SimpleTest::assertTrue(testCoherentMatrix1->equals(*testCoherentMatrix2), "Po priradeni sa matice rovnaju");

		delete testCoherentMatrix1;
		delete testCoherentMatrix2;
	}

	IncoherentMatrixTestCopyConsturctor::IncoherentMatrixTestCopyConsturctor() : SimpleTest("IncoherentMatrix::CopyConstructor()")
	{
	}

	void IncoherentMatrixTestCopyConsturctor::test()
	{
		structures::IncoherentMatrix<int>* testIncoherentMatrix = new structures::IncoherentMatrix<int>(4, 4);

		for (size_t i = 0; i < testIncoherentMatrix->getRowCount(); i++)
		{
			for (size_t j = 0; j < testIncoherentMatrix->getColumnCount(); j++)
			{
				testIncoherentMatrix->at(i, j) = i * j;
			}
		}

		structures::IncoherentMatrix<int>* testCopyIncoherentMatrix = new structures::IncoherentMatrix<int>(*testIncoherentMatrix);

		SimpleTest::assertTrue(testCopyIncoherentMatrix->equals(*testIncoherentMatrix));

		delete testCopyIncoherentMatrix;
		delete testIncoherentMatrix;
	}


	IncoherentMatrixTestAt::IncoherentMatrixTestAt() : SimpleTest("IncoherentMatrix::At()")
	{
	}

	void IncoherentMatrixTestAt::test()
	{
		structures::IncoherentMatrix<int>* testIncoherentMatrix = new structures::IncoherentMatrix<int>(4, 4);

		for (size_t i = 0; i < testIncoherentMatrix->getRowCount(); i++) {
			for (size_t j = 0; j < testIncoherentMatrix->getColumnCount(); j++) {
				testIncoherentMatrix->at(i, j) = i * j;
			}
		}

		for (size_t i = 0; i < testIncoherentMatrix->getRowCount(); i++) {
			for (size_t j = 0; j < testIncoherentMatrix->getColumnCount(); j++) {
				SimpleTest::assertTrue(testIncoherentMatrix->at(i, j) == i * j, "Coherent Matrix at: " + std::to_string(j * i));
			}
		}

		delete testIncoherentMatrix;
	}

	IncoherentMatrixTestEquals::IncoherentMatrixTestEquals() : SimpleTest("IncoherentMatrix::Equals()")
	{
	}

	void IncoherentMatrixTestEquals::test()
	{
		structures::IncoherentMatrix<int>* testIncoherentMatrix1 = new structures::IncoherentMatrix<int>(4, 4);
		structures::IncoherentMatrix<int>* testIncoherentMatrix2 = new structures::IncoherentMatrix<int>(4, 4);
		for (size_t i = 0; i < testIncoherentMatrix1->getRowCount(); i++) {
			for (size_t j = 0; j < testIncoherentMatrix1->getColumnCount(); j++) {
				testIncoherentMatrix1->at(i, j) = i * j;
				testIncoherentMatrix2->at(i, j) = i * j;
			}
		}

		SimpleTest::assertTrue(testIncoherentMatrix1->equals(*testIncoherentMatrix2), "Rovnaju sa");

		delete testIncoherentMatrix1;
		delete testIncoherentMatrix2;
	}


	IncoherentMatrixTestAssign::IncoherentMatrixTestAssign() : SimpleTest("IncoherentMatrix::Assing()")
	{
	}

	void IncoherentMatrixTestAssign::test()
	{
		structures::IncoherentMatrix<int>* testIncoherentMatrix1 = new structures::IncoherentMatrix<int>(4, 4);
		structures::IncoherentMatrix<int>* testIncoherentMatrix2 = new structures::IncoherentMatrix<int>(4, 4);
		for (size_t i = 0; i < testIncoherentMatrix1->getRowCount(); i++) {
			for (size_t j = 0; j < testIncoherentMatrix1->getColumnCount(); j++) {
				testIncoherentMatrix1->at(i, j) = i * j;
				testIncoherentMatrix2->at(i, j) = i;
			}
		}

		SimpleTest::assertFalse(testIncoherentMatrix1->equals(*testIncoherentMatrix2), "Povodne matice sa nerovnaju");

		testIncoherentMatrix2->assign(*testIncoherentMatrix1);

		SimpleTest::assertTrue(testIncoherentMatrix1->equals(*testIncoherentMatrix2), "Po priradeni sa matice rovnaju");

		delete testIncoherentMatrix1;
		delete testIncoherentMatrix2;
	}

	ScenarioACoherent::ScenarioACoherent() : SimpleTest("Scenar CoherentMatrix")
	{
	}

	void ScenarioACoherent::test()
	{
		int pocetRiadok = 10;
		int pocetStlpcov = 50;

		structures::CoherentMatrix<int>* scenarioAMatrix = new structures::CoherentMatrix<int>(pocetRiadok, pocetStlpcov);

		for (size_t i = 0; i < scenarioAMatrix->getRowCount(); i++) {
			for (size_t j = 0; j < scenarioAMatrix->getColumnCount(); j++) {
				scenarioAMatrix->at(i, j) = i + j;
			}
		}

		int maxPocetAt = 900000;
		int pocitadloAt = 0;
		int maxPocetGetRowCount = 50000;
		int pocitadloRC = 0;
		int maxPocetGetColumCount = 50000;
		int pocitadloCC = 0;
		int operacia = 0;
		int riadok = 0;
		int stlpec = 0;

		srand(time(NULL));

		for (int i = 0; i < 1000000; i++)
		{
			if (pocitadloAt < maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = rand() % 3;
			}
			else if (pocitadloAt == maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloAt < maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = rand() % 2;
				if (operacia == 1) {
					operacia = operacia + 1;
				}
			} 
			else if (pocitadloAt < maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = rand() % 2;
			} 
			else if (pocitadloAt < maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = 0;
			} 
			else if (pocitadloAt == maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = 1;
			}
			else if (pocitadloAt == maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = 2;
			}

			if (operacia == 0) {
				riadok = rand() % scenarioAMatrix->getRowCount();
				stlpec = rand() % scenarioAMatrix->getColumnCount();
				SimpleTest::startStopwatch();
				scenarioAMatrix->at(riadok, stlpec);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "At");
				pocitadloAt++;
			}
			if (operacia == 1) {
				SimpleTest::startStopwatch();
				scenarioAMatrix->getColumnCount();
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloCC, SimpleTest::getElapsedTime(), "CC");
				pocitadloCC++;
			}
			if (operacia == 2) {
				SimpleTest::startStopwatch();
				scenarioAMatrix->getRowCount();
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloRC, SimpleTest::getElapsedTime(), "RC ");
				pocitadloRC++;
			}
			
		}
		delete scenarioAMatrix;
	}

	ScenarioAIncoherent::ScenarioAIncoherent() : SimpleTest("Scenar IncoherentMatrix")
	{
	}

	void ScenarioAIncoherent::test()
	{
		int pocetRiadok = 500;
		int pocetStlpcov = 2000;

		structures::IncoherentMatrix<int>* scenarioAMatrix = new structures::IncoherentMatrix<int>(pocetRiadok, pocetStlpcov);

		for (size_t i = 0; i < pocetRiadok; i++) {
			for (size_t j = 0; j < pocetStlpcov; j++) {
				scenarioAMatrix->at(i, j) = i + j;
			}
		}

		int maxPocetAt = 600000;
		int pocitadloAt = 0;
		int maxPocetGetRowCount = 100000;
		int pocitadloRC = 0;
		int maxPocetGetColumCount = 300000;
		int pocitadloCC = 0;
		int operacia = 0;
		int riadok = 0;
		int stlpec = 0;

		srand(time(NULL));

		for (int i = 0; i < 1000000; i++)
		{
			if (pocitadloAt < maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = rand() % 3;
			}
			else if (pocitadloAt == maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = (rand() % 2) + 1;
			}
			else if (pocitadloAt < maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = rand() % 2;
				if (operacia == 1) {
					operacia = operacia + 1;
				}
			}
			else if (pocitadloAt < maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = rand() % 2;
			}
			else if (pocitadloAt < maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = 0;
			}
			else if (pocitadloAt == maxPocetAt && pocitadloCC < maxPocetGetColumCount && pocitadloRC == maxPocetGetRowCount) {
				operacia = 1;
			}
			else if (pocitadloAt == maxPocetAt && pocitadloCC == maxPocetGetColumCount && pocitadloRC < maxPocetGetRowCount) {
				operacia = 2;
			}

			if (operacia == 0) {
				riadok = rand() % scenarioAMatrix->getRowCount();
				stlpec = rand() % scenarioAMatrix->getColumnCount();
				SimpleTest::startStopwatch();
				scenarioAMatrix->at(riadok, stlpec);
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloAt, SimpleTest::getElapsedTime(), "At");
				pocitadloAt++;
			}
			if (operacia == 1) {
				SimpleTest::startStopwatch();
				scenarioAMatrix->getColumnCount();
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloCC, SimpleTest::getElapsedTime(), "CC");
				pocitadloCC++;
			}
			if (operacia == 2) {
				SimpleTest::startStopwatch();
				scenarioAMatrix->getRowCount();
				SimpleTest::stopStopwatch();
				structures::Logger::getInstance().logDuration(pocitadloRC, SimpleTest::getElapsedTime(), "RC");
				pocitadloRC++;
			}

		}
		delete scenarioAMatrix;
	}

	TimeAt::TimeAt() : SimpleTest("Zlozitosti pre At()")
	{
	}

	void TimeAt::AtCoherent()
	{
		srand(time(NULL));
		csv_log_consumer* logger = new csv_log_consumer("CasovaZlozitostAtCohNovy.csv");
		DurationTime cas;

		for (int i = 1; i <= 1001; i = i + 100)
		{
			for (int j = 1; j <= 1001; j = j + 100)
			{
				structures::CoherentMatrix<int>* testCoherentMatrix = new structures::CoherentMatrix<int>(i, j);
				for (int k = 0; k < testCoherentMatrix->getRowCount(); k++)
				{
					for (int l = 0; l < testCoherentMatrix->getColumnCount(); l++)
					{
						testCoherentMatrix->at(k, l) = k + l;
					}
				}

				for (int m = 0; m < 100; m++)
				{
					int riadky = rand() % testCoherentMatrix->getRowCount();
					int stlpce = rand() % testCoherentMatrix->getColumnCount();

					SimpleTest::startStopwatch();
					testCoherentMatrix->at(riadky,stlpce);
					SimpleTest::stopStopwatch();
					cas += SimpleTest::getElapsedTime();
				}
				cas = cas / 100;
				logger->zapisDoRiadku(cas);
				cas = (DurationTime)0;
				delete testCoherentMatrix;
			}
			logger->odriadkuj();
		}
		delete logger;
	}

	void TimeAt::AtIncoherent()
	{
		srand(time(NULL));
		csv_log_consumer* logger = new csv_log_consumer("CasovaZlozitostAtIncNovy.csv");
		DurationTime cas;

		for (int i = 1; i <= 1001; i = i + 100)
		{
			for (int j = 1; j <= 1001; j = j + 100)
			{
				structures::IncoherentMatrix<int>* testCoherentMatrix = new structures::IncoherentMatrix<int>(i, j);
				for (int k = 0; k < testCoherentMatrix->getRowCount(); k++)
				{
					for (int l = 0; l < testCoherentMatrix->getColumnCount(); l++)
					{
						testCoherentMatrix->at(k, l) = k + l;
					}
				}

				for (int m = 0; m < 100; m++)
				{
					int riadky = rand() % testCoherentMatrix->getRowCount();
					int stlpce = rand() % testCoherentMatrix->getColumnCount();

					SimpleTest::startStopwatch();
					testCoherentMatrix->at(riadky,stlpce);
					SimpleTest::stopStopwatch();
					cas += SimpleTest::getElapsedTime();
				}
				cas = cas / 100;
				logger->zapisDoRiadku(cas);
				cas = (DurationTime)0;
				delete testCoherentMatrix;
			}
			logger->odriadkuj();
		}
		delete logger;
	}

	void TimeAt::test()
	{
		AtCoherent();
		AtIncoherent();
	}

	TimeAssign::TimeAssign() : SimpleTest("Zlozitosti pre Assign()")
	{
	}

	void TimeAssign::AssignIncoherent()
	{
		srand(time(NULL));
		csv_log_consumer* logger = new csv_log_consumer("CasovaZlozitostAssignCoh.csv");
		DurationTime cas;

		for (int i = 1; i <= 1001; i = i + 100)
		{
			for (int j = 1; j <= 1001; j = j + 100)
			{
				structures::CoherentMatrix<int>* testCoherentMatrix = new structures::CoherentMatrix<int>(i, j);
				structures::CoherentMatrix<int>* copyTestCoherentMatrix = new structures::CoherentMatrix<int>(i, j);
				for (int k = 0; k < testCoherentMatrix->getRowCount(); k++)
				{
					for (int l = 0; l < testCoherentMatrix->getColumnCount(); l++)
					{
						testCoherentMatrix->at(k, l) = k + l;
						copyTestCoherentMatrix->at(k, l) = k;
					}
				}

				for (int m = 0; m < 100; m++)
				{
					int riadky = testCoherentMatrix->getRowCount();
					int stlpce = testCoherentMatrix->getColumnCount();

					SimpleTest::startStopwatch();
					copyTestCoherentMatrix->assign(*testCoherentMatrix);
					SimpleTest::stopStopwatch();
					cas += SimpleTest::getElapsedTime();
				}
				cas = cas / 100;
				logger->zapisDoRiadku(cas);
				cas = (DurationTime)0;
				delete testCoherentMatrix;
				delete copyTestCoherentMatrix;
			}
			logger->odriadkuj();
		}
		delete logger;
	}

	void TimeAssign::AssignCoherent()
	{
		srand(time(NULL));
		csv_log_consumer* logger = new csv_log_consumer("CasovaZlozitostAssignIncoh.csv");
		DurationTime cas;

		for (int i = 1; i <= 1001; i = i + 100)
		{
			for (int j = 1; j <= 1001; j = j + 100)
			{
				structures::IncoherentMatrix<int>* testCoherentMatrix = new structures::IncoherentMatrix<int>(i, j);
				structures::IncoherentMatrix<int>* copyTestCoherentMatrix = new structures::IncoherentMatrix<int>(i, j);
				for (int k = 0; k < testCoherentMatrix->getRowCount(); k++)
				{
					for (int l = 0; l < testCoherentMatrix->getColumnCount(); l++)
					{
						testCoherentMatrix->at(k, l) = k + l;
						copyTestCoherentMatrix->at(k, l) = k;
					}
				}

				for (int m = 0; m < 100; m++)
				{
					int riadky = testCoherentMatrix->getRowCount();
					int stlpce = testCoherentMatrix->getColumnCount();

					SimpleTest::startStopwatch();
					copyTestCoherentMatrix->assign(*testCoherentMatrix);
					SimpleTest::stopStopwatch();
					cas += SimpleTest::getElapsedTime();
				}
				cas = cas / 100;
				logger->zapisDoRiadku(cas);
				cas = (DurationTime)0;
				delete testCoherentMatrix;
				delete copyTestCoherentMatrix;
			}
			logger->odriadkuj();
		}
		delete logger;
	}

	void TimeAssign::test()
	{
		AssignCoherent();
		AssignIncoherent();
	}
}
