#pragma once

#include <iostream>

#include "../include/simplefactory.h"
#include "../include/factory.h"

namespace designpattern
{
    namespace test
    {
        // 简单工厂
        void testSimpleFactory()
        {
            simplefactory::Operation *oper = nullptr;
            simplefactory::OperationFactory *operationfactory = new simplefactory::OperationFactory;
            const char operation = '*';
            oper = operationfactory->createOperate(operation);

            double numberA = 1;
            double numberB = 2;
            oper->setNumberA(numberA);
            oper->setNumberB(numberB);

            double result = oper->getResult();
            if (result == DBL_MIN) return;
            std::cout << numberA << operation << numberB << "=" << result << std::endl;

            delete operationfactory;
            operationfactory = nullptr;
            delete oper;
            oper = nullptr;
        }

        // 工厂
        void testFactory()
        {
            factory::LeiFengFactory *undergraduatefactory = new factory::UndergraduateFactory;
            factory::LeiFeng* student = undergraduatefactory->createLeiFeng();
            student->buyRice();
            student->sweep();
            student->wash();

            factory::LeiFengFactory* volunteerfactory = new factory::VolunteerFactory;
            factory::LeiFeng* volunteer = volunteerfactory->createLeiFeng();
            volunteer->buyRice();
            volunteer->sweep();
            volunteer->wash();

            delete undergraduatefactory;
            undergraduatefactory = nullptr;
            delete student;
            student = nullptr;

            delete volunteerfactory;
            volunteerfactory = nullptr;
            delete volunteer;
            volunteer = nullptr;
        }
    } // namespace test
} // namespace designpattern