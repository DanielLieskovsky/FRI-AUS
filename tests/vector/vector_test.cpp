#include "vector_test.h"
#include "../../structures/vector/vector.h"

namespace tests
{
// VectorTestInterface:

    VectorTestInterface::VectorTestInterface() :
        SimpleTest("Interface")
    {
    }

    void VectorTestInterface::test()
    {
        structures::Vector* vector = new structures::Vector(10);
        vector->size();
        vector->assign(*vector);
        vector->equals(*vector);
        vector->at(0);
        vector->getBytePointer(0);
        structures::Vector::copy(*vector, 0, *vector, 0, 1);
        delete vector;
        SimpleTest::logPass("Compiled.");
    }

    VectorTestAt::VectorTestAt() : SimpleTest("Vector::at(int)") //hodi do tych testov ako nazov a zaklikavacie policko
    {
    }

    void VectorTestAt::test()
    {
        //structures::Logger::getInstance().logInfo("Zaciatok testu");

        SimpleTest::startStopwatch();

        //SimpleTest::logInfo("Nazdar"); //vykona dany test
        structures::Vector* testVector = new structures::Vector(10);
        SimpleTest::assertTrue(testVector->size() == 10, "testVector->size()");

        for (int i = 0; i < 10; i++)
        {
            testVector->at(i) = i;
        }

        for (int i = 0; i < 10; i++)
        {
            SimpleTest::assertTrue(testVector->at(i) == i, "testVector->at(" + std::to_string(i) + ")");
            
            SimpleTest::assertTrue(*(testVector->getBytePointer(i)) == i, "testVector->at(" + std::to_string(i) + ")");
        }
        delete testVector;

        SimpleTest::stopStopwatch();
        structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), "Trvanie");
    }

    VectorTestCopyConstruct::VectorTestCopyConstruct() : SimpleTest("Vector::CopyConsturct()")
    {
    }

    void VectorTestCopyConstruct::test()
    {
        structures::Vector* testVector = new structures::Vector(10); //vektor s velkostou 10

        for (int i = 0; i < 10; i++) //naplnim ho od 0 az po 9
        {
            testVector->at(i) = i;
        }

        structures::Vector* copyTestVector = new structures::Vector(*testVector);


        SimpleTest::assertTrue(copyTestVector->equals(*testVector), "Kopia rovnaka ako povodny");

        copyTestVector->at(0) = 10;

        SimpleTest::assertFalse(copyTestVector->equals(*testVector), "Kopia rozdielna ako povodny po priradeni na 0 poziciu hodnoty 10");

        testVector->assign(*copyTestVector);

        SimpleTest::assertTrue(copyTestVector->equals(*testVector), "Povodny rovnaky ako kopia po priradeni kopie do povodneho");

        delete testVector;
        delete copyTestVector;
    }

// VectorTestOverall:

    VectorTestOverall::VectorTestOverall() :
        ComplexTest("Vector")
    {
        addTest(new VectorTestInterface());
        addTest(new VectorTestAt()); //potreba ho zaregistorvat
        addTest(new VectorTestCopyConstruct());
    }
    
    

}